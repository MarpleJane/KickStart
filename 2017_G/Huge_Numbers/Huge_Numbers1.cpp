#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

long hugeNumbers(long A, long N, long P);

long factorial(long N);

void execute()
{
   ofstream outobj;
   ifstream inobj;
   inobj.open("A-small-practice.in");
   outobj.open("A-small-practice.out");
   if (!inobj.is_open())
   {
      cout << "Error opening file" << endl;
      exit(1);
   }
   if (!outobj.is_open())
   {
      cout << "Error opening file" << endl;
      exit(1);
   }

   long num, A, N, P, result;
   inobj >> num;
   cout << "Test cases: " << num << endl;
   for (long i = 0; i < num; i ++)
   {
      inobj >> A >> N >> P;
      result = hugeNumbers(A, N, P);
      outobj << "Case #" << i + 1 << ": " << result << endl;
   }
   inobj.close();
   outobj.close();
}

long factorial(long N)
{
   if (N == 1 || N == 0)
      return 1;
   else
      return N * factorial(N-1);
}

long hugeNumbers(long A, long N, long P)
{
   long power = factorial(N);
   long ans = 1;
   for (long i = 0; i < power; i ++)
   {
      ans = (ans * A) % P;
   }
   return ans;
}

int main()
{
   execute();
   return 0;
}
