#include <iostream>

using namespace std;

class Node
{
   public:
      int value;
      Node* next;
      Node(int v)
      {
         value = v;
         next = NULL;
      }
};

class LinkList
{
   public:
      Node* head;
      LinkList()
      {
         head = NULL;
      }

      ~LinkList()
      {
         Node* cur = head;
         Node* d = cur;
         while (cur != NULL)
         {
            cur = cur->next;
            delete d;
         }
         cout << "Cleaned" << endl;
      }

      void push(int v)
      {
         Node* temp = new Node(v);
         temp->next = head;
         head = temp;
      }

      void reverseList(Node* end)
      {
         Node* pre, *cur, *nxt;
         pre = NULL;
         cur = head;
         nxt = NULL;
         if (cur == end)
            return;
         
         while (cur != end)
         {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
         }
      }

      void reverseK(Node* head, int k)
      {
         Node* temp = head;
         for (int i = 1; i < k && temp != NULL; i ++)
         {
            temp = temp->next;
         }
         if (temp == NULL)
            return head;

         Node* head2 = temp->next;

      }
};
