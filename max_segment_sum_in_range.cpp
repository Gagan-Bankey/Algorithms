//@gagan2001
#include<bits/stdc++.h>
using namespace std;

vector<int>arr;  // Given Array

struct node{
 int pre , suf , full , maxx ; 
};

vector<node>tree;

node combine( node l , node r )
{
	node n;
	n.suf  = max( r.suf , r.full+ l.suf );
	n.pre  = max( l.pre , l.full+ r.pre );
	n.full = l.full + r.full ;
	n.maxx = max( l.suf+r.pre  , max( r.maxx , l.maxx ) );
    return n;
}

node build_tree( int n , int tl , int tr )
{
  if(tl==tr)
  {
     tree[n] = { arr[tl] , arr[tl] , arr[tl] , arr[tl] };
     return tree[n];
  }

  int tm = (tl+tr)/2;
  build_tree( (2*n)+1 , tl , tm );
  build_tree( (2*n)+2 , tm+1 ,tr);
  tree[n] = combine( tree[(2*n)+1] , tree[(2*n)+2] );
  return tree[n];
}


node query( int n, int tl, int tr , int l , int  r)
{
    if( l > r )
    	return {0,0,0,0};
    
    if( tl==l && tr==r )
    return tree[n];
    
    int tm = (tl+tr)/2;
    node a = query( (2*n)+1 ,  tl , tm , l , min( tm , r )  ) ;
    node b = query( (2*n)+2 , tm+1 , tr , max( tm+1 , l ) , r );  
   return combine(a,b);

}


int main()
{
  int n;
  cin>>n;
  arr.assign(n,0);
  tree.assign(4*n,{0,0,0,0});
  
  for( int i=0;i<n;i++ )
  	cin>>arr[i];

  build_tree(0,0,n-1);

  int l,r;
  cin>>l>>r; // 0 indexed

  node a = query(0,0,n-1,l,r);
  cout<< a.maxx;
  
}