#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int test_Count; cin>>test_Count;
	while(test_Count--){
		long long int n; cin>>n; 
		long long int mat_Arr[n][n];
		for(long long int i=0;i<n;i++)
		{
		 for(long long int j=0;j<n;j++)
		 {
		   cin>>mat_Arr[i][j];
		 }
		}
	 long long int res_Count=0;	
		   for(long long int i=n-1;i>0;i--)
		   {
		   	 long long int op_Yes = 1+mat_Arr[i][i-1];
		   	 if(op_Yes!=mat_Arr[i][i])
		   	 {
		   	 	res_Count++;
		   	 	long long int x = i+1;
		   	 	for(long long int j=0;j<x;j++)
		   	 	{
		   	 		for(long long int k=j;k<x;k++)
		   	 		{
		   	 			long long int temp = mat_Arr[j][k];
		   	 			mat_Arr[j][k] = mat_Arr[k][j];
		   	 			mat_Arr[k][j] = temp;
		   	 		}
		   	 	}
		   	 }
		   }
		 printf("%d",res_Count);
		printf("\n"); 
	}
	return 0;
}