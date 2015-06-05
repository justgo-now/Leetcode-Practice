/*************************************************************************
	> File Name: swapNodesInPairs.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 May 2015 10:14:01 AM CST
 ************************************************************************/

#include <iostream>

using namespace std;


typedef struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head)
{
  if (head == NULL || head->next == NULL) return head;
  ListNode *cursor = head;
  
  //swap the first and second node;
  ListNode *tail = cursor->next->next;
  head = cursor->next;
  cursor->next->next = cursor;
  cursor->next = tail;
  cursor = head->next->next;
  ListNode *prev = head->next;
  while(cursor && cursor->next)
  {
    tail = cursor->next->next;
    cursor->next->next = cursor;
    prev->next = cursor->next;
    cursor->next = tail;

    cursor = cursor->next;
    prev = prev->next->next;
  }

  return head;
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
  ListNode a(1), b(2), c(3), d(4);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  ListNode *res = swapPairs(&a);
  printList(res);
  return 0;
}
