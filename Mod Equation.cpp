/*<---Rathin R--->*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fora(i, x, n) for(int i = x; i <=n; i++)
#define foru(i,x,n,k)   for(int i=x;i<=n;i=i+k)
#define fors(i, x, n) for(int i = x; i >= n; i--)
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double>
#define vpii vector<pair< int, int > >
#define vpll vector<pair< long long, long long > >
#define vvi vector<vector< int > >
#define vvll vector<vector<long long > >
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define seti set<int> 
#define setll set<long long>
#define mii map<int, int>
#define mll map<long long, long long>
#define pb push_back
#define fs first
#define ss second
#define minele *min_element
#define maxele *max_element 
#define mp(x,y) make_pair(x,y)
#define all(x) x.begin(),x.end()
#define mod 1000000007
int main()
{
ios_base::sync_with_stdio(false); 
cin.tie(NULL); 
cout.tie(NULL);
ll t,n,m;
 cin>>t;
while(t--){   
    ll final=0;
    cin>>n>>m;
    vll arr(n+1,1); //creating a vector of size n+1 with all values initialized to 1
    fora(k,2,n){
        ll factor=m%k;
        final=final+arr[factor];
        foru(z,factor,n,k){
          arr[z]=arr[z]+1;}}
    cout<<final<<"\n";}
return 0;
}