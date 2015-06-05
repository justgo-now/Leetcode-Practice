/*************************************************************************
	> File Name: medianSortedArrays.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Apr 2015 03:07:46 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2)
{
  int len1 = nums1.size();
  int len2 = nums2.size();
  if ( len1 == 0 && len2 == 0 ) return 0.0;
  if ( len1 == 0 ) return len2%2==1 ? nums2[len2/2] : (nums2[len2/2-1] + nums2[len2/2])/2.0;
  if ( len2 == 0 ) return len1%2==1 ? nums1[len1/2] : (nums1[len1/2-1] + nums1[len1/2])/2.0;
  vector<int> v(len1 + len2);
  merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());

  if ((len1 + len2) & 0x1)
  {
    return v[(len1 + len2) / 2 + 1];
  }
  return ((v[(len1 + len2) / 2 - 1] + v[(len1 + len2) / 2] ) / 2.0);
}

int main()
{
  //int a[] = {1};
  //int b[] = {2, 3};
  int a[] = {1, 3, 5, 7, 9};
  int b[] = {2, 4, 6, 8, 10};
  int len1 = sizeof(a) / sizeof(int);
  int len2 = sizeof(b) / sizeof(int);
  vector<int> va(a, a + len1);
  vector<int> vb(b, b + len2);
  cout << "Median : " << findMedianSortedArrays(va, vb) << endl;
  return 0;
}

