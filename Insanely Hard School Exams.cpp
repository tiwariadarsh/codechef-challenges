#include <iostream>
#include<bits/stdc++.h>
using namespace std;


long long int fun(long long int num,int colour,vector<long long int> lines_set[]){
    
    vector<long long int> lines = lines_set[colour];
    for(long long int i=0;i<lines.size() && num>0 ;i++){
        
        long long int temp = min(lines[i],num);
        lines[i] = lines[i] - temp;
        num = num - temp;
    
    }
    
    if(num>0){
        return 0;
    }
    
   
    
    long long int sum1 = 0; 
    long long int k = lines.size();
    for (int i=0; i<k; i++) 
        sum1 += lines[i]; 
  
    long long int sum2 = 0; 
    long long int temp[k+1]; 
    for (long long int i=0; i<k; i++) 
    { 
        temp[i] = lines[i]*(sum1-lines[i]); 
        sum2 += temp[i]; 
    } 
    sum2 /= 2; 
  
    long long int sum3 = 0; 
    for (long long int i=0; i<k; i++) 
        sum3 += lines[i]*(sum2-temp[i]); 
    sum3 /= 3; 
  
    return sum3;
}


int main() {
    long long int t;
    cin>>t;
    
    while(t--){
       long long int N,C,K;
       cin>>N>>C>>K;
       
       unordered_map<long long int,int> colour[C+1];
       
       vector<long long int> lines[C+1];
       
       for(int i=1;i<=N;i++){
           long long int a,b,col;
           cin>>a>>b>>col;
           
          
           colour[col][a]++;
       }
       
       long long int V[C+1]={0};
       for(long long int i=1;i<=C;i++){
           cin>>V[i];
       }
       
       
       for(long long int i=1;i<=C;i++){
           vector<long long int> lines_set;
           for(auto it : colour[i]){
               lines_set.push_back(it.second);
           }
          sort(lines_set.begin(),lines_set.end());
           lines[i] = lines_set;
       }
 
       
       long long int dp[K+1][C+1];
       long long int fun_mem[K+1][C+1];
       for(int i=0;i<=K;i++){
           for(long long int j=0;j<=C;j++){
               dp[i][j] = LLONG_MAX;
               if(j==0){
                   dp[i][j]=0;
               }
               
               fun_mem[i][j] = -1;
           }
       }
       
       for(long long int i=0;i<=K;i++){
       
           for(long long int j=1;j<=C;j++){
               long long int max_lines_rem = i/V[j];
               for(long long int k=0;k<=max_lines_rem;k++){
                   
                   long long int val_rem = k*V[j];
                  if(fun_mem[k][j]==-1){
                       fun_mem[k][j] = fun(k,j,lines);
                     
                  }
                   
                   dp[i][j] = min(dp[i][j] , dp[i-val_rem][j-1] + fun_mem[k][j] );
                
               }
           }
       }
       
    
      cout<<dp[K][C]<<"\n";
       
       
    }
  return 0;
}