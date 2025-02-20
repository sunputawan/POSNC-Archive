#include <iostream>
#include <vector>
#include <algorithm>
#define inf 99999
using namespace std;
int n,k,k_adress;
long long count_subarr=0;
vector<int> a;
int c[1000000];
/*void print_array(void){
    for(int i=0;i<n;i++){
            cout<<c[i]<<" ";
    }
        cout<<endl;
}*/
int find_subarray(void){
    c[k_adress]=0;
        for(int i=k_adress-1;i>=0;i--){
                c[i]=c[i+1]+a[i];
        }
        for(int i=k_adress;i<n-1;i++){
            c[i+1]=c[i]+a[i+1];
        }
        for(int i=k_adress;i>=0;i--){
            for(int j=k_adress;j<n;j++){
                if(c[i]+c[j]==0)
                    count_subarr++;
            }
        }
}
int main(){
    int l;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>l;
        if(l<k)
            a.push_back(-1);
        if(l==k){
            a.push_back(0);
            k_adress=i;
        }
        if(l>k)
            a.push_back(1);
    }
   find_subarray();
   cout<<count_subarr;
}
