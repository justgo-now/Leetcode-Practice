/*************************************************************************
	> File Name: longestValidParentheses.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 20 May 2015 10:56:34 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
#define MAX(a, b) a > b ? a : b
int longestValidParentheses(string s)
{
  stack<pair<int, int> > st;
  int length = s.length();
  int max = 0, curLen = 0;
  for (int i = 0; i < length; ++i)
  {
    if (s[i] == 0x28)
    {
      st.push(make_pair(i, 0));
    }
    else
    {
      if (st.empty() || st.top().second == 1)
      {
        st.push(make_pair(i, 1));
      }
      else
      {
        st.pop();
        curLen = st.empty() ? i + 1 : i - st.top().first;
        max = MAX(max, curLen);
      }

    }
  }
  return max;
}

int longestValidParenthesesDP(string s) {
  int n = s.size(), maxLen = 0;
  vector<int> dp(n+1,0);
  for(int i=1; i<=n; i++) {
      int j = i-2-dp[i-1];
      if(s[i-1]=='(' || j<0 || s[j]==')') 
          dp[i] = 0;
      else {
          dp[i] = dp[i-1]+2+dp[j];
          maxLen = max(maxLen, dp[i]);
      }
  }
  return maxLen;
}

int main()
{
  string s;
  while(true)
  {
    cin >> s;
    cout << longestValidParenthesesDP(s) << endl;
  }
  return 0;
}

