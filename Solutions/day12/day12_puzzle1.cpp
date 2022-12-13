// --- Day 12: Hill Climbing Algorithm ---
// 
// You try contacting the Elves using your handheld device, but the river you're following must be too low to get a decent signal.
// 
// You ask the device for a heightmap of the surrounding area (your puzzle input). The heightmap shows the local area from above broken into a grid; the elevation of each square of the grid is given by a single lowercase letter, where a is the lowest elevation, b is the next-lowest, and so on up to the highest elevation, z.
// 
// Also included on the heightmap are marks for your current position (S) and the location that should get the best signal (E). Your current position (S) has elevation a, and the location that should get the best signal (E) has elevation z.
// 
// You'd like to reach E, but to save energy, you should do it in as few steps as possible. During each step, you can move exactly one square up, down, left, or right. To avoid needing to get out your climbing gear, the elevation of the destination square can be at most one higher than the elevation of your current square; that is, if your current elevation is m, you could step to elevation n, but not to elevation o. (This also means that the elevation of the destination square can be much lower than the elevation of your current square.)
// 
// For example:
// 
// Sabqponm
// abcryxxl
// accszExk
// acctuvwj
// abdefghi
// Here, you start in the top-left corner; your goal is near the middle. You could start by moving down or right, but eventually you'll need to head toward the e at the bottom. From there, you can spiral around to the goal:
// 
// v..v<<<<
// >v.vv<<^
// .>vv>E^^
// ..v>>>^^
// ..>>>>>^
// In the above diagram, the symbols indicate whether the path exits each square moving up (^), down (v), left (<), or right (>). The location that should get the best signal is still E, and . marks unvisited squares.
// 
// This path reaches the goal in 31 steps, the fewest possible.
// 
// What is the fewest steps required to move from your current position to the location that should get the best signal?

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
            if(g[i][j] == 'S') sx = i, sy = j;
            else if(g[i][j] == 'E') rx = i, ry = j;
        }
    }
    pq.push({0, {sx, sy}});
    g[sx][sy] = 'a', dis[sx][sy] = 0;
    int dirs[5] = {-1, 0, 1, 0, -1};
    while(!pq.empty()){
        pair<int, vector<int>> v = pq.top();
        pq.pop();
        int r = v.second[0], c = v.second[1];
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

