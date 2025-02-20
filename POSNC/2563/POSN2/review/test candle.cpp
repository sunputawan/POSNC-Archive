#include <bits/stdc++.h>
using namespace std;
char w[2005][2005]; //���红����ŷ��⨷�������
int main() {
  int m, n;
  scanf("%d%d", &m, &n); //�纨ӹǹ�ǡѺ��������
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      scanf(" %c", &w[i][j]);
  queue<pair<int, int>> q; //���纾ԡѴ㹡�ä��ҵ���ǡ��ҧ
  int di[8][2] = {
      {1, 0}, {-1, 0}, {0, 1},  {0, -1},
      {1, 1}, {-1, 1}, {1, -1}, {-1, -1}}; //������ǹ�社ԡѴ�ͺ�ԡѴ�Ѩ�غѹ��� 8 ���
  int ans = 0;                             //��Ѻ����դ��������������
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (w[i][j] == '1') {
        ans++;
        q.emplace(i, j);
        while (!q.empty()) {
          pair<int, int> f = q.front(); //�֧�����ŵ��˹���ش�ͧ queue
          q.pop();
          int x = f.first, y = f.second;
          if (w[x][y] == '0')
            continue;
          w[x][y] = '0';
          for (int k = 0; k < 8; k++) {
            int xx = x + di[k][0], yy = y + di[k][1]; //��˹��㹾ԡѴ�ͺ�ԡѴ�Ѩ�غѹ
            if (xx < 1 || xx > m || yy < 1 ||
                yy > n) //��Ǩ�ͺ�������Թ���ҧ㹤����繨�ԧ
              continue;
            if (w[xx][yy] == '1')
              q.emplace(xx, yy);
          }
        }
      }
  printf("%d", ans);
}
