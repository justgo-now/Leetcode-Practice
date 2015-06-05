/*************************************************************************
	> File Name: Numbers_Of_Island.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Apr 2015 04:21:25 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char> > &grid, int x, int y)
{
  if (x < 0 || x >= grid.size()) return;
  if (y < 0 || y >= grid[0].size()) return;
  if (grid[x][y] != '1') return;
  grid[x][y] = ' ';
  dfs(grid, x - 1, y);
  dfs(grid, x + 1, y);
  dfs(grid, x, y - 1);
  dfs(grid, x, y + 1);
}

int numIslands(vector<vector<char> > &grid)
{
  int x = grid.size();
  int y = grid[0].size();
  int count = 0;
  if (x == 0 && y == 0) return 0;
  for( int i = 0; i < x; ++i)
  {
    for( int j = 0; j < y; ++j)
    {
      if(grid[i][j] == '1')
      {
        dfs(grid, i, j);
        ++count;
      }
    }
  }
  return count;
}

int main()
{
  return 0;
}

