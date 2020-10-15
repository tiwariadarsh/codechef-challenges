#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> pp;
bool com(pp x,pp y){
    return x.ff<y.ff;
}
class data{
    public:
        int p,q,r;
};
bool comp(data x,data y){
    return x.r<y.r;
}
ll power(ll x,ll y){
    ll prod=1;
    while(y){
        if(y&1) prod=(prod*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return prod;
}
const int N=1e5+9;
int find(int u,vector<int> &par){
    if(par[u]==-1) return u;
    return par[u]=find(par[u],par);
}
void merge(int u,int v,vector<int> &par){
    par[u]=v;
}
void solve(){
	int n,d;
    cin>>n>>d;
    int x[n][d];
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++) cin>>x[i][j];
    }
    vector<vector<pp>> a(1ll<<d);
    int b[n][1ll<<d];
    for(int i=0;i<n;i++){
        int sum=0,y;
        for(int j=0;j<d;j++) sum+=x[i][j];
        y=sum;
        for(int j=0;j<(1ll<<d);j++){
            sum=y;
            for(int k=0;k<d;k++){
                if((1ll<<k)&j){
                    sum-=(2*x[i][k]);
                }
            }
            a[j].pb({sum,i+1});
            b[i][j]=sum;
        }
    }
    for(int i=0;i<(1ll<<d);i++)
        sort(a[i].begin(),a[i].end(),com);
    vector<data> arr;
    for(int i=0;i<n;i++){
        for(int j=0;j<(1ll<<d);j++){
            int s=b[i][j];
            int mx=s-a[j][0].ff;
            data d;
            d.p=i+1;
            if(mx>=0){
                d.q=a[j][0].ss;
                d.r=mx;
                arr.pb(d);
            }
            mx=s-a[j][n-1].ff;
            if(mx>=0){
                d.q=a[j][n-1].ss;
                d.r=mx;
                arr.pb(d);
            }
        }
    }
    sort(arr.begin(),arr.end(),comp);
    vector<int> par(n+1,-1);
    ll ans=0;
    for(int i=arr.size()-1;i>=0;i--){
        data pqr=arr[i];
        int u=find(pqr.p,par);
        int v=find(pqr.q,par);
        if(u!=v){
            merge(u,v,par);
            ans+=pqr.r;
        } 
    }
    //for(int i=1;i<=n;i++) cout<<par[i]<<" ";
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int t=1;
	//cin>>t;
	while(t--) 
	    solve();
	return 0; 
}