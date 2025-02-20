#include <iostream>
#include <algorithm>
#include <vector>
int m;
long long n;
using namespace std;
struct contain{
    int t;
    int k;
}blank;
bool increasing_comparator(contain a,contain b){
    return a.t<b.t;
}
vector<contain> labor;
int main(){
    int a;
    cin>>m>>n;
    blank.k=0;
    for(int i=0;i<m;i++){
        cin>>blank.t;
        labor.push_back(blank);
    }
    std::sort(labor.begin(),labor.end(),increasing_comparator);
    /*for(int i=0;i<m;i++){
        cout<<labor[i].t<<" ";
    }*/
}
