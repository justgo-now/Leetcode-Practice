/*************************************************************************
	> File Name: Compare_Version_Numbers.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 Apr 2015 03:50:18 PM CST
 ************************************************************************/

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int getVersionNum(string &str)
{
  int ret = 0;
  size_t index = str.find(".");
  if (index != string::npos)
  {
    ret = atoi(str.substr(0, index).c_str());
    str = str.substr(index + 1);
    return ret;
  }
  ret = atoi(str.c_str());
  str.clear();
  return ret;
}

int compareVersion(string version1, string version2)
{
  while(!version1.empty() || !version2.empty())
  {
    int first = getVersionNum(version1);
    int second = getVersionNum(version2);
    if (first > second)
    {
      return 1;
    }
    else if (first < second)
    {
      return -1;
    }
  }
  return 0;
}

int main(int argc, char **argv)
{
  cout << compareVersion(argv[1], argv[2]) << endl;
}

