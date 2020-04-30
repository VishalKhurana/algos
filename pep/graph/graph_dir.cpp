#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Edge
{
 public:
int v;
int w;
Edge(int v,int w)
{
    this->v=v;
    this->w=w;
}
};
int s=3;

vector<vector<Edge*>>graph;


void display()
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"->";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<"("<<graph[i][j]->v<<","<<graph[i][j]->w<<")"<<" ";
        }
        cout<<endl;

    }
}
void addEdge(int u,int v,int w)
{
    if(u<0||v<0||v>=graph.size()||u>=graph.size())
    {
        return;
    }
    graph[u].push_back(new Edge(v,w));
    graph[v].push_back(new Edge(u,w));


}

int count_special(int n,int m,int p,int q)
{
    int count=0;
    int flag=0;
//cout<<graph.size()<<endl;
   for(int i=0;i<graph.size();i++)
   {
       flag=0;
    //    cout<<1<<endl;
       if(graph[i].size()<2)
           {
               continue;
           }
       int neighbour=graph[i].size();
      // cout<<neighbour<<endl;
       for(int j=0;j<graph[i].size();j++)
       {
        //    int neighbour=graph[i].size();
           
           int n1=graph[i][j]->v;
           for(int k=0;k<graph[i].size();k++)
           {
               int n2=graph[i][k]->v;
               if(k==j)
               {
                   continue;
               }
              if(((p*graph[n1].size())<neighbour)&&(neighbour<(q*graph[n2].size())))
              {
                  flag=1;
              }
              else if(((q*graph[n1].size())<neighbour)&&(neighbour<(p*graph[n2].size())))
              {
                  flag=1;
              }
              else if(((p*graph[n1].size())>neighbour)&&(neighbour>(q*graph[n2].size())))
              {
                  flag=1;
              }
              else if(((q*graph[n1].size())>neighbour)&&(neighbour>(p*graph[n2].size())))
              {
                  flag=1;
              }
           }


       }
       if(flag==1)
       {
           count++;
           
       }
   }
  return count;
}


void solve()
{
    for(int i=0;i<7;i++)
{
  vector<Edge*>ar;
  graph.push_back(ar);
}
addEdge(1,2,10);
addEdge(2,3,10);
addEdge(3,4,10);
addEdge(4,5,10);
addEdge(5,6,40);
// addEdge(3,4,2);
// addEdge(4,5,2);
// addEdge(4,6,3);
// addEdge(5,6,8);


}
void dfs(int u,vector<bool>&visited,stack<int>&s)
{
   // cout<<"1";
    visited[u]=true;
  for(int i=0;i<graph[u].size();i++)
  {
      if(!visited[graph[u][i]->v])
      {
          //visited[graph[u][i]->v]=true;
          dfs(graph[u][i]->v,visited,s);

          
      }
      
  }
  s.push(u);
  

}
void helper()
{
    stack<int>s;
    vector<bool>visited(7,false);
    for(int i=0;i<7;i++)
    {
         if(!visited[i])
         {
             
         dfs(i,visited,s);
         
         }
    }
  //  cout<<s.size();
    while(s.size()>0)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

/*void topological(int u,bool*vis)
{ int count=0;
    for(int i=0;graph[u].size();i++)
    {
        if(!vis[graph[u][i]->v])
        {
            break;
        }
        else if(count==graph[u].size())
        {
            return;
        }
        else
        {
            count++;
            continue;
        }
        

    }
   stack<int>s;
   s.push(u);
//  bool*visited= new bool[7];
 
 for(int i=0;i<graph[u].size();i++)
 {
    stack<int>s1;
    s1.push(graph[u][i]->v);
    if(!vis[graph[u][i]->v])
    {
            topological(graph[u][i]->v,vis);
            vis[graph[u][i]->v]=true;
            s1.pop();
    }



 }


}*/

int main()
{

solve();
//display();
//bool*visited= new bool[7];
// helper();

cout<<count_special(6,5,1,2);
cout<<endl;
// display();



}
