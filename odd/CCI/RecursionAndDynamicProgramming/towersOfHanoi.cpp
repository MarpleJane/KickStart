#include <iostream>
#include <stack>

using namespace std;

void hanoi(int n, char A, char B, char C)
{
   if (n == 1)
      cout << "Disk " << n << ": " << A << " to " << C << endl;
   else
   {
      hanoi(n - 1, A, C, B);
      cout << "Disk " << n << ": " << A << " to " << C << endl;
      hanoi(n - 1, B, A, C);
   }
}

int main()
{
   hanoi(3, 'A', 'B', 'C');
   return 0;
}
