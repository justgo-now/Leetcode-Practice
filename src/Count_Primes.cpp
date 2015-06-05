/*************************************************************************
	> File Name: Count_Primes.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Apr 2015 10:45:12 AM CST
 ************************************************************************/

#include <math.h>
#include<iostream>
using namespace std;

int countPrimes(int n)
{
  if (n < 2) return 0;
  else if (n < 3) return 1;
  else if (n < 4) return 2;
  int count = 2;
  for( int i = 5; i < n; i += 2)
  {
    int j = 2;
    for(; j < sqrt(i); ++j)
    {
      if (i % j == 0)
      {
        break;
      }
    }
    if (i % j != 0)
    {
      ++count;
    }
  }
  return count;
}

int countPrimes2(int n)
{
  bool* flag = new bool[n + 1];
 
  memset(flag, 0, sizeof(flag[0]) * n);
  flag[2] = false;
  for(int i = 2; i < n; ++i)
  {
    if (!flag[i])
    {
      if (i * i > n) break;
      for(int j = 2; j * i < n; ++j)
      {
        flag[i * j] = true;
      }
    }
  }
 
  int count = 0;
  for(int i = 2; i < n; ++i)
  {
    if(!flag[i])
      ++count;
  }
  delete[] flag;
  return count;
}

int main()
{
  int num = 0;

  while(true)
  {
    cout << "Input : ";
    cin >> num;
    cout << "Prime num is " << countPrimes2(num) << endl;
  }
}



