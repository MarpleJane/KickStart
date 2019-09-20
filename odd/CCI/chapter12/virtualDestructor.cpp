#include <iostream>

using namespace std;

#define NAME_SIZE 50

class Person
{
   public:
      virtual ~Person()
      {
         cout << "Deleting a Person" << endl;
      }
};

class Student: public Person
{
   public:
      ~Student()
      {
         cout << "Deleting a Student" << endl;
      }
};

int main()
{
   Person* p = new Student();
   delete p;
   return 0;
}
