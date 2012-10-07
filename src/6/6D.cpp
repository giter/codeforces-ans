#include <iostream>
using namespace std;

#define N 16
#define INF 0x7fffffff

int n,a,b,p,e;
int h[N];
int s[N*N];

int nbs = INF;
int bs[N*N];

bool is_ans(){

	for(int i=1;i<=n;i++) if(h[i] >= 0){
		return false;
	}

	return true;
}

void dfs(int i){

	if(i>=nbs){
		return;
	}

	if(is_ans()){

		if(i<nbs){
			nbs = i;
			for(int j=0;j<i;j++){
				bs[j] = s[j];
			}
		}

		return ;
	}

	for(int j=(i>0?s[i-1]:2);j<n;j++) {
		if(h[j] >= 0 || h[j-1] >= 0 || h[j+1] >= 0){


			s[i] = j;
			
			h[j] -= a;
			h[j-1] -= b;
			h[j+1] -= b;

			dfs(i+1);

			h[j] += a;
			h[j-1] += b;
			h[j+1] += b;
		}
	}
}

int main(){
	
	cin>>n>>a>>b;
	
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}

	while(h[0] > 0){
		p++;
		h[0] -=b;
		h[1] -= a;
		h[2] -= b;
	}

	while(h[n] > 0){
		e++;
		h[n] -= b;
		h[n-1] -=a;
		h[n-2] -=b;
	}

	dfs(0);


	for(int i=0;i<nbs;i++){
		bs[i+p] = bs[i];
	}

	for(int i=0;i<p;i++){
		bs[i] = 2;
	}

	for(int i=0;i<e;i++){
		bs[nbs+i] = n-1;
	}

	nbs = nbs+p+e;

	cout<<nbs<<endl;

	cout<<bs[0];
	for(int i=1;i<nbs;i++){
		cout<<' '<<bs[i];
	}
	cout<<endl;

	return 0;
}
