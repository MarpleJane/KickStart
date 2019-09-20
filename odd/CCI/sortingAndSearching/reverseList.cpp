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
      Node()
      {
         next = NULL;
      }
};

class LinkedList
{
   public:
      Node* head;
      LinkedList()
      {
         head = NULL;
      }

      void reverseList()
      {
         Node *pre, *cur, *nxt;
         cur = head;
         pre = NULL;
         nxt = cur->next;
         if (cur == NULL)
            return;

         cout << "reverse" << endl;
         while (cur != NULL)
         {
            nxt = cur->next;
            cout << cur->value << endl;
            cur->next = pre;
            cout << "pre: " << (pre ? pre->value : 0) << endl;
            pre = cur;
            cur = nxt;
            cout << "bk1" << endl;
         }
         cout << "bk2" << endl;
         head = pre;
      }

      void push(int v)
      {
         Node* temp = new Node(v);
         temp->next = head;
         head = temp;
      }

      ~LinkedList()
      {
         cout << "Cleaned" << endl;
         Node* cur = head;
         Node* d = cur;
         while (cur != NULL)
         {
            cur = cur->next;
            delete d;
            d = cur;
         }

      }
};

int main()
{
   LinkedList l;
   for (int i = 5; i >= 1; i --)
   {
      l.push(i);
   }

   Node* cur = l.head;
   while (cur != NULL)
   {
      cout << cur->value << "->";
      cur = cur->next;
   }

   l.reverseList();
   cur = l.head;
   while (cur != NULL)
   {
      cout << cur->value << "->";
      cur = cur->next;
   }
   cout << endl;
}
