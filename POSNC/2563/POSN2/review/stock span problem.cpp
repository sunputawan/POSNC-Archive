#include <iostream>
#include <stack>

using namespace std;
int main(){
    int n;
    stack<int> s1,s2;
    cout<<"Enter the number of day : ";
    cin>>n;
    int s[n];
    for(int i=0;i<n;i++){
        int a;
        cout<<"Day"<<i+1<<" : ";
        cin>>a;
        s2.push(a);
        while(!s1.empty()&&s1.top()<a){
            s2.push(s1.top());
            s1.pop();
        }
        s[i]=s2.size();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    for(int i=0;i<n;i++)
        cout<<s[i]<<" ";
}
