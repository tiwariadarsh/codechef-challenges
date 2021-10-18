#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a;
	    vector<int>arr,brr;
	    cin>>a;
	    if(a%4!=0){cout<<"NO"<<endl;
	        
	    }
	    else {
	    for(int i=1;i<=a/2;i=i+2){
	        arr.push_back(i);
	        brr.push_back(i+1);
	    }
	    for(int i=(a/2)+1;i<=a;i=i+2)
	    {
	        brr.push_back(i);
	        arr.push_back(i+1);
	    }
	    cout<<"YES"<<endl;
	    sort(arr.begin(),arr.end());
	    sort(brr.begin(),brr.end());
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
	cout<<endl;
	for(int i=0;i<brr.size();i++)cout<<brr[i]<<" ";
	cout<<endl;
	}

	}
	return 0;
}
