#include <iostream>
#include <vector>

using namespace std;
vector<int> a={1,2,3,4,1,2,3,4};
int main(){
    for(int i=1;i<a.size();i++){
        if(a[i-1]==a[a.size()-1])
            a.pop_back();
    }
    int sum=0;
    for(auto it=a.begin();it<a.end();it++){
        sum+=*it;
    }
    cout<<sum;
}
