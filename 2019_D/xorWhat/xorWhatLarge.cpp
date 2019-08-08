#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXE = 1e5;
int A[MAXE + 5];

int main()
{
   int T, N, Q;
   cin >> T;
   for (int i = 1; i <= T; i ++)
   {
      vector<int> result;
      set<int> pos;
      cin >> N >> Q;
      for (int j = 0; j < N; j ++)
      {
         cin >> A[j];
         if (__builtin_popcount(A[j]) % 2 == 1)
            pos.insert(j);
      }
      int p, v;
      for (int k = 0; k < Q; k ++)
      {
         cin >> p >> v;
         int popcountV, popcountA;
         popcountV = __builtin_popcount(v);
         popcountA = __builtin_popcount(A[p]);
         if (popcountV % 2 == 1 && popcountA % 2 == 0)
            pos.insert(p);
         if (popcountV % 2 == 0 && popcountA % 2 == 1)
            pos.erase(p);
         A[p] = v;
         int ans = 0;
         if (pos.size() % 2 == 0)
            ans = N;
         else
            ans = max(N - 1 - *pos.begin(), *pos.rbegin());
         result.push_back(ans);
      }
      cout << "Case #" << i << ": ";
      for (int j = 0; j < result.size(); j ++)
         cout << result[j] << " ";
      cout << endl;
   }
}
