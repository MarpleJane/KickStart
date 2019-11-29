#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void* threadA_run(void*)
{
   cout << "thread A start..." << endl;
   sleep(1);
   cout << "thread A stop..." << endl;
}

int main()
{
   pthread_t threadA;
   pthread_create(&threadA, NULL, threadA_run, NULL);
   pthread_join(threadA, NULL);
   cout << "thread main stop" << endl;
}
