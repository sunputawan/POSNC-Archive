#include <iostream>
#include <vector>
#include <time.h>
#define n 10

using namespace std;
vector<int> s,track;
int sum;
int S[10000][10000] = {};
void generate_input(void){
    srand(time(NULL));
    bool first_time = true;
    do{
        sum=0;
        s.clear();
        first_time = false;
        for(int i=0;i<n;i++){
            s.push_back(rand()%20+1);
            sum+=s[i];
        }
    }while(sum%2!=0);
    sum/=2;
    cout<<"Set ref : ";
    for(auto i:s)
        cout<<i<<' ';
    cout<<endl<<"sum : "<<sum<<endl;
}
void initialize(void){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            S[i][j] = -1;
        }
    }
}
int subsetsum(int i,int j){
    if(j==0) S[i][j] = 1;
    if(i==0&&j!=0) S[i][j] = 0;
    if(S[i][j]==-1){
        if(j<s[i-1]){
            if(subsetsum(i-1,j))
                S[i][j]=1;
            else
                S[i][j]=0;
        }
        else{
            if(subsetsum(i-1,j-s[i-1])||subsetsum(i-1,j))
                S[i][j]=1;
            else
                S[i][j]=0;
        }
    }
    return S[i][j];
}
int main(){
    generate_input();
    initialize();
    if(subsetsum(n,sum)){
        cout<<"Exist! ";
        for(int j=1;j<=sum;j++){
            for(int i=0;i<=n;i++){
                if(S[i][j]==1){
                    track.push_back(s[i-1]);
                    break;
                }
            }
        }
        cout<<'(';
        for(auto i:track){
            cout<<i<<",";
        }
        cout<<")\n";
    }
    else
        cout<<"Doesn't exist!\n";
    for(int a=0;a<=n;a++){
        for(int b=0;b<=sum;b++)
            if(S[a][b]==-1)
                cout<<"- ";
            else
                cout<<S[a][b]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
