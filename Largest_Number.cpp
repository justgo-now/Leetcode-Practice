/*************************************************************************
	> File Name: Largest_Number.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Mar 2015 12:53:12 PM CST
 ************************************************************************/

#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

bool LargestNumberCompare(int a, int b)
{
  int numCount = 1;
  int tmpb = b / 10;
  while(tmpb)
  {
    ++numCount;
    tmpb = tmpb / 10;
  }
  uint64_t first = (uint64_t)(a * (pow(10, numCount)) + b);

  numCount = 1;
  int tmpa = a / 10;
  while(tmpa)
  {
    ++numCount;
    tmpa = tmpa / 10;
  }
  uint64_t second = (uint64_t)(b * (pow(10, numCount)) + a);

  return (first > second);
}

string getString(const int i)
{
  stringstream ss;
  ss << i;
  return ss.str();
}

bool isAllZero(vector<int> &num)
{
  for(vector<int>::iterator it = num.begin(); it != num.end(); ++it)
  {
    if (*it)
    {
      return false;
    }
  }
  return true;
}

string largestNumber(vector<int> &num)
{
  string s;
  if (isAllZero(num))
  {
    s.append(getString(0));
  }
  else
  {
    sort(num.begin(), num.end(), LargestNumberCompare);
    for(vector<int>::iterator it = num.begin(); it != num.end(); ++it)
    {
      s.append(getString(*it));
    }
  }
  return s;
}

int main()
{
  //int a[] = {3, 30, 34, 5, 9};
  int a[] = {999999998,999999997,999999999};
  vector<int> num(a, a + sizeof(a) / sizeof(int));
  cout << largestNumber(num) << endl;
  return 0;
}


