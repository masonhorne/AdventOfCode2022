// --- Part Two ---
// 
// As you walk up the hill, you suspect that the Elves will want to turn this into a hiking trail. The beginning isn't very scenic, though; perhaps you can find a better starting point.
// 
// To maximize exercise while hiking, the trail should start as low as possible: elevation a. The goal is still the square marked E. However, the trail should still be direct, taking the fewest steps to reach its goal. So, you'll need to find the shortest path from any square at elevation a to the square marked E.
// 
// Again consider the example from above:
// 
// Sabqponm
// abcryxxl
// accszExk
// acctuvwj
// abdefghi
// Now, there are six choices for starting position (five marked a, plus the square marked S that counts as being at elevation a). If you start at the bottom-left square, you can reach the goal most quickly:
// 
// ...v<<<<
// ...vv<<^
// ...v>E^^
// .>v>>>^^
// >^>>>>>^
// This path reaches the goal in only 29 steps, the fewest possible.
// 
// What is the fewest steps required to move starting from any square with elevation a to the location that should get the best signal?

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int main () {
    ifstream input;
    input.open("day12_input.txt");
    vector<string> g;
    string s;
    while(getline(input, s)) g.push_back(s);
    int m = g.size(), n = g[0].size();
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
    int sx, sy, rx, ry;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) {
            if(g[i][j] == 'E') rx = i, ry = j; 
            else if(g[i][j] == 'S' || g[i][j] == 'a') {
                g[i][j] = 'a', dis[i][j] = 0;
                pq.push({0, {i, j}});
            }
        }
    }
    int dirs[5] = {-1, 0, 1, 0, -1};
    while(!pq.empty()){
        pair<int, vector<int>> v = pq.top();
        pq.pop();
        int r = v.second[0], c = v.second[1];
        dis[r][c] = min(dis[r][c], v.first);           
        for(int k = 0; k < 4; k++) {
            int nr = r + dirs[k];
            int nc = c + dirs[k + 1];
            if(nr < 0 || nc < 0 || nr >=m || nc >= n) continue;
            if((g[nr][nc] > g[r][c] + 1 && g[nr][nc] != 'E') || (g[nr][nc] == 'E' && g[r][c] <'y')) continue;
            if(dis[nr][nc] <= dis[r][c] + 1) continue;
            dis[nr][nc] = dis[r][c] + 1;
            pq.push({dis[r][c] + 1, {nr, nc}});
        }
    }
    cout << dis[rx][ry] << endl;
    return 0;
}

