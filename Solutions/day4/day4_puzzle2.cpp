// --- Part Two ---
// 
// It seems like there is still quite a bit of duplicate work planned. Instead, the Elves would like to know the number of pairs that overlap at all.
// 
// In the above example, the first two pairs (2-4,6-8 and 2-3,4-5) don't overlap, while the remaining four pairs (5-7,7-9, 2-8,3-7, 6-6,4-6, and 2-6,4-8) do overlap:
// 
// 5-7,7-9 overlaps in a single section, 7.
// 2-8,3-7 overlaps all of the sections 3 through 7.
// 6-6,4-6 overlaps in a single section, 6.
// 2-6,4-8 overlaps in sections 4, 5, and 6.
// So, in this example, the number of overlapping assignment pairs is 4.
// 
// In how many assignment pairs do the ranges overlap?

#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
using namespace std;

pair<int, int> parse(string s){
    int c = 0;
    while(s[c] != '-') c++;
    return {stoi(s.substr(0, c)), stoi(s.substr(c + 1, s.size() - c - 1))};
}

int main() {
    ifstream input;
    input.open("day4_input.txt");
    long ans = 0;
    string s;
    while(input >> s) {
        int c = 0;
        while(s[c] != ',') c++;
        pair<int, int> i1 = parse(s.substr(0, c));
        pair<int, int> i2 = parse(s.substr(c + 1, s.size() - c - 1));
        int start = max(i1.first, i2.first);
        int end = min(i1.second, i2.second);
        if(end - start + 1 > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}

