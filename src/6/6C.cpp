#include <iostream>
using namespace std;

int n;
int c[100001];
int na,nb;
int a,b;
int ca,cb;

int main(){
	ca = cb = a = b = na = nb = 0;

	cin>>n;
	nb = n-1;
	
	for(int i=0;i<n;i++)
		cin>>c[i];

	while(na<=nb){
		if(ca==cb || ca < cb){
			ca += c[na];
			a++;
			na++;
		}else{
			cb += c[nb];
			b++;
			nb--;
		}
	}

	cout<<a<<' '<<b<<endl;

	return 0;
}
