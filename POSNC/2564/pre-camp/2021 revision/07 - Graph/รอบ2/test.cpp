#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int to_int(string s){
        int i=0;
        bool negative=false;
        if(s[i]=='-'){
            negative=true;
            i++;
        }
        int num=0;
        while(i!=int(s.size())){
            num*=10;
            num+=s[i]-'0';
            i++;
        }
        if(negative)
            return -num;
        else
            return num;
    }
int calPoints(vector<string>& ops){
    stack<int> s;
        for(string str:ops){
            if(str[0]=='D'){
                s.push(2*s.top());
            }
            else if(str[0]=='C'){
                s.pop();
            }
            else if(str[0]=='+'){
                int tmp = s.top();
                s.pop();
                int x = tmp+s.top();
                s.push(tmp);
                s.push(x);
            }
            else{
                int n = to_int(str);
                //cout<<n<<endl;
                s.push(n);
            }
        }
        int sum=0;
        while(!s.empty()){
            sum+=s.top();
            s.pop();
        }
        return sum;
}
int main(){
    //vector<string> s = {"1","C","-62","-45","-68"};
    vector<string> s = {"5","-2","4","C","D","9","+","+"};
    cout<<calPoints(s);
}
