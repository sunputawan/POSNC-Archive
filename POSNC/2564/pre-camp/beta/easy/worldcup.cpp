#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct stats{
    string name;
    int shoot;
    int shot;
    int diff;
    int score;
    stats(){
        shoot=0;
        shot=0;
        score=0;
    }
};
bool sort_by_shoot(const stats &a,const stats &b){
    return a.shoot>b.shoot;
}
bool sort_by_diff(const stats &a,const stats &b){
    return a.diff>b.diff;
}
bool sort_by_score(const stats &a,const stats &b){
    return a.score>b.score;
}
int result[4][4];
vector<stats> team(4);
int main(){
    for(int i=0;i<4;i++){
        cin>>team[i].name;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>result[i][j];
            if(i==j)
                continue;
            team[i].shoot+=result[i][j];
            team[j].shot+=result[i][j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(result[i][j]>result[j][i])
                team[i].score+=3;
            if(result[i][j]<result[j][i])
                team[j].score+=3;
            if(result[i][j]==result[j][i]){
                team[i].score++;
                team[j].score++;
            }
        }
        team[i].diff=team[i].shoot-team[i].shot;
    }
    std::sort(team.begin(),team.end(),sort_by_shoot);
    std::sort(team.begin(),team.end(),sort_by_diff);
    std::sort(team.begin(),team.end(),sort_by_score);
    for(int i=0;i<4;i++){
        cout<<team[i].name<<" "<<team[i].score<<endl;
    }
}
