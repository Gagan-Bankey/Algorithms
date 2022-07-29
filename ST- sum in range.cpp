#include<bits/stdc++.h>
using namespace std;

 
 vector<int>v;
 vector<int>tree;
 

void build_tree( int n , int tl, int tr )
{
   if( tl == tr )
   	tree[n] = v[tl];
   else
   {
   	int tm = (tl+tr)/2;
     build_tree( (2*n)+1 , tl , tm );
     build_tree( (2*n)+2 , tm+1 , tr );
   	tree[n] = tree[ (2*n)+1 ] + tree[ (2*n)+2 ];
   }

}

int sum_in_range( int n, int tl , int tr , int l, int r )
{
	if( l > r )
		return 0;
	if( tl == l && tr == r )
	{
		return tree[n];
	}
	else
	{
	 int tm = (tl+tr)/2;
	 return	sum_in_range( (2*n)+1 ,  tl , tm , l  ,  min(r,tm) ) +
	 	 	sum_in_range( (2*n)+2 ,  tm+1 , tr , max( l , tm+1) ,  r  ) ;
	}
}

int update_tree( int n, int tl ,int tr, int val ,int pos )
{
   if( tl==tr )
   {
   	  if( tl == pos )
   	  {
   	  	v[pos]=val;
   	  	tree[n] = val;
   	  }
   	  return tree[n];
   }
   else{
      int tm = (tr+tl)/2;
      if( pos <= tm )
   	  update_tree( (2*n)+1 , tl , tm , val , pos);
      else
   	  update_tree( (2*n)+2 , tm+1 , tr , val , pos );
      tree[n] = tree[(2*n)+1]+ tree[(2*n)+2];
   }

}

 int main()
 {
    
    int n;
    cin>>n;
    v.assign(n,0);
    tree.assign(4*n,0);
    for(int i=0;i<n;i++)
    	cin>>v[i];

    
    build_tree(0,0,n-1);

    int l , r;
    cin>>l>>r;
    l--;
    r--;

    cout<< sum_in_range( 0 , 0 , n-1 , l , r )<<endl;

    update_tree( 0 , 0 , n-1 , 6 , 5 );

    for(int i=0 ;i< 4*n ; i++)
    	cout<<tree[i]<<" ";


  return 0;

 }
