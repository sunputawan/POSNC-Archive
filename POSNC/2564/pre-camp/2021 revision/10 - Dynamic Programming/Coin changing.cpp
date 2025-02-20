#include <iostream>
#include <vector>
#include <algorithm>
#define INTMAX 9999999
#define n 10
#define M 40

using namespace std;
vector<int> c;
int C[10000][10000];
void generate_coin(void){
    int i=0;
    while(i!=n){
        int x = rand()%30+1;
        bool duplicate=false;
        for(int j=0;j<i;j++)
            if(c[j]==x) {duplicate = true; break;}
        if(duplicate) continue;
        c.push_back(x);
        cout<<x<<" ";
        i++;
    }
}

// recurrence relation : C(i,j) represents a number of minimum possible
//                              coin(0-i) which its value equal to j
void initialize(void){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=M;j++){
            C[i][j] = -1;
        }
    }
}
int coin_change(int i,int j){
    if(j==0) C[i][j] = 0;
    if(i==0) C[i][j] = INTMAX;
    if(C[i][j]==-1){
        if(j<c[i-1]) C[i][j] = coin_change(i-1,j);
        else C[i][j] = min(1+coin_change(i,j-c[i-1]),coin_change(i-1,j));
    }
    return C[i][j];
}
int main(){
    cout<<"n,M : "<<n<<' '<<M<<endl<<"coin ref : ";
    generate_coin();
    initialize();
    cout<<endl<<coin_change(n,M)<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=M;j++){
            if(C[i][j]== INTMAX) {cout<<"- ";continue;}
            cout<<C[i][j]<<' ';
        }
        cout<<endl;
    }
}
