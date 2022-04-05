// Gagan2001
// String Hashing
// hash["abcd"] = 97*p + 98*p^2 + 99*p^3 + 100*p^4
 
#include<bits/stdc++.h>
using namespace std;


long long POW(long long a, long long b)    // for calculation power efficiently in log
{ 
   unsigned long long res = 1;
   while (b > 0)
   {    if(b & 1)
        res = res * a ;  
        a = a * a;
        b >>= 1;
   } 
     return res;
}

vector<unsigned long long>hash_;       // stores the hash value of the prefixes 
                                       // by using it we can calculate hash of the substring efficiently
unsigned long long p = 13331 ;         // assign according to your convinence 

void compute_hash_Ofprefix( string s )
{   // require vector hash_ declared above
	hash_.push_back(0);
	unsigned long long hash_value = 0;
	for( int i = 0 ;  i < s.length() ; i++ )
	{	
		hash_value = (p*hash_value)+int(s[i]);
		hash_.push_back(hash_value);
	}
}

long long compute_hash_Of_subString( long long i , long long j )
{
 unsigned long long hash_value =0;
 hash_value = hash_[j+1] - ( hash_[i]* POW( p , j-i+1 ) );
 
 return hash_value;
}


long long compute_hash(string s )
{
	unsigned long long mod,p,hash_value;

	for(int i=0;i< s.length() ;i++)
     hash_value=(p*hash_value)+int(s[i]);

	return hash_value ;
}


int main()
{
  
 // use this functions
 
 // Happy Coding `:)
 return 0;
}
