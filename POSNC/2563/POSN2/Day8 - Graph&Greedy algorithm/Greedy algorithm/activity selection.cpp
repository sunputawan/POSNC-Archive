#include<iostream>
#include<vector>
int s[]={1,3,0,5,3,5,6,8,8,2,12};
int f[]={4,5,6,7,9,9,10,11,12,14,16};
using namespace std;

vector<int> greedy_activity_selection(int s[],int f[]){
    vector<int>A;
    A.push_back(0);
    int k=0;
    for(int m=1;m<11;m++){
        if(s[m]>=f[k]){
            A.push_back(m);
            k=m;
        }
    }
    return A;
}
int main(){
    vector<int>S;
    S=greedy_activity_selection(s,f);
    for(int i=0;i<S.size();i++){
        cout<<"activity"<< S[i]+1<<" -> ";
    }
}
