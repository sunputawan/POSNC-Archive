#include <iostream>
#include <vector>
#include <time.h>
#define W 100

using namespace std;
vector<int> weight,value,final_ans;
int n=50;
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
int best_val = 0;
void knapsack(vector<int> s,int w,int v,int level){
    if(level==n){
        if(best_val<v){
           best_val=v;
           final_ans=s;
        }
        return;
    }
    if(w+weight[level]<=W){
        s.push_back(level);
        knapsack(s,w+weight[level],v+value[level],level+1);
        s.pop_back();
    }
    knapsack(s,w,v,level+1);
}
int main(){
    input();
    vector<int> empty_set;
    knapsack(empty_set,0,0,0);
    cout<<"Maximum value : "<<best_val<<"\nYour set : {";
    for(auto i:final_ans)
        cout<<i<<", ";
    cout<<"}"<<endl;
}
