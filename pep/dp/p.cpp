#include <bits/stdc++.h> 
#include<map>
#include<vector>
#include<climits>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int gcd(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    return gcd(b%a,a);
}
int fib(int n) {
vector<int>f[n+2];

    int i;
    f[0] = 0;
    f[1] = 1;
 
    for(i = 2; i <= n; i++)
    {
       f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}
int main()
{

    int A=2;
    vector<int>B={1,2,3,1,2,3,5};
    map<int,int>m;
    for(int i=0;i<B.size();i++)
    {
        if(m.count(B[i])==0)
        {
            m[B[i]]=1;
        }
        else
        {
            m[B[i]]++;
        }
        
    }
    
    map<int, int> :: iterator it;
    vector<int>temp;
    int max1=INT_MIN;

     for (it=m.begin(); it!=m.end(); it++) 
  { 
    temp.push_back(it->second);
    max1=max(max1,(it->second/A));
   // cout<<it->second<<" ";
  }
  sort(temp.begin(),temp.end(), greater<int>());
  //cout<<temp.size();
int res;
 
      res=temp[0];
      for(int i=1;i<A;i++)
      {
         res=gcd(temp[i],res);
      }
    //   if(res==1)
    //   {
    //       cout<<1<<endl;
    //   }
    
      cout<<max(res,max1);


  
  


    return 0;
}
