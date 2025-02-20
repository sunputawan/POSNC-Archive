#include <iostream>
#include <vector>
#define n 100
#define INT_MAX 9999999

using namespace std;
vector<int> arr;
void generate_arr(void){
    for(int i=0;i<n;i++){
        arr.push_back(rand()%1000+1);
    }
}

void printarr(void){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
void merge(int p,int q,int r){
    vector<int> L,R;
    for(int i=p;i<=q;i++)
        L.push_back(arr[i]);
    for(int i=q+1;i<=r;i++)
        R.push_back(arr[i]);
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);
    int i=0,j=0;
    int k=p;
    while(k!=r+1){
        if(L[i]<R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
}
void mergesort(int l,int r){
    int mid = (l+r)/2;
    if(l>=r)
        return;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,mid,r);
}
void binary_search(int l,int r,int target){
    if(l==r){
        if(arr[l]==target)
            cout<<l;
        return;
    }
    binary_search(l,(l+r)/2,target);
    binary_search((l+r)/2+1,r,target);
}
int main(){
    generate_arr();
    cout<<"List ref : ";
    printarr();
    mergesort(0,n-1);
    cout<<"Sorted array : ";
    printarr();
    cout<<endl;
    cout<<465<<" index = ";
    binary_search(0,n-1,465);
}
