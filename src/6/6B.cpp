#include <cstdio>
using namespace std;

int n,m;
char cp;
char p[2];
char ma[101][101];
int  s[256] = {0};

int main(){

	scanf("%d%d%s\n",&n,&m,&p);
	cp = p[0];

	for(int i=0;i<n;i++){
		scanf("%s",ma[i]);
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ma[i][j] != cp && ma[i][j] != '.'){
				if( 
					(i>0 && ma[i-1][j] == cp)
					||
					(j>0 && ma[i][j-1] == cp)
					|| 
					(i<n-1 && ma[i+1][j] == cp)
					||
					(j<m-1 && ma[i][j+1] == cp)
				){
					s[ma[i][j]] = 1;	
				}
			}
		}
	}

	int v = 0;
	for(int i=0;i<256;i++){
		v += s[i];
	}

	printf("%d\n",v);

	return 0;
}
