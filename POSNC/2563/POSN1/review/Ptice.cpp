#include <iostream>
#include <vector>

using namespace std;
struct info{
    string name;
    int score;
    info(){
        score=0;
    }
}m[3];

int main(){
    int n;
    cin>>n;
    char ans[n];
    cin>>ans;
    m[0].name = "Adrian";
    m[1].name = "Bruno";
    m[2].name = "Goran";
    for(int i=0;i<n;i++){
        switch(i%3){
            case 0:{
                if(ans[i]=='A')
                    m[0].score++;
                break;
            }
            case 1:{
                if(ans[i]=='B')
                    m[0].score++;
                break;
            }
            case 2:{
                if(ans[i]=='C')
                    m[0].score++;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        switch(i%4){
            case 0:{
                if(ans[i]=='B')
                    m[1].score++;
                break;
            }
            case 1:{
                if(ans[i]=='A')
                    m[1].score++;
                break;
            }
            case 2:{
                if(ans[i]=='B')
                    m[1].score++;
                break;
            }
            case 3:{
                if(ans[i]=='C')
                    m[1].score++;
                break;
            }
        }
    }
      for(int i=0;i<n;i++){
        switch(i%6){
            case 0:{
                if(ans[i]=='C')
                    m[2].score++;
                break;
            }
            case 1:{
                if(ans[i]=='C')
                    m[2].score++;
                break;
            }
            case 2:{
                if(ans[i]=='A')
                    m[2].score++;
                break;
            }
            case 3:{
                if(ans[i]=='A')
                    m[2].score++;
                break;
            }
            case 4:{
                if(ans[i]=='B')
                    m[2].score++;
                break;
            }
            case 5:{
                if(ans[i]=='B')
                    m[2].score++;
                break;
            }
        }
    }
    int maximum=m[0].score;
    if(maximum<m[1].score)
        maximum=m[1].score;
    if(maximum<m[2].score)
        maximum=m[2].score;
    cout<<maximum<<endl;
    for(int i=0;i<3;i++){
        if(m[i].score==maximum)
            cout<<m[i].name<<endl;
    }
}
