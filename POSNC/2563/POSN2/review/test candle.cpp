#include <bits/stdc++.h>
using namespace std;
char w[2005][2005]; //ใช้เก็บข้อมูลที่โจทย์ให้มา
int main() {
  int m, n;
  scanf("%d%d", &m, &n); //เก็บจำนวนแถวกับคอลั่มน์
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      scanf(" %c", &w[i][j]);
  queue<pair<int, int>> q; //ใช้เก็บพิกัดในการค้นหาตามแนวกว้าง
  int di[8][2] = {
      {1, 0}, {-1, 0}, {0, 1},  {0, -1},
      {1, 1}, {-1, 1}, {1, -1}, {-1, -1}}; //เอาไว้วนเช็คพิกัดรอบๆพิกัดปัจจุบันทั้ง 8 ทิศ
  int ans = 0;                             //ใช้นับว่ามีคนทั้งหมดที่กลุ่ม
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (w[i][j] == '1') {
        ans++;
        q.emplace(i, j);
        while (!q.empty()) {
          pair<int, int> f = q.front(); //ดึงข้อมูลตัวหน้าสุดของ queue
          q.pop();
          int x = f.first, y = f.second;
          if (w[x][y] == '0')
            continue;
          w[x][y] = '0';
          for (int k = 0; k < 8; k++) {
            int xx = x + di[k][0], yy = y + di[k][1]; //เก็บหนึ่งในพิกัดรอบๆพิกัดปัจจุบัน
            if (xx < 1 || xx > m || yy < 1 ||
                yy > n) //ตรวจสอบว่าไม่เกินตารางในความเป็นจริง
              continue;
            if (w[xx][yy] == '1')
              q.emplace(xx, yy);
          }
        }
      }
  printf("%d", ans);
}
