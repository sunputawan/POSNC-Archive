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

struct Node{
    int x, y, dist;
    int cost;
    Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}

    bool operator<(const Node& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};
int BFS(Node src, Node dest){
    set<Node> visited;
    queue<Node> q;
    q.push(src);
    while (!q.empty()){
        Node node = q.front();
        q.pop();

        int x = node.x;
        int y = node.y;
        int dist = node.dist;

        if (x == dest.x && y == dest.y){
            return dist;
        }
        if (!visited.count(node)){
            visited.insert(node);
            for (int i = 0; i < 8; i++){

                int x1 = x + row[i];
                int y1 = y + col[i];

                if (isValid(x1, y1)) {
                    q.push({x1, y1, dist + 1});
                }
            }
        }
    }

    return INT_MAX;
}

int main()
{
    Node src = {4, 4};
    Node dest = {0, 0};

    cout << "The minimum number of steps required is " << BFS(src, dest);

    return 0;
}
