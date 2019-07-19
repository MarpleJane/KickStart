#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;

int x[maxn], y[maxn];
int r[maxn], s[maxn];
int A[maxn], B[maxn];
int sum[maxn];
int idx[maxn];
int tree[maxn];

vector<int> vals;

void init()
{
    for (int i = 1; i <= (int)vals.size(); ++i)
        tree[i] = 0;
}

void add(int x)
{
    while (x <= (int)vals.size())
    {
        ++tree[x];
        x += x & -x;
    }
}

int query(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret += tree[x];
        x -= x & -x;
    }
    return ret;
}

vector<int> get(int *A, int N, int K)
{
    for (int i = 1; i <= N; ++i)
        sum[i] = sum[i - 1] + A[i];
    vals.clear();
    for (int i = 0; i <= N; ++i)
        vals.push_back(sum[i]);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i <= N; ++i)
        idx[i] = (int)(lower_bound(vals.begin(), vals.end(), sum[i]) - vals.begin()) + 1;
    int L = -1e9;
    int R = 1e9;
    while (L < R)
    {
        int M = (L + R) >> 1;
        long long cnt = 0;
        init();
        for (int i = 0; i <= N; ++i)
        {
            int t = lower_bound(vals.begin(), vals.end(), sum[i] - M) - vals.begin();
            cnt += query(t);
            add(idx[i]);
        }
        if (cnt < K)
            R = M;
        else
            L = M + 1;
    }
    vector<int> ret;
    multiset<int> st;
    for (int i = 0; i <= N; ++i)
    {
        for (int x : st)
        {
            if (sum[i] - x <= L)
                break;
            ret.push_back(sum[i] - x);
        }
        st.insert(sum[i]);
    }
    while ((int)ret.size() < K)
        ret.push_back(L);
    return ret;
}

vector<int> getAll(int *A, int N)
{
    vector<int> ret;
    for (int i = 1; i <= N; ++i)
        sum[i] = sum[i - 1] + A[i];
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < i; ++j)
            ret.push_back(sum[i] - sum[j]);
    return ret;
}

void test1()
{
    static int a[11];
    for (int i = 1; i <= 10; ++i)
        a[i] = i - 5;
    auto res = get(a, 9, 23);
    sort(res.begin(), res.end());
    for (int x : res)
        printf("%d ", x);
    puts("");
}

int main()
{
    // test1();
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase)
    {
        int N, K, A1, B1, C, D, E1, E2, F;
        scanf("%d %d %d %d %d %d %d %d %d", &N, &K, &A1, &B1, &C, &D, &E1, &E2, &F);
        x[1] = A1;
        y[1] = B1;
        r[1] = 0;
        s[1] = 0;
        A[1] = A1;
        B[1] = B1;
        for (int i = 2; i <= N; ++i)
        {
            x[i] = (C * x[i - 1] + D * y[i - 1] + E1) % F;
            y[i] = (D * x[i - 1] + C * y[i - 1] + E2) % F;
            r[i] = (C * r[i - 1] + D * s[i - 1] + E1) % 2;
            s[i] = (D * r[i - 1] + C * s[i - 1] + E2) % 2;
            A[i] = x[i];
            B[i] = y[i];
            if (r[i] == 1)
                A[i] = -A[i];
            if (s[i] == 1)
                B[i] = -B[i];
        }
        vector<int> AK;
        vector<int> BK;
        long long tot = 1ll * N * (N + 1) / 2;
        if (K * 2 >= tot)
        {
            AK = getAll(A, N);
            BK = getAll(B, N);
        }
        else
        {
            AK = get(A, N, K);
            BK = get(B, N, K);
            for (int i = 1; i <= N; ++i)
            {
                A[i] = -A[i];
                B[i] = -B[i];
            }
            vector<int> AKneg = get(A, N, K);
            vector<int> BKneg = get(B, N, K);
            for (int x : AKneg)
                AK.push_back(-x);
            for (int x : BKneg)
                BK.push_back(-x);
        }
        sort(BK.begin(), BK.end());
        long long L = -1e18;
        long long R = 1e18;
        while (L < R)
        {
            long long M = (L + R) >> 1;
            long long cnt = 0;
            for (int x : AK)
            {
                if (x == 0)
                {
                    if (M < 0)
                        cnt += BK.size();
                }
                else if (x > 0)
                {
                    int l = 0, r = BK.size();
                    while (l < r)
                    {
                        int m = (l + r) >> 1;
                        if (1ll * x * BK[m] > M)
                            r = m;
                        else
                            l = m + 1;
                    }
                    cnt += (int)BK.size() - l;
                }
                else
                {
                    int l = 0, r = BK.size();
                    while (l < r)
                    {
                        int m = (l + r) >> 1;
                        if (1ll * x * BK[m] > M)
                            l = m + 1;
                        else
                            r = m;
                    }
                    cnt += l;
                }
            }
            if (cnt < K)
                R = M;
            else
                L = M + 1;
        }
        printf("Case #%d: %lld\n", kase, L);
    }
    return 0;
}