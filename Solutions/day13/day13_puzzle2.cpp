// --- Part Two ---
// 
// Now, you just need to put all of the packets in the right order. Disregard the blank lines in your list of received packets.
// 
// The distress signal protocol also requires that you include two additional divider packets:
// 
// [[2]]
// [[6]]
// Using the same rules as before, organize all packets - the ones in your list of received packets as well as the two divider packets - into the correct order.
// 
// For the example above, the result of putting the packets in the correct order is:
// 
// []
// [[]]
// [[[]]]
// [1,1,3,1,1]
// [1,1,5,1,1]
// [[1],[2,3,4]]
// [1,[2,[3,[4,[5,6,0]]]],8,9]
// [1,[2,[3,[4,[5,6,7]]]],8,9]
// [[1],4]
// [[2]]
// [3]
// [[4,4],4,4]
// [[4,4],4,4,4]
// [[6]]
// [7,7,7]
// [7,7,7,7]
// [[8,7,6]]
// [9]
// Afterward, locate the divider packets. To find the decoder key for this distress signal, you need to determine the indices of the two divider packets and multiply them together. (The first packet is at index 1, the second packet is at index 2, and so on.) In this example, the divider packets are 10th and 14th, and so the decoder key is 140.
// 
// Organize all of the packets into the correct order. What is the decoder key for the distress signal?

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int ordered(const string &a, const string &b) {
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
           res = ordered(a.substr(s1 + 1, e1 - s1 - 2), b.substr(s2 + 1, e2 - s2 - 2));
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
        return a[0] == '[' ? ordered(a, ns) : ordered(ns, b);
    } else {
        int p1 = 0, p2 = 0;
        while(p1 < a.size() && a[p1] != ',') p1++;
        while(p2 < b.size() && b[p2] != ',') p2++;
        int v1 = stoi(a.substr(0, p1)), v2 = stoi(b.substr(0, p2));
        if(v1 != v2) return v1 < v2 ? 1 : -1;
        if(p1 >= a.size() && p2 >= b.size()) return 0;
        if(p1 >= a.size()) return 1;
        if(p2 >= b.size()) return -1;
        return ordered(a.substr(p1 + 1, a.size() - p1 - 1), b.substr(p2 + 1, b.size() - p2 - 1));
    }
}

bool compare(const string &a, const string &b) {
    return ordered(a, b) == 1 ? 1 : 0;
}

int main () {
    ifstream input;
    input.open("day13_input.txt");
    vector<string> v;
    string s, t;
    while(getline(input, s) && getline(input, t)) {
        v.push_back(s);
        v.push_back(t);
        getline(input, s);
    }
    v.push_back("[[2]]");
    v.push_back("[[6]]");
    sort(v.begin(), v.end(), compare);
    long k, j;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == "[[2]]") k = i + 1;
        else if(v[i] == "[[6]]") j = i + 1;
    }
    cout << k * j << endl;
    return 0;
}

