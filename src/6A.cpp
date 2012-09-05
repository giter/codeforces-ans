#include <iostream>
using namespace std;

int main(){
	int a[4];
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	int type = 0;
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
			for(int k=j+1;k<4;k++){
				if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j] && a[j]+a[k]>a[i]){
					type = 1;
				}else if(a[i]+a[j]==a[k] || a[i]+a[k]==a[j] || a[j]+a[k]==a[i]){
					if(type==0){
						type = 2;
					}
				}
			}
		}
	}
	switch(type){
		case 2:
			cout<<"SEGMENT"<<endl;
			break;
		case 1:
			cout<<"TRIANGLE"<<endl;
			break;
		default:
			cout<<"IMPOSSIBLE"<<endl;
			break;
	}
	return 0;
}
