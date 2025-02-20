#include <iostream>
#include <vector>
#define n 10
#define INTMAX 999999

using namespace std;
int arr[n];
void generate_input(void){
    for(int i=0;i<n;i++)
        arr[i] = rand()%100+1;
}
int find_min(int l,int r){
    if(l==r)
        return arr[l];
    int mid = (l+r)/2;
    int leftside = find_min(l,mid);
    int rightside  = find_min(mid+1,r);
    return min(leftside,rightside);
}
int find_max(int l,int r){
    if(l==r)
        return arr[l];
    int mid = (l+r)/2;
    int leftside = find_max(l,mid);
    int rightside  = find_max(mid+1,r);
    return max(leftside,rightside);
}
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void merge(int l,int mid ,int r){
    vector<int> left,right;
    for(int i=l;i<=mid;i++)
        left.push_back(arr[i]);
    for(int i=mid+1;i<=r;i++){
        right.push_back(arr[i]);
    }
    left.push_back(INTMAX);
    right.push_back(INTMAX);
    int i=0,j=0;
    for(int k=l;k<=r;k++){
        if(left[i]<right[j]){
            arr[k] = left[i]; i++;
        }
        else{
            arr[k] = right[j]; j++;
        }
    }

}
void mergesort(int l,int r){
    if(l>=r){
        return;
    }
    int mid = (l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,mid,r);
}
int main(){
    generate_input();
    cout<<"List ref : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"min : "<<find_min(0,n-1)<<endl;
    cout<<"max : "<<find_max(0,n-1)<<endl;
    mergesort(0,n-1);
    cout<<"sorted : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\nmaximum diff : "<<find_max(0,n-1)-find_min(0,n-1)<<endl;
}
