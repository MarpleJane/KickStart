#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

//bool PalindromePermutation(string str)
//{
//   map<char, int> strMap;
//   int charCnt = 0;
//   for (int i = 0; i < str.size(); i ++)
//   {
//      if (isspace(str[i]))
//         continue;
//      charCnt ++;
//      strMap[tolower(str[i])] ++;
//   }
//
//   bool odd = charCnt & 1;
//   int oddCount = 0;
//   map<char, int>::iterator it;
//   for (it = strMap.begin(); it != strMap.end(); it ++)
//   {
//      bool mapOdd = it->second & 1;
//      if (mapOdd)
//         oddCount ++;
//      if (!odd && mapOdd)
//      {
//         cout << "[!odd && mapOdd]" << endl;
//         return false;
//      }
//   }
//   if (odd && oddCount != 1)
//   {
//      cout << "[odd && oddCount != 1]: " << oddCount << endl;
//      return false;
//   }
//   return true;
//}

int getCharNumber(char c)
{
   int a = 'a';
   int z = 'z';
   int value = c;
   if (a <= value && value <= z)
      return value - 'a';
   return -1;
}

int toggle(int bitVector, int index)
{
   if (index < 0)
      return bitVector;
   int mask = 1 << index;
   if ((bitVector & mask) == 0)
      bitVector |= mask;
   else
      bitVector &= ~mask;
   return bitVector;
}

int createBitVector(string phrase)
{
   int bitVector = 0;
   for (int i = 0; i < phrase.size(); i ++)
   {
      int x = getCharNumber(tolower(phrase[i]));
      //cout << x << endl;
      bitVector = toggle(bitVector, x);
      //cout << bitset<32>(bitVector) << endl;
   }
   return bitVector;
}

bool checkExactlyOneBitSet(int bitVector)
{
   //cout << "checkExactlyOneBitSet: " << bitset<32>((bitVector & (bitVector - 1))) << endl;
   return (bitVector & (bitVector - 1)) == 0;
}

bool isPermutationOfPalindrome(string phrase)
{
   int bitVector = createBitVector(phrase);
   //cout << "Result: " << bitset<32>(bitVector) << endl;
   return bitVector == 0 || checkExactlyOneBitSet(bitVector);
}

int main()
{
   //cout << PalindromePermutation("Tact cCoa") << endl;
   cout << isPermutationOfPalindrome("Tact cCoa") << endl;
}
