#include <iostream>
#include <vector>

using namespace std;

#define ll long long

// Iteratively, O(3^n)
int TripleStep(int n)
{
   if (n == 0 || n == 1)
      return 1;
   if (n == 2)
      return TripleStep(1) + TripleStep(0);
   return TripleStep(n - 1) + TripleStep(n - 2) + TripleStep(n - 3);
}

// Memoization
int TripleStepMemo(int n, vector<ll>& memo)
{
   if (n == 0 || n == 1)
      memo[n] = 1LL;
   if (n == 2)
      memo[n] = 2LL;
   if (memo[n] == 0LL)
      memo[n] = TripleStepMemo(n - 1, memo) * 1LL + TripleStepMemo(n - 2, memo) * 1LL + TripleStepMemo(n - 3, memo) * 1LL;
   return memo[n];
}

int TripleStepMemo(int n)
{
   vector<ll> memo(n + 1, 0LL);
   return TripleStepMemo(n, memo);
}
// End Memoization

int main()
{
   cout << TripleStepMemo(38) << endl;
}
