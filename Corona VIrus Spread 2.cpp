#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	 cin>>t;
	 while(t--){
	 	int n, mx=1, mn=6, count=0;
	 	cin>>n;
	 	vector<int> v(n);
	 	vector<pair<int, int>>o(n);
	 	for(int i=0; i<n; i++){
	 		cin>>v[i];
	 		o[i]=make_pair(v[i], i);
		 }
	 	sort(o.begin(), o.end());
	 	for(int k=0; k<n; k++){
		 	vector<bool> p(n, 0);
	 		p[k]=1;
	 		count=0;
	 		for(int i=0; i<n; i++){
	 			int pos=o[n-1-i].second;
	 			for(int j=pos+1; j<n; j++){
	 				if(v[pos]>v[j] && (p[pos]==1 || p[j]==1)){
	 					p[pos]=1;p[j]=1;
				 	}
			 	}
			 }
			for(int i=0; i<n; i++){
				if(p[i]==1)
				 	count++;
			}
			mx=max(mx, count);
			mn=min(mn, count);		
		 }
		 cout<<mn<<" "<< mx<<"\n";
	 }
	return 0;
}