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
int t;
 cin>>t;
 string a,b,c;
while(t--)
{    int final=0,countx=0,counto=0,countwinx=0,countwino=0,countemp=0,flag=0;
    cin>>a>>b>>c;

    //checking win and empty spaces
    if((a[0]=='X'&&a[1]=='X'&&a[2]=='X')||(a[0]=='O'&&a[1]=='O'&&a[2]=='O'))
    {   flag++;
        if(a[0]=='X')
        countwinx++;
        if(a[0]=='O')
        countwino++;

  
    
    }


    if((b[0]=='X'&&b[1]=='X'&&b[2]=='X')||(b[0]=='O'&&b[1]=='O'&&b[2]=='O'))
    {
        if(b[0]=='X')
        countwinx++;
        if(b[0]=='O')
        countwino++;
    
    }

    if((c[0]=='X'&&c[1]=='X'&&c[2]=='X')||(c[0]=='O'&&c[1]=='O'&&c[2]=='O'))
    {
        if(c[0]=='X')
        countwinx++;
        if(c[0]=='O')
        countwino++;
   
    }

    if(((a[0]=='X'&&b[0]=='X'&&c[0]=='X')||(a[0]=='O'&&b[0]=='O'&&c[0]=='O')))
    {  
        if(a[0]=='X')
        countwinx++;
        if(a[0]=='O')
        countwino++;
           
    }


    if(((a[1]=='X'&&b[1]=='X'&&c[1]=='X')||(a[1]=='O'&&b[1]=='O'&&c[1]=='O')))
    {
        if(a[1]=='X')
        countwinx++;
        if(a[1]=='O')
        countwino++;
        
    }



       if(((a[2]=='X'&&b[2]=='X'&&c[2]=='X')||(a[2]=='O'&&b[2]=='O'&&c[2]=='O')))
    {
        if(a[2]=='X')
        countwinx++;
        if(a[2]=='O')
        countwino++;
        
    }
       if(((a[0]=='X'&&b[1]=='X'&&c[2]=='X')||(a[0]=='O'&&b[1]=='O'&&c[2]=='O')))
    {
        if(a[0]=='X')
        countwinx++;
         if(a[0]=='O')
        countwino++;
       
    }



       if(((a[2]=='X'&&b[1]=='X'&&c[0]=='X')||(a[2]=='O'&&b[1]=='O'&&c[0]=='O')))
    {
        if(a[2]=='X')
        countwinx++;
        if(a[2]=='O')
        countwino++;
    }


  for(int i=0;i<=2;i++)
  {
      if(a[i]=='_')
      countemp++;
       if (b[i]=='_')
      countemp++;
       if(c[i]=='_')
      countemp++;
       if(a[i]=='X')
      countx++;
       if(b[i]=='X')
      countx++;
       if(c[i]=='X')
      countx++;
        if(a[i]=='O')
      counto++;
       if(b[i]=='O')
      counto++;
       if(c[i]=='O')
      counto++;
  }

if((countwinx==1&&countwino==1)||(countx-counto<0)||(countx-counto>1))
final=3;
else if(countx==0&&counto==0&&countemp==9)
final=2;
else if(countwinx==1&&countwino==0&&countx>counto)
final=1;
else if(countwinx==0&&countwino==1&&countx==counto)
final=1;
else if(countwinx==0&&countwino==0&&countemp==0)
final=1;
else if(countwinx==0&&countwino==0&&countemp>0)
final=2;
else if(countwinx==2&&countwino==0&&countemp==0)
final=1;
else
final=3;


cout<<final<<"\n";

}

return 0;
}