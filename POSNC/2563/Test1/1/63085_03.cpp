#include <iostream>
#include <vector>

using namespace std;
int main(){
    string a;
    cin>>a;
    vector<int> c;
    int n;
    int j;
    while(a[j]!='\0'){
        n++;
        j++;
    }
    for(int i=0;i<n;i++){
        int is_not_copy=1;
        for(auto j: c){
            if(j==a[i])
                is_not_copy=0;
        }
        if(is_not_copy){
            cout<<a[i];
            c.push_back(a[i]);
        }
    }
}
