#include <iostream>

using namespace std;
int a[1000][1000];
int b[1000][1000]={};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(i==0)
                b[i][j] = 1;
        }
    }
    for(int i=1;i<m;i++){
        if(i%2==0){
            a[i][0] +=a[i-1][0];
            b[i][0] = b[i-1][0];
            for(int j=1;j<n;j++){
                int x = a[i-1][j-1];
                int y = a[i-1][j];
                if(x==y){
                    a[i][j]+= x;
                    b[i][j] = b[i-1][j-1] + b[i-1][j];
                }
                else if(x<y){
                    a[i][j]+= y;
                    b[i][j] = b[i-1][j];
                }
                else{
                    a[i][j]+= x;
                    b[i][j] = b[i-1][j-1];
                }
            }
        }
        else{
            a[i][n-1] += a[i-1][n-1];
            b[i][n-1] = b[i-1][n-1];
            for(int j=0;j<n-1;j++){
                int x = a[i-1][j];
                int y = a[i-1][j+1];
                if(x==y){
                    a[i][j]+= x;
                    b[i][j] = b[i-1][j] + b[i-1][j+1];
                }
                else if(x<y){
                    a[i][j]+= y;
                    b[i][j] = b[i-1][j+1];
                }
                else{
                    a[i][j]+= x;
                    b[i][j] = b[i-1][j];
                }
            }
        }
    }
    /*cout<<endl;
    for(int i=0;i<m;i++){
        if(i%2==1)
            cout<<" ";
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        if(i%2==1)
            cout<<" ";
        for(int j=0;j<n;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    int max = a[m-1][0];
    int count = 0;
    for(int j=0;j<n;j++){
        if(max<a[m-1][j]){
            max = a[m-1][j];
            count=b[m-1][j];
        }
        else if(max==a[m-1][j]){
            count+=b[m-1][j];
        }
    }
    cout<<max<<" "<<count;
}
