// --- Day 18: Boiling Boulders ---
// 
// You and the elephants finally reach fresh air. You've emerged near the base of a large volcano that seems to be actively erupting! Fortunately, the lava seems to be flowing away from you and toward the ocean.
// 
// Bits of lava are still being ejected toward you, so you're sheltering in the cavern exit a little longer. Outside the cave, you can see the lava landing in a pond and hear it loudly hissing as it solidifies.
// 
// Depending on the specific compounds in the lava and speed at which it cools, it might be forming obsidian! The cooling rate should be based on the surface area of the lava droplets, so you take a quick scan of a droplet as it flies past you (your puzzle input).
// 
// Because of how quickly the lava is moving, the scan isn't very good; its resolution is quite low and, as a result, it approximates the shape of the lava droplet with 1x1x1 cubes on a 3D grid, each given as its x,y,z position.
// 
// To approximate the surface area, count the number of sides of each cube that are not immediately connected to another cube. So, if your scan were only two adjacent cubes like 1,1,1 and 2,1,1, each cube would have a single side covered and five sides exposed, a total surface area of 10 sides.
// 
// Here's a larger example:
// 
// 2,2,2
// 1,2,2
// 3,2,2
// 2,1,2
// 2,3,2
// 2,2,1
// 2,2,3
// 2,2,4
// 2,2,6
// 1,2,5
// 3,2,5
// 2,1,5
// 2,3,5
// In the above example, after counting up all the sides that aren't connected to another cube, the total surface area is 64.
// 
// What is the surface area of your scanned lava droplet?

#include<iostream>
#include<fstream>
#include<unordered_map>
#include<vector>
using namespace std;

struct PositionHash {
    int operator() (const vector<int> &v) const {
        int hash = v.size();
        for(const int &i : v) hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        return hash;
    }
};

typedef unordered_map<vector<int>, int>::iterator mpit;

int main () {
    ifstream input;
    input.open("day18_input.txt");
    unordered_map<vector<int>, int, PositionHash> mp;
    string s;
    while(input >> s) {
        int p = 0, pp = p, o = 6;
        vector<int> c;
        for(int i = 0; i < 3; i++){
            while(p < s.size() && s[p] != ',') p++;
            c.push_back(stoi(s.substr(pp, p - pp)));
            p += 1, pp = p;
        }
        for(int i = 0; i < 3; i++) {
            c[i] -= 1;
            if(mp[c]) mp[c]--, o--;
            c[i] += 2;
            if(mp[c]) mp[c]--, o--;
            c[i]--;
        }
        mp[c] = o;
    }
    long ans = 0;
    for(mpit it = mp.begin(); it != mp.end(); it++) ans += it->second;
    cout << ans << endl;
    return 0;
}

