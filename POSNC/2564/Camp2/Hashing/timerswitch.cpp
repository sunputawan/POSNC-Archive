#include <iostream>

using namespace std;
typedef long long ll;
const int p = 53;
const int mod = 1e9+7;
int main(){
    int n; string s,ss;
    cin>>n>>s;

    ll hashref = 0;
    ll highest = 1;
    for(auto c:s){
        hashref*=p;
        hashref+=(c-'0'+1);
        highest*=p;

    }

    ll currhash = hashref;
    ss = s+s;
    int i=0;
    //cout<<"ref : "<<hashref<<endl;
    for(int i=0;i<n;i++){
        currhash*=p;
        currhash-=(s[i]-'0'+1)*highest;
        currhash+=(s[i]-'0'+1);
        //cout<<currhash<<"\n";

        if(currhash==hashref){
            bool correct =true;

            for(int j=0;j<n;j++){
                if(s[j]!=ss[i+j+1]){
                    correct = false;
                    break;
                }
            }
            if(correct){
                cout<<i+1;
                return 0;
            }
        }
    }
    cout<<n;
}
