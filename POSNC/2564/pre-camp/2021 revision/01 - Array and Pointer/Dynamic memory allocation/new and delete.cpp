#include <iostream>
#include <vector>

using namespace std;
void operation(int n){
    int *p=new int[n];
    for(int i=0;i<n;i++){
        p[i]=i*i;
    }
    for(int i=0;i<n;i++){
        cout<<*p+i<<" "; // *p = p[0]
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(p+i)<<" "; // *(p+i) = p[i]
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*p+i**p+i<<" "; // *p + i(*p) + i =
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(p+i)*(*(p+i))<<" "; // p[i]*p[i]
    }
    delete(p);
}
int main(){
    int n=10;
    operation(n);
}
