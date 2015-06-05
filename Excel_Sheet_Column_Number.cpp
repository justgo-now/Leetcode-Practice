/*************************************************************************
	> File Name: Excel_Sheet_Column_Number.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Apr 2015 03:10:41 PM CST
 ************************************************************************/

#include <math.h>
#include <iostream>
#include <string>
using namespace std;

int CharToInt(char c)
{
  return c - 'A' + 1;
}
int titleToNumber(string s)
{
  int sum = 0;
  int len = s.length();
  for(int i = len - 1; i >= 0; --i)
  {
    sum += CharToInt(s[i]) * pow(26, (len - 1 - i));
  }
  return sum;
}

char IntToChar(int val)
{
  return val + 'A';
}

string convertToTitle(int n)
{
  string s;
  while(n)
  {
    int left = (n - 1) % 26;
    s.insert(s.end(), IntToChar(left));
    n = (n - left) / 26;
  }
  return string(s.rbegin(), s.rend());
}

int main(int argc, char **argv)
{
  cout << titleToNumber(argv[1]) << endl;
  for(int i = 25; i < 29; ++i)
  {
    cout << convertToTitle(i).c_str() << endl;
  }
}


