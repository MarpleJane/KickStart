#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

const int maxn = 1e5 + 5;
const int INF = 1e9 + 7;
int x[maxn], type[maxn];
set<int> clockwise, anticlock;
int N, G, M;
int num[maxn][2];
int ans[maxn];

int change(int time){
    while(time <= 0){
        time += N;
    }while(time > N){
        time -= N;
    }
    return time;
}

int main(){
    int T;
    int cas = 0;
    cin >> T;
    while(T--){
        cin >> N >> G >> M;
        clockwise.clear();
        anticlock.clear();
        memset(num, 0, sizeof(num));
        for(int i = 1;i <= G;i++){
            char s[3];
            scanf("%d%s", &x[i], s);
            if(s[0] == 'C'){
                type[i] = 0;
                clockwise.insert(x[i]);
                clockwise.insert(x[i] - N);
                clockwise.insert(x[i] - N*2);
            }else{
                type[i] = 1;
                anticlock.insert(x[i]);
                anticlock.insert(x[i] + N);
                anticlock.insert(x[i] + N*2);
            }
        } 
        int mod = M % N;
        if(M > N){
            M = N + mod;
        }
        for(int i = 1;i <= N;i++){
            int t1, t2;
            auto it = clockwise.lower_bound(i - M);
            auto it2 = anticlock.upper_bound(i + M);
            if((it == clockwise.end()) || ((*it) > i)){
                 t1 = INF;   
            }else{
                t1 = (*it) - (i - M);
            }
            if(it2 == anticlock.begin()){
                t2 = INF;
            }else{
                it2--;
                if((*it2) < i){
                    t2 = INF;
                }else{
                    t2 = (i + M) - (*it2);
                }
            }
            if(t1 == INF && t2 == INF)
                continue;
            else{
                if(t1 == INF){
                    num[change(*it2)][1]++;    
                }else if(t2 == INF){
                    num[change(*it)][0]++;
                }else{
                    if(t1 < t2){
                        num[change(*it)][0]++;
                    }else if(t1 == t2){
                        num[change(*it)][0]++;
                        num[change(*it2)][1]++;
                    }else{
                        num[change(*it2)][1]++;
                    }
                }
            }
        }
        printf("Case #%d:", ++cas);
        for(int i = 1;i <= G;i++){
            printf(" %d", num[x[i]][type[i]]);
        }
        puts("");
    }
    return 0;
}
