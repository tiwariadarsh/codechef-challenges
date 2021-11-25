#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int t;
  cin>>t;
  while(t--){
	int n;
	cin>>n;
	string s, res="No";
    cin>>s;
    for(int i=1; i<n; i++){
        if(s[i]==s[i-1]){
            res="Yes";
            break;
        }
    }
    cout<<res<<endl;
  }
	return 0;
}
