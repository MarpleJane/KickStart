#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
   int T, N, K, result, day, cur;
   int A[5000];
   cin >> T;
   for (int t = 1; t <= T; t ++)
   {
      result = 0;
      cin >> N >> K;
      for (int i = 1; i <= N; i ++)
         cin >> A[i];
      sort(A + 1, A + N + 1);

      day = 1, cur = 0;
      for (int i = 1; i <= N; i ++)
      {
         if (A[i] >= day)
         {
            result ++;
            cur ++;
            if (cur == K)
            {
               cur = 0;
               day ++;
            }
         }
      }
      cout << "Case #" << t << ": " << result << endl;
   }
}
