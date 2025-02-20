#include <iostream>
#include <set>
#include <queue>
#include <climits>

using namespace std;

#define N 8

int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

bool isValid(int x, int y){
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;
    return true;
}
struct node{
    int x,y,distance;
    int cost;
    node(int x,int y,int distance =0): x(x),y(y),distance(distance){}

    bool operator<(const node& o) const{
        return x<o.x || (x==o.x&&y<o.y);
    }
};
