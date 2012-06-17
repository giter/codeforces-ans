#include <string>
#include <iostream>
using namespace std;

int n,m;
string s[1024];

void o(int n,char c){
	while(n--){
		cout<<c;
	}
}

int main(){

	m = 0;
	n = 0;
	while(true){
		getline(cin,s[m++]);
		if(cin.fail()){
			m--;
			break;
		}

		if(s[m-1].size() > n){
			n = s[m-1].size();
		}
	}

	o(n+2,'*');
	cout<<endl;
	
	int alt = 1;
	for(int i=0;i<m;i++){
		cout<<'*';
		
		if((n-s[i].size())%2 == 1){

			if(alt){
				o((n-s[i].size())/2,' ');
			}else{
				o(n-s[i].size()-(n-s[i].size())/2,' ');
			}

			cout<<s[i];

			if(alt){
				o(n-s[i].size()-(n-s[i].size())/2,' ');
			}else{
				o((n-s[i].size())/2,' ');
			}

			cout<<'*';
			cout<<endl;
			alt = alt == 0 ? 1 : 0;
		}else{
			o((n-s[i].size())/2,' ');
			cout<<s[i];
			o((n-s[i].size())/2,' ');
			cout<<'*';
			cout<<endl;
		}
		
	}

	o(n+2,'*');
	cout<<endl;

}


