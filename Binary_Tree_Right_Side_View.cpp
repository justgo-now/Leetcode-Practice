#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode *root)
{
  vector<int> res;
  if (!root)
  {
    return res;
  }
  if (!root->left && !root->right)
  {
    res.push_back(root->val);
    return res;
  }

  TreeNode *cur = NULL;
  queue<TreeNode*> tq;
  tq.push(root);
  while(!tq.empty())
  {
    int size = tq.size();
    for(int i = 0; i < size; ++i)
    {
      cur = tq.front(); 
      tq.pop();
      if (cur->left) tq.push(cur->left);
      if (cur->right) tq.push(cur->right);
    }
    res.push_back(cur->val);
  }

  return res;
}

int main()
{
  TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
  n1.left = &n2;
  n2.right = &n5;
  n1.right = &n3;
  n3.right = &n4;

  vector<int> res = rightSideView(&n1);
  for(vector<int>::iterator it = res.begin(); it != res.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}
  
