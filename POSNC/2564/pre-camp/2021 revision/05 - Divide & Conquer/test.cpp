#include <iostream>
#include <time.h>
#include <iterator>
#include <algorithm>
#include <vector>
#define n 100

using namespace std;
vector<int> arr;
void generate_list(void){
    //srand(time(NULL));
    int i=0;
    while(i!=n){
        int x=rand()%1000+1;
        cout<<x<<" ";
        if(find(arr.begin(),arr.end(),x)==arr.end()){
            arr.push_back(x);
            i++;
            cout<<" i : "<<i-1<<endl;
        }
    }
}
void check(int x){
    std::vector<int>::iterator k=std::find(arr.begin(),arr.end(),x);
    cout<<*k<<" "<<x<<" ";
    if(k==arr.end())
        cout<<"found";
    else
        cout<<"not found";
    cout<<endl;
}
void printlist(void){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    //generate_list();
    for(int i=0;i<n;i++)
        arr.push_back(i);
        cout<<"List ref : ";
    printlist();
    for(int i=-5;i<150;i++){
        check(i);
    }
}
/*
'operator==' (operand types are '__gnu_cxx::__normal_iterator<int*, std::vector<int> >*' and 'std::vector<int>::iterator {aka __gnu_cxx::__normal_iterator<int*, std::vector<int> >}')|*/
