/*************************************************************************
	> File Name: Dungeon_Game.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Apr 2015 10:08:26 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
  return (a > b ? a : b);
}

int min(int a, int b)
{
  return (a < b ? a : b);
}

int calculateMinimumHP(vector<vector<int> > &dungeon) 
{
  if(dungeon.empty() && dungeon[0].empty()) return 1;
  int x = dungeon.size();
  int y = dungeon[0].size();

  dungeon[x - 1][y - 1] = max(0, 0 - dungeon[x - 1][y - 1]);

  for(int i = x - 2; i >= 0; --i)
  {
    dungeon[i][y - 1] = max(0, dungeon[i + 1][y - 1] - dungeon[i][y - 1]);
  }
  for(int i = y - 2; i >= 0; --i)
  {
    dungeon[x - 1][i] = max(0, dungeon[x - 1][i + 1] - dungeon[x - 1][i]);
  }

  for (int i = x - 2; i >= 0; --i)
  {
    for (int j = y - 2; j >=0; --j)
    {
      dungeon[i][j] = max(min(dungeon[i + 1][j], dungeon[i][j + 1]) - dungeon[i][j], 0);
    }
  }

  return dungeon[0][0] + 1;
}

int main()
{
  vector<int> sub[3];
  sub[0].push_back(-2);
  sub[0].push_back(-3);
  sub[0].push_back(3);
  sub[1].push_back(-5);
  sub[1].push_back(-10);
  sub[1].push_back(1);
  sub[2].push_back(10);
  sub[2].push_back(30);
  sub[2].push_back(-5);

  vector<vector<int> > mainFrame;
  for(int i = 0; i < 3; ++i)
  {
    mainFrame.push_back(sub[i]);
  }

  cout << calculateMinimumHP(mainFrame) << endl;
}


