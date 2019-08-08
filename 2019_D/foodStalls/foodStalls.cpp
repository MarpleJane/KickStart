#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   int T, K, N;
   cin >> T;
   for (int t = 1; t <= T; t ++)
   {
      cin >> K >> N;
      vector<long long> x(N), c(N);
      for (int i = 0; i < N; i ++) cin >> x[i];
      for (int i = 0; i < N; i ++) cin >> c[i];
      long long ans = 1000000000ll * 1000000000ll; // This big number is needed!
      for (int i = 0; i < N; i ++)
      {
         vector<long long> costResults;
         long long curCost = c[i];
         for (int j = 0; j < N; j ++)
         {
            if (i == j)
               continue;
            costResults.push_back(c[j] + abs(x[i] - x[j]));
         }
         sort(costResults.begin(), costResults.end());
         for (int k = 0; k < K; k ++)
            curCost += costResults[k];
         ans = min(ans, curCost);
      }
      cout << "Case #" << t << ": " << ans << endl;
   }
   return 0;
}
