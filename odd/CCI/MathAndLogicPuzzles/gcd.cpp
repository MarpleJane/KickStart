#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
   int temp = a;
   a = b;
   b = temp;
}

int gcd(int a, int b)
{
   if (a < b)
      swap(a, b);
   int c = 0;
   while (b)
   {
      c = a % b;
      a = b;
      b = c;
   }
   return a;
}

int main()
{
   cout << gcd(27, 15) << endl;
}
