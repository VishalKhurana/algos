#include<iostream>
#include<vector>
using namespace std;
int binarySearch(int *arr,int s,int e,int ele)
{
    while(s<e)
    {
   int mid=(s+e)/2;
   if(arr[mid]==ele)
   {
       cout<<"found"<<endl;
       return mid;
   }
   else if(ele<arr[mid])
   {
       e=mid-1;

       /* code */

   }
   else
   {
       s=mid+1;
   }
   
    }
    return -1;
   
}
int main()
{
int *arr=new int[10];
for(int i=0;i<10;i++)
{
    int v;
    cin>>v;
    arr[i]=v;

}
int ele=binarySearch(arr,0,9,6);
cout<<ele<<endl;
return 0;
}