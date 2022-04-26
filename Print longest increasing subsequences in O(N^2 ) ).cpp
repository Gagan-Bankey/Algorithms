// gagan2001
#include<bits/stdc++.h>
using namespace std;

// printing longest increasing subsequence  in O(n^2) 

void print_LIS( vector<int>&a )
{    
	 int n = a.size();
     vector<int>dp(n,1);     // for length of LIS ending at i
     vector<int>hash(n);     // for index of prev element of the LIS ending at i

  	for(int i =0 ;i<n;i++)
   		hash[i]=i;
  	
  	int bigest=0;

  	for(int i=0 ; i < n; i++)
  	{
  		for (int j = 0; j < i; j++)
  		{
              if( a[i] > a[j] )
              {
              	 if( dp[j]+1 > dp[i] )
              	 {
              	 	dp[i] = dp[j]+1;
              	 	hash[i]= j;
              	 }
              }
  		}
      if( dp[bigest] < dp[i] )
      	bigest=i;

  	}

   vector<int>lis;
   lis.push_back( a[bigest] );
   while( hash[bigest] != bigest )
   {
   	   lis.push_back( a[hash[bigest]] ) ;
   	   bigest = hash[bigest];
   }
   reverse( lis.begin() , lis.end() );

   for(int i =0 ; i<lis.size() ;i++)
   	cout<<lis[i]<<" ";

}

int main()
{
     int n;
     cin>>n;
     vector<int>v(n);
     for(int i=0;i<n;i++)
     {
        cin>>v[i];
     }

     print_LIS(v);
}
