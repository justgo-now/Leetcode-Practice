/*************************************************************************
	> File Name: implementStrstr.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 May 2015 02:55:03 PM CST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle)
{
  size_t found = haystack.find(needle);
  if (found == string::npos) return -1;
  return found;
}

int main()
{
  string haystack, needle;
  while(true)
  {
    cin >> haystack;
    cin >> needle;
    cout << strStr(haystack, needle) << endl;
  }
}
