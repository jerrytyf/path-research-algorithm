#include <iostream>
using namespace std;
int sum = 0;
int ditu[50][50], book[50][50];
struct Node {
    int x, y, s, f;
};
Node que[25000];
int ans;
int fangxiang[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> ditu[i][j];
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    int head = 0, tail = 1;
  //  que[head] = {sx, sy, 0, -1};  // 初始化起点，f 设置为 -1 表示没有前驱
    que[head].x = sx;
    que[head].y = sy;
    que[head].s = 0;
    que[head].f = -1;
    int mark = 0;
    while (head < tail) {
        Node current = que[head];
        for (int i = 0; i < 4; i++) {
            int nx = current.x + fangxiang[i][0];
            int ny = current.y + fangxiang[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && ditu[nx][ny] == 0 && book[nx][ny] == 0) {
                book[nx][ny] = 1;
                que[tail].x = nx;
                que[tail].y = ny;
                que[tail].s = current.s + 1;
                que[tail].f = head;
                printf("%2d %2d\n",nx,ny);
                sum++;
                tail++;
             //   que[tail++] = {nx, ny, current.s + 1, head};
                if (nx == dx && ny == dy) {
                    ans = que[tail - 1].s;
                    mark = 1;
                    break;
                }
            }
        }
        if (mark) break;  // 如果找到路径，跳出循环
        head++;
    }
    cout<<sum;
/*
    // 输出路径
    if (ans != -1) {  // 假设 ans 初始化为 -1 表示未找到路径
        cout << ans << endl;
        int t = tail - 1;
        while (t != -1) {  // t != -1 表示不是起点
            cout << que[t].x << " " << que[t].y << "   ";
            t = que[t].f;
        }
       // cout << sx << " " << sy;  // 输出起点
    } else {
        cout << "No path found" << endl;
    }
    cout<<endl;
*/
    return 0;
}