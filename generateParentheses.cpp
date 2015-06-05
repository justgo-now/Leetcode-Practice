/*************************************************************************
	> File Name: generateParentheses.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 May 2015 04:51:12 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate(int n, int left, int right, string s, vector<string> &vec)
{
  if (left < right) return;
  if(left ==n && right == n)
  {
    vec.push_back(s);
    return;
  }
  if (left == n)
  {
    generate(n, left, right + 1, s + ")", vec);
    return;
  }
  generate(n, left + 1, right, s + "(", vec);
  generate(n, left, right + 1, s + ")", vec);
}

vector<string> generateParenthesis(int n) 
{
  vector<string> vec;
  generate(n, 0, 0, "", vec);
  return vec;
}
void printVec(const vector<string> &vec)
{
  for(vector<string>::const_iterator it = vec.begin(); it != vec.end(); ++it)
  {
    cout << (*it).c_str() << endl;
  }
}
int main()
{
  int n;
  while(true)
  {
    cin >> n;
    vector<string> vec = generateParenthesis(n);
    printVec(vec);
  }
  return 0;
}


