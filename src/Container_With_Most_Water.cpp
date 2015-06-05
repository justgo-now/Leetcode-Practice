/*************************************************************************
	> File Name: Container_With_Most_Water.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 14 May 2015 03:23:02 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b)
{
  return (a > b) ? b : a;
}
int maxArea(vector<int> &height)
{
  int size = height.size();
  int max = 0;
  int start = 0, end = size - 1;
  while(start < end)
  {
    int area = (end - start) * min(height[start], height[end]);
    if (max < area) max = area;
    if (height[start] < height[end]) ++start;
    else --end;
  }

  return max;
}

int main()
{
  vector<int> height;
  height.push_back(1);
  height.push_back(1);
  
  cout << maxArea(height) << endl;
  return 0;
}


