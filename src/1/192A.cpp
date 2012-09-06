#include <map>
#include <cstdio>
using namespace std;

long long n;
map< long long, int > s ;

int main(){

	scanf("%I64d",&n);

	for(int i=1;i*(long long)i<=32*n;i++){
		s[i*(long long)i] = i;
	}

	bool found = false;

	for(int i=1;i*(long long)(i+1)<2*n;i++){
		long long t = 2*n - i*(long long)(i+1);
		if(s[1+4*t]%2 == 1){
			found = true;
			break;
		}
	}

	printf(found?"YES\n":"NO\n");

	return 0;
}
