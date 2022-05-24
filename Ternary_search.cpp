#include<bits/stdc++.h>
using namespace std;

int ternary_search(int l, int r) {

   // return the MINIMUN value of the functionin [l,r] .
   // The behaviour of the function should  be unimodal ( /\ ) or ( \/ )
   
    int eps = 5;          
    while (r - l >= eps )
   {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int f1 = fun(m1);   
        int f2 = fun(m2);  
        if (f1 >= f2)                 // For maximum change here  >= by <
            l = m1;
        else
            r = m2;
    }
    int minn = INT_MAX;           // For maximum change here
    for( int i =l ; i<=r ;i++ )
      minn = min( minn , fun(i) );    // For maximum change here
   
    return minn;                  
}
