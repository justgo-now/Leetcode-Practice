/*************************************************************************
	> File Name: hammingWeight.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 20 Mar 2015 02:15:37 PM CST
 ************************************************************************/

#include<iostream>
#include <stdlib.h>
using namespace std;
int hammingWeight(uint32_t n)
{
  int count = 0;
  while(n)
  {
    if(n & 0x1)
    {
      ++count;
    }
    n = n >> 1;
  }
  return count;
}
int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Args error!\n");
    exit(0);
  }
  int val = atoi(argv[1]);
  cout << "Count = " << hammingWeight(val) << endl;
  return 0;
}
