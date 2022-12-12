// --- Part Two ---
// 
// You're worried you might not ever get your items back. So worried, in fact, that your relief that a monkey's inspection didn't damage an item no longer causes your worry level to be divided by three.
// 
// Unfortunately, that relief was all that was keeping your worry levels from reaching ridiculous levels. You'll need to find another way to keep your worry levels manageable.
// 
// At this rate, you might be putting up with these monkeys for a very long time - possibly 10000 rounds!
// 
// With these new rules, you can still figure out the monkey business after 10000 rounds. Using the same example above:
// 
// == After round 1 ==
// Monkey 0 inspected items 2 times.
// Monkey 1 inspected items 4 times.
// Monkey 2 inspected items 3 times.
// Monkey 3 inspected items 6 times.
// 
// == After round 20 ==
// Monkey 0 inspected items 99 times.
// Monkey 1 inspected items 97 times.
// Monkey 2 inspected items 8 times.
// Monkey 3 inspected items 103 times.
// 
// == After round 1000 ==
// Monkey 0 inspected items 5204 times.
// Monkey 1 inspected items 4792 times.
// Monkey 2 inspected items 199 times.
// Monkey 3 inspected items 5192 times.
// 
// == After round 2000 ==
// Monkey 0 inspected items 10419 times.
// Monkey 1 inspected items 9577 times.
// Monkey 2 inspected items 392 times.
// Monkey 3 inspected items 10391 times.
// 
// == After round 3000 ==
// Monkey 0 inspected items 15638 times.
// Monkey 1 inspected items 14358 times.
// Monkey 2 inspected items 587 times.
// Monkey 3 inspected items 15593 times.
// 
// == After round 4000 ==
// Monkey 0 inspected items 20858 times.
// Monkey 1 inspected items 19138 times.
// Monkey 2 inspected items 780 times.
// Monkey 3 inspected items 20797 times.
// 
// == After round 5000 ==
// Monkey 0 inspected items 26075 times.
// Monkey 1 inspected items 23921 times.
// Monkey 2 inspected items 974 times.
// Monkey 3 inspected items 26000 times.
// 
// == After round 6000 ==
// Monkey 0 inspected items 31294 times.
// Monkey 1 inspected items 28702 times.
// Monkey 2 inspected items 1165 times.
// Monkey 3 inspected items 31204 times.
// 
// == After round 7000 ==
// Monkey 0 inspected items 36508 times.
// Monkey 1 inspected items 33488 times.
// Monkey 2 inspected items 1360 times.
// Monkey 3 inspected items 36400 times.
// 
// == After round 8000 ==
// Monkey 0 inspected items 41728 times.
// Monkey 1 inspected items 38268 times.
// Monkey 2 inspected items 1553 times.
// Monkey 3 inspected items 41606 times.
// 
// == After round 9000 ==
// Monkey 0 inspected items 46945 times.
// Monkey 1 inspected items 43051 times.
// Monkey 2 inspected items 1746 times.
// Monkey 3 inspected items 46807 times.
// 
// == After round 10000 ==
// Monkey 0 inspected items 52166 times.
// Monkey 1 inspected items 47830 times.
// Monkey 2 inspected items 1938 times.
// Monkey 3 inspected items 52013 times.
// After 10000 rounds, the two most active monkeys inspected items 52166 and 52013 times. Multiplying these together, the level of monkey business in this situation is now 2713310158.
// 
// Worry levels are no longer divided by three after each item is inspected; you'll need to find another way to keep your worry levels manageable. Starting again from the initial state in your puzzle input, what is the level of monkey business after 10000 rounds?

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Monkey {
    public:
    queue<long> items;
    pair<char, int> op;
    long div, to, from, inspected;
    Monkey(queue<long> v, pair<char, int> o, int d, int t, int f) {
        this->items = v;
        this->op = o;
        this->div = d;
        this->to = t;
        this->from = f;
        this->inspected = 0;
    }
};

Monkey* parse(ifstream &input) {
    string s;
    getline(input, s);
    int idx = s.size() - 1, p = idx;
    queue<long> v;
    while(s[idx + 1] != ':'){
        while(s[idx] != ' ') idx--;
        v.push(stoi(s.substr(idx + 1, p - idx)));
        idx -= 2, p = idx;
    }
    getline(input, s);
    idx = s.size() - 1;
    int va;
    if(s[idx] > '9' || s[idx] < '0') va = -1, idx -= 4;
    else{
        p = idx;
        while(s[idx] != ' ') idx--;
        va = stoi(s.substr(idx + 1, p - idx));
        idx--;
    }
    pair<char, int> op = make_pair(s[idx], va);
    vector<int> divtofrom;
    for(int i = 0; i < 3; i++){
        getline(input, s);
        idx = s.size() - 1, p = idx;
        while(s[idx] != ' ') idx--;
        divtofrom.push_back(stoi(s.substr(idx + 1, p - idx)));
    }
    getline(input, s);
    return new Monkey(v, op, divtofrom[0], divtofrom[1], divtofrom[2]); 
}


int main() {
    ifstream input;
    input.open("day11_input.txt");
    vector<Monkey*> m;
    string s;
    while(getline(input, s)) m.push_back(parse(input));
    long mod = 1;
    for(int i = 0; i < m.size(); i++) mod *= m[i]->div;
    for(int i = 0; i < 10000; i++) {
        for(int j = 0; j < m.size(); j++) {
            Monkey* mk = m[j];
            int sz = mk->items.size();
             for(int k = 0; k < sz; k++) {
                long it = mk->items.front();
                mk->items.pop();
                if(mk->op.first == '*') it *= mk->op.second == -1 ? it : mk->op.second;
                else it += mk->op.second == -1 ? it : mk->op.second;
                it %= mod;
                if(it % mk->div == 0) m[mk->to]->items.push(it);
                else m[mk->from]->items.push(it);
                mk->inspected++;
            }
        }
    }
    vector<int> v;
    for(int i = 0; i < m.size(); i++) v.push_back(m[i]->inspected);
    sort(v.begin(), v.end(), greater<int>());
    cout << fixed << (double) v[0] * v[1] << endl;
    return 0;
}

