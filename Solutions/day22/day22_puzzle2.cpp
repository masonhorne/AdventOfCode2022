// --- Part Two ---
// 
// As you reach the force field, you think you hear some Elves in the distance. Perhaps they've already arrived?
// 
// You approach the strange input device, but it isn't quite what the monkeys drew in their notes. Instead, you are met with a large cube; each of its six faces is a square of 50x50 tiles.
// 
// To be fair, the monkeys' map does have six 50x50 regions on it. If you were to carefully fold the map, you should be able to shape it into a cube!
// 
// In the example above, the six (smaller, 4x4) faces of the cube are:
// 
//         1111
//         1111
//         1111
//         1111
// 222233334444
// 222233334444
// 222233334444
// 222233334444
//         55556666
//         55556666
//         55556666
//         55556666
// You still start in the same position and with the same facing as before, but the wrapping rules are different. Now, if you would walk off the board, you instead proceed around the cube. From the perspective of the map, this can look a little strange. In the above example, if you are at A and move to the right, you would arrive at B facing down; if you are at C and move down, you would arrive at D facing up:
// 
//         ...#
//         .#..
//         #...
//         ....
// ...#.......#
// ........#..A
// ..#....#....
// .D........#.
//         ...#..B.
//         .....#..
//         .#......
//         ..C...#.
// Walls still block your path, even if they are on a different face of the cube. If you are at E facing up, your movement is blocked by the wall marked by the arrow:
// 
//         ...#
//         .#..
//      -->#...
//         ....
// ...#..E....#
// ........#...
// ..#....#....
// ..........#.
//         ...#....
//         .....#..
//         .#......
//         ......#.
// Using the same method of drawing the last facing you had with an arrow on each tile you visit, the full path taken by the above example now looks like this:
// 
//         >>v#    
//         .#v.    
//         #.v.    
//         ..v.    
// ...#..^...v#    
// .>>>>>^.#.>>    
// .^#....#....    
// .^........#.    
//         ...#..v.
//         .....#v.
//         .#v<<<<.
//         ..v...#.
// The final password is still calculated from your final position and facing from the perspective of the map. In this example, the final row is 5, the final column is 7, and the final facing is 3, so the final password is 1000 * 5 + 4 * 7 + 3 = 5031.
// 
// Fold the map into a cube, then follow the path given in the monkeys' notes. What is the final password?

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int face(int r, int c) {
    if(150 <= r && r < 200 && 0 <= c && c < 50) return 1;
    if(100 <= r && r < 150 && 0 <= c && c < 50) return 2;
    if(100 <= r && r < 150 && 50 <= c && c < 100) return 3;
    if(50 <= r && r < 100 && 50 <= c && c < 100) return 4;
    if(0 <= r && r < 50 && 50 <= c && c < 100) return 5;
    if(0 <= r && r < 50 && 100 <= c && c < 150) return 6;
    return -1;
}

int main () {
    ifstream input;
    input.open("day22_input.txt");
    int mx = 0;
    vector<string> v;
    string s;
    while(getline(input, s) && s != "") v.push_back(s), mx = s.size() > mx ? s.size() : mx;
    vector<string> g(v.size(), string(mx, ' '));
    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v[i].size(); j++) g[i][j] = v[i][j];
    input >> s;
    long m = g.size(), n = g[0].size(), r = 0, c = 0, d = 0, i = 0;
    while(g[r][c] != '.') c++;
    while(i < s.size()) {
        if(s[i] >= '0' && s[i] <= '9') {
            int cc = i, mv = 1;
            while(i < s.size() && s[i] >= '0' && s[i] <= '9') i++;
            cc = stoi(s.substr(cc, i - cc));
            while(mv && cc--) {
                int nr = r, nc = c, pd = d, f = face(nr, nc);
                if(f == 1 && d == 0 && nc + 1 >= 50) nc = 50 + (nr % 50),  nr = 149, d = 3;
                else if(f == 1 && d == 1 && nr + 1 >= 200) nc = 100 + (nc % 50), nr = 0, d = 1; 
                else if(f == 1 && d == 2 && nc - 1 < 0) nc = 50 + (nr % 50), nr = 0, d = 1; 
                else if(f == 2 && d == 2 && nc - 1 < 0)  nr = (49 - (nr % 50)), nc = 50, d = 0; 
                else if(f == 2 && d == 3 && nr - 1 < 100) nr = 50 + (nc % 50), nc = 50, d = 0; 
                else if(f == 3 && d == 1 && nr + 1 >= 150) nr = 150 + (nc % 50), nc = 49, d = 2; 
                else if(f == 3 && d == 0 && nc + 1 >= 100) nr = (49 - (nr % 50)), nc = 149, d = 2; 
                else if(f == 4 && d == 2 && nc - 1 < 50) nc = nr % 50, nr = 100, d = 1; 
                else if(f == 4 && d == 0 && nc + 1 >= 100) nc = 100 + (nr % 50), nr = 49, d = 3; 
                else if(f == 5 && d == 2 && nc - 1 < 50) nr = 100 + (49 - (nr % 50)), nc = 0, d = 0; 
                else if(f == 5 && d == 3 && nr - 1 < 0) nr = 150 + (nc % 50), nc = 0, d = 0; 
                else if(f == 6 && d == 3 && nr - 1 < 0) nc = (nc % 50), nr = 199, d = 3; 
                else if(f == 6 && d == 0 && nc + 1 >= 150) nr = 100 + (49 - (nr % 50)), nc = 99, d = 2; 
                else if(f == 6 && d == 1 && nr + 1 >= 50) nr = 50 + (nc % 50), nc = 99, d = 2; 
                else if(d == 0) nc += 1;
                else if(d == 1) nr += 1;
                else if(d == 2) nc -= 1;
                else if(d == 3) nr -= 1;
                if(g[nr][nc] == '#') mv = 0, d = pd;
                else r = nr, c = nc;
            }
        } else {
            if(s[i++] == 'R') d = (d + 1) % 4;
            else d = (d + 3) % 4;
        }
    }
    cout << (r + 1) * 1000 + 4 * (c + 1) + d << endl;
    return 0;
}

