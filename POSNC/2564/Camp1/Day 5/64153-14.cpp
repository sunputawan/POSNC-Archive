#include <iostream>

using namespace std;
int main(){
    int a[4][4];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            printf("Enter index[%d][%d] : ",i,j); cin>>a[i][j];
        }
    int sum=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(i==j||i+j==3)
                sum+=a[i][j];
    cout<<"sum : "<<sum;
}
