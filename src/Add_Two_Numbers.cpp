/*************************************************************************
	> File Name: Add_Two_Numbers.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 Apr 2015 11:25:33 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseListNode(ListNode *list)
{
  ListNode *cur = list;
  ListNode *rev = NULL;
  while(cur)
  {
    if (!rev)
    {
      rev = cur;
      cur = cur->next;
      rev->next = NULL;
    }
    else
    {
      ListNode *tmp = cur;
      cur = cur->next;
      tmp->next = rev;
      rev = tmp;
    }
  }
  return rev;
}

void addResult2ListTail(ListNode *head, int val)
{
  ListNode *newNode = new ListNode(val);
  ListNode *cur = head;
  while(cur->next) cur = cur->next;
  cur->next = newNode;
}
ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
  int carryover = 0;
  bool isFirst = true;
  ListNode *reverseList = NULL;
  ListNode *tp1 = reverseListNode(l1), *tp2 = reverseListNode(l2);
  while(tp1 || tp2)
  {
    int a = tp1 ? tp1->val : 0;
    int b = tp2 ? tp2->val : 0;
    int result = a + b + carryover;
    carryover = result / 10;
    if (isFirst)
    {
      isFirst = false;
      reverseList = new ListNode(result % 10); 
    }
    else
    {
      addResult2ListTail(reverseList, result % 10);
    }

    if (tp1)
      tp1 = tp1->next;
    if (tp2)
      tp2 = tp2->next;
  }
  if (carryover)
  {
    addResult2ListTail(reverseList, carryover);
  }
  return reverseList;
}

int main()
{
  ListNode lf1(1), lf2(8), lf3(3);
  lf1.next = &lf2;
  lf2.next = NULL;
  
  ListNode ls1(0), ls2(6), ls3(4);
  ls1.next = NULL;
  //ls2.next = &ls3;

  /*ListNode *reverse = reverseListNode(&lf1);
  while(reverse)
  {
    cout << reverse->val << " ";
    reverse = reverse->next;
  }
  cout << endl;
  exit(0);*/
  ListNode *listnode = addTwoNumbers(&lf1, &ls1);
  
  cout << listnode->val;
  listnode = listnode->next;
  while(listnode)
  {
    cout << " -> " << listnode->val;
    listnode = listnode->next;
  }
  cout << endl;
  return 0;
}
