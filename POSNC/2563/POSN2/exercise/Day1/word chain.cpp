#include <iostream>
#include <stack>

using namespace std;
int main(){
    int L,N;
    cin>>L>>N;
    string w[N];
    for(int i=0;i<N;i++){
        cin>>w[i];
    }
    stack<string> chain;
    chain.push(w[0]);
    int i=1;
    while(chain.size()!=N){
        int count=0;
        for(int j=0;j<L;j++){
            if(chain.top()[j]==w[i][j])
                count++;
        }
        if(count<L-2)
            break;
        else{
            chain.pop();
            chain.push(w[i]);
            i++;
        }
    }
    cout<<chain.top();
}
