/*************************************************************************
	> File Name: palindromePartitioning.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Jun 2015 01:44:30 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
    bool isPalindrome(const string &s, int start, int end); 
    void partitionHelper(const string &s, int start, 
        vector<string> pars, vector<vector<string> > &result);
vector<vector<string> > partition(string s) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > result;
        vector<string> pars;
        
        partitionHelper(s, 0, pars, result);
        return result;
    }
    
    void partitionHelper(const string &s, int start, 
        vector<string> pars, vector<vector<string> > &result)
    {
        int slength = s.length();
        cout << "partitionHelper : " << s.c_str() << endl;
        if (start == slength)
        {
            cout << "insert to result : " << pars.size() << endl;
            result.push_back(pars);
        }
        for (int i = start; i < slength; ++i) {
            if (isPalindrome(s, start, i)) {
                string tmp = s.substr(start, i - start + 1);
                cout << "Start = " << start << " i = " << i << endl;
                cout << "isPalindrome push_back : " << tmp.c_str() << " left s : " << s.c_str() << endl;
                pars.push_back(tmp);
                partitionHelper(s, i + 1, pars, result);
                cout << "pars pop_back" << endl;
                pars.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string &s, int start, int end) 
    {
        if (start == end)
            return true;
            
        while (start < end) {
            if (s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        
        return true;
    }

int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) 
          cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
int main()
{
  string s;
  while(true)
  {
    cin >> s;
    partition(s);
    cout << "min cuts : " << minCut(s) << endl;
  }
}
