//gagan2001
#include<bits/stdc++.h>
using namespace std;

// Return the length of the longest increasing subsequence  in O(N.logN) .

int longestIncreasingSubsequence( vector<int>arr , int n )
{
     vector<int>a;
     a.push_back( arr[0] );
	   for(int  i=1 ; i<n ; i++ )
	   {
      int lb = lower_bound(a.begin(),a.end(),arr[i])-a.begin();
	  
      if( lb == a.size() )
	    a.push_back(arr[i]);
		  else
	  	a[lb]=arr[i];
	   }
  
    	return a.size();
}
