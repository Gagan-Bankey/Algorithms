// gagan2001
string next_Balenced_seq( string s )
{
    int depth = 0;
    int open = 0 , close  = 0 ;
   for(int i = s.length()-1 ; i >= 0  ; i-- )
   {
      if( s[i]=='(' ){
         depth--;
         open++;
      }
      else{
         depth++;
         close++;
      }
      if( s[i]=='(' && depth > 0 )
      {
           close--;
         string ans= s.substr(0, i)+")";
         string str ;
         ans+=str.assign(open,'('); 
         ans+=str.assign(close,')');
         s = ans;
         break;
      }
   }
   return s;
}
