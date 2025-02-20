#include <iostream>
#define inf 999999

using namespace std;

#define V 9
int parent[V];
char map[]={'S','A','B','C','D','E','F','G','H'};
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void initialize(int cost [][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            if(cost [i][j]==0)
                cost[i][j]=inf;
    }
}
void kruskal(int cost[][V])
{
    initialize(cost);
    int mincost = 0;
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edge_count = 0;
    while (edge_count < V-1 ) {
        int min = inf, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        cout<<map[edge_count++]<<" ("<<map[a]<<"->"<<map[b]<<") :"<<min<<endl;
        mincost += min;
    }
    cout<<endl<<"Minimum cost required : "<<mincost<<endl;
}


int main()
{
    int cost[][V] = {0,3,2,5,0,0,0,0,0,
               0,0,0,3,0,0,0,2,0,
               0,5,0,0,6,0,0,0,0,
               0,0,4,0,0,0,0,0,3,
               0,0,0,0,0,2,3,0,0,
               0,0,0,0,0,0,5,0,0,
               0,0,0,0,0,0,0,0,0,
               0,0,0,0,4,5,0,0,0,
               0,4,0,0,4,0,0,0,0};

    kruskal(cost);

    return 0;
}
