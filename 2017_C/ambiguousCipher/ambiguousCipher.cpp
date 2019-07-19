#include <iostream>
#include <string>

using namespace std;

int plainArray[55];
int cipherArray[55];

string ambiguousCipher(const string& cipher)
{
   string result = "AMBIGUOUS";
   int len = cipher.size();
   if (len & 1)
      return result;

   for (int i = 0; i < len; i ++)
   {
      cipherArray[i] = cipher[i] - 'A';
   }
   plainArray[1] = cipherArray[0];
   plainArray[len - 2] = cipherArray[len - 1];
   for (int i = 2; i < len; i += 2)
   {
      plainArray[i + 1] = (cipherArray[i] - plainArray[i - 1]) % 26;
      if (plainArray[i + 1] < 0)
         plainArray[i + 1] += 26;
   }
   for (int i = len - 3; i > 0; i -= 2)
   {
      plainArray[i - 1] = (cipherArray[i] - plainArray[i + 1]) % 26;
      if (plainArray[i - 1] < 0)
         plainArray[i - 1] += 26;
   }
   result.clear();
   for (int i = 0; i < len; i ++)
      result += plainArray[i] + 'A';
   return result;
}

int main()
{
   int T;
   cin >> T;
   string cipher, result;
   for (int i = 1; i <= T; i ++)
   {
      cin >> cipher;
      result = ambiguousCipher(cipher);
      cout << "Case #" << i << ": " << result << endl;
   }
   return 0;
}
