1.bellman ford code
#include<stdio.h>
struct Graph* creategraph(int v,int e);
struct Edge
{
     int source;
     int destination;
     int weight;
};
struct Graph
{
     int V;
     int E;
     struct Edge *edge;
};
main()
{
     int v,e;
     printf("enter the no of vertices and edges\n");
     scanf("%d%d",&v,&e);
     struct Graph*graph=creategraph(v,e);
     for(int i=0;i<e;i++)
     {
          scanf("%d",&graph->edge[i].source);
          scanf("%d",&graph->edge[i].destination);
          scanf("%d",&graph->edge[i].weight);
     }
     bellmanford(graph,0);
}
struct Graph* creategraph(int v,int e)
{
     struct Graph*graph=(struct Graph*)malloc(sizeof(struct Graph));
     graph->V=v;
     graph->E=e;
     graph->edge=(struct Edge*)malloc(graph->E * sizeof(struct Edge));
     return graph;
}
void bellmanford(struct Graph*graph,int source)
{
     int V,E,dist[20];
     V=graph->V;
     E=graph->E;
     for(int i=0;i<V;i++)
     {
          dist[i]=999;
     }
     dist[source]=0;
     for(int i=1;i<V;i++)
     {
          for(int j=0;j<E;j++)
          {
               int u=graph->edge[j].source;
               int v=graph->edge[j].destination;
               int weight=graph->edge[j].weight;
               if(dist[u]+weight<dist[v])
               {
                    dist[v]=dist[u]+weight;
               }

          }
     }
     for(int j=0;j<E;j++)
     {
          int u=graph->edge[j].source;
          int v=graph->edge[j].destination;
          int weight=graph->edge[j].weight;
          if(dist[u]+weight<dist[v])
          {
               printf("graph contains negative weights\n ");
          }
     }
     printf("vertex distance from source\n");
     for(int i=0;i<V;i++)
     {
     printf("%d->%d %d\n",source,i,dist[i]);
     }
}
