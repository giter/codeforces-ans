#include <iostream>
using namespace std;

int main(){

  int n,m,ans=4,k;
  cin>>n>>m;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>k;
      if(k == 1 && (i==0||i==n-1||j==0||j==m-1)){
        ans=2;
      }
    }
  }

  cout<<ans<<endl;

  return 0;
}
