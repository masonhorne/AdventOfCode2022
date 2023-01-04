// --- Part Two ---
// 
// While you were choosing the best blueprint, the elephants found some food on their own, so you're not in as much of a hurry; you figure you probably have 32 minutes before the wind changes direction again and you'll need to get out of range of the erupting volcano.
// 
// Unfortunately, one of the elephants ate most of your blueprint list! Now, only the first three blueprints in your list are intact.
// 
// In 32 minutes, the largest number of geodes blueprint 1 (from the example above) can open is 56. One way to achieve that is:
// 
// == Minute 1 ==
// 1 ore-collecting robot collects 1 ore; you now have 1 ore.
// 
// == Minute 2 ==
// 1 ore-collecting robot collects 1 ore; you now have 2 ore.
// 
// == Minute 3 ==
// 1 ore-collecting robot collects 1 ore; you now have 3 ore.
// 
// == Minute 4 ==
// 1 ore-collecting robot collects 1 ore; you now have 4 ore.
// 
// == Minute 5 ==
// Spend 4 ore to start building an ore-collecting robot.
// 1 ore-collecting robot collects 1 ore; you now have 1 ore.
// The new ore-collecting robot is ready; you now have 2 of them.
// 
// == Minute 6 ==
// 2 ore-collecting robots collect 2 ore; you now have 3 ore.
// 
// == Minute 7 ==
// Spend 2 ore to start building a clay-collecting robot.
// 2 ore-collecting robots collect 2 ore; you now have 3 ore.
// The new clay-collecting robot is ready; you now have 1 of them.
// 
// == Minute 8 ==
// Spend 2 ore to start building a clay-collecting robot.
// 2 ore-collecting robots collect 2 ore; you now have 3 ore.
// 1 clay-collecting robot collects 1 clay; you now have 1 clay.
// The new clay-collecting robot is ready; you now have 2 of them.
// 
// == Minute 9 ==
// Spend 2 ore to start building a clay-collecting robot.
// 2 ore-collecting robots collect 2 ore; you now have 3 ore.
// 2 clay-collecting robots collect 2 clay; you now have 3 clay.
// The new clay-collecting robot is ready; you now have 3 of them.
// 
// == Minute 10 ==
// Spend 2 ore to start building a clay-collecting robot.
// 2 ore-collecting robots collect 2 ore; you now have 3 ore.
// 3 clay-collecting robots collect 3 clay; you now have 6 clay.
// The new clay-collecting robot is ready; you now have 4 of them.
// 
// == Minute 11 ==
// Spend 2 ore to start building a clay-collecting robot.
// 2 ore-collecting robots collect 2 ore; you now have 3 ore.
// 4 clay-collecting robots collect 4 clay; you now have 10 clay.
// The new clay-collecting robot is ready; you now have 5 of them.
// 
// == Minute 12 ==
// Spend 2 ore to start building a clay-collecting robot.
// 2 ore-collecting robots collect 2 ore; you now have 3 ore.
// 5 clay-collecting robots collect 5 clay; you now have 15 clay.
// The new clay-collecting robot is ready; you now have 6 of them.
// 
// == Minute 13 ==
// Spend 2 ore to start building a clay-collecting robot.
// 2 ore-collecting robots collect 2 ore; you now have 3 ore.
// 6 clay-collecting robots collect 6 clay; you now have 21 clay.
// The new clay-collecting robot is ready; you now have 7 of them.
// 
// == Minute 14 ==
// Spend 3 ore and 14 clay to start building an obsidian-collecting robot.
// 2 ore-collecting robots collect 2 ore; you now have 2 ore.
// 7 clay-collecting robots collect 7 clay; you now have 14 clay.
// The new obsidian-collecting robot is ready; you now have 1 of them.
// 
// == Minute 15 ==
// 2 ore-collecting robots collect 2 ore; you now have 4 ore.
// 7 clay-collecting robots collect 7 clay; you now have 21 clay.
// 1 obsidian-collecting robot collects 1 obsidian; you now have 1 obsidian.
// 
// == Minute 16 ==
// Spend 3 ore and 14 clay to start building an obsidian-collecting robot.
// 2 ore-collecting robots collect 2 ore; you now have 3 ore.
// 7 clay-collecting robots collect 7 clay; you now have 14 clay.
// 1 obsidian-collecting robot collects 1 obsidian; you now have 2 obsidian.
// The new obsidian-collecting robot is ready; you now have 2 of them.
// 
// == Minute 17 ==
// Spend 3 ore and 14 clay to start building an obsidian-collecting robot.
// 2 ore-collecting robots collect 2 ore; you now have 2 ore.
// 7 clay-collecting robots collect 7 clay; you now have 7 clay.
// 2 obsidian-collecting robots collect 2 obsidian; you now have 4 obsidian.
// The new obsidian-collecting robot is ready; you now have 3 of them.
// 
// == Minute 18 ==
// 2 ore-collecting robots collect 2 ore; you now have 4 ore.
// 7 clay-collecting robots collect 7 clay; you now have 14 clay.
// 3 obsidian-collecting robots collect 3 obsidian; you now have 7 obsidian.
// 
// == Minute 19 ==
// Spend 3 ore and 14 clay to start building an obsidian-collecting robot.
// 2 ore-collecting robots collect 2 ore; you now have 3 ore.
// 7 clay-collecting robots collect 7 clay; you now have 7 clay.
// 3 obsidian-collecting robots collect 3 obsidian; you now have 10 obsidian.
// The new obsidian-collecting robot is ready; you now have 4 of them.
// 
// == Minute 20 ==
// Spend 2 ore and 7 obsidian to start building a geode-cracking robot.
// 2 ore-collecting robots collect 2 ore; you now have 3 ore.
// 7 clay-collecting robots collect 7 clay; you now have 14 clay.
// 4 obsidian-collecting robots collect 4 obsidian; you now have 7 obsidian.
// The new geode-cracking robot is ready; you now have 1 of them.
// 
// == Minute 21 ==
// Spend 3 ore and 14 clay to start building an obsidian-collecting robot.
// 2 ore-collecting robots collect 2 ore; you now have 2 ore.
// 7 clay-collecting robots collect 7 clay; you now have 7 clay.
// 4 obsidian-collecting robots collect 4 obsidian; you now have 11 obsidian.
// 1 geode-cracking robot cracks 1 geode; you now have 1 open geode.
// The new obsidian-collecting robot is ready; you now have 5 of them.
// 
// == Minute 22 ==
// Spend 2 ore and 7 obsidian to start building a geode-cracking robot.
// 2 ore-collecting robots collect 2 ore; you now have 2 ore.
// 7 clay-collecting robots collect 7 clay; you now have 14 clay.
// 5 obsidian-collecting robots collect 5 obsidian; you now have 9 obsidian.
// 1 geode-cracking robot cracks 1 geode; you now have 2 open geodes.
// The new geode-cracking robot is ready; you now have 2 of them.
// 
// == Minute 23 ==
// Spend 2 ore and 7 obsidian to start building a geode-cracking robot.
// 2 ore-collecting robots collect 2 ore; you now have 2 ore.
// 7 clay-collecting robots collect 7 clay; you now have 21 clay.
// 5 obsidian-collecting robots collect 5 obsidian; you now have 7 obsidian.
// 2 geode-cracking robots crack 2 geodes; you now have 4 open geodes.
// The new geode-cracking robot is ready; you now have 3 of them.
// 
// == Minute 24 ==
// Spend 2 ore and 7 obsidian to start building a geode-cracking robot.
// 2 ore-collecting robots collect 2 ore; you now have 2 ore.
// 7 clay-collecting robots collect 7 clay; you now have 28 clay.
// 5 obsidian-collecting robots collect 5 obsidian; you now have 5 obsidian.
// 3 geode-cracking robots crack 3 geodes; you now have 7 open geodes.
// The new geode-cracking robot is ready; you now have 4 of them.
// 
// == Minute 25 ==
// 2 ore-collecting robots collect 2 ore; you now have 4 ore.
// 7 clay-collecting robots collect 7 clay; you now have 35 clay.
// 5 obsidian-collecting robots collect 5 obsidian; you now have 10 obsidian.
// 4 geode-cracking robots crack 4 geodes; you now have 11 open geodes.
// 
// == Minute 26 ==
// Spend 2 ore and 7 obsidian to start building a geode-cracking robot.
// 2 ore-collecting robots collect 2 ore; you now have 4 ore.
// 7 clay-collecting robots collect 7 clay; you now have 42 clay.
// 5 obsidian-collecting robots collect 5 obsidian; you now have 8 obsidian.
// 4 geode-cracking robots crack 4 geodes; you now have 15 open geodes.
// The new geode-cracking robot is ready; you now have 5 of them.
// 
// == Minute 27 ==
// Spend 2 ore and 7 obsidian to start building a geode-cracking robot.
// 2 ore-collecting robots collect 2 ore; you now have 4 ore.
// 7 clay-collecting robots collect 7 clay; you now have 49 clay.
// 5 obsidian-collecting robots collect 5 obsidian; you now have 6 obsidian.
// 5 geode-cracking robots crack 5 geodes; you now have 20 open geodes.
// The new geode-cracking robot is ready; you now have 6 of them.
// 
// == Minute 28 ==
// 2 ore-collecting robots collect 2 ore; you now have 6 ore.
// 7 clay-collecting robots collect 7 clay; you now have 56 clay.
// 5 obsidian-collecting robots collect 5 obsidian; you now have 11 obsidian.
// 6 geode-cracking robots crack 6 geodes; you now have 26 open geodes.
// 
// == Minute 29 ==
// Spend 2 ore and 7 obsidian to start building a geode-cracking robot.
// 2 ore-collecting robots collect 2 ore; you now have 6 ore.
// 7 clay-collecting robots collect 7 clay; you now have 63 clay.
// 5 obsidian-collecting robots collect 5 obsidian; you now have 9 obsidian.
// 6 geode-cracking robots crack 6 geodes; you now have 32 open geodes.
// The new geode-cracking robot is ready; you now have 7 of them.
// 
// == Minute 30 ==
// Spend 2 ore and 7 obsidian to start building a geode-cracking robot.
// 2 ore-collecting robots collect 2 ore; you now have 6 ore.
// 7 clay-collecting robots collect 7 clay; you now have 70 clay.
// 5 obsidian-collecting robots collect 5 obsidian; you now have 7 obsidian.
// 7 geode-cracking robots crack 7 geodes; you now have 39 open geodes.
// The new geode-cracking robot is ready; you now have 8 of them.
// 
// == Minute 31 ==
// Spend 2 ore and 7 obsidian to start building a geode-cracking robot.
// 2 ore-collecting robots collect 2 ore; you now have 6 ore.
// 7 clay-collecting robots collect 7 clay; you now have 77 clay.
// 5 obsidian-collecting robots collect 5 obsidian; you now have 5 obsidian.
// 8 geode-cracking robots crack 8 geodes; you now have 47 open geodes.
// The new geode-cracking robot is ready; you now have 9 of them.
// 
// == Minute 32 ==
// 2 ore-collecting robots collect 2 ore; you now have 8 ore.
// 7 clay-collecting robots collect 7 clay; you now have 84 clay.
// 5 obsidian-collecting robots collect 5 obsidian; you now have 10 obsidian.
// 9 geode-cracking robots crack 9 geodes; you now have 56 open geodes.
// However, blueprint 2 from the example above is still better; using it, the largest number of geodes you could open in 32 minutes is 62.
// 
// You no longer have enough blueprints to worry about quality levels. Instead, for each of the first three blueprints, determine the largest number of geodes you could open; then, multiply these three values together.
// 
// Don't worry about quality levels; instead, just determine the largest number of geodes you could open using each of the first three blueprints. What do you get if you multiply these numbers together?

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

