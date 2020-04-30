import java.util.Scanner;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Arrays;

//LinkedList<>LL=new LinkedList<>();



public class graph
{
    public static Scanner s=new Scanner(System.in);
    static ArrayList<Edge>[] graph=new ArrayList[7];

    public static class Edge{
        int v;
        int w;
        Edge(int v,int w)
        {
            this.v=v;
            this.w=w;
        }
        Edge()
        {

        }
    };
  public static  class BFS_pair{
      int vtx;
      int wsf;
      String psf="";
      BFS_pair()
      {

      }
      BFS_pair(int vtx,int wsf,String psf)
      {
          this.vtx=vtx;
          this.wsf=wsf;
          this.psf=psf;
      }

  }
  static LinkedList<BFS_pair>que=new LinkedList<>();
  static boolean [] vis=new boolean[40];
    public static void bfs(int src,int des)
    {

        que.addLast(new BFS_pair(src,0,""+src));
        que.add(null);
        int cycle=0;
        boolean isPath=false;
        int level=1;
        while(que.size()!=1)
        {
           BFS_pair rpair=que.removeFirst();

           //cycle
           if(vis[rpair.vtx])
           {
                  cycle++;
              System.out.println("Cycle:"+cycle+" " +rpair.psf);
           

           }
           vis[rpair.vtx]=true;

            if(rpair.vtx==des)
            {
                System.out.println(rpair.vtx+" "+rpair.psf);
                return;

            }

            for(int i=0;i<graph[rpair.vtx].size();i++)
            {

                if(!vis[graph[rpair.vtx].get(i).v])
                {
                    BFS_pair a=new BFS_pair(graph[rpair.vtx].get(i).v,rpair.wsf+graph[rpair.vtx].get(i).w,rpair.psf+graph[rpair.vtx].get(i).v+"");
                    que.addLast(a);

                   
                }
            }

            if(que.getFirst()==null)
            {
                que.removeFirst();
                level++;
                que.addLast(null);

            }
 
        }


    }


     public static void bfs01(int src,boolean [] vis)
    {

        que.addLast(new BFS_pair(src,0,""+src));
        //que.add(null);
        int cycle=0;
        boolean isPath=false;
        int level=1;
        while(que.size()!=0)
        {
           BFS_pair rpair=que.removeFirst();

           //cycle
           if(vis[rpair.vtx])
           {
                  cycle++;
              System.out.println("Cycle:"+cycle+" " +rpair.psf);
           

           }
          vis[rpair.vtx]=true;

        //     if(rpair.vtx==des)
        //     {
        //         System.out.println(rpair.vtx+" "+rpair.psf);
        //         return;

        //     }

            for(int i=0;i<graph[rpair.vtx].size();i++)
            {

                if(!vis[graph[rpair.vtx].get(i).v])
                {
                    BFS_pair a=new BFS_pair(graph[rpair.vtx].get(i).v,rpair.wsf+graph[rpair.vtx].get(i).w,rpair.psf+graph[rpair.vtx].get(i).v+"");
                    que.addLast(a);

                   
                }
            }

            // if(que.getFirst()==null)
            // {
            //     que.removeFirst();
            //     level++;
            //     que.addLast(null);

            // }

        }


    }

    public static class Bipar{
        int vtx;
        char color;
        Bipar(int vtx,char color)
        {
            this.color=color;
            this.vtx=vtx;


        }
        Bipar()
        {

        }
    }
    //  char[] color= new char[10];
    // for(int i=0;i<10;i++)
    // {
    //     color[i]='a';
    // }
   static boolean [] vis1=new boolean[10];
   static int flag=0;
  static  int flag1=0;
   static LinkedList<Bipar> queue=new LinkedList<>();

static  void isBipartitte(int  src)
{
     char[] color= new char[10];
    for(int i=0;i<10;i++)
    {
        color[i]='a';
    }
      queue.addLast(new Bipar(src,'R'));
     while(queue.size()!=0)
     {
    Bipar rpair=queue.removeFirst();
    if(flag==1)
    {
        if(rpair.color=='G'||rpair.color=='a')
        {
    color[rpair.vtx]='G';
    }
    else
    {
        System.out.println("Not A Bipartite graph");
        return;
    }
    }

    if(flag==0)
    {
        if(rpair.color=='R'||rpair.color=='a')
       {
        color[rpair.vtx]='R';
       }
       else{
           System.out.println("Not a Bipartite graph");
           return;
       }
    }
   // flag1=1;
    if(flag==0)
    {
        flag=1;
    }
    if(flag1==1)
    {
        flag=0;
    }
    vis1[rpair.vtx]=true;
    for(int i=0;i<graph[rpair.vtx].size();i++)
    {
          if(!vis1[graph[rpair.vtx].get(i).v])
          {
              if(flag==1)
              {
         queue.push(new Bipar(graph[rpair.vtx].get(i).v,'R'));
              }
              else{
                       queue.push(new Bipar(graph[rpair.vtx].get(i).v,'G'));
              }
          }

    }

}
        }

