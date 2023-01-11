// --- Part Two ---
// 
// It seems you're on the right track. Finish simulating the process and figure out where the Elves need to go. How many rounds did you save them?
// 
// In the example above, the first round where no Elf moved was round 20:
// 
// .......#......
// ....#......#..
// ..#.....#.....
// ......#.......
// ...#....#.#..#
// #.............
// ....#.....#...
// ..#.....#.....
// ....#.#....#..
// .........#....
// ....#......#..
// .......#......
// Figure out where the Elves need to go. What is the number of the first round where no Elf moves?

#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>
using namespace std;

typedef map<pair<int, int>, pair<int, int>>::iterator mpit;

int main () {
    ifstream input;
    input.open("day23_input.txt");
    map<pair<int, int>, pair<int, int>> mp;
    map<pair<int, int>, int> pp; 
    string s;
    int p = 0, m = 0, r = 0, a = 1;
    while(getline(input, s)) {
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '#') mp[make_pair(p, i)] = {INT_MAX, INT_MAX}, m++; 
        p++;
    }
    p = 0;
    while(a){
        for(mpit it = mp.begin(); it != mp.end(); it++){
            int x = it->first.first, y = it->first.second;
            if(!mp.count(make_pair(x - 1, y + 1)) && !mp.count(make_pair(x - 1, y)) && !mp.count(make_pair(x - 1, y - 1)) && !mp.count(make_pair(x, y - 1)) &&
                    !mp.count(make_pair(x, y + 1)) && !mp.count(make_pair(x + 1, y - 1)) && !mp.count(make_pair(x + 1, y)) && !mp.count(make_pair(x + 1, y + 1))) continue;
            int mv = 1;
            for(int i = p; i < p + 4 && mv; i++){
                if(i % 4 == 0 && !mp.count(make_pair(x - 1, y - 1)) && !mp.count(make_pair(x - 1, y)) && !mp.count(make_pair(x - 1, y + 1))) mp[make_pair(x, y)] =
                    make_pair(x - 1, y), pp[make_pair(x - 1, y)] += 1, mv = 0;   
                else if(i % 4 == 1 && !mp.count(make_pair(x + 1, y - 1)) && !mp.count(make_pair(x + 1, y)) && !mp.count(make_pair(x + 1, y + 1))) mp[make_pair(x, y)] =
                    make_pair(x + 1, y), pp[make_pair(x + 1, y)] += 1, mv = 0;
                else if(i % 4 == 2 && !mp.count(make_pair(x - 1, y - 1)) && !mp.count(make_pair(x, y - 1)) && !mp.count(make_pair(x + 1, y - 1))) mp[make_pair(x, y)] =
                    make_pair(x, y - 1), pp[make_pair(x, y - 1)] += 1, mv = 0;
                else if(i % 4 == 3 && !mp.count(make_pair(x - 1, y + 1)) && !mp.count(make_pair(x, y + 1)) && !mp.count(make_pair(x + 1, y + 1))) mp[make_pair(x, y)] =
                    make_pair(x, y + 1), pp[make_pair(x, y + 1)] += 1, mv = 0;
            }
        }
        vector<mpit> b;
        for(mpit it = mp.begin(); it != mp.end(); it++) {
            if(pp[it->second] != 1) mp[it->first] = {INT_MAX, INT_MAX};
            else {
                mp[it->second] = {INT_MAX, INT_MAX};
                b.push_back(it);
            } 
        }
        if(!b.size()) a = 0;
        for(mpit it : b) mp.erase(it);
        pp.clear();
        p = (p + 1) % 4, r++;
    }
    cout << r << endl;
    return 0;
}

