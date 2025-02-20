#include <iostream>
#include <vector>
#include <time.h>
#define W 100

using namespace std;
int n = 50;
vector<int> weight,value,final_ans;
void input(void){
    srand(time(NULL));
    for(int i=0;i<n;i++){
        weight.push_back(rand()%50+1);
        value.push_back(rand()%50+1);
    }
    cout<<"(weight,value) : {";
    for(int i=0;i<n;i++){
        cout<<"("<<weight[i]<<","<<value[i]<<"), ";
    }
    cout<<"}\n";
}
int current_best_val=0;
int best_possible_val=0; //upper bound
void knapsack(vector<int> s,int w,int v,int level,int current_val_bound){
    if(level==n){
        if(v>current_best_val){
            final_ans=s;
            current_best_val=v;
        }
        return;
    }
    if(current_val_bound<current_best_val)
        return;
    if(w+weight[level]<=W){
        s.push_back(level);
        knapsack(s,w+weight[level],v+value[level],level+1,current_val_bound);
        s.pop_back();
    }
    knapsack(s,w,v,level+1,current_val_bound-value[level]);
}
int main(){
    input();
    vector<int> empty_set;
    for(auto val:value)
        best_possible_val+=val;
    knapsack(empty_set,0,0,0,best_possible_val);
        cout<<"Maximum value : "<<current_best_val<<"\nYour set : {";
    for(auto i:final_ans)
        cout<<i<<", ";
    cout<<"}"<<endl;
}
