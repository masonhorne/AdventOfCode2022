// --- Part Two ---
// 
// You're worried that even with an optimal approach, the pressure released won't be enough. What if you got one of the elephants to help you?
// 
// It would take you 4 minutes to teach an elephant how to open the right valves in the right order, leaving you with only 26 minutes to actually execute your plan. Would having two of you working together be better, even if it means having less time? (Assume that you teach the elephant before opening any valves yourself, giving you both the same full 26 minutes.)
// 
// In the example above, you could teach the elephant to help you as follows:
// 
// == Minute 1 ==
// No valves are open.
// You move to valve II.
// The elephant moves to valve DD.
// 
// == Minute 2 ==
// No valves are open.
// You move to valve JJ.
// The elephant opens valve DD.
// 
// == Minute 3 ==
// Valve DD is open, releasing 20 pressure.
// You open valve JJ.
// The elephant moves to valve EE.
// 
// == Minute 4 ==
// Valves DD and JJ are open, releasing 41 pressure.
// You move to valve II.
// The elephant moves to valve FF.
// 
// == Minute 5 ==
// Valves DD and JJ are open, releasing 41 pressure.
// You move to valve AA.
// The elephant moves to valve GG.
// 
// == Minute 6 ==
// Valves DD and JJ are open, releasing 41 pressure.
// You move to valve BB.
// The elephant moves to valve HH.
// 
// == Minute 7 ==
// Valves DD and JJ are open, releasing 41 pressure.
// You open valve BB.
// The elephant opens valve HH.
// 
// == Minute 8 ==
// Valves BB, DD, HH, and JJ are open, releasing 76 pressure.
// You move to valve CC.
// The elephant moves to valve GG.
// 
// == Minute 9 ==
// Valves BB, DD, HH, and JJ are open, releasing 76 pressure.
// You open valve CC.
// The elephant moves to valve FF.
// 
// == Minute 10 ==
// Valves BB, CC, DD, HH, and JJ are open, releasing 78 pressure.
// The elephant moves to valve EE.
// 
// == Minute 11 ==
// Valves BB, CC, DD, HH, and JJ are open, releasing 78 pressure.
// The elephant opens valve EE.
// 
// (At this point, all valves are open.)
// 
// == Minute 12 ==
// Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.
// 
// ...
// 
// == Minute 20 ==
// Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.
// 
// ...
// 
// == Minute 26 ==
// Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.
// With the elephant helping, after 26 minutes, the best you could do would release a total of 1707 pressure.
// 
// With you and an elephant working together for 26 minutes, what is the most pressure you could release?

#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

typedef map<string, pair<int, vector<string>>>::iterator mpit;

map<string, pair<int, vector<string>>> parse(ifstream &input) {
    map<string, pair<int, vector<string>>> g;
    string s;
    while(getline(input, s)) {
        string k = s.substr(6, 2);
        int p = 23;
        while(s[p] != ';') p++;
        int r = stoi(s.substr(23, p - 23));      
        while(s.substr(p, 6) != "valves" && s.substr(p, 5) != "valve") p++;
        p += s.substr(p, 6) == "valves" ? 7 : 6;
        vector<string> v;
        while(p < s.size()) v.push_back(s.substr(p, 2)), p += 4;
        g[k] = {r, v};
    }
    return g;
}

pair<vector<int>, vector<vector<int>>> floydwarshall(map<string, pair<int, vector<string>>> &g) {
    map<string, int> idxs;
    int p = 0;
    for(mpit it = g.begin(); it != g.end(); it++) idxs[it->first] = p++;
    vector<vector<int>> dis(p, vector<int>(p, INT_MAX / 2));                            
    vector<int> val(p);                                                                 
    int sz = 0;                                                                         
    for(mpit it = g.begin(); it != g.end(); it++) {                                     
        int u = idxs[it->first];                                                        
        val[u] = it->second.first;                                                      
        if(val[u]) sz++;
        dis[u][u] = 0;
        for(string n : it->second.second) dis[u][idxs[n]] = 1;
    }
    for(int i = 0; i < p; i++)
        for(int j = 0; j < p; j++)
            for(int k = 0; k < p; k++)
                if(dis[j][k] > dis[j][i] + dis[i][k]) dis[j][k] = dis[j][i] + dis[i][k];
    vector<vector<int>> ndis;
    vector<int> nval;
    for(int i = 0; i < p; i++){
        if(i == 0 || val[i]){
            nval.push_back(val[i]);
            vector<int> r;
            for(int j = 0; j < p; j++) if(j == 0 || val[j]) r.push_back(dis[i][j]);
            ndis.push_back(r);
        }
    }
    return {nval, ndis};
}    
 
int dfs(int idx, int time, int total, int opened, int cnt, int mask, vector<int> &val, vector<vector<int>> &dis) {
    if(cnt == mask) return total + (30 - time) * opened;
    int ans = 0;
    for(int i = 0; i < dis.size(); i++) {
        if(cnt & (1 << (i - 1)) || i == idx || !val[i] || !(mask & (1 << (i - 1)))) continue;
        long nt = time + dis[idx][i] + 1, ntt = total + opened * (dis[idx][i] + 1), no = opened + val[i];
        if(nt > 30) ans = max(ans, total + (30 - time) * opened);
        else ans = max(ans, dfs(i, nt, ntt, no, cnt | (1 << (i - 1)), mask, val, dis));
    }
    return ans;
}

int main() {
    ifstream input;
    input.open("day16_input.txt");
    map<string, pair<int, vector<string>>> g = parse(input);
    pair<vector<int>, vector<vector<int>>> vd = floydwarshall(g);
    int mask = (2 << (vd.first.size() - 2)) - 1, ans = 0;
    for(int s = 0; s < mask / 2; s++){
        int mmask = s;
        int emask = ~s & mask;
        ans = max(ans, dfs(0, 4, 0, 0, 0, mmask, vd.first, vd.second) + dfs(0, 4, 0, 0, 0, emask, vd.first, vd.second));
    }
    cout << ans << endl;
    return 0;
}

