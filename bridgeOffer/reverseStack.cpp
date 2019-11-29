#include <iostream>
#include <stack>

using namespace std;

template<class T> void addToBottom(stack<T>& s, T elem)
{
   if (s.empty())
      s.push(elem);
   else
   {
      T top = s.top();
      s.pop();
      addToBottom(s, elem);
      s.push(top);
   }
}

template<class T> void reverseStack(stack<T>& s)
{
   if (!s.empty())
   {
      T top = s.top();
      s.pop();
      reverseStack(s);
      addToBottom(s, top);
   }
}

int main()
{
   stack<int> s;
   for (int i = 1; i <= 5; i ++)
      s.push(i);
   reverseStack(s);
   while (!s.empty())
   {
      int top = s.top();
      s.pop();
      cout << top << " ";
   }
   cout << endl;
   return 0;
}
