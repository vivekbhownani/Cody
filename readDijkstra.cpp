#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
	std::fstream fstr("dijkstra.txt");
	std::string line;
	while(std::getline(fstr, line))
	{
	   int vertex;
	   std::istringstream linestream(line);
	   linestream >> vertex;
	   std::cout<<vertex<<"\t";
	   std::string  pairstr;
	   while(std::getline(linestream, pairstr, '\t'))
	   {
		int W, length;
		std::istringstream pairstream(pairstr);
		std::string vals;
		std::getline(pairstream, vals, ',');
		std::istringstream valstream(vals);
		valstream >> W >> length; 
		
		std::cout<<W << " "<<length<<'\t';
	   }
std::cout <<std::endl;
	}
return 0;	
}
