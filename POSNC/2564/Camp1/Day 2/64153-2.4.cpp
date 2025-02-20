#include <iostream>

using namespace std;
int main(){
    int score,m,f;
    cout<<"Enter enter midterm score : "; cin>>m;
    cout<<"Enter enter midterm score : "; cin>>f;
    if(m<0||m>100||f<0||f>100){
        cout<<"Invalid Input!!";
        return 0;
    }
    score = float(m+f)/2;
    char grade;
    cout<<"Your Score = "<<score<<"%\n";
    switch(score%10){
        case 10:
        case 9:
        case 8:{
            cout<<"Grade = G, Good";
            break;
        }
        case 7:
        case 6:
        case 5:{
            cout<<"Grade = P, Pass";
            break;;
        }
        default :{
            cout<<"Grade = F, Fail";
            break;
        }
    }
}
