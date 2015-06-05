/*************************************************************************
	> File Name: BST_Iterator.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Apr 2015 01:34:36 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

typedef struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(NULL), right(NULL) {}
};

class BSTIterator {
public:

  BSTIterator(TreeNode *root) {
    pushNode2Stack(root); 
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
      return !s.empty();
  }

  /** @return the next smallest number */
  int next() {
    TreeNode *top = s.top();
    s.pop();
    pushNode2Stack(top->right);
    return top->val;
  }

private:
  void pushNode2Stack(TreeNode *node)
  {
    TreeNode *cur = node;
    while(NULL != cur)
    {
      s.push(cur);
      cur = cur->left;
    }
  }

  stack<TreeNode*> s;
};

int main()
{
  TreeNode node[7];
  node[0].val = 5;
  node[1].val = 3;
  node[2].val = 7;
  node[3].val = 1;
  node[4].val = 4;
  node[5].val = 6;
  node[6].val = 8;

  node[0].left = &node[1];
  node[0].right = &node[2];
  node[1].left = &node[3];
  node[1].right = &node[4];
  node[2].left = &node[5];
  node[2].right = &node[6];
  
  BSTIterator iter(&node[0]);

  while(iter.hasNext())
  {
    cout << iter.next();
  }
}


