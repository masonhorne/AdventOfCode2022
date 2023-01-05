// --- Part Two ---
// 
// Due to some kind of monkey-elephant-human mistranslation, you seem to have misunderstood a few key details about the riddle.
// 
// First, you got the wrong job for the monkey named root; specifically, you got the wrong math operation. The correct operation for monkey root should be =, which means that it still listens for two numbers (from the same two monkeys as before), but now checks that the two numbers match.
// 
// Second, you got the wrong monkey for the job starting with humn:. It isn't a monkey - it's you. Actually, you got the job wrong, too: you need to figure out what number you need to yell so that root's equality check passes. (The number that appears after humn: in your input is now irrelevant.)
// 
// In the above example, the number you need to yell to pass root's equality test is 301. (This causes root to get the same number, 150, from both of its monkeys.)
// 
// What number do you yell to pass root's equality test?

#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

unordered_map<string, vector<string>> parse(ifstream &input) {
    unordered_map<string, vector<string>> mp;
    string s;
    while(input >> s) {
        string t = s.substr(0, s.size() - 1);
        vector<string> v(3);
        input >> s;
        if(s[0] >= '0' && s[0] <= '9'){
            v.clear();
            v.push_back(s);
        } else {
            v[0] = s;
            input >> v[2] >> v[1];
        }
        mp[t] = v;
    }
    return mp;
}

long dfs(unordered_map<string, vector<string>> &mp, string t) {
    if(mp[t].size() == 1) return stol(mp[t][0]);
    long ans = 0;
    if(mp[t][2] == "+") ans = dfs(mp, mp[t][0]) + dfs(mp, mp[t][1]);
    if(mp[t][2] == "-") ans = dfs(mp, mp[t][0]) - dfs(mp, mp[t][1]);
    if(mp[t][2] == "*") ans = dfs(mp, mp[t][0]) * dfs(mp, mp[t][1]);
    if(mp[t][2] == "/") ans = dfs(mp, mp[t][0]) / dfs(mp, mp[t][1]);
    mp[t].clear();
    mp[t].push_back(to_string(ans));
    return ans;
}

pair<int, long> dependent(unordered_map<string, vector<string>> &mp, string t) {
    unordered_map<string, vector<string>> mpp = mp, mppp = mp;
    mpp["humn"].clear(), mppp["humn"].clear();
    mpp["humn"].push_back(to_string(stol(mp["humn"][0]))), mppp["humn"].push_back(to_string(stol(mp["humn"][0]) + 10));
    dfs(mpp, t), dfs(mppp, t);
    if(mpp[mp[t][0]][0] != mppp[mp[t][0]][0]) return {0, stol(mpp[mp[t][1]][0])};
    else return {1, stol(mpp[mp[t][0]][0])};
}

long solve(unordered_map<string, vector<string>> &mp, string t, long tv) {
    if(t == "humn") return tv;
    pair<int, long> di = dependent(mp, t);
    if(mp[t][2] == "-" && di.first) return solve(mp, mp[t][di.first], di.second - tv);
    else if(mp[t][2] == "-") return solve(mp, mp[t][di.first], tv + di.second);
    if(mp[t][2] == "+") return solve(mp, mp[t][di.first], tv - di.second);
    if(mp[t][2] == "*") return solve(mp, mp[t][di.first], tv / di.second);
    if(di.first) return solve(mp, mp[t][di.first], di.second / tv);
    else return solve(mp, mp[t][di.first], tv * di.second);
}

int main() {    
    ifstream input;
    input.open("day21_input.txt");
    unordered_map<string, vector<string>> mp = parse(input);
    pair<int, long> d = dependent(mp, "root");
    cout << solve(mp, mp["root"][d.first], d.second) << endl; 
    return 0;
}

