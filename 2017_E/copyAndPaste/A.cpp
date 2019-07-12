#include <stdio.h>
#include <string.h>
#define INF 1000000

char key[310];
int dp[310][310][310];
bool isSame[310][310][310];
int len;

void Prework(){
	memset(isSame, false, sizeof(isSame));
	
	for(int i=0; i<len; i++){
		for(int j=0; j<i; j++){
			for(int k=j; k<=i; k++){
				if(k-j == 1){
					if(key[i] == key[j]) isSame[i][j][k] = true;
				}
				else{
					if(isSame[i][j][k-1] && key[i+k-1-j] == key[k-1]) isSame[i][j][k] = true;
				}
			}
		}
	}
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	
	int jcase;
	
	scanf("%d", &jcase);
	gets(key);
	for(int icase=0; icase<jcase; icase++){
		gets(key);
		len = strlen(key);
		Prework();
		
		memset(dp, 127, sizeof(dp));
		dp[1][0][0] = 1;
		
		for(int i=1; i<len; i++){
			int best = INF;
			for(int j=0; j<i; j++){
				for(int k=j; k<=i; k++){
					if(dp[i][j][k] < best) best = dp[i][j][k];
				}
			}
			
			for(int j=0; j<i; j++){
				for(int k=j; k<=i; k++){
					if(dp[i][j][k] > best+1) dp[i][j][k] = best+1;
					
					//type next letter
					if(dp[i+1][j][k] > dp[i][j][k] + 1) dp[i+1][j][k] = dp[i][j][k] + 1;
					
					//paste the letters
					if(i+ k-j <= len && isSame[i][j][k]){
						if(dp[i+k-j][j][k] > dp[i][j][k] + 1) dp[i+k-j][j][k] = dp[i][j][k] + 1;
					}
				}
			}
		}
		
		//get ans;
		int best = INF;
		for(int i=0; i<len; i++){
			for(int j=i; j<=len; j++){
				if(dp[len][i][j] < best) best = dp[len][i][j];
			}
		}
		
		printf("Case #%d: %d\n", icase+1, best);
	}
	
	return 0;
}
