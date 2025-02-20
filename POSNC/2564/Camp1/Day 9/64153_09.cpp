#include <iostream>

using namespace std;
int main(){
    string s;
    int j=0;
    int line=0;
    int length,width;
    cin>>s>>length>>width;
    int n=int(s.size());
    cout<<n<<endl;
    while(line!=width){
        //.cout<<j<<":"<<n<<" ";
        j=line;
        j%=n;
        for(int i=0;i<length;i++){
            if(j==s.size()){
                j=0;
            }
            cout<<s[j];
            j++;

        }
        line++;
        cout<<endl;
    }

}
