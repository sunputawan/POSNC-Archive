#include <iostream>

using namespace std;
void clearq(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]='\0';
    }
}
bool can_be_place(int q[],int k,int j){
    for(int i=0;i<k;i++){
        if(q[i]==j)
            return false;
        if(q[i]==j-k+i||q[i]==j+k-i)
            return false;
    }
    return true;
}
int queen(int q[],int k,int n){
    if(k==n){
        for(int i=0;i<n;i++)
            printf("%d ", q[i]);
        printf("\n");
        return 0;
    }
    else{
        for(int j=0;j<n;j++){
            if(can_be_place(q,k,j)){
                q[k]=j;
                queen(q,k+1,n);
            }
        }
    }
}
int main(){
    cout<<"Enter n :";
    int n;
    cin>>n;
    int q[n];
    clearq(q,n);
    queen(q,0,n);
}
