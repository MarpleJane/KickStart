#include <stdio.h>

double dp[210][55];
double cdp[210][55];
int dist[55][55];
int N, E, P;

int main(){
	int jcase;
	
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);
	
	scanf("%d", &jcase);
	for(int icase=0; icase<jcase; icase++){
		scanf("%d %d %d", &N, &E, &P);
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				dist[i][j] = 1000000;
			}
		}
		
		for(int i=0; i<E; i++){
			int u, v, d;
			scanf("%d %d %d", &u, &v, &d);
			dist[u-1][v-1] = d;
			dist[v-1][u-1] = d;
		}
		
		//warshall's
		for(int k=0; k<N; k++){
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
		
		for(int i=0; i<=P; i++){
			for(int j=0; j<N; j++){ 
				dp[i][j] = 0;
				cdp[i][j] = 0;
			}
		}
		cdp[0][0] = 1;
		
		for(int i=0; i<P; i++){
			for(int j=0; j<N; j++){
				if(cdp[i][j] == 0) continue;
				for(int k=0; k<N; k++){
					if(j == k) continue;
					dp[i+1][k] += (dp[i][j] + dist[j][k]) * cdp[i][j];
					cdp[i+1][k] += cdp[i][j];
				}
			}
			
			double totc = 0;
			for(int j=0; j<N; j++){
				if(cdp[i+1][j] != 0){ 
					totc += cdp[i+1][j];
					dp[i+1][j] /= cdp[i+1][j];
					//printf("dp %d %d = %lf %lf\n", i+1, j, dp[i+1][j], cdp[i+1][j]);
				}
			}
			
			for(int j=0; j<N; j++){
				cdp[i+1][j] /= totc;
			}
		}
		
		double ans = 0, ctr = 0;
		for(int i=0; i<N; i++){
			ans += dp[P][i] * cdp[P][i];
			ctr += cdp[P][i];
		}
		ans /= ctr;
		
		printf("Case #%d: %.7lf\n", icase+1, ans);
	}
	
	return 0;
}
