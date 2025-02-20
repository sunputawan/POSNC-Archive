#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int base;
    string num1,num2,num3;
    cin>>base>>num1>>num2;
    for(int i=1;i<=max(num1.size(),num2.size());i++){
        int x,y;
        //cout<<int(num1.size())-i<<" "<<int(num2.size()-i)<<"\t";
        if(int(num1.size()-i)<0)x=48;
        else x = num1[num1.size()-i];
        if(int(num2.size()-i)<0)y=48;
        else y = num2[num2.size()-i];
        //cout<<x<<" "<<y<<" : ";
        if(x<='9')
            x-=48;
        else
            x-=55;
        if(y<='9')
            y-=48;
        else
            y-=55;
        //cout<<x<<" "<<y<<endl;
        num3.push_back(x+y);
    }
    reverse(num3.begin(),num3.end());
    bool tmp = false;
    for(int i=num3.size()-1;i>=0;i--){
        if(tmp){
            num3[i]++;
            tmp=false;
        }
        if(num3[i]>=base){
            tmp=true;
            num3[i]-=base;
            if(i==0)
                cout<<1;
        }
    }
    for(auto c:num3){
        if(c>=10)
            cout<<char(c+55);
        else
            cout<<int(c);
    }
}
