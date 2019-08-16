#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
   int T, L;
   string A, B;
   cin >> T;
   for (int t = 1; t <= T; t ++)
   {
      cin >> L >> A >> B;
      set<string> subsB;
      for (int i = 0; i < L; i ++)
      {
         for (int j = i; j < L; j ++)
         {
            string sub = B.substr(i, j - i + 1);
            sort(sub.begin(), sub.end());
            subsB.insert(sub);
         }
      }

      int total = 0;
      for (int i = 0; i < L; i ++)
      {
         for (int j = i; j < L; j ++)
         {
            string sub = A.substr(i, j - i + 1);
            sort(sub.begin(), sub.end());
            total += subsB.count(sub);
         }
      }
      cout << "Case #" << t << ": " << total << endl;
   }

   return 0;
}
