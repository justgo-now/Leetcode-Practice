/*************************************************************************
	> File Name: Happy_Number.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Apr 2015 02:57:54 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int getSize(int n)
{
  int size = 0;
  while(n)
  {
    ++size;
    n /= 10;
  }

  return size;
}
int getUnit(int n)
{
  return (n % 10);
}
void devideNumber(vector<int> &vec, int n)
{
  vec.clear();
  while(n)
  {
    vec.push_back(getUnit(n));
    n /= 10;
  }
}
int calc(vector<int> vec, int size)
{
  int sum = vec[0] * vec[0];
  for(int i = 1; i < size; ++i)
  {
    sum += vec[i] * vec[i];
  }
  return sum;
}
bool isHappy(int n)
{
  vector<int> vec;
  vec.reserve(8);
  int size = getSize(n);
  int tmp = n;
  int timeout = 0;
  while(tmp != 1 && timeout < 50)
  {
    devideNumber(vec, tmp);
    tmp = calc(vec, size);
    size = getSize(tmp);
  }
  if (tmp == 1) return true;
  return false;

}

int main()
{
  while(true)
  {
    int n;
    cin>>n;
    cout << "Is " << n << "Happy ?" << (isHappy(n) ? "yes" : "no") << endl;
  }
}
