/*************************************************************************
	> File Name: House_Robber.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 Apr 2015 11:03:23 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

#define MAX(a, b) (a) > (b) ? (a) : (b)
int rob(vector<int> &num)
{
  if (num.size() == 0)
  {
    return 0;
  }
  else if (num.size() == 1)
  {
    return num[0];
  }
  else
  {
    int *max = new int[num.size()];
    max[0] = num[0];
    max[1] = MAX(num[0], num[1]);
    
    for( int i = 2; i < num.size(); ++i )
    {
      max[i] = MAX(max[i - 2] + num[i], max[i - 1]);
    }
    return max[num.size() - 1];
  }
}

int main()
{  

  return 0;
}
