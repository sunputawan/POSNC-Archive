#include <iostream>

using namespace std;
int main(){
    int a[3][2],b[3][2],sum=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++){
            printf("Enter a[%d][%d] : ",i,j); cin>>a[i][j];
        }
    cout<<endl;
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++){
            printf("Enter b[%d][%d] : ",i,j); cin>>b[i][j];
        }
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++){
            sum+=a[i][j]+b[i][j];
        }
    cout<<"sum : "<<sum;
}
