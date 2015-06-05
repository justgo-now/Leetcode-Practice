/*************************************************************************
	> File Name: Isomorphic_Strings.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Apr 2015 10:28:02 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <map>
using namespace std;


bool isIsomorphic(string s, string t)
{
  int sizeOfS = s.length();
  int sizeOfT = t.length();
  if (sizeOfS != sizeOfT) return false;
  
  map<char, int> mapS;
  map<char, int> mapT;
  for(int i = 0; i < sizeOfS; ++i)
  {
    map<char, int>::iterator iterS = mapS.find(s[i]), iterT = mapT.find(t[i]);
    if (iterS == mapS.end() && iterT == mapT.end())
    {
      mapS.insert(make_pair(s[i], i));
      mapT.insert(make_pair(t[i], i));
    }
    else
    {
      if (!(iterS != mapS.end() && iterT != mapT.end() && iterS->second == iterT->second))
      {
        return false;
      }
    }
  }
  return true;
}


int main(int argc, char **argv)
{
  cout << isIsomorphic(argv[1], argv[2]) << endl;
}


