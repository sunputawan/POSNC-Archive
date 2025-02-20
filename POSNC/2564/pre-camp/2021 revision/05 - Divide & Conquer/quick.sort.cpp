#include <iostream>
#include <time.h>
#include <vector>
#define n 1000

using namespace std;
vector<int> arr;
bool exist(int x){
    for(auto i:arr)
        if(i==x)
            return true;
    return false;
}
void generate_list(void){
    srand(time(NULL));
    int i=0;
    while(i!=n){
        int x=rand()%1000+1;
        if(!exist(x)){
            arr.push_back(x);
            i++;
        }
    }
}
void printlist(void){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
void swap(int *x,int *y){
    int tmp = *x;
    *x=*y;
    *y=tmp;
}
int partition(int l,int r){
    int p=arr[l];
    //cout<<endl<<"l,r : "<<l<<" "<<r<<" pivot = "<<p<<endl;
    //printlist();
    int i=l,j=r;
    while(i<j){
        while(arr[i]<p&&i<=r){
            i++;
        }
        while(arr[j]>p&&j>=l){
            j--;
        }
        //cout<<"i,j : "<<i<<" "<<j<<endl;
        swap(&arr[i],&arr[j]);
        //printlist();
    }
    //cout<<"i,j : "<<i<<" "<<j<<endl;
    swap(&arr[i],&arr[j]);
    return j;
}
void quick_sort(int l,int r){
    if(l>=r)
        return;
    int s = partition(l,r);
    /*cout<<"return index = "<<s<<endl;
    cout<<"current list : ";
    printlist();
    cout<<endl;*/
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
int main(){
    generate_list();
    /*cout<<"List ref : ";
    printlist();*/
    cout<<"\nIs your array be sorted? ... ";
    quick_sort(0,n-1);
    /*cout<<"Sorted list : ";
    printlist();*/
    if(is_sorted())
        cout<<"Y\n";
    else
        cout<<"N\n";
}
