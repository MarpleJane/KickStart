// To check if n is divisible by a prime number

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void crossOff(vector<bool>& flags, int prime)
{
   for (int i = prime * prime; i < flags.size(); i += prime)
      flags[i] = false;
}

int getNextPrime(vector<bool>& flags, int prime)
{
   for (int i = prime + 1; i < flags.size(); i ++)
   {
      if (flags[i])
         return i;
   }
}

bool sieveOfEratosthenes(int max)  // true: is prime; false: not prime
{
   vector<bool> flags(max + 1, true);
   int count = 0;

   int prime = 2;

   while (prime <= sqrt(max))
   {
      crossOff(flags, prime);
      prime = getNextPrime(flags, prime);
   }

   return flags[max];
}

int main()
{
   cout << "37: " << sieveOfEratosthenes(37) << endl;
   cout << "100: " << sieveOfEratosthenes(100) << endl;
   cout << "9999: " << sieveOfEratosthenes(9999) << endl;
   cout << "827: " << sieveOfEratosthenes(827) << endl;
}
