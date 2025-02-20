#include <iostream>

using namespace std;
char block[5][5];
int n,m,k;
bool is_alp(int i,int j){
    if(block[i][j]>='A'&&block[i][j]<='Z')
        return true;
    else
        return false;
}
bool drop(void){
    bool isDropped = false;
    for(int j=0;j<m;j++){
        int floor = n-1;
        for(int i=n-1;i>=0;i--){
            if(block[i][j]=='#'){
                floor = i;
                continue;
            }
            if(block[i][j]=='-') continue;
            if(is_alp(i,j)){
                if(floor==i+1)
                    floor--;
                else{
                    block[floor-1][j] = block[i][j];
                    block[i][j] = '-';
                    floor--;
                    isDropped=true;
                }
            }
        }
    }
    return isDropped;
}
bool mergeblock(void){
    bool isMerged = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!is_alp(i,j)) continue;
            int tmpblock = block[i][j];
            if(tmpblock==block[i][j+1]){
                block[i][j] = '-';
                block[i][j+1] = '-';
                if(block[i][j+2]==tmpblock)
                    block[i][j+2] = '-';
                if(block[i+1][j+1]==tmpblock)
                    block[i+1][j+1] = '-';
                isMerged = true;
            }
            if(tmpblock==block[i+1][j]){
                block[i][j] = '-';
                block[i+1][j] = '-';
                isMerged = true;
            }
        }
    }
    return isMerged;
}
void printblock(void){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<block[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    cin>>n>>m;
    int startAlp = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>block[i][j];
            if(is_alp(i,j))
                startAlp++;
        }
    }
    cin>>k;
    int foul = 0;
    while(k--){
        int x,y;
        char dir;
        cin>>x>>y>>dir;
        int newy = y;
        if(dir=='L') newy--;
        else newy++;
        if(is_alp(x,y)&&block[x][newy]=='-'){
            block[x][newy]=block[x][y];
            block[x][y] = '-';
            bool isDropped;
            bool isMerged;
            do{
                isDropped = drop();
                isMerged = mergeblock();
            }while(isDropped||isMerged);
            //printblock();
        }
        else
            foul++;
    }
    int currAlp = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(is_alp(i,j))
                currAlp++;
        }
    }
    cout<<((startAlp-currAlp)-foul)*5<<endl;
    printblock();
    return 0;
}
