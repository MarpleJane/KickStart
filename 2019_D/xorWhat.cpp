// prefix xor

#include <iostream>
#include <vector>

using namespace std;

const int MAXE = 1e5;
int A[MAXE + 5], preXor[MAXE + 5];

bool oddOnes(int x)
{
    int cnt = 0;
    while (x)
    {
        cnt ++;
        x &= x - 1;
    }
    return cnt & 1;
}

int main()
{
    int T, N, Q, p, v, maxmod;
    cin >> T;
    for (int i = 1; i <= T; i ++)
    {
        vector<int> results;
        cin >> N >> Q;
        for (int j = 0; j < N; j ++)
            cin >> A[j];
        for (int j = 0; j < Q; j ++)
        {
            maxmod = 0;
            cin >> p >> v;
            A[p] = v;
            preXor[0] = A[0];
            for (int k = 1; k < N; k ++)
                preXor[k] = preXor[k - 1] ^ A[k];
            for (int x = 0; x < N; x ++)
            {
                for (int y = x; y < N; y ++)
                {
                    bool odd = true;
                    int xorResult = -1;
                    if (x == 0)
                        xorResult = preXor[y];
                    else
                        xorResult = preXor[y] ^ preXor[x - 1];
                    odd = oddOnes(xorResult);
                    if (odd == false && (y - x + 1) >= maxmod)
                    {
                        maxmod = y - x + 1;
                    }
                }
            }
            results.push_back(maxmod);
        }
        cout << "Case #" << i << ": ";
        int ss = results.size();
        for (int s = 0; s < ss; s ++)
        {
            if (s != ss - 1)
                cout << results[s] << " ";
            else
                cout << results[s];
        }
        cout << endl;

    }
}
