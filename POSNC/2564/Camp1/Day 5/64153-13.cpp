#include <iostream>

using namespace std;
int main(){
    int a[5][3];
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            printf("Enter index[%d][%d] : ",i,j); cin>>a[i][j];
        }
    }
    cout<<endl;
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<5;j++)
            sum+=a[j][i];
        cout<<"column "<<i<<"'s sum : "<<sum<<endl;
    }
    for(int i=0;i<5;i++){
        int sum=0;
        for(int j=0;j<3;j++)
            sum+=a[i][j];
        cout<<"row "<<i<<"'s sum : "<<sum<<endl;
    }
}
