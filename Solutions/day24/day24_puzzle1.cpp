// --- Day 24: Blizzard Basin ---
// 
// With everything replanted for next year (and with elephants and monkeys to tend the grove), you and the Elves leave for the extraction point.
// 
// Partway up the mountain that shields the grove is a flat, open area that serves as the extraction point. It's a bit of a climb, but nothing the expedition can't handle.
// 
// At least, that would normally be true; now that the mountain is covered in snow, things have become more difficult than the Elves are used to.
// 
// As the expedition reaches a valley that must be traversed to reach the extraction site, you find that strong, turbulent winds are pushing small blizzards of snow and sharp ice around the valley. It's a good thing everyone packed warm clothes! To make it across safely, you'll need to find a way to avoid them.
// 
// Fortunately, it's easy to see all of this from the entrance to the valley, so you make a map of the valley and the blizzards (your puzzle input). For example:
// 
// #.#####
// #.....#
// #>....#
// #.....#
// #...v.#
// #.....#
// #####.#
// The walls of the valley are drawn as #; everything else is ground. Clear ground - where there is currently no blizzard - is drawn as .. Otherwise, blizzards are drawn with an arrow indicating their direction of motion: up (^), down (v), left (<), or right (>).
// 
// The above map includes two blizzards, one moving right (>) and one moving down (v). In one minute, each blizzard moves one position in the direction it is pointing:
// 
// #.#####
// #.....#
// #.>...#
// #.....#
// #.....#
// #...v.#
// #####.#
// Due to conservation of blizzard energy, as a blizzard reaches the wall of the valley, a new blizzard forms on the opposite side of the valley moving in the same direction. After another minute, the bottom downward-moving blizzard has been replaced with a new downward-moving blizzard at the top of the valley instead:
// 
// #.#####
// #...v.#
// #..>..#
// #.....#
// #.....#
// #.....#
// #####.#
// Because blizzards are made of tiny snowflakes, they pass right through each other. After another minute, both blizzards temporarily occupy the same position, marked 2:
// 
// #.#####
// #.....#
// #...2.#
// #.....#
// #.....#
// #.....#
// #####.#
// After another minute, the situation resolves itself, giving each blizzard back its personal space:
// 
// #.#####
// #.....#
// #....>#
// #...v.#
// #.....#
// #.....#
// #####.#
// Finally, after yet another minute, the rightward-facing blizzard on the right is replaced with a new one on the left facing the same direction:
// 
// #.#####
// #.....#
// #>....#
// #.....#
// #...v.#
// #.....#
// #####.#
// This process repeats at least as long as you are observing it, but probably forever.
// 
// Here is a more complex example:
// 
// #.######
// #>>.<^<#
// #.<..<<#
// #>v.><>#
// #<^v^^>#
// ######.#
// Your expedition begins in the only non-wall position in the top row and needs to reach the only non-wall position in the bottom row. On each minute, you can move up, down, left, or right, or you can wait in place. You and the blizzards act simultaneously, and you cannot share a position with a blizzard.
// 
// In the above example, the fastest way to reach your goal requires 18 steps. Drawing the position of the expedition as E, one way to achieve this is:
// 
// Initial state:
// #E######
// #>>.<^<#
// #.<..<<#
// #>v.><>#
// #<^v^^>#
// ######.#
// 
// Minute 1, move down:
// #.######
// #E>3.<.#
// #<..<<.#
// #>2.22.#
// #>v..^<#
// ######.#
// 
// Minute 2, move down:
// #.######
// #.2>2..#
// #E^22^<#
// #.>2.^>#
// #.>..<.#
// ######.#
// 
// Minute 3, wait:
// #.######
// #<^<22.#
// #E2<.2.#
// #><2>..#
// #..><..#
// ######.#
// 
// Minute 4, move up:
// #.######
// #E<..22#
// #<<.<..#
// #<2.>>.#
// #.^22^.#
// ######.#
// 
// Minute 5, move right:
// #.######
// #2Ev.<>#
// #<.<..<#
// #.^>^22#
// #.2..2.#
// ######.#
// 
// Minute 6, move right:
// #.######
// #>2E<.<#
// #.2v^2<#
// #>..>2>#
// #<....>#
// ######.#
// 
// Minute 7, move down:
// #.######
// #.22^2.#
// #<vE<2.#
// #>>v<>.#
// #>....<#
// ######.#
// 
// Minute 8, move left:
// #.######
// #.<>2^.#
// #.E<<.<#
// #.22..>#
// #.2v^2.#
// ######.#
// 
// Minute 9, move up:
// #.######
// #<E2>>.#
// #.<<.<.#
// #>2>2^.#
// #.v><^.#
// ######.#
// 
// Minute 10, move right:
// #.######
// #.2E.>2#
// #<2v2^.#
// #<>.>2.#
// #..<>..#
// ######.#
// 
// Minute 11, wait:
// #.######
// #2^E^2>#
// #<v<.^<#
// #..2.>2#
// #.<..>.#
// ######.#
// 
// Minute 12, move down:
// #.######
// #>>.<^<#
// #.<E.<<#
// #>v.><>#
// #<^v^^>#
// ######.#
// 
// Minute 13, move down:
// #.######
// #.>3.<.#
// #<..<<.#
// #>2E22.#
// #>v..^<#
// ######.#
// 
// Minute 14, move right:
// #.######
// #.2>2..#
// #.^22^<#
// #.>2E^>#
// #.>..<.#
// ######.#
// 
// Minute 15, move right:
// #.######
// #<^<22.#
// #.2<.2.#
// #><2>E.#
// #..><..#
// ######.#
// 
// Minute 16, move right:
// #.######
// #.<..22#
// #<<.<..#
// #<2.>>E#
// #.^22^.#
// ######.#
// 
// Minute 17, move down:
// #.######
// #2.v.<>#
// #<.<..<#
// #.^>^22#
// #.2..2E#
// ######.#
// 
// Minute 18, move down:
// #.######
// #>2.<.<#
// #.2v^2<#
// #>..>2>#
// #<....>#
// ######E#
// What is the fewest number of minutes required to avoid the blizzards and reach the goal?

