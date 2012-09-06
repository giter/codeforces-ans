#include <cstdio>
#include <set>
using namespace std;

#define N 1000010

int n;
int p[N];
set< pair<int,int> > r;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",p+i);
	}

	int ans = 0;
	for(int i=0;i<n;i++){
		{
			int m = -1;
			for(int j=1;j<n-1;j++){
				int k = (i+j)%n;
				if(p[k]>=m){
					for(int l=0;l<=j;l++){
						printf("%d ",p[(i+l)%n]);
					}
					printf("+\n");
					m = p[k];
					if(r.count(pair<int,int>(i,k)) == 0){
						r.insert(pair<int,int>(i,k));
						r.insert(pair<int,int>(k,i));
						ans++;
					}
				}
				if(p[k] > p[i]){
					break;
				}
			}
		}
		{
			int m = -1;
			for(int j=1;j<n-1;j++){
				int k = (i+n-j)%n;
				if(p[k] >= m){
					for(int l=0;l<=j;l++){
						printf("%d ",p[(i+n-l)%n]);
					}
					printf("-\n");
					m = p[k];

					if(r.count(pair<int,int>(i,k)) == 0){
						r.insert(pair<int,int>(i,k));
						r.insert(pair<int,int>(k,i));
						ans++;
					}
				}
				if(p[k] > p[i]){
					break;
				}
			}
		}
	}

	if(ans == 1)
		printf("1\n");
	else
		printf("%d\n",ans);
	return 0;
}
