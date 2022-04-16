// @Gagan2001
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// LCS using Tabulation

void solve()
{
   string s1,s2;
   cin>>s1>>s2;
   s1 = " "+s1;
   s2 = " "+s2;

   int n,m;
   n = s1.length();
   m = s2.length();
   vector<vector<int>>dp(  n , vector<int>(m,0) );

  for(int i = 1 ; i < n ; i++ )
  {
     for(int j = 1; j < m ; j++ )
     {
       if( s1[i]==s2[j] )
       dp[i][j]= 1 + dp[i-1][j-1];
       else
       {
         dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
       }
     }
  }

cout<<dp[n-1][m-1];
 
}

int main()
{ 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  solve();

  return 0;
}

