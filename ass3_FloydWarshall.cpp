#include <iostream>
#define NODE 4
#define INF 999
using namespace std;

int costMat[NODE][NODE] = {
    {0, 5, 4, 10},
    {3, 0, 3, 8},
    {2, 6, 0, 1},
    {1, 6, 2, 0}};
void floydWarshal()
{
    int cost[NODE][NODE];
    for (int i = 0; i < NODE; i++)
        for (int j = 0; j < NODE; j++)
            cost[i][j] = costMat[i][j];

    for (int k = 0; k < NODE; k++)
    {
        for (int i = 0; i < NODE; i++)
            for (int j = 0; j < NODE; j++)
                if (cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
    }

    cout << "The matrix :" << endl;
    for (int i = 0; i < NODE; i++)
    {
        for (int j = 0; j < NODE; j++)
        if(cost[i][j] == INF){
            cout<<" "<<"INF";
        }else{
            cout << " "<< cost[i][j];
        }
        cout << endl;
    }
}
int main()
{
    floydWarshal();
}