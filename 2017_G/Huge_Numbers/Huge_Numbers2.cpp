#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

long hugeNumber(long A, long N, long P);

long pow(long A, long N, long P);

void execute()
{
   ifstream inobj;
   ofstream outobj;
   inobj.open("A-large-practice.in");
   outobj.open("A-large-practice.out");
   if (!inobj.is_open())
   {
      cout << "Error to open in file" << endl;
      exit(1);
   }
   if (!outobj.is_open())
   {
      cout << "Error to open out file" << endl;
      exit(1);
   }
   long num, A, N, P, result;
   inobj >> num;
   for (long i = 0; i < num; i ++)
   {
      inobj >> A >> N >> P;
      result = hugeNumber(A, N, P);
      outobj << "Case #" << i + 1 << ": " << result << endl;
   }
   inobj.close();
   outobj.close();
}

long pow(long A, long N, long P)
{
   if (N == 0)
      return 1;

   long pow_half = pow(A, N/2, P);
   long pow_half_sq = (pow_half * pow_half) % P;
   if (N % 2 == 0)
      return pow_half_sq;
   else
      return (pow_half_sq * A) % P;
}

long hugeNumber(long A, long N, long P)
{
   long ans = A % P;
   for (long i = 2; i <= N; i ++)
      ans = pow(ans, i, P);
   return ans;
}

int main()
{
   execute();
   return 0;
}
