/*************************************************************************
	> File Name: Rotate_Array.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 20 Mar 2015 02:33:35 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
void rotateSingle(int &a, int &b)
{
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
void rotateRegion(int nums[], int start, int end)
{
  while (start < end)
  {
    rotateSingle(nums[start], nums[end]);
    start++;
    end--;
  }
}
void rotate(int nums[], int n, int k)
{
  int step = k % n;
  if (step == 0)
    return;
  rotateRegion(nums, 0, n - step - 1);
  rotateRegion(nums, n - step, n - 1);
  rotateRegion(nums, 0, n - 1);
  /*int *array = new int[k];
  memcpy(array, nums + n - k, k * sizeof(int));
  memmove(nums + k, nums, (n - k) * sizeof(int));
  memcpy(nums, array, k * sizeof(int));
  delete array;*/
}
void printArray(int nums[], int n)
{
  cout << "Array : ";
  for(int i = 0; i < n; ++i)
  {
    cout << nums[i] << " ";
  }
  cout << endl;
}
int main()
{
  int nums[] = {1, 2, 3, 4, 5, 6, 7};
  rotate(nums, 7, 3);
  printArray(nums, 7);
  return 0;
}
