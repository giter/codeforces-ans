#include <cstdio>

int s,d;
int dp[32][250];
int r[32];
int p[32];
int a,b;

int main(){
	
	scanf("%d%d",&d,&s);
	
	for(int i=0;i<d;i++){
		for(int j=0;j<=s;j++){
			dp[i][j] = -1; 
		}
	}

	for(int i=0;i<d;i++){
		scanf("%d%d",&a,&b);
		if(i > 0){
			for(int j=0;j<=s;j++)if(dp[i-1][j] != -1){
				for(int k=a;k<=b && j+k<=s;k++){
					dp[i][j+k] = k;
				}
			}
		}else{
			for(int j=a;j<=b;j++){
				dp[i][j] = j;
			}
		}
	}
	
	if(dp[d-1][s] != -1){
			p[d-1] = s;
			r[d-1] = dp[d-1][p[d-1]];
			for(int i=d-1;i>0;i--){
				p[i-1] = p[i] - r[i];
				r[i-1] = dp[i-1][p[i-1]];
			}
			printf("YES\n");
			printf("%d",r[0]);
			for(int i=1;i<d;i++){
				printf(" %d",r[i]);
			}
			printf("\n");
	}else{
		printf("NO\n");
	}

}
