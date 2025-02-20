#include <iostream>
#include <time.h>
#include <vector>
#define n 10
#define k 15

using namespace std;
void print_set(const vector<int> &s){
    for(auto i:s)
        cout<<i<<" ";
    cout<<endl;
}
void generate_set(vector<int> &s){
    srand(time(NULL));
    int i=0;
    while(i!=n){
        int x = rand()%20+1;
        bool in_set = false;
        for(auto j:s){
            if(j==x){
                in_set=true;
                break;
            }
        }
        if(in_set)
            continue;
        s.push_back(x);
        i++;
    }
    cout<<"Set ref : ";
    for(auto i:s)
        cout<<i<<" ";
    cout<<endl<<"target sum : "<<k<<endl<<endl;
}
void subset_sum(vector<int> s,vector<int> p,int current_index,int sum){
    if(sum==k){
        print_set(p);
        return;
    }
    if(current_index==n)
        return;
    if(s[current_index]+sum<=k){
        p.push_back(s[current_index]);
        subset_sum(s,p,current_index+1,sum+s[current_index]);
        p.pop_back();
    }
    subset_sum(s,p,current_index+1,sum);
}
int main(){
    vector<int> s,p;
    generate_set(s);
    subset_sum(s,p,0,0);
}
