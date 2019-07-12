#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <string>
#include <math.h>

using namespace std;

string rb[2] = {"R", "B"};
set<string> eliminate;

void dfs(int delta, string p)
{
   if (delta == 0)
   {
//      cout << "Insert: " << p << endl;
      eliminate.insert(p);
      return;
   }

   for (int i = 0; i < 2; i ++)
   {
      delta --;
      p.append(rb[i]);
//      cout << "Append: " << p << endl;
      dfs(delta, p);
      delta ++;
      p.erase(p.end()-1, p.end());
//      cout << "Erase: " << p << endl;
   }
   return;
}

int main()
{
   int T, N, P;
   cin >> T;
   for (int i = 1; i <= T; i ++)
   {
      eliminate.clear();
      cin >> N >> P;
      for (int j = 0; j < P; j ++)
      {
         string p;
         cin >> p;
         int delta = N - p.size();
         dfs(delta, p);
      }
      long long total = pow(2, N);
//      cout << "Total: " << total << endl;
      long long eliSum = eliminate.size();
      cout << "Case #" << i << ": " << total - eliSum << endl;
   }

   return 0;
}
