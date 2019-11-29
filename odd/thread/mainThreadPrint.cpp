#include <iostream>
#include <pthread.h>
#include <memory.h>

using namespace std;

char wordBuffer[128] = {"\0"};

void* threadA_run(void*)
{
   char word[] = {'H', 'i', '!', '\n', '\0'};
   while (1)
   {
      memcpy(wordBuffer, word, sizeof(word));
   }
}

void* threadB_run(void*)
{
   char word[] = {'H', 'e', 'l', 'l', 'o', '\n', '\0'};
   while (1)
   {
      memcpy(wordBuffer, word, sizeof(word));
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
      memcpy(tmp, wordBuffer, sizeof(wordBuffer));
      cout << tmp;
   }
}
