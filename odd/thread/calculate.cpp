#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void* calc(void* arg)
{
   int* input = (int*)arg;
   int* output = new int(sizeof(int));
   *output = 0;
   while ((*input) --)
   {
      (*output) ++;
   }
   return output;
}

int main()
{
   pthread_t threadA, threadB;
   int *retvalA, *retvalB;
   int result;
   int argA = 10, argB = 20;
   pthread_create(&threadA, NULL, calc, &argA);
   pthread_create(&threadB, NULL, calc, &argB);
   pthread_join(threadA, (void**)&retvalA);
   pthread_join(threadB, (void**)&retvalB);
   result = (int)*retvalA + (int)*retvalB;
   delete retvalA;
   delete retvalB;
   cout << "result: " << result << endl;
}
