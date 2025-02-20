#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;
bool ascending(int a,int b){
    return a<b;
}
bool descending(int a,int b){
    return a>b;
}
int main(){
    srand(time(NULL));
   int n;
   cin>>n;
   int a[n];
   if(n<=0)
    return 0;
   if(n==1){
    cout<<((a[n]+2)%99)+1;
    return 0;
   }
   vector<int> x,y;
   if(n%2==1){
    for(int i=0;i<n/2;i++){
            int a=(rand()%99)+1;
        x.push_back(a);
    }
    if(n%2==1){
         int a=(rand()%99)+1;
        x.push_back(a);
    }
    for(int i=n/2;i<n-1;i++){
             int a=(rand()%99)+1;
        y.push_back(a);
    }
   }
   if(n%2==0){
    for(int i=0;i<n/2;i++){
             int a=(rand()%99)+1;
        x.push_back(a);
    }
    for(int i=n/2;i<n;i++){
         int a=(rand()%99)+1;
        y.push_back(a);
    }
   }
   for(int i=0;i<x.size();i++)
        cout<<x[i]<<" ";
    for(int i=0;i<y.size();i++)
        cout<<y[i]<<" ";
    cout<<endl;
    std::sort(x.begin(),x.end(),descending);
    std::sort(y.begin(),y.end(),ascending);
    for(int i=0;i<x.size();i++)
        cout<<x[i]<<" ";
    cout<<"|";
    for(int i=0;i<y.size();i++)
        cout<<y[i]<<" ";
}
