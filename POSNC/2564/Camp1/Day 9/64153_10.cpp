#include <iostream>

using namespace std;
int main(){
    int n;
    string a;
    cin>>n;
    cin.ignore();
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        bool is_char = ('a'<=a[i]&&a[i]<='z')||('A'<=a[i]&&a[i]<='Z');
        if(!is_char){
            cout<<a[i];
            continue;
        }
        a[i]-=n;
        bool is_up = false;
        bool is_low = false;
        if(a[i]<='Z'){
            is_up = true;
        }
        else
            is_low = true;
        if(is_up&&a[i]<'A')
            a[i]+=26;
        if(is_low&&a[i]<'a')
            a[i]+=26;
        cout<<char(a[i]);
    }
}
