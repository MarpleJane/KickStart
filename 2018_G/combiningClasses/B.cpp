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

const int MAXN = 5e5;
const int MAXP = 13500;
const int SQRTN = 320;
const int LOGN = 32;
const int INT_INFINITY = 1001001001;

const slong LONG_INFINITY = 1001001001001001001ll;

int N, Q;
int X[MAXN+5], Y[MAXN+5], Z[MAXN+5];

int L[MAXN+5], R[MAXN+5], K[MAXN+5];

slong S[MAXN+5];

int ll[MAXN+5];
int rr[MAXN+5];

void parallel()
{
    for (int i = 1; i <= Q; i++)
    {
        ll[i] = 1;
        rr[i] = MOD;
        S[i] = 0;
    }

    vector<pair<pii, int> > firstData;

    for (int i = 1; i <= N; i++)
    {
        firstData.eb(mp(R[i], 2), i);
        firstData.eb(mp(L[i], 1), i);
    }

    sort(ALL(firstData), greater<pair<pii, int> >());

    for (int step = 1; step <= LOGN; step++)
    {
        vector<pair<pii, int> > secondData;

        for (int i = 1; i <= Q; i++)
        {
            if (ll[i] <= rr[i])
            {
                int mid = (ll[i]+rr[i])/2;
                secondData.eb(mp(mid, 0), i);
            }
        }

        if (secondData.empty())
        {
            break;
        }

        sort(ALL(secondData), greater<pair<pii, int> >());

        vector<pair<pii, int> > data(firstData.size() + secondData.size());

        merge (firstData.begin(), firstData.end(), secondData.begin(), secondData.end(), data.begin(), greater<pair<pii, int> >());

        slong onlyRSum = 0;
        slong onlyRCount = 0;
        slong alsoLSum = 0;

        for (auto p: data)
        {
            int &id = p.se;
            int &type = p.fi.se;
            if (type == 2)
            {
                onlyRSum += R[id];
                onlyRCount++;
            }
            else if (type == 1)
            {
                onlyRSum -= R[id];
                onlyRCount--;

                alsoLSum += R[id] - L[id] + 1;
            }
            else
            {
                //query

                slong mid = p.fi.fi;

                slong ans = alsoLSum;
                ans += onlyRSum - onlyRCount*mid + onlyRCount;

                if (ans >= K[id])
                {
                    S[id] = mid;
                    ll[id] = mid+1;
                }
                else
                {
                    rr[id] = mid-1;
                }
            }
        }
    }
}

slong countHigher(slong value)
{
    slong ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (R[i] < value)
        {
            continue;
        }
        ans += R[i] - max(1ll*L[i], value) + 1;;
    }
    return ans;
}

slong findAns(slong value)
{
    slong first = 1;
    slong last = MOD;
    slong mid;
    slong best = 0;

    while (first <= last)
    {
        mid = (first+last)/2;
        if (countHigher(mid) >= value)
        {
            best = mid;
            first = mid+1;
        }
        else
        {
            last = mid-1;
        }
    }

    return best;
}

int main()
{
    cin.tie(0);
    
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> N >> Q;

        slong A1, B1, C1, M1;
        slong A2, B2, C2, M2;
        slong A3, B3, C3, M3;
        
        cin >> X[1] >> X[2] >> A1 >> B1 >> C1 >> M1;
        cin >> Y[1] >> Y[2] >> A2 >> B2 >> C2 >> M2;
        cin >> Z[1] >> Z[2] >> A3 >> B3 >> C3 >> M3;

        for (int i = 3; i <= N; i++)
        {
            X[i] = (A1*X[i-1] + B1*X[i-2] + C1) % M1;
        }

        for (int i = 3; i <= N; i++)
        {
            Y[i] = (A2*Y[i-1] + B2*Y[i-2] + C2) % M2;
        }

        for (int i = 3; i <= Q; i++)
        {
            Z[i] = (A3*Z[i-1] + B3*Z[i-2] + C3) % M3;
        }

        for (int i = 1; i <= N; i++)
        {
            L[i] = min(X[i], Y[i]) + 1;
            R[i] = max(X[i], Y[i]) + 1;
            assert(L[i] >= 1);
        }

        for (int i = 1; i <= Q; i++)
        {
            K[i] = Z[i] + 1;
        }

        slong ans = 0;

        parallel();

        for (int i = 1; i <= Q; i++)
        {
            ans += 1ll*i*S[i];
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}

