#include<bits/stdc++.h>
using namespace std;
int problem()
{
    long int value,x ,c=0,y,p,xr,j,s;
    cin>>value>>x;

    long int rat[value+1];

    for(long long int c=0;c<value;c++)
    {
        cin>>rat[c];
    } 

    for(y=x;y>0&&c<value-1;y--)
    {
        int flag = 0;
        p = log2 (rat[c]);
        xr =1<<p;
        rat[c]=rat[c]^xr;

        for(j=c+1;j<value;j++)
        {
            if ((rat[j]^xr)<rat[j])
            {
                rat[j]=rat[j]^xr;
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            rat[value-1]=rat[value-1]^xr;
        }

        while (rat[c]<=0)
        {
            c++;
        }
    }

        s=y+1;

        if(s>0)
        {
            if((value<3)&&(s%2==0)&&s>0)
            {
                rat[value-1]=rat[value-1]^1;
                rat[value-2]=rat[value-2]^1;
            }
        }
    

    for (int i=0;i<value;i++)
    {
        cout<<rat[i]<<" ";
    }

    cout<<"\n";
    return 0 ;

}


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
	cout.tie(NULL);

	int t;
    cin>>t;
    while(t--)
    {
	
        problem();
    }
    
}s