// --- Part Two ---
// 
// As you watch the crane operator expertly rearrange the crates, you notice the process isn't following your prediction.
// 
// Some mud was covering the writing on the side of the crane, and you quickly wipe it away. The crane isn't a CrateMover 9000 - it's a CrateMover 9001.
// 
// The CrateMover 9001 is notable for many new and exciting features: air conditioning, leather seats, an extra cup holder, and the ability to pick up and move multiple crates at once.
// 
// Again considering the example above, the crates begin in the same configuration:
// 
//     [D]    
// [N] [C]    
// [Z] [M] [P]
//  1   2   3 
// Moving a single crate from stack 2 to stack 1 behaves the same as before:
// 
// [D]        
// [N] [C]    
// [Z] [M] [P]
//  1   2   3 
// However, the action of moving three crates from stack 1 to stack 3 means that those three moved crates stay in the same order, resulting in this new configuration:
// 
//         [D]
//         [N]
//     [C] [Z]
//     [M] [P]
//  1   2   3
// Next, as both crates are moved from stack 2 to stack 1, they retain their order as well:
// 
//         [D]
//         [N]
// [C]     [Z]
// [M]     [P]
//  1   2   3
// Finally, a single crate is still moved from stack 1 to stack 2, but now it's crate C that gets moved:
// 
//         [D]
//         [N]
//         [Z]
// [M] [C] [P]
//  1   2   3
// In this example, the CrateMover 9001 has put the crates in a totally different order: MCD.
// 
// Before the rearrangement process finishes, update your simulation so that the Elves know where they should stand to be ready to unload the final supplies. After the rearrangement procedure completes, what crate ends up on top of each stack?

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

vector<vector<char>> parse(ifstream &input) {
    string s;
    getline(input, s);
    int n = (s.size() + 1) / 4;
    vector<vector<char>> ans(n);
    while(s[1] != '1') {
        for(int i = 0; i < n; i++)
            if(s[1 + i * 4] != ' ') ans[i].push_back(s[1 + i * 4]);
        getline(input, s);
    }
    getline(input, s);
    for(int i = 0; i < n; i++) reverse(ans[i].begin(), ans[i].end());
    return ans;
}

int main () {
    ifstream input;
    input.open("day5_input.txt");
    vector<vector<char>> state = parse(input);
    int a, s, e;
    string f;
    while(input >> f) {
        input >> a >> f >> s >> f >> e;
        s -= 1, e -= 1;
        for(int i = state[s].size() - a; i < state[s].size(); i++)
            state[e].push_back(state[s][i]);
        while(a--) state[s].pop_back();
    }
    for(int i = 0; i < state.size(); i++) cout << state[i].back();
    cout << endl;
    return 0;
}

