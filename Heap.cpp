#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class HeapImpl
{
private:
   std::vector<int> fHeap;
public:
   void insert(int elem);
   //int extractMin();
   void printHeap();
};


void HeapImpl::printHeap()
{
 for(auto v : fHeap)
  std::cout << v << " ";
 
std::cout<<endl;
}


// 1 4 5 7 8 3 
void HeapImpl::insert(int elem)
{
 fHeap.push_back(elem);
 // Now elem needs to moved to its right position by bubbling up
 int currentPos = fHeap.size();
 bool bubbleup = true;
 
while(bubbleup && currentPos > 1) { 
   int parentPos = currentPos/2;
   std::cout<<"parentPos="<<parentPos<< " " <<"currentPos="<<" "<< currentPos<< endl;;
   if(fHeap[parentPos-1] > fHeap[currentPos-1])
   {
     std::iter_swap(fHeap.begin() + parentPos - 1, fHeap.begin() + currentPos - 1);
     currentPos = parentPos;
   }
   else
   {
     bubbleup = false;
   }
 }

}

int main()
{
  HeapImpl myHeap;
  myHeap.insert(4); 
  myHeap.insert(4); 
  myHeap.insert(8);
  myHeap.insert(9);
  myHeap.insert(4);
  myHeap.insert(12);
  myHeap.insert(9);
 myHeap.insert(11);
  myHeap.insert(13);
 
 myHeap.insert(7);
 myHeap.insert(10);
myHeap.insert(5);
myHeap.insert(1);
  myHeap.printHeap();
}  
