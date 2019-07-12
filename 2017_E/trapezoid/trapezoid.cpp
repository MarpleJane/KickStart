#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

long C3(int n)
{
   long a = n * (n - 1) * (n - 2);
   long b = 3 * 2 * 1;
   return a / b;
}

long C2(int n)
{
   long a = n * (n - 1);
   long b = 2 * 1;
   return a / b;
}

long trapezoidCount(vector<unsigned long>& v)
{
   long total = 0;
   sort(v.begin(), v.end());
   vector<unsigned long> vv = v;  // set
   vector<int> cnt;
   vector<unsigned long>::iterator vit;
   vit = unique(vv.begin(), vv.end());
   vv.resize(distance(vv.begin(), vit));
   for (int i = 0; i < vv.size(); i ++)
   {
      cnt.push_back(count(v.begin(), v.end(), vv[i]));
   }
   for (int i = 0; i < cnt.size(); i ++)
   {
      if (cnt[i] >= 3)
      {
         for (int j = 0; j < cnt.size(); j ++)
         {
            if (i != j && vv[j] < vv[i] * 3)
               total += C3(cnt[i]) * cnt[j];
         }
      }

      if (cnt[i] >= 2)
      {
         vector<unsigned long> A;
         vector<int> Acnt;
         for (int j = 0; j < vv.size(); j ++)
         {
            if (i != j)
            {
               A.push_back(vv[j]);
               Acnt.push_back(cnt[j]);
            }
         }
         for (int j = 0; j < A.size(); j ++)
         {
            int k = A.size() - 1;
            while (k > j)
            {
               if (A[k] < A[j] + 2 * vv[i])
               {
                  total += C2(cnt[i]) * Acnt[k] * Acnt[j];
               }
               k --;
            }
         }
      }
   }
   return total;
}

int main()
{
   int T, N, l;
   cin >> T;
   for (int i = 1; i <= T; i ++)
   {
      cin >> N;
      vector<unsigned long> v;
      for (int j = 0; j < N; j ++)
      {
         cin >> l;
         v.push_back(l);
      }
      long result = trapezoidCount(v);
      cout << "Case #" << i << ": " << result << endl;
   }

   return 0;
}
