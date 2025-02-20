#include <iostream>
#include <vector>
#define n 100

using namespace std;
vector<int> arr;
bool exist(int x){
    for(auto i:arr)
        if(i==x)
            return true;
    return false;
}
void generate_list(void){
    int i=0;
    while(i!=n){
            int x = rand()%100+1;
        if(!exist(x)){
            arr.push_back(x);
            i++;
        }
    }
}
void swap(int *x,int *y){
    int tmp = *x;
    *x=*y;
    *y=tmp;
}
int partition(int l,int r){
    int pivot = arr[l];
    int i=l,j=r;
    while(i<j){
        while(pivot>arr[i]&&i<=r){
            i++;
        }
        while(pivot<arr[j]&&j>=l){
            j--;
        }
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[i],&arr[j]);
    return j;
}
void quick_sort(int l,int r){
    if(l>=r)
        return;
    int s = partition(l,r);
    quick_sort(l,s-1);
    quick_sort(s+1,r);
}
bool is_sorted(){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            cout<<arr[i]<<" "<<arr[i+1];
            return false;
        }
    }
    return true;
}
void printlist(void){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl<<endl;
}
int main(){
    generate_list();
    cout<<"List ref : ";
    printlist();
    quick_sort(0,n-1);
    cout<<"Your array : ";
    printlist();
    cout<<"\nIs your array be sorted? ... ";
    if(is_sorted())
        cout<<"Y\n";
    else
        cout<<"N\n";
}
