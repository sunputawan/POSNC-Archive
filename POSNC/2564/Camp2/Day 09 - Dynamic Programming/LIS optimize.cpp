#include <iostream>
#include <vector>

using namespace std;
int arr[] = {2,5,4,8,1,9,6,7};
vector<int> test = {1,3,7,11,15,32,47,66};
const int n = sizeof(arr)/sizeof(arr[0]);
vector<int> L;
int search(const vector<int> &L,int l,int r,int x){
    if(l==r)
        return l;
    int mid = (l+r)/2;
    if(L[mid]>x)
        return search(L,l,mid,x);
    else if(L[mid]<x)
        return search(L,mid+1,r,x);
    else
        return mid;
}
int main(){
    L.push_back(arr[0]);
    int maximum = 0;
    for(int i=2;i<=n;i++){
        if(arr[i-1]>L[L.size()-1])
            L.push_back(arr[i-1]);
        else{
            int k = search(L,0,L.size()-1,arr[i-1]); //return x's index or the minimum index k such arr[k]>x
            L[k] = arr[i-1];
        }
        /*for(auto j:L)
            cout<<j<<" ";
        cout<<endl;*/
    }
    cout<<L.size();
}
