#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(), (v).end()

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long int slong;
typedef pair<int, int> pii;
typedef pair<slong, slong> pll;

#ifdef VSP4 
    #include "debug.h"    
#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif

const int MOD = 1000000007;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;

const int MAXN = 7e3;
const int MAXP = 13500;
const int SQRTN = 320;
const int LOGN = 16;
const int INT_INFINITY = 1001001001;

const slong LONG_INFINITY = 1001001001001001001ll;

int N;
string A, B;

int main()
{
	cin.tie(0);
	
	int T;
	cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> N;

        slong cntzero = 0;

        vector<int> data;

        for (int i = 1; i <= N; i++)
        {
            int d;
            cin >> d;
            if (d == 0)
            {
                cntzero++;
            }
            else
            {
                data.pb(d);
            }
        }

        slong ans = 0;

        if (data.size() >= 1)
        {
            map<slong, int> cntvals;

            sort(ALL(data));
            
            for (int i = data.size()-1; i >= 0; i--)
            {
                for (int j = i-1; j >= 0; j--)
                {
                    slong prod = 1ll*data[i]*data[j];
                    map<slong, int>::iterator it = cntvals.find(prod);
                    //auto it = cntvals.find(prod);
                    if (it != cntvals.end())
                    {
                        ans += it->se;
                    }
                }
                cntvals[data[i]]++;
            }
        }

        ans += (cntzero*(cntzero-1)*(cntzero-2))/6;
        ans += ((cntzero*(cntzero-1))/2)*data.size();

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}

