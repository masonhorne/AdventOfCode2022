// --- Part Two ---
// 
// The grove coordinate values seem nonsensical. While you ponder the mysteries of Elf encryption, you suddenly remember the rest of the decryption routine you overheard back at camp.
// 
// First, you need to apply the decryption key, 811589153. Multiply each number by the decryption key before you begin; this will produce the actual list of numbers to mix.
// 
// Second, you need to mix the list of numbers ten times. The order in which the numbers are mixed does not change during mixing; the numbers are still moved in the order they appeared in the original, pre-mixed list. (So, if -3 appears fourth in the original list of numbers to mix, -3 will be the fourth number to move during each round of mixing.)
// 
// Using the same example as above:
// 
// Initial arrangement:
// 811589153, 1623178306, -2434767459, 2434767459, -1623178306, 0, 3246356612
// 
// After 1 round of mixing:
// 0, -2434767459, 3246356612, -1623178306, 2434767459, 1623178306, 811589153
// 
// After 2 rounds of mixing:
// 0, 2434767459, 1623178306, 3246356612, -2434767459, -1623178306, 811589153
// 
// After 3 rounds of mixing:
// 0, 811589153, 2434767459, 3246356612, 1623178306, -1623178306, -2434767459
// 
// After 4 rounds of mixing:
// 0, 1623178306, -2434767459, 811589153, 2434767459, 3246356612, -1623178306
// 
// After 5 rounds of mixing:
// 0, 811589153, -1623178306, 1623178306, -2434767459, 3246356612, 2434767459
// 
// After 6 rounds of mixing:
// 0, 811589153, -1623178306, 3246356612, -2434767459, 1623178306, 2434767459
// 
// After 7 rounds of mixing:
// 0, -2434767459, 2434767459, 1623178306, -1623178306, 811589153, 3246356612
// 
// After 8 rounds of mixing:
// 0, 1623178306, 3246356612, 811589153, -2434767459, 2434767459, -1623178306
// 
// After 9 rounds of mixing:
// 0, 811589153, 1623178306, -2434767459, 3246356612, 2434767459, -1623178306
// 
// After 10 rounds of mixing:
// 0, -2434767459, 1623178306, 3246356612, -1623178306, 2434767459, 811589153
// The grove coordinates can still be found in the same way. Here, the 1000th number after 0 is 811589153, the 2000th is 2434767459, and the 3000th is -1623178306; adding these together produces 1623178306.
// 
// Apply the decryption key and mix your encrypted file ten times. What is the sum of the three numbers that form the grove coordinates?

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Node {
    public:
    Node *a, *b;
    long v;
    Node(long n) {
        this->v = n;
    }
};

vector<Node*> parse(ifstream &input) {
    vector<Node*> ans;
    long v;
    while(input >> v) {
        Node* n = new Node(v * 811589153);
        if(!ans.empty()) n->b = ans.back(), ans.back()->a = n;
        ans.push_back(n);
    }
    ans[0]->b = ans[ans.size() - 1], ans[ans.size() - 1]->a = ans[0];
    return ans;
}

int main () {
    ifstream input;
    input.open("day20_input.txt");
    vector<Node*> v = parse(input);
    Node* s;
    for(int i = 0; i < 10; i++) {
        for(Node* n : v) {
            long c = n->v;
            if(c == 0) s = n;
            else {
                Node *t = n;
                n->a->b = n->b, n->b->a = n->a;
                if(c < 0) {
                    c = abs(c) % (v.size() - 1) * -1;
                    while(c) n = n->b, c++;
                    t->b = n->b, t->a = n;
                } else {
                    c = c % (v.size() - 1);
                    while(c) n = n->a, c--;
                    t->a = n->a, t->b = n;
                }
                t->a->b = t, t->b->a = t;
            }
        }
    }
    long ans = 0;
    for(int i = 1; i <= 3000; i++){
        s = s->a;
        if(i % 1000 == 0) ans += s->v;
    }
    cout << ans << endl;
    return 0;
}

