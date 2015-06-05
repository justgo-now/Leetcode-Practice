/*************************************************************************
	> File Name: Repeated_DNA_Sequences.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 20 Mar 2015 03:46:01 PM CST
 ************************************************************************/

#include <math.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
//void test(string s)
/*
 * Time Limit Exceeded
 *
vector<string> findRepeatedDnaSequences(string s) 
{
  vector<string> vect;
  int startIndex = 0;
  int strLen = s.length();
  while(startIndex < (strLen - 10))
  {
    string sample = s.substr(startIndex, 10);
    string leftStr = s.substr(startIndex + 10, strLen - startIndex - 10 - 1);
    size_t found = leftStr.find(sample);
    if (found != string::npos)
    {
      vect.push_back(sample);
    }
    ++startIndex;
  }
  return vect;
} */
int DNAEncode(char c)
{
  switch(c)
  {
    case 'A':
      return 0;
    case 'C':
      return 1;
    case 'G':
      return 2;
    case 'T':
      return 3;
  }
  return 0;
}
char DNADecode(int val)
{
  switch(val)
  {
    case 0:
      return 'A';
    case 1:
      return 'C';
    case 2:
      return 'G';
    case 3:
      return 'T';
  }
  return 0;
}
vector<string> findRepeatedDnaSequences(string s) 
{
  map<int, int> m;
  vector<string> vect;
  vect.clear();

  int strLen = s.length();
  if(strLen < 10)
  {
    return vect;
  }

  int sum = 0;
  int i = 0;
  for (; i < 10; ++i)
  {
    sum = (sum << 2) + DNAEncode(s[i]); 
  }
  ++m[sum];

  const uint32_t maxGuard = (uint32_t)pow(4, 10) - 1;
  for(i = 1; i + 10 <= strLen; ++i)
  {
    sum = ((sum << 2) & maxGuard) + DNAEncode(s[i + 9]);
    ++m[sum];
  }

  string tempStr;
  tempStr.resize(10);

  map<int, int>::iterator iter;
  for(iter = m.begin(); iter != m.end(); ++iter)
  {
    if (iter->second < 2)
    {
      continue;
    }
    sum = iter->first;
    for(i = 9; i >= 0; --i)
    {
      tempStr[9 - i] = DNADecode(sum >> 2 * i);
      sum &= ((1 << 2 * i) - 1);
    }
    vect.push_back(tempStr);
  }

  m.clear();
  return vect;

}


int main()
{
  string s("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
  vector<string> vect = findRepeatedDnaSequences(s);
  for(vector<string>::iterator iter = vect.begin(); iter != vect.end(); ++iter)
  {
    cout << *iter << ";" << endl;
  }
  return 0;
}

