#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<list>
using namespace std;
queue<int>q;

class Edge
{
    public:
    int v=0;
    int w=0;
    Edge(int v,int w)
    {
        this->v=v;
        this->w=w;
    }
    Edge()
    {}

};
vector<vector<Edge*>>graph;
vector<vector<Edge*>>dgraph;
void addEdge(int u,int v,int w)
{
  if(u<0||v<0||v>=graph.size()||u>=graph.size())
  {
      return;
  }
  graph[u].push_back(new Edge(v,w));
  graph[v].push_back(new Edge(u,w));
}
void addEdge02(int u,int v,int w)
{
  if(u<0||v<0||v>=dgraph.size()||u>=dgraph.size())
  {
      return;
  }
  dgraph[u].push_back(new Edge(v,w));
  dgraph[v].push_back(new Edge(u,w));
}
void solve()
{
    
    for(int i=0;i<7;i++)
    {
        vector<Edge*>ar;
    graph.push_back(ar);

    vector<Edge*>ar1;
    dgraph.push_back(ar1);
    }
         addEdge(0,3,10);
        addEdge(0,1,10);
        addEdge(1,2,10);
        addEdge(2,3,40);
        addEdge(3,4,2);
       addEdge(4,5,2);
        addEdge(4,6,3);
        addEdge(5,6,8);
}
class partite_pair
{
    public:
    int vtx=0;
    int color=0;
    partite_pair()
    {

    }
    partite_pair(int vtx,int color)
    {
        this->color=color;
        this->vtx=vtx;
    }
};
void display02()
{
    for(int i=0;i<dgraph.size();i++)
    {
        cout<<i<<"->";
        for(int j=0;j<dgraph[i].size();j++)
        {
            cout<<"("<<dgraph[i][j]->v<<" "<<","<<dgraph[i][j]->w<<")";
        }
        cout<<endl;
    }
}
class dpair
{
    public:
    int wt;
    int wsf;
    string psf="";
    int vtx=0;
    int pvtx=-1;
    dpair(int wt,int wsf,string psf,int vtx,int pvtx)
    {
        this->wt=wt;
        this->wsf=wsf;
        this->psf=psf;
        this->vtx=vtx;
        this->pvtx=pvtx;
    }
    dpair()
    {

    }
    bool operator<(const  dpair & o  )const {
    return this->wsf>o.wsf;
   
}
};
void dijkstra(int src)
{
    vector<bool>visited(graph.size(),false);
    priority_queue<dpair>q;
    dpair root(0,0,"",src,-1);
    int des=6;
    q.push(root);
    while(q.size()>0)
    {
        dpair rpair=q.top();
        q.pop();
        if(visited[rpair.vtx])
        {
            continue;
        }
        if(rpair.vtx==des)
        {
            cout<<rpair.psf<<"->"<<"weight"<<rpair.wsf<<endl;
        }
        if(rpair.pvtx!=-1)
        {
            addEdge02(rpair.vtx,rpair.pvtx,rpair.wt);

        }

visited[rpair.vtx]=true;
  for(Edge*e:graph[rpair.vtx])
  {
      if(!visited[e->v])
      {
          dpair npair(e->w,rpair.wsf+e->w,rpair.psf+" ->"+to_string(e->v),e->v,rpair.vtx);
          q.push(npair);
      }
  }
    }
    display02();
}

bool bipartite(int src,vector<int>&vis)
{
    list<partite_pair>queue;
    queue.push_back(partite_pair(src,0));

       while(queue.size()>0)
       {
           partite_pair rpair=queue.front();
           queue.pop_front();
           vis[rpair.vtx]=rpair.color;
           if(vis[rpair.vtx]!=-1)
           {
               if(vis[rpair.vtx]!=rpair.color)
               {
                   cout<<rpair.vtx<<" "<<" not a bipartite"<<endl;
               }
               else
               {
                   cout<<rpair.vtx<<" ";
               }
               
           }
           for(Edge* e:graph[rpair.vtx])
           {
               if(!vis[e->v]==-1)
               {
                   partite_pair npair(e->v,(rpair.color+1)%2);
                   queue.push_back(npair);
               }
           }
       } 
}
int ltwt=INT_MAX;
string fans="";
void light(int src,int des,int wt,vector<bool>&vis,string ans)
{
    if(src==des)
    {
         if(ltwt>wt)
         {
             fans=ans;
             ltwt=wt;
         }

    }
    vis[src]=true;
    for(int i=0;i<graph[src].size();i++)
    {
        if(!vis[graph[src][i]->v])
        {
           vis[graph[src][i]->v]=true;
           light(graph[src][i]->v,des,wt+graph[src][i]->w,vis,ans+to_string(graph[src][i]->v)+"");
            vis[graph[src][i]->v]=false;
        }


    }

}
int ltwt_h=INT_MIN;
string fans_h="";
void heavy(int src,int des,int wt,vector<bool>&vis,string ans)
{
    if(src==des)
    {
         if(ltwt_h<wt)
         {
             fans_h=ans;
             ltwt_h=wt;
         }

    }
    vis[src]=true;
    for(int i=0;i<graph[src].size();i++)
    {
        if(!vis[graph[src][i]->v])
        {
           vis[graph[src][i]->v]=true;
           heavy(graph[src][i]->v,des,wt+graph[src][i]->w,vis,ans+to_string(graph[src][i]->v)+"");
            vis[graph[src][i]->v]=false;
        }

    }

}



void display()
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"->";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<"("<<graph[i][j]->v<<")";
        }
        cout<<endl;
    }
}


//bool visited []={20,false};



// void preorder(int u)
// {
//    // cout<<visited[2];
   
//   // visited[u]=true;
//     cout<<u<<"->";
//     for(int i=0;i<graph[u].size();i++)
//     {
//         if(!visited[graph[u][i]->v])
//         {
//           visited[graph[u][i]->v]=true;
//           preorder(graph[u][i]->v);
//         }
//     }
// }
   
// }
// void bfs(int src)
// {
//     vector<bool> vis(10, false);
//     q.push(src);
//     while(!q.empty())
//     {
//         int front=q.front();
//         q.pop();
//         if(!vis[front])
//         {
//             cout<<front<<" ->";
//         }
//         vis[front]=true;

//         for(int i=0;i<graph[front].size();i++)
//         {
//             if(!vis[graph[front][i]->v])
//           q.push(graph[front][i]->v);
//         }

//     }
// }
int main()
{
    solve();
    vector<bool> vis(7, false);
    //light(0,5,0,vis,"");
    // cout<<fans<<endl;
    // cout<<ltwt<<endl;
   // heavy(0,5,0,vis,"");
    //cout<<fans_h<<endl;
    //cout<<ltwt_h<<endl;
   // bfs(0);
   dijkstra(0);
   
    //display();
    //cout<<endl;
   // preorder(0);
   return 0;
}

