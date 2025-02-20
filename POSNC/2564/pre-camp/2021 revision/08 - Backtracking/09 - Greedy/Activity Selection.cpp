#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <time.h>

using namespace std;
vector<pair<int,int>> a;
void swap(int *x,int *y){
    int tmp = *x;
    *x=*y;
    *y=tmp;
}
bool sec_ref_nondes(const pair<int,int> x,const pair<int,int> y){
    return x.second<=y.second;
}
void generate_input(int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){
        int s = rand()%50+1;
        int f = rand()%50+1;
        if(s>f) swap(&s,&f);
        a.push_back({s,f});
    }
    std::sort(a.begin(),a.end(),sec_ref_nondes);
    cout<<"Activity list : ";
    for(auto act:a)
        cout<<"("<<act.first<<","<<act.second<<"), ";
    cout<<endl;
}
vector<int> selected_act;
void greedy(void){
    int i=0;
    int current_time=a[0].second;
    selected_act.push_back(0);
    while(i!=a.size()-1){
        i++;
        if(a[i].first<current_time)
            continue;
        selected_act.push_back(i);
        current_time=a[i].second;
    }
}
void print_act(void){
    cout<<"\nSelected Activity : ";
    for(auto act:selected_act){
        cout<<act<<"("<<a[act].first<<"->"<<a[act].second<<") , ";
    }
    cout<<endl;
    cout<<"\nMaximum Activity Taken : "<<selected_act.size()<<endl;
}
int main(){
    int n=20;
    generate_input(n);
    greedy();
    print_act();
}