    public static void caseI()
    {
        for(int i=0;i<graph.length;i++)
        {
            graph[i]=new ArrayList<Edge>();
        }
        addEdge(0,3,10);
        addEdge(0,1,10);
        addEdge(1,2,10);
        addEdge(2,3,10);
        addEdge(3,4,10);
       addEdge(4,5,10);
        addEdge(4,6,10);
        addEdge(5,6,10);

    }
    void Dijkstra()
    {
        
    }
    static boolean [] visited1=new boolean[100];
    static boolean res1=false;
    public static boolean minweight(int u,String ans2,int w)
    {
        int min=1000;
        int index=-1;
        visited[u]=true;
          
        for(int i=0;i<graph[u].size();i++)
        {
           if(graph[u].get(i).w<min)
           {
               min=graph[u].get(i).w;
               index=i;
           }
        }
           if(!visited1[graph[u].get(index).v])
           {
               visited1[graph[u].get(index).v]=true;
               System.out.print(graph[u].get(index).v+"->");
               res1=res1||minweight(graph[u].get(index).v,ans2+Integer.toString(graph[u].get(index).v),w+graph[u].get(index).w);
           }
        
        return res1;
    }
    public static void remove(int u,int v)
    {
        for(int i=0;i<graph[u].size();i++)
        {
            if(graph[u].get(i).v==v)
            {
                graph[u].remove(i);
            }
        }
    for(int i=0;i<graph[v].size();i++)
        {
            if(graph[v].get(i).v==u)
            {
                graph[v].remove(i);
            }
        }
    }
   static boolean [] visited=new boolean[100];
    static boolean ans=false;
    public static boolean hasallpath(int u,int v,String ans1)
    {
        if(u==v)
               {
                   //ans1=ans1+Integer.toString(v);
                   System.out.print(ans1);
                   System.out.println();
                   return true;
               }
        
           for(int i=0;i<graph[u].size();i++)
           {
               visited[u]=true;
              
               
               
                   if(!visited[graph[u].get(i).v])
                   {
                   ans=haspath(graph[u].get(i).v,v,ans1+Integer.toString(graph[u].get(i).v));
                  
                   }
                   visited[u]=false;
               
           }
           return ans;
    }

    public static boolean haspath(int u,int v,String ans1)
    {
        if(u==v)
               {
                   //ans1=ans1+Integer.toString(v);
                   System.out.print(ans1);
                   System.out.println();
                   return true;
               }
        
           for(int i=0;i<graph[u].size();i++)
           {
               visited[u]=true;
              
               
               
                   if(!visited[graph[u].get(i).v])
                   {
                   ans=haspath(graph[u].get(i).v,v,ans1+Integer.toString(graph[u].get(i).v));
                  
                   }
                   //visited[u]=false;
               
           }
           return ans;
    }
    public static void display()
    {
        for(int i=0;i<graph.length;i++)
        {
            System.out.print(i+"->");
            for(int j=0;j<graph[i].size();j++)
            {
                System.out.print("("+graph[i].get(j).v+","+graph[i].get(j).w+")");
            }
            System.out.println();
        }
    }

    public static void addEdge(int u,int v,int w)
    {
        if(u<0||v<0||u>=graph.length||v>=graph.length)
        {
            return;
        }
        graph[u].add(new Edge(v,w));
        graph[v].add(new Edge(u,w));

    }

    public static void main(String [] args)
    {
        caseI();
       // display();
        //remove(1,2);
        //System.out.println();
        //display();
       //boolean ans= haspath(0,3,"0");
       //minweight(0,"0",0);
       //bfs(0,6);
       boolean vis[] =new boolean[7];
       int gcc=0;
       for(int i=0;i<graph.length;i++)
       {
           if(!vis[i])
           {
               bfs01(i,vis);
               gcc++;
           }
       }
       System.out.print(gcc);
    //isBipartitte(0);

    }


} 