#include <iostream>
#include <string>

using namespace std;

#define NAME_SIZE 50

class Person
{
   int id;
   char name[NAME_SIZE];

   public:
   virtual void aboutMe()
   {
      cout << "I'm a person." << endl;
   }

   virtual bool addCourse() = 0;
};

class Student: public Person
{
   public:
      void aboutMe()
      {
         cout << "I'm a student." << endl;
      }

      bool addCourse()
      {
         cout << "Added course to student." << endl;
         return true;
      }
};

class Teacher: public Person
{
   public:
      bool addCourse()
      {
         cout << "Added course to teacher." << endl;
      }
};

int main()
{
   Person* p = new Student();
   p->addCourse();
   delete p;
   p = new Teacher();
   p->addCourse();
   delete p;
   return 0;
}
