/*************************************************************************
	> File Name: getMaxValueIndex.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 20 May 2015 01:55:50 PM CST
 ************************************************************************/

#include <stdlib.h>
#include <iostream>

using namespace std;

int getMaxValueIndex(int *array, int n)
{
  if (n == 1) return 0;
  int index = getMaxValueIndex(array + 1, n - 1);
  return array[0] > array[index + 1] ? 0 : index + 1;
}

int main()
{
  srandom(0);
  int array[10];
  for(int i = 0; i < 10; ++i)
  {
    int val = random() % 10;
    array[i] = val;
    cout << val << " ";
  }
  cout << "=> array" << endl;
  cout << getMaxValueIndex(array, 10) << endl;
  return 0;
}
