/*************************************************************************
	> File Name: mergeTwoSortedLists.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 May 2015 04:07:16 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

typedef struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertNode(ListNode *head, ListNode *l1, ListNode *l2, bool flag)
{
  ListNode *cur = head;
  cur->next = NULL;
  while(l1 && l2)
  {
    if (flag)
    {
      if (l1->val > l2->val)
      {
        ListNode *tmp = l2;
        l2 = l2->next;
        tmp->next = NULL;
        cur->next = tmp;
        cur = cur->next;
      }
      else
      {
        ListNode *tmp = l1;
        l1 = l1->next;
        tmp->next = NULL;
        cur->next = tmp;
        cur = cur->next;
      }
    }
    else
    {
      if (l1->val < l2->val)
      {
        ListNode *tmp = l2;
        l2 = l2->next;
        tmp->next = NULL;
        cur->next = tmp;
        cur = cur->next;
      }
      else
      {
        ListNode *tmp = l1;
        l1 = l1->next;
        tmp->next = NULL;
        cur->next = tmp;
        cur = cur->next;
      }
    }
  }
  if (l1) cur->next = l1;
  if (l2) cur->next = l2;
  return head;
}

bool isIncrease(ListNode *list)
{
  if(list->next && ((list->next->val - list->val) < 0))
  {
    return false;
  }
  return true;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
  if (l1 == NULL) return l2;
  if (l2 == NULL) return l1;
  if (l1->next == NULL && l2->next == NULL)
  {
    l1->next = l2;
    return l1;
  }

  ListNode *cursor1 = l1, *cursor2 = l2;
  ListNode *newlist = NULL;
  bool flag = true;
  l1->next ? flag = isIncrease(l1) : flag = isIncrease(l2);
  if (flag)
  {
    if (cursor1->val > cursor2->val)
    {
      newlist = cursor2;
      cursor2 = cursor2->next;
    }
    else
    {
      newlist = cursor1;
      cursor1 = cursor1->next;
    }
    newlist = insertNode(newlist, cursor1, cursor2, flag); 
  }
  else
  {
    if (cursor1->val < cursor2->val)
    {
      newlist = cursor2;
      cursor2 = cursor2->next;
    }
    else
    {
      newlist = cursor1;
      cursor1 = cursor1->next;
    }
    newlist = insertNode(newlist, cursor1, cursor2, flag); 
  }
  return newlist;
}
void printNode(ListNode *head)
{
  while(head)
  {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}
int main()
{
  ListNode a(1), b (2), c(3), d(4), e(5), f(6);
  a.next = &c;
  c.next = &f;
  b.next = &d;
  d.next = &e;
  ListNode *l1 = &a, *l2 = &b;
  ListNode *newlist = mergeTwoLists(l1, l2);
  printNode(newlist);
  return 0;
}
