// gagan2001

#include<bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> bit;   int n;

    BIT(int n) {  this->n = n;  bit.assign(n, 0);   }

    BIT(vector<int> a) : BIT(a.size()) {    for (size_t i = 0; i < a.size(); i++)  add(i, a[i]);}

    int sum(int r) {   int ret = 0;    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r]; return ret; }
   
    int sum(int l, int r) {   return sum(r) - sum(l - 1); }
   
    void add(int idx, int delta) {     for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta; }
};

int main()
{

  int n;
  cin>>n;

  BIT *tree = new BIT(n); 
  
  tree->add( 3 , 1 ); // add value 1 at index 3 ( 0-based ) in log(n) 

  cout<<tree->sum(9); // return sum from 0 to 9 (0-based) in log(n)
  
  return 0;
}
