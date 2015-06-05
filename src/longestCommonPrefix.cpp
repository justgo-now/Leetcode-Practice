/*************************************************************************
	> File Name: longestCommonPrefix.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 14 May 2015 04:08:57 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
  if (strs.empty() || strs[0].empty()) return "";
  string prefix = strs[0];
  for(int i = 1; i < strs.size(); ++i)
  {
    int j = 0;
    while (j < prefix.length() && j < strs[i].length() && strs[i][j] == prefix[j]) ++j;
    if (j == 0) return "";
    prefix = prefix.substr(0, j);
  }
  return prefix;
}

int main()
{
  string s1, s2;
  while(true)
  {
    cin >> s1;
    cin >> s2;
    vector<string> vec;
    vec.push_back(s1);
    vec.push_back(s2);
    cout << "Prefix : " << longestCommonPrefix(vec) << endl;
  }
  return 0;
}
