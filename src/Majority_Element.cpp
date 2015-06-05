/*************************************************************************
	> File Name: Majority_Element.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Apr 2015 03:51:57 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;


int majorityElement(vector<int>& nums) 
{
  int size = nums.size();
  map<int, int> numMap;
  const int guardNum = size / 2;

  for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
  {
    map<int, int>::iterator it = numMap.find(*iter);
    if (it != numMap.end())
    {
      numMap[*iter] += 1;
      if (it->second > guardNum) return it->first;
    }
    else
    {
      numMap.insert(make_pair(*iter, 1));
    }
  }
  return 0;
}


int main()
{
  vector<int> nums;
  for(int i = 0; i < 20; ++i)
  {
    int num = i + 1;
    if (i > 5) num = 5;
    nums.push_back(num);
  }
  cout << majorityElement(nums) << endl; 
}


