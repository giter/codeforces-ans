#include <iostream>
using namespace std;

int main(){

	long long a;
	int v[20];
	int nv = 0;

	cin>>a;

	int r = 0;
	int s = 1;

	while(a>0){
		v[nv++] = a%10;
		a /= 10;
	}

	for(int i=nv-1;i>=0;i--){
		if(v[i] > 1){
			for(int j=i;j>=0;j--)
				v[j] = 1;
			break;
		}
	}

	for(int i=0;i<nv;i++){
		r += v[i]*s;
		s *= 2;
	}

	cout<<r<<endl;

	return 0;
}