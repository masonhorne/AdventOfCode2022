// --- Part Two ---
// 
// Something seems off about your calculation. The cooling rate depends on exterior surface area, but your calculation also included the surface area of air pockets trapped in the lava droplet.
// 
// Instead, consider only cube sides that could be reached by the water and steam as the lava droplet tumbles into the pond. The steam will expand to reach as much as possible, completely displacing any air on the outside of the lava droplet but never expanding diagonally.
// 
// In the larger example above, exactly one cube of air is trapped within the lava droplet (at 2,2,5), so the exterior surface area of the lava droplet is 58.
// 
// What is the exterior surface area of your scanned lava droplet?

#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

int main () {
    ifstream input;
    input.open("day18_input.txt");
    string s;
    int grid[30][30][30] = {};
    while(input >> s) {
        int p = 0, pp = p;
        vector<int> c;
        for(int i = 0; i < 3; i++){
            while(p < s.size() && s[p] != ',') p++;
            c.push_back(stoi(s.substr(pp, p - pp)));
            p += 1, pp = p;
        }
        grid[c[0]][c[1]][c[2]] = 1;
    }
    queue<vector<int>> q;
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++) {
            q.push({0, i, j});
            q.push({i, 0, j});
            q.push({i, j, 0});
        }
    }
    int ans = 0;
    while(!q.empty()) {
        vector<int> p = q.front();
        q.pop();
        int x = p[0], y = p[1], z = p[2];
        if(x < 0 || y < 0 || z < 0 || x >= 30 || y >= 30 || z >= 30 || grid[x][y][z] == 2) continue;
        if(grid[x][y][z] == 1) ans++;
        else{ 
            grid[x][y][z] = 2;
            q.push({x - 1, y, z});
            q.push({x + 1, y, z}); 
            q.push({x, y - 1, z});
            q.push({x, y + 1, z});
            q.push({x, y, z - 1});
            q.push({x, y, z + 1});
        }
    }
    cout << ans << endl;
    return 0;
}

