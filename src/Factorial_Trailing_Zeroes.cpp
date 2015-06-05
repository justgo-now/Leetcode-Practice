/*************************************************************************
	> File Name: Factorial_Trailing_Zeroes.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Apr 2015 02:23:07 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int trailingZeroes(int n)
{
  int x = 5;
  int ans = 0;
  while(n >= x)
  {
    ans = ans + n / x;
    x = x * 5;
  }
  return ans;
}

int main()
{
  int n;
  while(true)
  {
    cin >> n;
    cout << trailingZeroes(n) << "个" << endl;
  }
}


