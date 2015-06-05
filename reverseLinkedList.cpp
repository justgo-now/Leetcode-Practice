/*************************************************************************
	> File Name: reverseLinkedList.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 26 May 2015 10:56:58 AM CST
 ************************************************************************/

#include <iostream>

using namespace std;

typedef struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* pushHead(ListNode *head, ListNode *node)
{
  if (head)
  {
    node->next = head;
    head = node;
  }

  else
  {
    head = node;
    head->next = NULL;
  }
  return head;
}

ListNode* reverseList(ListNode* head)
{
  if (head == NULL) return NULL;
  if (head->next == NULL) return head;

  ListNode *newHead = NULL;
  while(head)
  {
    ListNode *tmp = head;
    head = head->next;

    newHead = pushHead(newHead, tmp);
  }
  return newHead;
}

void printListNode(ListNode *head)
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
  ListNode a(1), b(2), c(3), d(4);
  a.next = &b;
  b.next = &c;
  c.next = &d;

  ListNode *head = reverseList(&a);
  printListNode(head);
  return 0;
}
