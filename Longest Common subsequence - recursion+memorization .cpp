// @Gagan2001
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>>dp; 
int longestCommonSubsequence(string &text1 , string &text2, int i , int j)
{
   
        if( i<0 || j<0 )
        return 0;
 
        if( dp[i][j]!=-1 )  
        return dp[i][j];
        
        int x ;
        if( text1[i] == text2[j] )
        {
          x = longestCommonSubsequence( text1 , text2 , i-1 , j-1 )+1;
        }
        else
        {
          x = max( longestCommonSubsequence( text1 , text2 , i-1 , j ) ,  longestCommonSubsequence( text1 , text2 , i , j-1 ) ) ;
        }
     
       dp[i][j]=x;
       return dp[i][j];
    }
 
void solve()
{
   string s1,s2;
   cin>>s1>>s2;
   dp.assign( s1.length() , vector<int>(s2.length() , -1 ) );
   cout<< longestCommonSubsequence(s1,s2, s1.length()-1 , s2.length()-1  )  ;  
   cout<<endl;
}

int main()
{ 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  solve();

  return 0;
}
