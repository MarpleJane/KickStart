#include <iostream>
#include <map>

using namespace std;

bool anagramMatch(string& A, string& B, int i, int j, int k, int l)
{
   bool result = true;
   map<char, int> mapA, mapB;
   for (int z = i; z <= j; z ++)
      mapA[A[z]] ++;
   for (int z = k; z <= l; z ++)
      mapB[B[z]] ++;
   map<char, int>::iterator it = mapA.begin();
   while (it != mapA.end())
   {
      if (it->second != mapB[it->first])
      {
         result = false;
         break;
      }
      it ++;
   }
   it = mapB.begin();
   while (it != mapB.end())
   {
      if (it->second != mapA[it->first])
      {
         result = false;
         break;
      }
      it ++;
   }
   return result;
}

int main()
{
   int T, L;
   string A, B;
   cin >> T;
   for (int t = 1; t <= T; t ++)
   {
      cin >> L;
      cin >> A >> B;
      int total = 0;
      for (int i = 0; i < L; i ++)
      {
         for (int j = i; j < L; j ++)
         {
            for (int k = 0; k < L; k ++)
            {
               if (anagramMatch(A, B, i, j, k, k + (j - i)))
               {
                  total ++;
                  break;
               }
            }
         }
      }
      cout << "Case #" << t << ": " << total << endl;
   }
   return 0;
}
