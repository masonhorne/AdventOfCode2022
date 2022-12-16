// --- Part Two ---
// 
// Your handheld device indicates that the distress signal is coming from a beacon nearby. The distress beacon is not detected by any sensor, but the distress beacon must have x and y coordinates each no lower than 0 and no larger than 4000000.
// 
// To isolate the distress beacon's signal, you need to determine its tuning frequency, which can be found by multiplying its x coordinate by 4000000 and then adding its y coordinate.
// 
// In the example above, the search space is smaller: instead, the x and y coordinates can each be at most 20. With this reduced search area, there is only a single position that could have a beacon: x=14, y=11. The tuning frequency for this distress beacon is 56000011.
// 
// Find the only possible position for the distress beacon. What is its tuning frequency?

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

const int Y = 4000000;

vector<vector<int>> parse(ifstream &input) {
    vector<vector<int>> ans;
    string s;
    while(getline(input, s)) {
        for(int i = 0; i < s.size(); i++){
            if(s[i] != 'x' && s[i + 1] != '=') continue;
            int p = i + 2;
            while(s[p] != ',') p++;
            int sx = stoi(s.substr(i + 2, p - i - 2));
            i = p + 4, p = i;
            while(s[p] != ':') p++;
            int sy = stoi(s.substr(i, p - i));
            i = p + 1;
            while(s[i] != 'x' && s[i + 1] != '=') i++;
            p = i + 2;
            while(s[p] != ',') p++;
            int bx = stoi(s.substr(i + 2, p - i - 2));
            i = s.size();
            int by = stoi(s.substr(p + 4, i - p));
            ans.push_back({sx, sy, abs(sx - bx) + abs(sy - by), bx, by});
        }
    }
    return ans;
}

int main () {
    ifstream input;
    input.open("day15_input.txt");
    vector<vector<int>> v = parse(input);
    long ax = -1, ay = -1;
    for(int k = 0; k <= Y && ax == -1; k++){
        vector<pair<int, int>> r;
        for(vector<int> p : v) {
            int x = p[0], y = p[1], mh = p[2], dis = abs(y - k);
            if(dis <= mh) {
                int left = mh - dis;
                if(left >= 0) r.push_back({x - left, x + left});
            }
        }
        sort(r.begin(), r.end());
        int p = 0;
        for(int i = 1; i < r.size(); i++)
            if(r[p].second >= r[i].first) r[p].second = max(r[p].second, r[i].second);
            else r[++p] = r[i];
        if(p > 0) ax = r[0].second + 1, ay = k;
    }
    cout << ax * 4000000 + ay << endl;
    return 0;
}

