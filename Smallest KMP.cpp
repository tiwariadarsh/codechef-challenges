#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	 int ans=0;
     string s,p;
     cin>>s>>p;
     map<char,int> m;
     for(int i=0;i<s.size();i++){
     	m[s[i]]++;
	 }
	 char k=p[0];
	 int f=0;
	 map<char,int>::iterator itr;
	 for(int i=0;i<p.size();i++){
	 	m[p[i]]--;
	 	if(p[i]!=p[0]&&f==0){
	 		k=p[i];
	 		f=1;
		 }
	 }
	 
	 for(itr=m.begin();itr!=m.end();itr++)
	 {
	 	if(itr->first==p[0]&&ans==0)
	 	{
	 		if(itr->first>k)
	 		{
	 			cout<<p;
	 			ans=1;
			 }
		 }
	 	if(itr->first>p[0]&&ans==0)
	 	{
	 		cout<<p;
	 		ans=1;
		 }
	 	for(int i=0;i<itr->second;i++)
	 	{
	 		cout<<itr->first;
		 }
	 }
	 if(ans==0)
	 {
	 	cout<<p;
	 }
	 cout<<"\n";
	}
	return 0;
}