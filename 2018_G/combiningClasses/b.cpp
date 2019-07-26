#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
const int NMAX = 400000;
const int QMAX = 100000;
ll X[NMAX+1], Y[NMAX+1], Z[NMAX+1], A[4], B[4], C[4];
ll L[NMAX+1], R[NMAX+1], K[QMAX+1], M[4];
int N, Q;

void gen(){
    for(int i=3;i<=N;i++) X[i] = (A[1]*X[i-1]+B[1]*X[i-2]+C[1])%M[1];
    for(int i=3;i<=N;i++) Y[i] = (A[2]*Y[i-1]+B[2]*Y[i-2]+C[2])%M[2];
    for(int i=3;i<=Q;i++) Z[i] = (A[3]*Z[i-1]+B[3]*Z[i-2]+C[3])%M[3];

    for(int i=1;i<=N;i++) L[i] = min(X[i],Y[i])+1, R[i]=max(X[i],Y[i])+1;
    for(int i=1;i<=Q;i++) K[i] = Z[i]+1;
}

vector<pair<int,int>> timeline; // score, howmany?

void pre(){
    timeline.clear();
    map<int,int> mp;
    for(int i=1;i<=N;i++){
        mp[L[i]]++;
        mp[R[i]+1]--;
    }

    int w = 0;
    for(const auto& kv:mp){
        w += kv.second;
        timeline.emplace_back(kv.first, w);
    }
}

ll ans[QMAX+1];

void go(){
    long long tot = 0;
    for(int i=1;i<=N;i++) tot += R[i]-L[i]+1;

    vector<pair<ll,int>> query; // k, idx
    for(int i=1;i<=Q;i++){
        if(K[i] > tot) ans[i] = 0;
        else query.push_back({tot+1-K[i], i});
    }
    sort(query.begin(), query.end());

    long long seen = 0;
    int curid = 0;
    for(const auto& q:query){
        ll k = q.first;

        bool done = false;
        while(1){
            if(curid == (int)timeline.size()-1){
                done = true;
                ans[q.second] = 0;
                break;
            }

            ll w = timeline[curid].second;

            long long cur_block = 1LL*(timeline[curid+1].first - timeline[curid].first)*w;
            if(seen + cur_block < k){
                curid++;
                seen += cur_block;
            }
            else break;
        }

        if(done) continue;

        // answer is in this block!
        ll start_score = timeline[curid].first;
        ll w = timeline[curid].second;

        ll passed = (k-seen-1) / w;
        ans[q.second] = start_score + passed;
    }
}

int main(){
    int TC; scanf("%d",&TC);
    for(int tc=1;tc<=TC;tc++){
        scanf("%d%d",&N,&Q);
        scanf("%lld%lld%lld%lld%lld%lld", X+1,X+2,A+1,B+1,C+1,M+1);
        scanf("%lld%lld%lld%lld%lld%lld", Y+1,Y+2,A+2,B+2,C+2,M+2);
        scanf("%lld%lld%lld%lld%lld%lld", Z+1,Z+2,A+3,B+3,C+3,M+3);

        gen();
        pre();
        go();
        long long sum = 0;
        for(int i=1;i<=Q;i++) sum += ans[i]*i;
        printf("Case #%d: %lld\n", tc, sum);
    }
}
