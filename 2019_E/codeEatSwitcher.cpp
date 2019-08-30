#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

const int MAXE = 1e5 + 5;

struct Node
{
   int c;
   int e;
};


bool cmp(Node x, Node y)
{
   return x.c * y.e < y.c * x.e;
}

int main()
{
   int T, D, S, A, B, l, r;
   cin >> T;
   for (int t = 1; t <= T; t ++)
   {
      cout << "Case #" << t << ": ";
      cin >> D >> S;
      ll prefix[MAXE], sufix[MAXE];
      Node nodes[MAXE];
      for (int s = 1; s <= S; s ++)
      {
         cin >> nodes[s].c >> nodes[s].e;
      }

      sort(nodes + 1, nodes + 1 + S, cmp);
      prefix[0] = 0LL; sufix[S + 1] = 0LL;
      for (int s = 1; s <= S; s ++)
         prefix[s] = prefix[s - 1] + nodes[s].e * 1LL;
      for (int s = S; s > 0; s --)
         sufix[s] = sufix[s + 1] + nodes[s].c * 1LL;
      
      for (int d = 0; d < D; d ++)
      {
         cin >> A >> B;
         l = 1, r = S;
         int ans = -1, mid;
         bool ok = false;
         while (l <= r)
         {
            mid = (l + r) / 2;
            if (B <= prefix[mid])
            {
               ans = mid;
               r = mid - 1;
            }
            else
               l = mid + 1;
         }

         if (ans == -1) ok = false;
         else
         {
            ll allE = prefix[ans - 1], allC = sufix[ans + 1];
            ll delta = nodes[ans].c * 1LL * nodes[ans].e - nodes[ans].c * 1LL * (B - allE) + allC * nodes[ans].e * 1LL;
            if (delta >= A * 1LL * nodes[ans].e)
               ok = true;
         }
         if (ok)
            cout << "Y";
         else
            cout << "N";
      }
      cout << endl;
   }
}
