/*************************************************************************
	> File Name: reverseNodesInKGroup.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 May 2015 10:33:41 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

typedef struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

int getListLength(ListNode *head)
{
  int count = 0;
  ListNode *cursor = head;
  while(cursor)
  {
    ++count;
    cursor = cursor->next;
  }
  return count;
}

ListNode *addNodes(ListNode *head, stack<ListNode*> &st)
{
  if (head == NULL)
  {
    head = st.top();
    head->next = NULL;
    st.pop();
  }
  ListNode *cursor = head;
  while(cursor->next)
  {
    cursor = cursor->next;
  }
  while(!st.empty())
  {
    cursor->next = st.top();
    cursor->next->next = NULL;
    st.pop();
    cursor = cursor->next;
  }
  return head;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
  ListNode *result = NULL;
  stack<ListNode*> st;
  int length = getListLength(head);
  ListNode *cursor = head;
  int count = 0;

  while(length >= k)
  {
    if (count < k)
    {
      ++count;
      st.push(cursor);
      cursor = cursor->next;
      continue;
    }
    result = addNodes(result, st);
    length -= count;
    count = 0;
  }

  if (cursor)
  {
    if (result == NULL)
    {
      result = cursor;
    }
    else
    {
      ListNode *tail = result;
      while(tail->next)
      {
        tail = tail->next;
      }
      tail->next = cursor;
    }
  }
  
  return result;
}

void printList(ListNode *head)
{
  ListNode *cursor = head;
  while(cursor)
  {
    cout << cursor->val << " -> ";
    cursor = cursor->next;
  }
  cout << "NULL" << endl;
}

int main()
{
  ListNode a(1), b(2), c(3), d(4), e(5);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  //ListNode *res1 = reverseKGroup(&a, 2);
  //printList(res1);
  ListNode *res2 = reverseKGroup(&a, 3);
  printList(res2);
  return 0;
}