vector<vector<int>> parse(ifstream &input) {
    vector<vector<int>> bps;
    string s;
    while(input >> s) {
        vector<int> bp(7);
        input >> s;
        bp[0] = stoi(s.substr(0, s.size() - 1));
        for(int i = 0; i < 5; i++) input >> s;
        bp[1] = stoi(s);
        for(int i = 0; i < 6; i++) input >> s;
        bp[2] = stoi(s);
        for(int i = 0; i < 6; i++) input >> s;
        bp[3] = stoi(s);
        for(int i = 0; i < 3; i++) input >> s;
        bp[4] = stoi(s);
        for(int i = 0; i < 6; i++) input >> s;
        bp[5] = stoi(s);
        for(int i = 0; i < 3; i++) input >> s;
        bp[6] = stoi(s);
        input >> s;
        bps.push_back(bp);
    }
    return bps;
}

int dfs(int o, int c, int obs, int g, int ro, int rc, int robs, int rg, int time, vector<int> &bp) {
    if(time < 0) return 0;
    int ans = g + rg * time;
    if(ro < max(max(bp[1], bp[2]), max(bp[3], bp[5]))){
        int mn = o < bp[1] ? (bp[1] - o) / ro + ((bp[1] - o) % ro != 0) + 1 : 1;
        ans = max(ans, dfs(o + ro * mn - bp[1], c + rc * mn, obs + robs * mn, g + rg * mn, ro + 1, rc, robs, rg, time - mn, bp));
    }
    if(rc < bp[4]){
        int mn = o < bp[2] ? (bp[2] - o) / ro + ((bp[2] - o) % ro != 0) + 1 : 1;
        ans = max(ans, dfs(o + ro * mn - bp[2], c + rc * mn, obs + robs * mn, g + rg * mn, ro, rc + 1, robs, rg, time - mn, bp));
    }
    if(rc && robs < bp[6]){
        int mn = o < bp[3] ? (bp[3] - o) / ro + ((bp[3] - o) % ro != 0) + 1 : 1;
        if(c < bp[4]) mn = max(mn, (bp[4] - c) / rc + ((bp[4] - c) % rc != 0) + 1);
        ans = max(ans, dfs(o + ro * mn - bp[3], c + rc * mn - bp[4], obs + robs * mn, g + rg * mn, ro, rc, robs + 1, rg, time - mn, bp));
    }
    if(robs){
        int mn = o < bp[5] ? (bp[5] - o) / ro + (bp[5] % ro != 0) + 1 : 1;
        if(obs < bp[6]) mn = max(mn, (bp[6] - obs) / robs + ((bp[6] - obs) % robs != 0) + 1);
        ans = max(ans, dfs(o + ro * mn - bp[5], c + rc * mn, obs + robs * mn - bp[6], g + rg * mn, ro, rc, robs, rg + 1, time - mn, bp));
    }
    return ans;
}

int main () {
    ifstream input;
    input.open("day19_input.txt");
    vector<vector<int>> bps = parse(input);
    long ans = 1;
    for(int i = 0; i < 3; i++) ans *= dfs(0, 0, 0, 0, 1, 0, 0, 0, 32, bps[i]);
    cout << ans << endl;
    return 0;
}

