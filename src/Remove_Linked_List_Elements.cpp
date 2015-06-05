/*************************************************************************
	> File Name: Remove_Linked_List_Elements.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Apr 2015 02:27:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


typedef bool (*remove_func)(int val, ListNode *node);
bool remove_if(int val, ListNode *node)
{
  return (val == node->val);
}

ListNode* remove_node(ListNode **head, remove_func fn, int val)
{
  for(ListNode **cur = head; *cur;)
  {
    ListNode *entry = *cur;
    if(fn(val, *cur))
    {
      *cur = entry->next;
    }
    else
    {
      cur = &entry->next;
    }
  }
}
ListNode* removeElements(ListNode *head, int val)
{
  remove_func fn = remove_if;
  ListNode *cur = head;
  remove_node(&cur, fn, val);
  return cur;
}

int main()
{
  return 0;
}
