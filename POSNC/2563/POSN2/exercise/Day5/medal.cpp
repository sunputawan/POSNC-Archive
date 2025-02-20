#include <iostream>
#include <vector>
#include <algorithm>
long long ans;
int diff(int i,int j){
    if(i>j)
        return i-j;
    else
        return j-i;
}
bool increasing_comparator(int i,int j){
    return(i<j);
}
bool decreasing_comparator(int i,int j){
    return(i>j);
}
using namespace std;
int n;
vector<int>t,h,sum;
int main(){
    int a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        t.push_back(a);
    }
    for(int i=0;i<n;i++){
        cin>>a;;
        h.push_back(a);
    }
    std::sort(t.begin(),t.end(),increasing_comparator);
    std::sort(h.begin(),h.end(),decreasing_comparator);
    for(int i=0;i<n;i++){
        sum.push_back(t[i]+h[i]);
    }
    std::sort(sum.begin(),sum.end(),increasing_comparator);
    for(int i=0;i<n-1;i++){
        ans+=diff(sum[i],sum[i+1]);
    }
    cout<<ans;
}
