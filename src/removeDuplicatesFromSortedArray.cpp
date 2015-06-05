/*************************************************************************
	> File Name: removeDuplicatesFromSortedArray.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 May 2015 11:23:29 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


int removeDuplicates(vector<int>& nums)
{
  int count = 1;
  vector<int>::iterator tmp = nums.begin();
  for(vector<int>::iterator it = nums.begin() + 1; it != nums.end(); ++it)
  {
    if (*it != *tmp)
    {
      ++count;
      ++tmp;
      *tmp = *it;
    }
  }
  return count;
}

void printVector(vector<int> &vec, int size)
{
  for(int i = 0; i < size; ++i)
  {
    cout << vec[i];
  }
  cout << endl;
}

int main()
{
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(2);
  int length  = removeDuplicates(vec);
  cout << length << endl;
  printVector(vec, length);
  
  return 0;
}
