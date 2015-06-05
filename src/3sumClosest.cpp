/*************************************************************************
	> File Name: 3sumClosest.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 14 May 2015 04:37:53 PM CST
 ************************************************************************/

#include <math.h>
#include <iostream>
#include <vector>

using namespace std;


int threeSumClosest(vector<int> &nums, int target)
{
      int size = nums.size();
      int tar = 0;
      int dis = 0x7fffffff;
      for (int i = 0; i < size; ++i)
      {
        for(int start = i + 1; start < size; ++start)
        {
            for(int end = start + 1; end < size; ++end)
            {
              int sum = nums[i] + nums[start] + nums[end];
              int tmp = abs(sum - target);
              if (dis > tmp)
              {
                dis = tmp;
                tar = sum;
              }
            }
        }
        return tar;
      }
    }
int main()
{
  vector<int> vec;
  vec.push_back(0);
  vec.push_back(2);
  vec.push_back(1);
  vec.push_back(-3);
  cout << threeSumClosest(vec, 1);
  return 0;
}
