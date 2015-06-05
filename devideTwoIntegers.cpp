/*************************************************************************
	> File Name: devideTwoIntegers.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 May 2015 03:11:05 PM CST
 ************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

int divide(int dividend, int divisor)
{
  long int divid = abs((long int)dividend);
  long int divis = abs((long int)divisor);
  
  int ret = 0;
  while(divid >= divis)
  {
    int count = 0;
    while(divid >= (divis << (count))) ++count;
    ret += 1 << (count - 1);
    divid -= divis << (count - 1);
  }
  if ((dividend > 0 && divisor > 0)
      || (dividend < 0 && divisor < 0))
  {
    return ret;
  }
  return ret * -1;
}

int main()
{
  cout << INT_MAX << endl;
  return 0;
}
