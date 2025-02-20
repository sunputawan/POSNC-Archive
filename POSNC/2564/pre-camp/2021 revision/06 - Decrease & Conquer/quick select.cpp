#include <iostream>
#include <algorithm>
#include <vector>
#define n 1000
#define position 16


using namespace std;
vector<int> list,list_ref,sorted_list;
void generate_list(void){
    for(int i=0;i<n;i++){
        int x = rand()%100000+1;
        list_ref.push_back(x);
        list.push_back(x);
        sorted_list.push_back(x);
    }
    sort(sorted_list.begin(),sorted_list.end());
}
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void print_sorted_list(void){
    cout<<"Sorted list : ";
    for(auto i : sorted_list)
        cout<<i<<" ";
    cout<<endl;
}
void print_list(int l,int r){
    for(int i=l;i<=r;i++)
        cout<<list[i]<<" ";
    cout<<endl;
}
int partition(int l,int r){
    int pivot = list[l];
    //cout<<endl<<"pivot,l,r : "<<pivot<<" "<<l<<" "<<r<<endl;
    int s=l; int i = l+1;
    //print_list(l,r);
    while(i!=r+1){
        if(list[i]<=pivot){
            s++;
            swap(&list[s],&list[i]);
        }
        i++;
    }
    swap(&list[s],&list[l]);
    //print_list(l,r);
    return s;
}
int quick_select(int l,int r,int k){
    if(l==r)
        return list[l];
    int s = partition(l,r);
        //cout<<"s,k : "<<s<<" "<<k<<endl;
    if(s-l==k)
        return list[s];
    if(s-l<k)
        return quick_select(s+1,r,k-(s-l+1));
    if(s-l>k)
        return quick_select(l,s-1,k);
}
void debug_messages(bool correct){
    cout<<"\n\nIs your function select correctly? ... ";
    if(correct)
        cout<<"Y";
    else
        cout<<"N";
}
void initialize(void){
    generate_list();
    cout<<"List ref : "; print_list(0,n-1); cout<<"\n"; print_sorted_list();
}
int main(){
    initialize();
    bool correct = true;
    for(int i=0;i<n;i++){
        int val = quick_select(0,n-1,i);
        if(val!=sorted_list[i])
            correct=false;
        cout<<"\nindex "<<i<<" : "<<val;
        list=list_ref;
    }
    debug_messages(correct);
}
