/*************************************************************************
	> File Name: Longest_Substring_Without_Repeat_Characters.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 Apr 2015 03:17:58 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int getCharacterRelativePosition(char c)
{
  return (c - 'a');
}

int lengthOfLongestSubstring(string s)
{
  int strLen = s.length();
  int max = 0;
  int startIndex = -1;
  char position[28];
  memset(position, -1, sizeof(position));

  for (int i = 0; i < strLen; ++i)
  {
    if (position[getCharacterRelativePosition(s[i])] > startIndex)
      startIndex = position[getCharacterRelativePosition(s[i])];
    if (i - startIndex > max)
      max = i - startIndex;
    position[getCharacterRelativePosition(s[i])] = i;
  }

  return max;
}

int main()
{
  string s("abcabcbb");
  cout << lengthOfLongestSubstring(s) << endl;
  return 0;
}

