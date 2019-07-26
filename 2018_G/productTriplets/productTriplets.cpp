#include <iostream>
#include <map>
#include <algorithm>
#include <memory.h>

using namespace std;

#define LL long long

map<LL, LL> triplets;
LL a[7005];
LL ans;

LL C3(LL n)
{
   LL a = n * (n - 1) * (n - 2) * 1ll;
   LL b = 3 * 2 * 1ll;
   return a / b;
}

LL C2(LL n)
{
   LL a = n * (n - 1) * 1ll;
   LL b = 2 * 1ll;
   return a / b;
}

void productSum(int N)
{
   sort(a, a + N);
   LL z = 0;
   for (int i = 0; i < N; i ++)
   {
      if (a[i] == 0)
         z ++;
      else
         break;
   }
   if (z >= 2ll)
      ans += C2(z) * (N - z);
   if (z >= 3ll)
      ans += C3(z);

   for (int y = N - 1; y >= z + 1; y --)
   {
      for (int x = y - 1; x >= z; x --)
      {
          map<LL, LL>::iterator it = triplets.find(a[x] * a[y] * 1ll);
          if (it != triplets.end())
            ans += it->second * 1ll;
      }
      triplets[a[y]] ++;
   }
}

int main()
{
   int T, N;
   cin >> T;
   for (int i = 1; i <= T; i ++)
   {
      cin >> N;
      memset(a, 0, sizeof(a));
      ans = 0ll;
      for (int j = 0; j < N; j ++)
         cin >> a[j];
      triplets.clear();
      productSum(N);
      cout << "Case #" << i << ": " << ans << endl;
   }

   return 0;
}
