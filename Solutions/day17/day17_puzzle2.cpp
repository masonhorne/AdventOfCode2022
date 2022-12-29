// --- Part Two ---
// 
// The elephants are not impressed by your simulation. They demand to know how tall the tower will be after 1000000000000 rocks have stopped! Only then will they feel confident enough to proceed through the cave.
// 
// In the example above, the tower would be 1514285714288 units tall!
// 
// How tall will the tower be after 1000000000000 rocks have stopped?

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<vector>
#include<unordered_map>
using namespace std;

struct StateHash {
    int operator() (const vector<int> &v) const {
        int hash = v.size();
        for(const int &i : v) hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        return hash;
    }
};

int main () {
    ifstream input;
    input.open("day17_input.txt");
    string s; input >> s;
    int grid[7][5000] = {};
    unordered_map<vector<int>, pair<int, int>, StateHash> mp;
    for(int i = 0; i < 7; i++) grid[i][0] = 1;
    int p = 0, r = 0, h = 0;
    long total = 1000000000000, hg = 0, c = 0; 
    while(r < total) {
        int rl = 2, rh = h + 4;
        bool fall = true;
        while(fall) {
            if(r % 5 == 0){
                if(s[p] == '<' && rl != 0 && !grid[rl - 1][rh]) rl--;           
                else if(s[p] == '>' && rl + 4 < 7 && !grid[rl + 4][rh]) rl++;   
                for(int i = rl; i < rl + 4 && fall; i++) {                                                  ///////////////////////
                    if(grid[i][rh - 1]) {                                                                   //                   //
                        for(int j = rl; j < rl + 4; j++) grid[j][rh] = 1;                                   //        ####       //
                        h = max(h, rh);                                                                     //                   //
                        fall = false;                                                                       ///////////////////////
                    }                                                           
                }
            } else if(r % 5 == 1) {
                if(s[p] == '<' && rl != 0 && !grid[rl - 1][rh + 1] && !grid[rl][rh] && !grid[rl][rh + 2]) rl--;                     
                else if(s[p] == '>' && rl + 3 < 7 && !grid[rl + 2][rh] && !grid[rl + 3][rh + 1] && !grid[rl + 2][rh + 2]) rl++;     
                if(grid[rl][rh] || grid[rl + 1][rh - 1] || grid[rl + 2][rh]){                                                                                  
                    for(int i = rl; i < rl + 3; i++) grid[i][rh + 1] = 1;                                   //////////////////////
                    grid[rl + 1][rh] = 1, grid[rl + 1][rh + 2] = 1;                                         //         #        //
                    h = max(h, rh + 2);                                                                     //        ###       //
                    fall = false;                                                                           //         #        //
                }                                                                                           //////////////////////
            } else if(r % 5 == 2) {
                if(s[p] == '<' && rl != 0 && !grid[rl - 1][rh] && !grid[rl + 1][rh + 1] && !grid[rl + 1][rh + 2]) rl--;
                else if(s[p] == '>' && rl + 3 < 7 && !grid[rl + 3][rh] && !grid[rl + 3][rh + 1] && !grid[rl + 3][rh + 2]) rl++;
                for(int i = rl; i < rl + 3 && fall; i++) {
                    if(grid[i][rh - 1]){
                        for(int j = rl; j < rl + 3; j++) grid[j][rh] = 1;                                   ///////////////////////
                        grid[rl + 2][rh + 1] = 1, grid[rl + 2][rh + 2] = 1;                                 //          #        //
                        h = max(h, rh + 2);                                                                 //          #        //
                        fall = false;                                                                       //        ###        //
                    }                                                                                       ///////////////////////
                }
            } else if(r % 5 == 3) {
                if(s[p] == '<' && rl != 0 && !grid[rl - 1][rh] && !grid[rl - 1][rh + 1] && !grid[rl - 1][rh + 2] && !grid[rl - 1][rh + 3]) rl--;
                else if(s[p] == '>' && rl + 1 < 7 && !grid[rl + 1][rh] && !grid[rl + 1][rh + 1] && !grid[rl + 1][rh + 2] && !grid[rl + 1][rh + 3]) rl++;
                if(grid[rl][rh - 1]) {                                                                      //////////////////////
                    grid[rl][rh] = 1, grid[rl][rh + 1] = 1, grid[rl][rh + 2] = 1, grid[rl][rh + 3] = 1;     //         #        //
                    h = max(h, rh + 3);                                                                     //         #        //
                    fall = false;                                                                           //         #        //
                }                                                                                           //         #        //
            } else {                                                                                        //////////////////////
                if(s[p] == '<' && rl != 0 && !grid[rl - 1][rh] && !grid[rl - 1][rh + 1]) rl--;
                else if(s[p] == '>' && rl + 2 < 7 && !grid[rl + 2][rh] && !grid[rl + 2][rh + 1]) rl++;
                if(grid[rl][rh - 1] || grid[rl + 1][rh - 1]) {
                    for(int i = rl; i < rl + 2; i++)                                                        ///////////////////////
                        for(int j = rh; j < rh + 2; j++)                                                    //        ##         //
                            grid[i][j] = 1;                                                                 //        ##         //
                    h = max(h, rh + 1);                                                                     ///////////////////////
                    fall = false;                                                    
                }
            }
            if(fall) rh--;
            else if(h >= 100 && !c){
                vector<int> l{r % 5, p};
                for(int i = h; i > h - 100; i--){
                    int v = 0;
                    for(int j = 0; j < 7; j++) v |= (grid[j][i] << j);
                    l.push_back(v);
                }
                if(!mp.count(l)) mp[l] = {r, h};
                else {
                    long er = r - mp[l].first, rr = total - r;
                    hg = h - mp[l].second, c = rr / er, total = r + (rr % er);
                }
            }
            p = (p + 1) % s.size();
        }
        r++;
    }
    cout << h + hg * c << endl;
    return 0;
}

