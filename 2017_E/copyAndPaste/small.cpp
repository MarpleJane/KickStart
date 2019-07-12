#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
//#include <unordered_set>
//#include <unordered_map>
//#include <sstream>
#include <set>
#include <map>
//#include <climits>
//#include <random>
//#include <deque>

using namespace std;

#define INF 2139062143
#define LINF 9187201950435737471
#define mem(a,v) memset(a,v,sizeof(a))
#define maxn 305
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define eps 1e-7
#define ll long long
#define mp make_pair
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
typedef pair<int,int> pp;

int dp[maxn][maxn][maxn];
int main() {
    ios::sync_with_stdio(false);cout.setf(ios::fixed); cout.precision(20);
//    freopen("/Users/huangqingwei/Documents/C++ workspace/codeforces/input.txt", "r",stdin);
    freopen("/Users/huangqingwei/Downloads/A-small-attempt0.in-2.txt", "r",stdin);
    freopen("/Users/huangqingwei/Documents/C++ workspace/codeforces/output.txt", "w",stdout);
    int T;
    cin>>T;
    rep(t,1,T)
    {
        string s;
        cin>>s;
        mem(dp,127);
        int n = s.length();
        dp[1][0][0] = 1;
        dp[1][1][1] = 2;
        for(int i=1;i<n;i++)
        {
            dp[i+1][0][0] = min(dp[i+1][0][0],dp[i][0][0]+1);
            for(int j=1;j<=i+1;j++)
                for(int k=j;k<=i+1;k++)
                    dp[i+1][j][k] = min(dp[i+1][j][k],dp[i+1][0][0]+1);
            for(int j=1;j<=i;j++)
                for(int k=j;k<=i;k++)
                {
                    int len = k-j+1;
                    if(i+k-j+1<=n && s.substr(i,len)==s.substr(j-1,len))
                        dp[i+len][j][k] = min(dp[i+len][j][k],dp[i][j][k]+1);
                    dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]+1);
                    for(int jj=1;jj<=i+1;jj++)
                        for(int kk=j;kk<=i+1;kk++)
                            dp[i+1][jj][kk] = min(dp[i+1][jj][kk],dp[i+1][j][k]+1);
                }
        }
        int ans = INF;
        rep(i,0,n)
            rep(j,0,n)
                ans = min(ans,dp[n][i][j]);
        cout<<"Case #"<<t<<": "<<ans<<'\n';
    }

    return 0;
}





















