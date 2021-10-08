/*<---Rathin R--->*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fora(i, x, n) for(int i = x; i < n; i++)
#define foru(j, x, n,k) for(int j = x; j < n; j=j+k)
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
const int _Z=4e6+5;
int int_seq[_Z],mem[_Z],r=1;
void preassign(){
    fora(i,0,_Z)
    int_seq[i]=i;
    fora(i,2,_Z)
    {
        if(int_seq[i]==i)
        {  int_seq[i]=i-r;
             foru(j,2*i,_Z,i)
            {
                int_seq[j]=int_seq[j]/i*(i-r); }}}
    fora(i,r,_Z)
    {mem[i]=mem[i]+(i-r);
    foru(j,2*i,_Z,i){
        mem[j]+=(i*((r+int_seq[j/i])/2));}}

}
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL); 
cout.tie(NULL);
preassign();
int t ;
 scanf("%d",&t);
while(t--){
    int k; 
    scanf("%d",&k);
    int final=mem[4*k+1];
    printf("%d\n",final);
}
return 0;
}