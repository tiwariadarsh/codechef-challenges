using namespace std;
#include<bits/stdc++.h>
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,p,k,posx=0;                                                                      
		cin>>n>>x>>p>>k;
		int arr[n];                                                                      
		for(int i=0;i<n;i++)
		cin>>arr[i];                                                    
		sort(arr,arr+n);
		
		for(int i=0;i<n;i++)
		{
				if(arr[i]<=x)
				posx++;
				else
				break;
		}
		
		 
		 if(arr[p-1]==x)
		cout<<0;
		else if(p==k)
		{
			if(p>=posx)
	     	{
	     			cout<<p-posx+1;
	        }
	     	else
			 {	
		
	     	cout<<posx-p;
	    	}
	    	
	    
			
		}
		else if(p<k&&p>=posx)
		{
		cout<<p-posx+1;	
		}
		else if(p>k&&p<=posx)
		{
			cout<<posx-p;
		}
	
     	else
		cout<<-1;
		
		
		
    
    }
}
