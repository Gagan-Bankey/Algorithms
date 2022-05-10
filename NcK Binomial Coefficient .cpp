// precompution in O(n) + modinverse IN O(logn) 
// each query in log(n) , great!

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1000000007;

vector<ll>factorial;
void preComputeFactorial( ll n , ll m)
{
   factorial.assign(n+1,1);
   factorial[0]=1;
   for( ll i = 1 ; i <= n ; i++ )
   {
   	 factorial[i] = (factorial[i-1]*i) % m ;
   }
}

ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
     if (x < 0)
        x += m0;
    return x;
}

ll NcK(  ll n , ll k )  // nck  
{
   return ( factorial[n]* modInverse( (factorial[k]*factorial[n-k]) % mod  , mod ) ) % mod ;
}


int  main()
{

	ll n,k; // nck = ( n!/(k! * (n-k)! ) )

    cin>>n>>k;
	preComputeFactorial(n,mod);
	cout<<NcK(n,k);

   return 0;
}
