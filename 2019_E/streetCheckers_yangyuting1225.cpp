#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long int LL;
 
LL pri[5] = {2, 3, 5, 61, 233};

inline LL qwr(LL a, LL n, LL mod)
{
    LL res = 1;
    while (n){
        if (n & 1) res =  res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

inline bool MR(LL p) 
{
   if(p < 2) return 0;
   if(p != 2 && !(p & 1)) return 0;
   LL s = p - 1, t, m;
   while( ! (s & 1)) s >>= 1;
   for(int i = 0; i < 5; ++i) {
      if(p == pri[i]) return 1;
      t = s, m = qwr(pri[i], s, p);
      while(t != p - 1 && m != 1 && m != p - 1) {
         m = m * m % p;
         t <<= 1;
      }
      if(m != p - 1 && !(t & 1)) return 0;
   }
    return 1;
}

int main() 
{
   LL x;
   int n, m, ans;
   int T; scanf("%d", &T);
   for(int cas = 1; cas <= T; ++cas) {
      scanf("%d %d", &n, &m);
      ans = 0;
      for(int i = n; i <= m; ++i) {
         if(i & 1) {
            x = i;
            if(x == 1 || MR(x)) ans++;
         }
         else {
            x = i; x /= 2;
            if(x & 1) ans++;
            else {
               x /= 2;
               if(x & 1) {
                  if(x == 1 || MR(x)) ans++;
               }
               else {
                  x /= 2;
                  if(x == 1) ans++;
               }
            }
         }
      }
      printf("Case #%d: %d\n", cas, ans);
   }
    return 0;
}
