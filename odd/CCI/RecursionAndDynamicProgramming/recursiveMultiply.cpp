#include <iostream>
#include <vector>

using namespace std;

// recursive
int recursiveMultiply(int a, int b)
{
   if (a == 0)
      return 0;
   else if (a == 1)
      return b;

   int left = a / 2;
   int right = a - left;
   return recursiveMultiply(left, b) + recursiveMultiply(right, b);
}

int multiply(int a, int b)
{
   if (a <= b)
      return recursiveMultiply(a, b);
   else
      return recursiveMultiply(b, a);
}
// recursive end


// memorize
int memoRecursiveMultiply(int a, int b, vector<int>& memo)
{
   if (a == 0)
      memo[0] = 0;
   else if (a == 1)
      memo[1] = b;

   if (memo[a] == -1)
   {
      int left = a / 2;
      int right = a - left;
      memo[a] = memoRecursiveMultiply(left, b, memo) + memoRecursiveMultiply(right, b, memo);
   }
   return memo[a];
}

int memoMultiply(int a, int b)
{
   vector<int> memo;
   if (a <= b)
   {
      memo.assign(a + 1, -1);
      memoRecursiveMultiply(a, b, memo);
   }
   else
   {
      memo.assign(b + 1, -1);
      memoRecursiveMultiply(b, a, memo);
   }
   return memo[a];
}

// memorize end

int main()
{
  // cout << multiply(50, 100) << endl;
  // cout << multiply(49, 51) << endl;

   cout << memoMultiply(50, 100) << endl;
   cout << memoMultiply(0, 50) << endl;
   cout << memoMultiply(49, 51) << endl;
}
