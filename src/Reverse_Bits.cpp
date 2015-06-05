/*************************************************************************
	> File Name: Reverse_Bits.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 20 Mar 2015 02:25:05 PM CST
 ************************************************************************/

#include<iostream>
#include<bitset>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
  int count = 0;
  bitset<32> bs;
  while(n)
  {
    if (n & 0x1)
    {
      bs.set(31 - count);
    }
    n = n >> 1;
    ++count;
  }
  return bs.to_ulong();
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cout << "Args error!" << endl;
    exit(0);
  }
  int val = atoi(argv[1]);
  cout << "Reserse result = " << reverseBits(val) << endl;
  return 0;
}
