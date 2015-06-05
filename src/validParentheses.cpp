/*************************************************************************
	> File Name: validParentheses.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 May 2015 03:50:04 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isMatch(char a, char b)
{
  bool flag = false;
  flag = (flag || (a == '(' && b == ')'));
  flag = (flag || (a == '[' && b == ']'));
  flag = (flag || (a == '{' && b == '}'));
  return flag;
}
bool isValid(string s)
{
  stack<char> st;
  int length = s.length();
  for(int i = 0; i < length; ++i)
  {
    if (st.empty())
    {
      st.push(s[i]);
    }
    else
    {
      char c = st.top();
      if (isMatch(c, s[i]))
      {
        st.pop();
      }
      else
      {
        st.push(s[i]);
      }
    }
  }
  return st.empty();
}

int main()
{
  string s;
  while(true)

  {
    cin >> s;
    cout << isValid(s) << endl;
  }
}

