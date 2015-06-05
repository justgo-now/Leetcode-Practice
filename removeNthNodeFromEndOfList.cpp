/*************************************************************************
	> File Name: removeNthNodeFromEndOfList.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 May 2015 02:57:36 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;
typedef struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
ListNode *removeNode(ListNode **head, int step)
{
  int count = 0;
  for(ListNode **cur = head; *cur;)
  {
    ListNode *entry = *cur;
    if (count == step)
    {
      *cur = entry->next;
      return *head;
    }
    else
    {
      cur = &entry->next;
    }
    ++count;
  }
}
ListNode *removeNthNodeFromEnd(ListNode *head, int n)
{
  ListNode *fast = head, *slow = head;
  if (fast->next == NULL) return NULL;
  int count = 1;
  while(fast && fast->next && slow)
  {
    ++count;
    fast = fast->next->next;
    slow = slow->next;
  }
  int total = (fast == NULL) ? (2 * count - 2) : (2 * count - 1);
  const int step = total - n;
  cout << "Total length of List is " << total << ". Need walking " << step << " steps." << endl;
 
  return removeNode(&head, step);
}

void printListNode(ListNode *head)
{
  ListNode *cur = head;
  while(cur)
  {
    cout << cur->val << " -> ";
    cur = cur->next;
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
  cout << "Before : ";
  printListNode(&a);
  removeNthNodeFromEnd(&a, 2);
  cout << "After : ";
  printListNode(&a);
  b.next = NULL;
  ListNode *head = &a;
  head = removeNthNodeFromEnd(head, 1);
  cout << "Again : ";
  printListNode(head);
}


