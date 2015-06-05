/*************************************************************************
	> File Name: heapSort.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 03 Jun 2015 10:15:32 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

#define LEFT(i) 2 * i
#define RIGHT(i) 2 * i + 1

void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

void printVector(vector<int> &nums)
{
  vector<int>::iterator it = nums.begin();
  for(; it != nums.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
}

void maxHeapify(vector<int> &nums, int index, int heapSize)
{
  int left = LEFT(index);
  int right = RIGHT(index);
  int largest = index;

  if (left <= heapSize && nums[left - 1] > nums[index - 1]) largest = left;
  else largest = index;

  if (right <= heapSize && nums[right - 1] > nums[largest - 1]) largest = right;

  if (largest != index)
  {
    swap(nums[largest - 1], nums[index - 1]);

    maxHeapify(nums, largest, heapSize);
  }
}

void makeMaxHeap(vector<int> &nums)
{
  for (int i = nums.size() / 2 ; i > 0; --i)
  {
    maxHeapify(nums, i, nums.size());
  }
}

void heapSort(vector<int> &nums)
{
  makeMaxHeap(nums);
  printVector(nums);
  for(int i = nums.size(); i > 1; --i)
  {
    swap(nums[0], nums[i - 1]);
    printVector(nums);
    maxHeapify(nums, 1, i - 1);
  }
}

int main()
{
  const int guardNum = 10;
  vector<int> vec;
  srand(0);
  for(int i = 0; i < guardNum; ++i)
  {
    vec.push_back(random() % guardNum);
  }
  printVector(vec);
  heapSort(vec);
  printVector(vec);

  return 0;
}
