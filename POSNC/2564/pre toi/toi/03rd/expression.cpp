#include <bits/stdc++.h>

using namespace std;
string s;
int key;
int l,r;
void expression(void){
    int n=0;
    vector<int> add,mul,pow;
    for(int i=l;i<=r;i++){
        if(s[i]=='(') n++;
        else if(s[i]==')') n--;
        else if(n==0){
            if(s[i]=='+')
                add.push_back(i);
            else if(s[i]=='*')
                mul.push_back(i);
            else if(s[i]=='^')
                pow.push_back(i);
        }
    }
    int lenA = add.size();
    int lenM = mul.size();
    int lenP = pow.size();
    if(lenA){
        if(key==1)
            r = add[0]-1;
        else if(key>lenA+1)
            l = r+1;
        else if(key==lenA+1)
            l = add[key-2]+1;
        else{
            l = add[key-2]+1;
            r = add[key-1]-1;
        }
    }
    else if(lenM){
        if(key==1)
            r = mul[0]-1;
        else if(key>lenM+1)
            l = r+1;
        else if(key==lenM+1)
            l = mul[key-2]+1;
        else{
            l = mul[key-2]+1;
            r = mul[key-1]-1;
        }
    }
    else if(lenP){
        if(key==1)
            r = pow[0]-1;
        else if(key>lenP+1)
            l = r+1;
        else if(key==lenP+1)
            l = pow[key-2]+1;
        else{
            l = pow[key-2]+1;
            r = pow[key-1]-1;
        }
    }
    else if(s[l]=='(' && s[r]==')' && key==1){
        l++,r--;
    }
    else if(key>1)
        l = r+1;
}
int main(){
    int n;
    cin>>s>>n;
    while(n--){
        stack<int> st;
        l=0,r=s.size()-1;
        while(true){
            cin>>key;
            if(!key) break;
            st.push(key);
            expression();
        }
        int cnt=st.size();
        while(!st.empty()){
            cout<<"op("<<st.top()<<',';
            st.pop();
        }
        cout<<'p';
        while(cnt--)
            cout<<')';
        cout<<'=';

        if(l>r)
            cout<<"null";
        else{
            for(int i=l;i<=r;i++)
                cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
