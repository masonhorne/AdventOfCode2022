// --- Part Two ---
// 
// Your device's communication system is correctly detecting packets, but still isn't working. It looks like it also needs to look for messages.
// 
// A start-of-message marker is just like a start-of-packet marker, except it consists of 14 distinct characters rather than 4.
// 
// Here are the first positions of start-of-message markers for all of the above examples:
// 
// mjqjpqmgbljsphdztnvjfqwrcgsmlb: first marker after character 19
// bvwbjplbgvbhsrlpgdmjqwftvncz: first marker after character 23
// nppdvjthqldpwncqszvftbrmjlhg: first marker after character 23
// nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg: first marker after character 29
// zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw: first marker after character 26
// How many characters need to be processed before the first start-of-message marker is detected?

#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
using namespace std;

int main () {
    fstream input;
    input.open("day6_input.txt");
    string s;
    input >> s;
    int o = 0, l = 0;
    unordered_map<char, int> mp;
    for(int i = 0; i < 14; i++) {
        mp[s[i] - 'a']++;
        if(mp[s[i] - 'a'] == 2) o++;
    }
    for(int r = 14; r < s.size() && o; r++){
        mp[s[l] - 'a']--;
        if(mp[s[l++] - 'a'] == 1) o--;
        mp[s[r] - 'a']++;
        if(mp[s[r] - 'a'] == 2) o++;
        if(!o) cout << r + 1 << endl;
    }
    return 0;
}

