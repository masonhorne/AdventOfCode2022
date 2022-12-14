// --- Day 13: Distress Signal ---
// 
// You climb the hill and again try contacting the Elves. However, you instead receive a signal you weren't expecting: a distress signal.
// 
// Your handheld device must still not be working properly; the packets from the distress signal got decoded out of order. You'll need to re-order the list of received packets (your puzzle input) to decode the message.
// 
// Your list consists of pairs of packets; pairs are separated by a blank line. You need to identify how many pairs of packets are in the right order.
// 
// For example:
// 
// [1,1,3,1,1]
// [1,1,5,1,1]
// 
// [[1],[2,3,4]]
// [[1],4]
// 
// [9]
// [[8,7,6]]
// 
// [[4,4],4,4]
// [[4,4],4,4,4]
// 
// [7,7,7,7]
// [7,7,7]
// 
// []
// [3]
// 
// [[[]]]
// [[]]
// 
// [1,[2,[3,[4,[5,6,7]]]],8,9]
// [1,[2,[3,[4,[5,6,0]]]],8,9]
// Packet data consists of lists and integers. Each list starts with [, ends with ], and contains zero or more comma-separated values (either integers or other lists). Each packet is always a list and appears on its own line.
// 
// When comparing two values, the first value is called left and the second value is called right. Then:
// 
// If both values are integers, the lower integer should come first. If the left integer is lower than the right integer, the inputs are in the right order. If the left integer is higher than the right integer, the inputs are not in the right order. Otherwise, the inputs are the same integer; continue checking the next part of the input.
// If both values are lists, compare the first value of each list, then the second value, and so on. If the left list runs out of items first, the inputs are in the right order. If the right list runs out of items first, the inputs are not in the right order. If the lists are the same length and no comparison makes a decision about the order, continue checking the next part of the input.
// If exactly one value is an integer, convert the integer to a list which contains that integer as its only value, then retry the comparison. For example, if comparing [0,0,0] and 2, convert the right value to [2] (a list containing 2); the result is then found by instead comparing [0,0,0] and [2].
// Using these rules, you can determine which of the pairs in the example are in the right order:
// 
// == Pair 1 ==
// - Compare [1,1,3,1,1] vs [1,1,5,1,1]
//   - Compare 1 vs 1
//   - Compare 1 vs 1
//   - Compare 3 vs 5
//     - Left side is smaller, so inputs are in the right order
// 
// == Pair 2 ==
// - Compare [[1],[2,3,4]] vs [[1],4]
//   - Compare [1] vs [1]
//     - Compare 1 vs 1
//   - Compare [2,3,4] vs 4
//     - Mixed types; convert right to [4] and retry comparison
//     - Compare [2,3,4] vs [4]
//       - Compare 2 vs 4
//         - Left side is smaller, so inputs are in the right order
// 
// == Pair 3 ==
// - Compare [9] vs [[8,7,6]]
//   - Compare 9 vs [8,7,6]
//     - Mixed types; convert left to [9] and retry comparison
//     - Compare [9] vs [8,7,6]
//       - Compare 9 vs 8
//         - Right side is smaller, so inputs are not in the right order
// 
// == Pair 4 ==
// - Compare [[4,4],4,4] vs [[4,4],4,4,4]
//   - Compare [4,4] vs [4,4]
//     - Compare 4 vs 4
//     - Compare 4 vs 4
//   - Compare 4 vs 4
//   - Compare 4 vs 4
//   - Left side ran out of items, so inputs are in the right order
// 
// == Pair 5 ==
// - Compare [7,7,7,7] vs [7,7,7]
//   - Compare 7 vs 7
//   - Compare 7 vs 7
//   - Compare 7 vs 7
//   - Right side ran out of items, so inputs are not in the right order
// 
// == Pair 6 ==
// - Compare [] vs [3]
//   - Left side ran out of items, so inputs are in the right order
// 
// == Pair 7 ==
// - Compare [[[]]] vs [[]]
//   - Compare [[]] vs []
//     - Right side ran out of items, so inputs are not in the right order
// 
// == Pair 8 ==
// - Compare [1,[2,[3,[4,[5,6,7]]]],8,9] vs [1,[2,[3,[4,[5,6,0]]]],8,9]
//   - Compare 1 vs 1
//   - Compare [2,[3,[4,[5,6,7]]]] vs [2,[3,[4,[5,6,0]]]]
//     - Compare 2 vs 2
//     - Compare [3,[4,[5,6,7]]] vs [3,[4,[5,6,0]]]
//       - Compare 3 vs 3
//       - Compare [4,[5,6,7]] vs [4,[5,6,0]]
//         - Compare 4 vs 4
//         - Compare [5,6,7] vs [5,6,0]
//           - Compare 5 vs 5
//           - Compare 6 vs 6
//           - Compare 7 vs 0
//             - Right side is smaller, so inputs are not in the right order
// What are the indices of the pairs that are already in the right order? (The first pair has index 1, the second pair has index 2, and so on.) In the above example, the pairs in the right order are 1, 2, 4, and 6; the sum of these indices is 13.
// 
// Determine which pairs of packets are already in the right order. What is the sum of the indices of those pairs?

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int compare(const string &a, const string &b) {
    if(a == b) return 0;
    if(a.size() == 0) return 1;
    if(b.size() == 0) return -1;    
    if(a[0] == '[' && b[0] == '[') {
       int res = 0, s1 = 0, e1 = 1, s2 = 0, e2 = 1, ao = 1, bo = 1;
       while(!res && s1 < a.size() && s2 < b.size()){         
           while(ao){
               if(a[e1] == '[') ao++;
               else if(a[e1] == ']') ao--;
               e1++;
           }
           while(bo){
               if(b[e2] == '[') bo++;
               else if(b[e2] == ']') bo--;
               e2++;
           }    
           res = compare(a.substr(s1 + 1, e1 - s1 - 2), b.substr(s2 + 1, e2 - s2 - 2));
           s1 = e1, e1 = s1 + 1, s2 = e2, e2 = s2 + 1;
       }
       if(res) return res;
       if(s1 >= a.size() && s2 < b.size()) return 1;
       if(s2 >= b.size() && s1 < a.size()) return -1;
       return 0;
    } else if((a[0] == '[') != (b[0] == '[')) {
        string s = a[0] == '[' ? b : a;
        int p = 0;
        while(p < s.size() && s[p] != ',') p++;
        string ns = "[" + s.substr(0, p) + "]" + s.substr(p, s.size() - p);
        return a[0] == '[' ? compare(a, ns) : compare(ns, b);
    } else {
        int p1 = 0, p2 = 0;
        while(p1 < a.size() && a[p1] != ',') p1++;
        while(p2 < b.size() && b[p2] != ',') p2++;
        int v1 = stoi(a.substr(0, p1)), v2 = stoi(b.substr(0, p2));
        if(v1 != v2) return v1 < v2 ? 1 : -1;
        if(p1 >= a.size() && p2 >= b.size()) return 0;
        if(p1 >= a.size()) return 1;
        if(p2 >= b.size()) return -1;
        return compare(a.substr(p1 + 1, a.size() - p1 - 1), b.substr(p2 + 1, b.size() - p2 - 1));
    }
}

int main () {
    ifstream input;
    input.open("day13_input.txt");
    vector<pair<string, string>> v;
    string s, t;
    while(getline(input, s) && getline(input, t)) {
        v.push_back({s, t});
        getline(input, s);
    }
    int ans = 0;
    for(int i = 0; i < v.size(); i++)
        if(compare(v[i].first, v[i].second) == 1) ans += i + 1;
    cout << ans << endl;
    return 0;
}

