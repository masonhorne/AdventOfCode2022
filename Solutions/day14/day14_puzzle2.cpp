// --- Part Two ---
// 
// You realize you misread the scan. There isn't an endless void at the bottom of the scan - there's floor, and you're standing on it!
// 
// You don't have time to scan the floor, so assume the floor is an infinite horizontal line with a y coordinate equal to two plus the highest y coordinate of any point in your scan.
// 
// In the example above, the highest y coordinate of any point is 9, and so the floor is at y=11. (This is as if your scan contained one extra rock path like -infinity,11 -> infinity,11.) With the added floor, the example above now looks like this:
// 
//         ...........+........
//         ....................
//         ....................
//         ....................
//         .........#...##.....
//         .........#...#......
//         .......###...#......
//         .............#......
//         .............#......
//         .....#########......
//         ....................
// <-- etc #################### etc -->
// To find somewhere safe to stand, you'll need to simulate falling sand until a unit of sand comes to rest at 500,0, blocking the source entirely and stopping the flow of sand into the cave. In the example above, the situation finally looks like this after 93 units of sand come to rest:
// 
// ............o............
// ...........ooo...........
// ..........ooooo..........
// .........ooooooo.........
// ........oo#ooo##o........
// .......ooo#ooo#ooo.......
// ......oo###ooo#oooo......
// .....oooo.oooo#ooooo.....
// ....oooooooooo#oooooo....
// ...ooo#########ooooooo...
// ..ooooo.......ooooooooo..
// #########################
// Using your scan, simulate the falling sand until the source of the sand becomes blocked. How many units of sand come to rest?

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int m[700][700] = {};

void parse(ifstream &input) {
    string s;
    int my = 0;
    while(getline(input, s)) {
        int px = -1, py = -1;
        for(int i = 0; i < s.size(); i++) {
            int p = i;
            while(s[i] != ',') i++;
            int x = stoi(s.substr(p, i - p));
            p = i + 1;
            while(i < s.size() && s[i] != ' ') i++;
            int y = stoi(s.substr(p, i - p));
            my = max(my, y);
            if(px != -1 && py != -1){
                if(px != x){
                    if(px < x) for(int k = px; k <= x; k++) m[k][y] = 1;
                    else for(int k = px; k >= x; k--) m[k][y] = 1;
                } else {
                    if(py < y) for(int k = py; k <= y; k++) m[x][k] = 1;
                    else for(int k = py; k >= y; k--) m[x][k] = 1;
                }
            }
            px = x, py = y, i += 3;
        }
    }
    for(int i = 0; i < 700; i++) m[i][my + 2] = 1;
}

bool dfs(int i, int j) {
    if(!m[i][j + 1]) return dfs(i, j + 1);
    if(!m[i - 1][j + 1]) return dfs(i - 1, j + 1);
    if(!m[i + 1][j + 1]) return dfs(i + 1, j + 1);
    m[i][j] = 2;
    return i == 500 && j == 0;
}

int main() {
    ifstream input;
    input.open("day14_input.txt");
    parse(input);
    int ans = 1;
    while(!dfs(500, 0)) ans++;
    cout << ans << endl;
    return 0;
}

