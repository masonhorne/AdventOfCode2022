// --- Day 16: Proboscidea Volcanium ---
// 
// The sensors have led you to the origin of the distress signal: yet another handheld device, just like the one the Elves gave you. However, you don't see any Elves around; instead, the device is surrounded by elephants! They must have gotten lost in these tunnels, and one of the elephants apparently figured out how to turn on the distress signal.
// 
// The ground rumbles again, much stronger this time. What kind of cave is this, exactly? You scan the cave with your handheld device; it reports mostly igneous rock, some ash, pockets of pressurized gas, magma... this isn't just a cave, it's a volcano!
// 
// You need to get the elephants out of here, quickly. Your device estimates that you have 30 minutes before the volcano erupts, so you don't have time to go back out the way you came in.
// 
// You scan the cave for other options and discover a network of pipes and pressure-release valves. You aren't sure how such a system got into a volcano, but you don't have time to complain; your device produces a report (your puzzle input) of each valve's flow rate if it were opened (in pressure per minute) and the tunnels you could use to move between the valves.
// 
// There's even a valve in the room you and the elephants are currently standing in labeled AA. You estimate it will take you one minute to open a single valve and one minute to follow any tunnel from one valve to another. What is the most pressure you could release?
// 
// For example, suppose you had the following scan output:
// 
// Valve AA has flow rate=0; tunnels lead to valves DD, II, BB
// Valve BB has flow rate=13; tunnels lead to valves CC, AA
// Valve CC has flow rate=2; tunnels lead to valves DD, BB
// Valve DD has flow rate=20; tunnels lead to valves CC, AA, EE
// Valve EE has flow rate=3; tunnels lead to valves FF, DD
// Valve FF has flow rate=0; tunnels lead to valves EE, GG
// Valve GG has flow rate=0; tunnels lead to valves FF, HH
// Valve HH has flow rate=22; tunnel leads to valve GG
// Valve II has flow rate=0; tunnels lead to valves AA, JJ
// Valve JJ has flow rate=21; tunnel leads to valve II
// All of the valves begin closed. You start at valve AA, but it must be damaged or jammed or something: its flow rate is 0, so there's no point in opening it. However, you could spend one minute moving to valve BB and another minute opening it; doing so would release pressure during the remaining 28 minutes at a flow rate of 13, a total eventual pressure release of 28 * 13 = 364. Then, you could spend your third minute moving to valve CC and your fourth minute opening it, providing an additional 26 minutes of eventual pressure release at a flow rate of 2, or 52 total pressure released by valve CC.
// 
// Making your way through the tunnels like this, you could probably open many or all of the valves by the time 30 minutes have elapsed. However, you need to release as much pressure as possible, so you'll need to be methodical. Instead, consider this approach:
// 
// == Minute 1 ==
// No valves are open.
// You move to valve DD.
// 
// == Minute 2 ==
// No valves are open.
// You open valve DD.
// 
// == Minute 3 ==
// Valve DD is open, releasing 20 pressure.
// You move to valve CC.
// 
// == Minute 4 ==
// Valve DD is open, releasing 20 pressure.
// You move to valve BB.
// 
// == Minute 5 ==
// Valve DD is open, releasing 20 pressure.
// You open valve BB.
// 
// == Minute 6 ==
// Valves BB and DD are open, releasing 33 pressure.
// You move to valve AA.
// 
// == Minute 7 ==
// Valves BB and DD are open, releasing 33 pressure.
// You move to valve II.
// 
// == Minute 8 ==
// Valves BB and DD are open, releasing 33 pressure.
// You move to valve JJ.
// 
// == Minute 9 ==
// Valves BB and DD are open, releasing 33 pressure.
// You open valve JJ.
// 
// == Minute 10 ==
// Valves BB, DD, and JJ are open, releasing 54 pressure.
// You move to valve II.
// 
// == Minute 11 ==
// Valves BB, DD, and JJ are open, releasing 54 pressure.
// You move to valve AA.
// 
// == Minute 12 ==
// Valves BB, DD, and JJ are open, releasing 54 pressure.
// You move to valve DD.
// 
// == Minute 13 ==
// Valves BB, DD, and JJ are open, releasing 54 pressure.
// You move to valve EE.
// 
// == Minute 14 ==
// Valves BB, DD, and JJ are open, releasing 54 pressure.
// You move to valve FF.
// 
// == Minute 15 ==
// Valves BB, DD, and JJ are open, releasing 54 pressure.
// You move to valve GG.
// 
// == Minute 16 ==
// Valves BB, DD, and JJ are open, releasing 54 pressure.
// You move to valve HH.
// 
// == Minute 17 ==
// Valves BB, DD, and JJ are open, releasing 54 pressure.
// You open valve HH.
// 
// == Minute 18 ==
// Valves BB, DD, HH, and JJ are open, releasing 76 pressure.
// You move to valve GG.
// 
// == Minute 19 ==
// Valves BB, DD, HH, and JJ are open, releasing 76 pressure.
// You move to valve FF.
// 
// == Minute 20 ==
// Valves BB, DD, HH, and JJ are open, releasing 76 pressure.
// You move to valve EE.
// 
// == Minute 21 ==
// Valves BB, DD, HH, and JJ are open, releasing 76 pressure.
// You open valve EE.
// 
// == Minute 22 ==
// Valves BB, DD, EE, HH, and JJ are open, releasing 79 pressure.
// You move to valve DD.
// 
// == Minute 23 ==
// Valves BB, DD, EE, HH, and JJ are open, releasing 79 pressure.
// You move to valve CC.
// 
// == Minute 24 ==
// Valves BB, DD, EE, HH, and JJ are open, releasing 79 pressure.
// You open valve CC.
// 
// == Minute 25 ==
// Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.
// 
// == Minute 26 ==
// Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.
// 
// == Minute 27 ==
// Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.
// 
// == Minute 28 ==
// Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.
// 
// == Minute 29 ==
// Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.
// 
// == Minute 30 ==
// Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.
// This approach lets you release the most pressure possible in 30 minutes with this valve layout, 1651.
// 
// Work out the steps to release the most pressure in 30 minutes. What is the most pressure you can release?

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
    int mask = (2 << (vd.first.size() - 2)) - 1;
    cout << dfs(0, 0, 0, 0, 0, mask, vd.first, vd.second) << endl;
    return 0;
}

