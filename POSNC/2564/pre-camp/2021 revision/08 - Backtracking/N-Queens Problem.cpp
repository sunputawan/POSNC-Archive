#include <iostream>
#include <vector>

using namespace std;
void print_queen(vector<int> q,int n){
    for(auto i:q){
        for(int j=0;j<i;j++)
            cout<<"| ";
        cout<<"|Q|"<<" ";
        for(int j=i+1;j<n;j++)
            cout<<"| ";
        cout<<endl<<'-';
        for(int j=0;j<n;j++)
            cout<<"--";
        cout<<endl;
    }
    cout<<endl<<endl;
}
bool check(vector<int> q,int ref){
    int j=q.size()-1;
    int k=1;
    while(j!=-1){
        if(q[j]==ref||q[j]==ref-k||q[j]==ref+k)
            return false;
        j--;
        k++;
    }
    return true;
}
void print_arr(vector<int> q){
    for(auto i:q)
        cout<<i<<" ";
    cout<<endl;
}
void nqueen(vector<int> q, int n){
    if(q.size()== n){
        print_queen(q,n);
        return;
    }
    //print_arr(q);
    for(int i=0;i<n;i++){
        if(check(q,i)){
            q.push_back(i);
            nqueen(q,n);
            q.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int n = 8;
    vector<int> q;
    nqueen(q,n);
}
