#include <bits/stdc++.h>

using namespace std;
int a[1000005];
int main(){
    int n;
    cin>>n;
    if(n<=2){
        cout<<2<<endl;
        return 0;
    }
    n--;
    if(n%2==0)
        n--;
    while(true){
        n+=2;
        bool pal = true;
        vector<int> dig;
        int tmp = n;
        while(n>0){
            dig.push_back(n%10);
            n/=10;
        }
        n = tmp;
        for(int i=0;i<dig.size()/2;i++){
            if(dig[i]!=dig[dig.size()-1-i]){
                pal = false;
                break;
            }
        }
        if(!pal) continue;
        //cout<<n<<'\n';
        bool prime = true;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                prime = false;
                break;
            }
        }
        if(!prime) continue;
        cout<<n<<endl;
        return 0;
    }
}
