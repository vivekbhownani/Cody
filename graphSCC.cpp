#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<fstream>
#include<sstream>

using namespace std;

typedef std::vector<int> Arcs;
typedef std::map<int, Arcs> Graph;
typedef std::vector<int> FinishingTimes;
typedef std::map<int, std::vector<int>> Components;

int t;
int leader;
const int NUM_V = 875714;
Components scc;
bool count_components = false;

void createGraphs(Graph &forward, Graph &reverse)
{
  std::fstream fstr("SCC.txt");
  
  int count = 0;
  int tail, head;
  while(fstr >> tail >> head)
  {
    forward[tail-1].push_back(head-1);
    reverse[head-1].push_back(tail-1);
  }
}

void DFS(Graph &g, int i, std::vector<bool> &explored, FinishingTimes &f /*= FinishingTimes()*/ )
{
  //std::cout<<"explored "<< i+1<<endl;

  explored[i] = true;
  if(count_components)
    scc[leader].push_back(i);

  // recurse for all arcs
  for(auto &j : g[i])
  {
    if(explored[j] == false)
      DFS(g, j, explored, f); 
  }
  if(!count_components)
  {
    ++t;
    f[i] = t;
  } 
}

void DFSLoop(Graph &g, FinishingTimes &f)
{
  t=-1;
  leader = 0;
  std::vector<bool> explored(NUM_V, false);
  if(!count_components)
  {
      for(int i=NUM_V-1; i >=0; i--)
	{
	  if(explored[i] == false)
	    {
	      //leader = i;
	      DFS(g, i, explored, f);  
	    } 
	}
  }
  else
  {
      for(int i = 0; i<NUM_V; i++)
      {
	auto max_it = std::max_element(f.begin(), f.end());
	int idx = std::distance(f.begin(), max_it);
	*max_it = -1;
	if(explored[idx] == false)
	  {
	    leader = idx;
	    DFS(g, idx, explored, f);
	  }
      }
  }
}

int main()
{
  Graph forward, reverse;
  createGraphs(forward, reverse);

  // Run DFS on the reverse graph
  FinishingTimes f(NUM_V, 0);
  DFSLoop(reverse, f);
  
  // std::cout<<"finishing times: ";

  /* for (auto val:f)
    {
      std::cout << val <<endl;
      }*/

  // Run DFS on the forward graph
  count_components = true;
  DFSLoop(forward, f);

  /*std::cout<<"finishing times: ";

  for (auto val:f)
    {
      std::cout << val <<endl;
      }*/

  // compute 5 highest scc

  std::vector<int> lengths(scc.size());

  for(auto val : scc)
    lengths.push_back(val.second.size());

  std::vector<int> max_five_lengths;
  for(int i = 0; i< 5; i++)
    {
      auto it = std::max_element(lengths.begin(), lengths.end());
      max_five_lengths.push_back(*it);
      *it = -1;
    }

  std::cout<< "total scc " <<lengths.size();
  std::cout<< " max 5: "<< max_five_lengths[0]<<" "<<max_five_lengths[1]<<" "<<max_five_lengths[2]<<" "<<max_five_lengths[3]<<" "<<max_five_lengths[4] << endl;
  
  return 0;
}
