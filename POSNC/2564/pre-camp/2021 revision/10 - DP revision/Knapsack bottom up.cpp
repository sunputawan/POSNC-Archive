#include <iostream>
#include <vector>
#define n 10
#define W 20

using namespace std;
vector<int> w,v;
int V[1000][1000] = {};
void generate_input(void){

    for(int i=0;i<n;i++){
        w.push_back(rand()%20+1);
        v.push_back(rand()%20+1);
    }
    cout<<"Item list (w,v): ";
    for(int i=0;i<n;i++){
        cout<<"("<<w[i]<<','<<v[i]<<") ";
    }
    cout<<endl;
}
int knapsack(void){
    for(int i=0;i<=n;i++) V[i][0]=0;
    for(int j=0;j<=W;j++) V[0][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(j<w[i-1])
                V[i][j] = V[i-1][j];
            else
                V[i][j] = max(V[i-1][j-w[i-1]]+v[i-1],V[i-1][j]);
        }
    }
    return V[n][W];
}
int main(){
    generate_input();
    cout<<"ans : "<<knapsack()<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++)
            printf("%2d ",V[i][j]);
        cout<<endl;
    }
}
