// --- Part Two ---
// 
// By the time you calculate the answer to the Elves' question, they've already realized that the Elf carrying the most Calories of food might eventually run out of snacks.
// 
// To avoid this unacceptable situation, the Elves would instead like to know the total Calories carried by the top three Elves carrying the most Calories. That way, even if one of those Elves runs out of snacks, they still have two backups.
// 
// In the example above, the top three Elves are the fourth Elf (with 24000 Calories), then the third Elf (with 11000 Calories), then the fifth Elf (with 10000 Calories). The sum of the Calories carried by these three elves is 45000.
// 
// Find the top three Elves carrying the most Calories. How many Calories are those Elves carrying in total?

#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

int main() {
    ifstream input;
    input.open("day1_input.txt");
    string s;
    priority_queue<int, vector<int>, greater<int>> pq;
    int cur;
    while(!input.eof()) {
       getline(input, s);
       if(s != "") cur += stoi(s);
       else {
            pq.push(cur);
            cur = 0;
            if(pq.size() > 3) pq.pop();
       } 
    }
    long ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    } 
    cout << ans << endl;
    return 0;
}



