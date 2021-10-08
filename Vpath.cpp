/*<---Rathin R--->*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fora(i, x, n) for(int i = x; i < n; i++)
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
#define ee resize
#define pp(a) (int)(a.size())
#define minele *min_element
#define maxele *max_element 
#define mp(x,y) make_pair(x,y)
#define all(x) x.begin(),x.end()
#define div 1000000007
ll final;
vvi _z;
vll rat,raj;
void sear(int roop,int joi){ rat[roop]=1;
raj[roop]=1;
ll sum=0;
ll ad=0;

fora(i,0,pp(_z[roop]))
{
    ll child=_z[roop][i];
    if(child!=joi){
        sear(child,roop);
        rat[roop]=rat[roop]+((2*rat[child])%div);
        rat[roop]=rat[roop]%div;
        ad=ad+1;
        raj[roop]=raj[roop]+raj[child];
        raj[roop]=raj[roop]%div;
        raj[roop]=raj[roop]+rat[child];
        raj[roop]=raj[roop]%div;
        sum=sum+rat[child];}}

fora(i,0,pp (_z[roop]))
{
    int child=_z[roop][i];
    if(child!=joi)
    {
        raj[roop]+=(rat[child]*((sum-rat[child]+div)%div))%div;
        raj[roop]=raj[roop]%div;
    }}}
int main()
{
ios_base::sync_with_stdio(false); 
cin.tie(NULL); 
cout.tie(NULL);
int t;
 cin>>t;
while(t--)
{
    final=0;
    int n;
    cin>>n;
    _z.ee(n+1);
    rat.ee(n+1);
    raj.ee(n+1);
    fora(i,0,n-1)
    {
        int _c,_w;
        cin>>_c>>_w;
        _z[_c].pb(_w);
        _z[_w].pb(_c);
    }
    sear(1,1);
    ll final=raj[1]%div;
    cout<<final<<"\n";
    rat.clear();
    _z.clear();
    raj.clear();
}
return 0;
}