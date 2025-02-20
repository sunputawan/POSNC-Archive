#include <iostream>
#include <vector>
char name[9]={'S','A','B','C','D','E','F','G','H'};
char pop_from[9]={};
int edge[9][9]={0,3,2,5,0,0,0,0,0,
               0,0,0,3,0,0,0,2,0,
               0,5,0,0,6,0,0,0,0,
               0,0,4,0,0,0,0,0,3,
               0,0,0,0,0,2,3,0,0,
               0,0,0,0,0,0,5,0,0,
               0,0,0,0,0,0,0,0,0,
               0,0,0,0,4,5,0,0,0,
               0,4,0,0,4,0,0,0,0};
using namespace std;

vector<char> Open={'S'};
vector<char> Visited;

int searchname(char a){
    for(int i=0;i<9;i++){
        if(name[i]==a)
            return i;
    }
}
bool is_in_open(char a){
    for(int i=0;i<Open.size();i++){
        if(Open[i]==a)
            return true;
    }
    return false;
}
bool is_in_visited(char a){
    for(int i=0;i<Visited.size();i++){
        if(Visited[i]==a)
            return true;
    }
    return false;
}
void depth_first_search(char goal){
    while(Open.size()!=0){
        char q=Open[0];
        int n=searchname(q);
        Open.erase(Open.begin());
        Visited.push_back(q);
        if(q==goal){
            for(int i=1;i<9;i++){
                if(q==name[i])
                    cout<<endl<<"** ";
                cout<<name[i]<<"(from "<<pop_from[i]<<")"<<endl;
                if(q==name[i])
                    cout<<endl;
            }
            return;
        }
        for(int i=0;i<9;i++){
            if((edge[n][i])&&(!is_in_visited(name[i]))&&(!is_in_open(name[i]))){
                Open.push_back(name[i]);
                pop_from[i]=q;
            }
        }
    }
}
int main(){
    char goal='E';
    pop_from[0]='\0';
    depth_first_search(goal);

}

