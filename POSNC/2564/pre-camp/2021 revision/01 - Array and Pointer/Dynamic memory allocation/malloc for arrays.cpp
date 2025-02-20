#include <iostream>

using namespace std;
int n=100;
void operation(void){
    int *a;
    a=(int*) malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        a[i]=2*i+1;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    free(a);
}
int main(){
    operation();
}
