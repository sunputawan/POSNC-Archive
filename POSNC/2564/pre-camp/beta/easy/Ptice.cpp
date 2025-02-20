#include <iostream>
#include <vector>

using namespace std;
struct score{
    int point;
    string name;
    score(){
        point=0;
    }
}student[3];
int main(){
    int n;
    string a;
    cin>>n>>a;
    student[0].name="Adrian";
    student[1].name="Bruno";
    student[2].name="Goran";
    for(int i=0;i<n;i++){
        switch(i%3){
            case 0:{
                if(a[i]=='A')
                    student[0].point++;
                break;
            }
            case 1:{
                if(a[i]=='B')
                    student[0].point++;
                break;
            }
            case 2:{
                if(a[i]=='C')
                    student[0].point++;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        switch(i%4){
            case 0:{
                if(a[i]=='B')
                    student[1].point++;
                break;
            }
            case 1:{
                if(a[i]=='A')
                    student[1].point++;
                break;
            }
            case 2:{
                if(a[i]=='B')
                    student[1].point++;
                break;
            }
            case 3:{
                if(a[i]=='C')
                    student[1].point++;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        switch(i%6){
            case 0:{
                if(a[i]=='C')
                    student[2].point++;
                break;
            }
            case 1:{
                if(a[i]=='C')
                    student[2].point++;
                break;
            }
            case 2:{
                if(a[i]=='A')
                    student[2].point++;
                break;
            }
            case 3:{
                if(a[i]=='A')
                    student[2].point++;
                break;
            }
            case 4:{
                if(a[i]=='B')
                    student[2].point++;
                break;
            }
            case 5:{
                if(a[i]=='B')
                    student[2].point++;
                break;
            }
        }
    }
    int max=student[0].point;
    if(max<student[1].point)
        max=student[1].point;
    if(max<student[2].point)
        max=student[2].point;
    cout<<max<<endl;
    for(int i=0;i<3;i++){
        if(student[i].point==max)
            cout<<student[i].name<<endl;
    }
}
