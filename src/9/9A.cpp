#include <iostream>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))

int gcd(int a,int b){
	return a % b == 0 ? b : gcd(b,a%b);
}

int main(){

	int a,b,k;
	cin>>a>>b;

	k = 6 - max(a,b) + 1;

	cout<< k/gcd(k,6) << '/' << 6/gcd(k,6) <<endl;

	return 0;
}




