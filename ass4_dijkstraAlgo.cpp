#include <iostream>
#include <stdio.h>
using namespace std;
#define INFINITY 9999
#define max 5
void dijkstra(int G[max][max], int n, int startnode);
int main()
{
   int G[max][max] = {{0, 2, 3, 0, 0}, {0, 0, 4, 3, 1}, {0, 0, 0, 2, 0}, {0, 2, 0, 0, 0}, {0, 0, 0, 4, 0}};
   int n = 5;
   int u = 0;
   dijkstra(G, n, u);
   return 0;
}



void dijkstra(int G[max][max], int n, int startnode)
{
   int cost[max][max], distance[max], pred[max];
   int visited[max], count, mindistance, nextnode, i, j;

   // idhar to bas cost nikal rahe hai
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
         if (G[i][j] == 0)
            cost[i][j] = INFINITY;
         else
            cost[i][j] = G[i][j];

   // initializing first distances D = { 0, 6, 2, 5, 10}
   for (i = 0; i < n; i++)
   {
      distance[i] = cost[startnode][i];
      pred[i] = startnode;
      visited[i] = 0;
   }



   distance[startnode] = 0;
   visited[startnode] = 1;
   count = 1;

   while (count < n - 1)
   {
      mindistance = INFINITY;

      for (i = 0; i < n; i++)
         if (distance[i] < mindistance && visited[i]!=1)
         {
            mindistance = distance[i];
            nextnode = i;
         }


      visited[nextnode] = 1;

      for (i = 0; i < n; i++)
         if (!visited[i])
            if (mindistance + cost[nextnode][i] < distance[i])
            {
               distance[i] = mindistance + cost[nextnode][i];
               pred[i] = nextnode;
            }
      count++;
   }




   for (i = 0; i < n; i++)
      if (i != startnode)
      {
         cout << "\nDistance of node " << i << " = " << distance[i];
         cout << "\nPath=" << i;
         j = i;
         do
         {
            j = pred[j];
            cout << "<-" << j;
         } while (j != startnode);
      }
}
