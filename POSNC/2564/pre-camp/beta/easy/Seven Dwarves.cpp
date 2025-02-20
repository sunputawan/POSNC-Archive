#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int sum=0;
int m,n;
void find(void){
     for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            if(v[i]+v[j]==sum-100){
                m=i;
                n=j;
                return;
            }
        }
    }
}
int main(){
    for(int i=0;i<9;i++){
        int a;
        cin>>a;
        v.push_back(a);
        sum+=a;
    }
    find();
    for(int i=0;i<9;i++){
        if(i!=m&&i!=n)
            cout<<v[i]<<endl;
    }
}

