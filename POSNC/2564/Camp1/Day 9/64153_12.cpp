#include <iostream>
#include <string.h>

using namespace std;
int main(){
    char str[100];
    char tmp[100];
    int head_index[100]={};
    bool available_str[100];
    int str_amount=0;
    cin>>str;
    int n = strlen(str);
    int start = 0;
    available_str[0]=true;
    for(int i=1;i<n;i++){
        available_str[i] = true;
        if(str[i]=='0'||i==n-1){
            head_index[str_amount]=start;
            start=i+1;
            str_amount++;
            continue;
        }
    }
    head_index[str_amount]=n;
    for(int i=0;i<str_amount;i++){
        int count=1;
        for(int j=i+1;j<str_amount;j++){
            if(!available_str[head_index[i]]||!available_str[head_index[j]]) continue;
            if(head_index[i+1]-head_index[i]!=head_index[j+1]-head_index[j]){  //check size
                continue;
            }
            int k=0;
            bool same = true;
            int ii=head_index[i];
            int jj=head_index[j];
            while(k!=head_index[i+1]-head_index[i]){
                if(str[ii]!=str[jj]){
                    same=false;
                    break;
                }
                ii++;jj++;k++;
            }

            if(same){
                count++;
                available_str[head_index[j]]=false;
            }
        }
        if(available_str[head_index[i]]){
            cout<<"'";
            for(int j=head_index[i];j<head_index[i+1];j++){
                cout<<str[j];
            }
        cout<<"' = "<<count<<endl;
        }
    }

    cout<<endl;
    for(int i=0;i<str_amount;i++){
        cout<<head_index[i]<<" ";
    }
}
