#include <stdio.h>
#include <time.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

int n,t;
int i,j,k;
int p[2] = {2,5};
int v[1001][1001][2];
int dp[1001][1001][2];
char r[2002];

int main(){

	int z;
	int zx,zy;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&t);
			if(t){
				for(k=0;k<2;k++){
					while(t%p[k]==0){
						t/=p[k];
						v[i][j][k]++;
					}
				}
			}else{
				z = 1;
				zx = i;
				zy = j;
			}
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<2;k++){
				if(i!=0 && j!=0){
					dp[i][j][k] = MIN(dp[i-1][j][k],dp[i][j-1][k])+v[i][j][k];
				}else if(j!=0){
					dp[i][j][k] = v[i][j][k] + dp[i][j-1][k];
				}else if(i!=0){
					dp[i][j][k] = v[i][j][k] + dp[i-1][j][k];
				}else{
					dp[i][j][k] = v[i][j][k];
				}
			}
		}
	}

	/*
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",v[i][j][1]);
		}
		printf("\n");
	}*/

	int ans = MIN(dp[n-1][n-1][0],dp[n-1][n-1][1]);

	if(z && ans > 1){
		printf("1\n");
		for(i=0;i<zx;i++){
			putchar('D');
		}
		for(i=0;i<zy;i++){
			putchar('R');
		}
		for(i=zx;i<n;i++){
			putchar('D');
		}
		for(i=zy;i<n;i++){
			putchar('R');
		}
		puts("");
	}else{

		printf("%d\n",MIN(dp[n-1][n-1][0],dp[n-1][n-1][1]));

		int x = n-1,y = n-1;
		k = dp[n-1][n-1][0] < dp[n-1][n-1][1] ? 0 : 1;

		i = 0;
		while(!(x==0 && y==0)){
			if(x!=0&&y!=0){
				if(v[x][y][k]+dp[x-1][y][k] == dp[x][y][k]){
					r[i++] = 'D';
					x--;
				}else{
					r[i++] = 'R';
					y--;
				}
			}else if(x!=0){
				r[i++] = 'D';
				x--;
			}else if(y!=0){
				r[i++] = 'R';
				y--;
			}
		}

		for(i--;i>=0;i--)putchar(r[i]);
		puts("");
	}

	return 0;
}


