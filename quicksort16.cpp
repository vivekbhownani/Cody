#include<iostream>
#include<vector>
#include<fstream>

int partition(std::vector<int> &arr, int left, int right, size_t &comparisons)
{
 comparisons += (right - left);
 int pivot = arr[left];
 int pivotposition = left + 1;
 for( int ctr = left+1; ctr<=right; ctr++)
 {
  if(arr[ctr] < pivot )
  {
  // swap smallest (left most) after pivot position with the current element
   size_t temp = arr[ctr];
   arr[ctr] = arr[pivotposition];
   arr[pivotposition] = arr[ctr];
   pivotposition++;
  } 
 }

// done with the comparisons, now swap the largest (right most) before pivot and the pivot
arr[left] = arr[pivotposition-1];
arr[pivotposition-1] = pivot;
return (pivotposition - 1);
}


void quicksort(std::vector<int> &arr, int left, int right, size_t & comparisons)
{
 int p = partition(arr, left, right, comparisons);
 quicksort(arr, 0, p-1, comparisons);
 quicksort(arr, p+1, right, comparisons);
}


int main()
{
 std::cout<<"1";
  std::ifstream fstr("QuickSort.txt");
  std::vector<int> arr;
  arr.reserve(10000);
  
  std::cout<<"before adding array "; 
  int val;

  while( fstr >> val)
    arr.push_back(val);

 
  size_t comparisons = 0;
  quicksort(arr, 0, arr.size()-1, comparisons);

  std::cout<<"comparisons: "<< comparisons; 
}
