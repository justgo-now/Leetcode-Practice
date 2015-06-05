/*************************************************************************
	> File Name: courseSchedule.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 27 May 2015 10:24:35 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites)

void printVector(vector<int> &nums)
{
  for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
  {
    cout << *it;
  }
  cout << endl;
}

int main()
{
  vector<pair<int, int> > prerequisites;
  prerequisites.push_back(make_pair(1, 0));
  prerequisites.push_back(make_pair(2, 0));
  prerequisites.push_back(make_pair(3, 1));
  prerequisites.push_back(make_pair(3, 2));

  vector<int> res = findOrder(4, prerequisites);
  printVector(res);

  return 0;
}
