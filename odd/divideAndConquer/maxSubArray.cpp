#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> findCrossSubArray(vector<int>& array, int low, int high)
{
   //cout << "findCrossSubArray: " << low << " " << high << endl;
   vector<int> result;
   int leftSum = -1000;
   int sum = 0;
   int mid = (low + high) / 2;
   int maxLeft = mid;
   for (int i = mid; i >= low; i --)
   {
      sum += array[i];
      if (sum > leftSum)
      {
         leftSum = sum;
         maxLeft = i;
      }
   }

   int rightSum = -1000;
   sum = 0;
   int maxRight = mid;
   for (int i = mid + 1; i < high; i ++)
   {
      sum += array[i];
      if (sum > rightSum)
      {
         rightSum = sum;
         maxRight = i;
      }
   }
   result.push_back(maxLeft);
   result.push_back(maxRight);
   result.push_back(leftSum + rightSum);

   return result;
}

vector<int> findSubArray(vector<int>& array, int low, int high)
{
   if (low == high)
   {
      vector<int> result;
      result.push_back(low);
      result.push_back(low);
      result.push_back(array[low]);
      return result;
   }
   else
   {
      //cout << "findSubArray: " << low << " " << high << endl;
      int mid = (low + high) / 2;
      vector<int> leftArray = findSubArray(array, low, mid);
      vector<int> rightArray = findSubArray(array, mid + 1, high);
      vector<int> crossArray = findCrossSubArray(array, low, high);
      int leftSum = leftArray[2];
      int rightSum = rightArray[2];
      int crossSum = crossArray[2];
      if (leftSum >= rightSum && leftSum >= crossSum)
         return leftArray;
      else if (rightSum >= leftSum && rightSum >= crossSum)
         return rightArray;
      else
         return crossArray;
   }
}

vector<int> genDiff(vector<int>& origin)
{
   vector<int> result(origin.size());
   result[0] = 0;
   for (int i = 1; i < origin.size(); i ++)
      result[i] = origin[i] - origin[i - 1];
   return result;
}

int main()
{
   int N;
   cin >> N;
   vector<int> origin(N), array(N);
   for (int i = 0; i < N; i ++)
      cin >> origin[i];
   array = genDiff(origin);
   vector<int> result = findSubArray(array, 1, array.size());
   cout << "Left: " << result[0] << endl;
   cout << "Right: " << result[1] << endl;
   cout << "Sum: " << result[2] << endl;
   return 0;
}
