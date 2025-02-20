#include <iostream>
#include <vector>
#include <utility>

using namespace std;
vector<int> year;
typedef long long unsigned llu;
llu bee[26];

int main(){
    int x;
    while(x!=-1){
        cin>>x;
        year.push_back(x);
    }
    bee[0]=1; bee[1]=2;
    for(int i=2;i<=25;i++){
        bee[i] = bee[i-1]+bee[i-2]+1;
    }
    year.pop_back();
    for(auto i:year){
        cout<<bee[i]<<" "<<bee[i+1]<<endl;
    }

}
