/*************************************************************************
	> File Name: Bitwise_AND_Of_Numbers_Range.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Apr 2015 03:56:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int rangeBitwiseAnd(int m, int n)
{
  if (!m) return 0;
  else if (m == n) return m;
  int offset = 0;
  while(m != n)
  {
    m >>= 1;
    n >>= 1;
    ++offset;
  }
  return m << offset;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << rangeBitwiseAnd(a, b) << endl;
}


