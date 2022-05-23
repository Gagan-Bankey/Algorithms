#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<iostream>
using namespace std;
using namespace __gnu_pbds; 
typedef long long ll;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

void solve()
{
        
   ll t = 1;
   cin>>t;
   cout<<fixed<<setprecision(10);
 while(t--)
 { 
  ordered_set os;
  os.insert(1);
  os.insert(3);
  os.insert(5);
  
   cout<< os.order_of_key(4); // out put is 2 because it will return the num of element <= 4
  
  cout<<endl;
 }
}
        
int  main() 
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     solve();
  return 0;
}
