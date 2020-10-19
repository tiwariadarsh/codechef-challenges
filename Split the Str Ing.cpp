#include<iostream>
using namespace std;
int main()
{  int t;
   cin>>t;
   for(int i=1;i<=t;i++)
   {
       int n;
       cin>>n;
       string s;
       cin>>s;
       int temp=0;
       for(int j=0;j<n-1;j++)
       {
         if(s[j]==s[n-1]) {cout<<"YES"<<endl; temp++; break;}
       }
       if(temp==0) cout<<"NO"<<endl;
   }
   return 0;
}
