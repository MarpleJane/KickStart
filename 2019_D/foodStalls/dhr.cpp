#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<iii> viii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
#define pb push_back
#define INF 1000000000
#define LINF (ll)INF*INF
#define all(x) x.begin(),x.end()
#define F first
#define S second
/*
	It's good to be back!
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int t;cin>>t;
for(int test=1;test<=t;test++)
{
    int k,n;cin>>k>>n;
    vector<long long> x(n),c(n);
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>c[i];
    long long ans=LINF;
    for(int i=0;i<n;i++)
    {
        ll cost = c[i];
        vector<ll> stcost;
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            stcost.push_back((long long)c[j]+abs(x[j]-x[i]));
        }
        sort(all(stcost));
        for(int i=0;i<k;i++)
            cost+=stcost[i];
        ans = min(ans,cost);
    }
    cout<<"Case #"<<test<<": "<<ans<<endl;
}
	return 0;
}
