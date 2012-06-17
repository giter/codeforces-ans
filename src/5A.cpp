#include <iostream>
#include <map>
#include <string>
using namespace std;

int n;
string s;
map<string,int> m;

int main(){
	while(true){
		getline(cin,s);

		if(cin.fail()){
			break;
		}

		if(s[0] == '+'){
			m[(s.substr(1))] = 1;
		}else if(s[0] == '-'){
			m.erase((s.substr(1)));
		}else{
			n += m.size() * s.substr(s.find(':') + 1).size();
			//cout<<(s.substr(s.find(':')+1))<<endl;
		}
	}
	cout<<n<<endl;
}
