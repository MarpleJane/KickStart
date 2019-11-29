#include <iostream>
#include <pthread.h>
#include <memory.h>

using namespace std;

char wordBuffer[128] = {'\0'};
pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;

void* threadA_run(void*)
{
   char word[] = {'H', 'i', '!', '\n', '\0'};
   while (1)
   {
      pthread_mutex_lock(&myMutex);
      memcpy(wordBuffer, word, sizeof(word));
      pthread_mutex_unlock(&myMutex);
   }
}

void* threadB_run(void*)
{
   char word[] = {'H', 'e', 'l', 'l', 'o', '!', '\n', '\0'};
   while (1)
   {
      pthread_mutex_lock(&myMutex);
      memcpy(wordBuffer, word, sizeof(word));
      pthread_mutex_unlock(&myMutex);
   }
}

int main()
{
   pthread_t threadA, threadB;
   pthread_create(&threadA, NULL, threadA_run, NULL);
   pthread_create(&threadB, NULL, threadB_run, NULL);
   char tmp[sizeof(wordBuffer)];
   while (1)
   {
      pthread_mutex_lock(&myMutex);
      memcpy(tmp, wordBuffer, sizeof(wordBuffer));
      pthread_mutex_unlock(&myMutex);
      cout << tmp;
   }
}