#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>
#include<queue>
using namespace std;

pair<pair<int, int>, map<pair<int, int>, vector<int>>> parse(ifstream &input) {
    string s;
    int r = 0, c = -1;
    map<pair<int, int>, vector<int>> mp;
    while(getline(input, s)) {
       if(c == -1) c = s.size();
       for(int i = 0; i < s.size(); i++) {
           if(s[i] == '#') mp[{r, i}] = {5, 5, 5, 5, 5};
           else if(s[i] == '.') mp[{r, i}] = {};
           else if(s[i] == '^') mp[{r, i}] = {1};
           else if(s[i] == '>') mp[{r, i}] = {2};
           else if(s[i] == 'v') mp[{r, i}] = {3};
           else if(s[i] == '<') mp[{r, i}] = {4};
       }
       r++;
    }
   return {{r, c}, mp};
}

int main() {
    ifstream input;
    input.open("day24_input.txt");
    pair<pair<int, int>, map<pair<int, int>, vector<int>>> d = parse(input);
    int mxr = d.first.first, mxc = d.first.second, t = 0, ans = -1;
    map<pair<int, int>, vector<int>> mp = d.second, bp;
    map<pair<int, int>, int> vis;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int dirs[5] = {-1, 0, 1, 0, -1};
    pq.push({0, {0, 1}});
    while(!pq.empty() && ans == -1) {
        while(!pq.empty() && pq.top().first <= t){
            int ct = pq.top().first, r = pq.top().second.first, c = pq.top().second.second;
            pq.pop();
            if(r == mxr - 1 && c == mxc - 2) ans = ct; 
            if(r < 0 || c < 0 || r >= mxr || c >= mxc || mp[{r, c}].size()) continue;
            if(!vis[{r, c}]) pq.push({ct + 1, {r, c}}), vis[{r, c}] = 1;
            for(int i = 0; i < 4; i++)
                if(!vis[{r + dirs[i], c + dirs[i + 1]}]) pq.push({ct + 1, {r + dirs[i], c + dirs[i + 1]}}), vis[{r + dirs[i], c + dirs[i + 1]}] = 1;
        }
        vis.clear();
        for(int i = 0; i < mxr; i++){
            for(int j = 0; j < mxc; j++) {
                vector<int> v = mp[{i, j}];
                if(v.size() && v[0] != 5){
                    for(int k = 0; k < v.size(); k++){
                        if(v[k] == 1){
                            if(i == 1) bp[{mxr - 2, j}].push_back(1);
                            else bp[{i - 1, j}].push_back(1); 
                        } else if(v[k] == 2) {
                            if(j == mxc - 2) bp[{i, 1}].push_back(2);
                            else bp[{i, j + 1}].push_back(2);
                        } else if(v[k] == 3) {
                            if(i == mxr - 2) bp[{1, j}].push_back(3);
                            else bp[{i + 1, j}].push_back(3);
                        } else if(v[k] == 4) {
                            if(j == 1) bp[{i, mxc - 2}].push_back(4);
                            else bp[{i, j - 1}].push_back(4);
                        }
                    }
                } else if(v.size()) bp[{i, j}] = {5, 5, 5, 5, 5};
            }
        }
        mp = bp;
        bp.clear();
        t++;
    }
    cout << ans << endl;
    return 0;
}

