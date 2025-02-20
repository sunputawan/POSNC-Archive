#include <iostream>
#include <vector>
#include <time.h>
#define n 10
#define W 20

using namespace std;
vector<int> w,v;
int V[10000][10000];
void generate_input(void){
    srand(time(NULL));
    for(int i=0;i<n;i++){
        w.push_back(rand()%20+1);
        v.push_back(rand()%20+1);
    }
}

//recurrence relation : OPT(i,j) = OPT(i-1,j-w[i])+v[i] ; j>=w[i]   >>> (includes item[i])
//                                 OPT(i-1,j)                       >>> (does not include item[i])

void initialize(void){
    for(int i=0;i<n;i++)
        for(int j=0;j<=W;j++)
            V[i][j] = -1;

}
int OPT(int i,int j){
    if(i==0||j==0)
        return 0;
    if(V[i][j]==-1){
        if(j>=w[i])
            V[i][j] = max(OPT(i-1,j-w[i])+v[i],OPT(i-1,j));
        else
            V[i][j] = OPT(i-1,j);
    }
    return V[i][j];
}
int main(){
    generate_input();
    initialize();
    cout<<"n,W = "<<n<<','<<W;
    cout<<"\nItem list : ";
    for(int i=0;i<n;i++)
        cout<<'('<<w[i]<<','<<v[i]<<')'<<",";
    cout<<endl<<OPT(n-1,W)<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
}
