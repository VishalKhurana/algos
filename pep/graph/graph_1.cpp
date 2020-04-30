#include<iostream>
#include<vector>
#include<queue>
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
  Edge()
  {

  }

};

vector<vector<Edge*>>graph;
void addEdge(int u,int v,int w)
{
    if(u<0||v<0||u>=graph.size()||v>=graph.size())
    {
        return ;
    }
    graph[u].push_back(new Edge(v,w));
}
void initialise(int n)
{
    for(int i=0;i<n;i++)
    {
        vector<Edge*>ar;
        graph.push_back(ar);

    }
    addEdge(0, 1,0); 
    addEdge(0, 3,0); 
    addEdge(3, 4,0); 
    addEdge(1, 5,0); 
    addEdge(5, 6,0); 
    addEdge(4, 7,0); 
}

void bfs_1(int src,int n)
{
    vector<bool>visited(n,false);
    queue<Edge*>q;
     int level=0;
    q.push(new Edge(src,0));

while(q.size()!=0)
{
    int size=q.size();
   
    while(size>0)
    {
        Edge* a=q.front();
        visited[a->v]=true;
        cout<<a->v<<" ";
        q.pop();
        size--;
        for(int i=0;i<graph[a->v].size();i++)
        {
            if(visited[graph[a->v][i]->v]==false)
            {
                q.push(graph[a->v][i]);
            }

        }


    }
    cout<<endl;
    level++;

}
cout<<level;

}

int main()
{
  int n;
  cin>>n;
  initialise(n);
  bfs_1(0,n);
  

  


}