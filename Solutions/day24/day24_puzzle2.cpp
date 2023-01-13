// --- Part Two ---
// 
// As the expedition reaches the far side of the valley, one of the Elves looks especially dismayed:
// 
// He forgot his snacks at the entrance to the valley!
// 
// Since you're so good at dodging blizzards, the Elves humbly request that you go back for his snacks. From the same initial conditions, how quickly can you make it from the start to the goal, then back to the start, then back to the goal?
// 
// In the above example, the first trip to the goal takes 18 minutes, the trip back to the start takes 23 minutes, and the trip back to the goal again takes 13 minutes, for a total time of 54 minutes.
// 
// What is the fewest number of minutes required to reach the goal, go back to the start, then reach the goal again?

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
    int mxr = d.first.first, mxc = d.first.second, t = 0, x = -1, y = -1, ans = -1;
    map<pair<int, int>, vector<int>> mp = d.second, bp;
    map<pair<int, int>, int> vis;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int dirs[5] = {-1, 0, 1, 0, -1};
    pq.push({0, {0, 1}});
    while(!pq.empty() && ans == -1) {
        while(!pq.empty() && pq.top().first <= t){
            int ct = pq.top().first, r = pq.top().second.first, c = pq.top().second.second;
            pq.pop();
            if(x == -1 && r == mxr - 1 && c == mxc - 2) x = ct, pq = priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>(), pq.push({ct + 1, {r, c}});
            else if(x != -1 && y == -1 && r == 0 && c == 1) y = ct, pq = priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>(), pq.push({ct + 1, {r, c}});
            else if(y != -1 && r == mxr - 1 && c == mxc - 2) ans = ct;
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

