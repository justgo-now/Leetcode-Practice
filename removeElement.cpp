/*************************************************************************
	> File Name: removeElement.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 May 2015 12:20:34 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
  sort(nums.begin(), nums.end());
  vector<int>::iterator start = nums.end(), end = nums.end();
  for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
  {
    if (*it == val && start == nums.end())
    {
      start = it;
    }
    if (start != nums.end() && *it != val && end == nums.end())
    {
      end = it;
      break;
    }
  }

  if (start == end && start == nums.end()) return nums.size();
    if (start == end) nums.erase(start);
    else nums.erase(start, end);
  return nums.size();
}

void printVector(vector<int> &vec)
{
  for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
  {
    cout << *it;
  }
  cout << endl;
}

int main()
{
  int a = 1, b = 2;
  swap(a, b);
  cout << a << " " << b << endl;
  vector<int> vec;
  for(int i = 0; i < 10; ++i)
  {
    vec.push_back(i % 3);
  }
  //printVector(vec);
  //cout << removeElement(vec, 2) << endl;
  //printVector(vec);
  vec.clear();
  vec.push_back(2);
  vec.push_back(2);
  vec.push_back(5);
  cout << removeElement(vec, 2) << endl;
  printVector(vec);
  
  return 0;
}
