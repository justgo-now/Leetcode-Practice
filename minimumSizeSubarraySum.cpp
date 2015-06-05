/*************************************************************************
  > File Name: minimumSizeSubarraySum.cpp
  > Author:
  > Mail:
  > Created Time: Tue 26 May 2015 05:03:22 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSubArrayLen(int s, vector<int> &nums)
{
  if (nums.empty())
  {
    return 0;
  }

  int start = -1, sum = nums[0], minLen = INT_MAX;
  bool flag = false;

  if (sum >= s)
  {
    start = 0;
    flag = true;
    minLen = 1;
  }

  for (int i = 1; i < nums.size(); i++)
  {
    sum += nums[i];

    if (sum >= s)
    {
      if (flag == false)
      {
        start = 0;
        flag = true;
      }

      while (sum - nums[start] >= s)
      {
        sum -= nums[start++];
      }

      minLen = min(i - start + 1, minLen);
    }
  }

  if (start == -1)
  {
    return 0;
  }
  else
  {
    return minLen;
  }
}
int main()
{
  vector<int> nums;
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(4);
  nums.push_back(3);

  int s = 7;
  cout << minSubArrayLen(s, nums) << endl;
}
