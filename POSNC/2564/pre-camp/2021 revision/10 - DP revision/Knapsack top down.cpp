#include <iostream>
#include <vector>
#include <stack>
#define n 10
#define W 20


using namespace std;
vector<int> w,v;
vector<bool> item;
stack<int> s;
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
void initialize(void){
    for(int i=0;i<=n;i++)
        for(int j=0;j<=W;j++)
            V[i][j] = -1;
    for(int i=0;i<n;i++)
        item[i]=false;
}
int knapsack(int i,int j){
    if(i==0||j==0)
        V[i][j] = 0;
    if(V[i][j]==-1){
        if(j<w[i-1]){
            V[i][j]=knapsack(i-1,j);
        }
        else{
            if(knapsack(i-1,j-w[i-1])+v[i-1]>knapsack(i-1,j)){
                item[i-1]=true;
                V[i][j] = knapsack(i-1,j-w[i-1])+v[i-1];
            }
            else
                V[i][j] = knapsack(i-1,j);
        }
    }
    return V[i][j];
}
void find_list(void){
    int ans = knapsack(n,W);
    int wt = W;
    for(int i=n-1;i>=0&&ans>0;i--){
        if(ans!=V[i][wt]){
            ans-=v[i];
            wt-=w[i];
            s.push(i);
        }
    }
}
int main(){
    generate_input();
    item.resize(n);
    initialize();
    cout<<"ans : "<<knapsack(n,W)<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++)
            printf("%2d ",V[i][j]);
        cout<<endl;
    }
    find_list();
    cout<<"Selected item : ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
