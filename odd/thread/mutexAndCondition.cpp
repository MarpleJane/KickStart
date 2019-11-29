#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <memory.h>

using namespace std;

pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t myCond = PTHREAD_COND_INITIALIZER;

char msg[1024];

void* son(void*)
{
   while (1)
   {
      pthread_mutex_lock(&myMutex);
      pthread_cond_wait(&myCond, &myMutex);
      cout << "Son: " << msg << endl;
      if (0 == strcmp(msg, "It's time for bed"))
      {
         pthread_mutex_unlock(&myMutex);
         break;
      }
      pthread_mutex_unlock(&myMutex);
   }
   cout << "Thread son exit" << endl;
}

int main()
{
   pthread_t threadSon;
   pthread_create(&threadSon, NULL, son, NULL);
   for (int i = 0; ;i ++)
   {
      sleep(2);
      if (i == 0)
      {
         pthread_mutex_lock(&myMutex);
         strcpy(msg, "It's time to get up");
         cout << "Mom: " << msg << endl;
         pthread_cond_broadcast(&myCond);
         pthread_mutex_unlock(&myMutex);
      }
      else if (i == 1)
      {
         pthread_mutex_lock(&myMutex);
         strcpy(msg, "It's time for breakfast");
         cout << "Mom: " << msg << endl;
         pthread_cond_broadcast(&myCond);
         pthread_mutex_unlock(&myMutex);
      }
      else if (i == 2)
      {
         pthread_mutex_lock(&myMutex);
         strcpy(msg, "It's time for lunch");
         cout << "Mom: " << msg << endl;
         pthread_cond_broadcast(&myCond);
         pthread_mutex_unlock(&myMutex);
      }
      else if (i == 3)
      {
         pthread_mutex_lock(&myMutex);
         strcpy(msg, "It's time for dinner");
         cout << "Mom: " << msg << endl;
         pthread_cond_broadcast(&myCond);
         pthread_mutex_unlock(&myMutex);
      }
      else if (i == 4)
      {
         pthread_mutex_lock(&myMutex);
         strcpy(msg, "It's time for bed");
         cout << "Mom: " << msg << endl;
         pthread_cond_broadcast(&myCond);
         pthread_mutex_unlock(&myMutex);
         break;
      }
   }
   cout << "Thread mom exit" << endl;
   pthread_join(threadSon, NULL);
   return 0;
}
