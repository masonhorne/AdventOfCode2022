// --- Part Two ---
// 
// The Elf finishes helping with the tent and sneaks back over to you. "Anyway, the second column says how the round needs to end: X means you need to lose, Y means you need to end the round in a draw, and Z means you need to win. Good luck!"
// 
// The total score is still calculated in the same way, but now you need to figure out what shape to choose so the round ends as indicated. The example above now goes like this:
// 
// In the first round, your opponent will choose Rock (A), and you need the round to end in a draw (Y), so you also choose Rock. This gives you a score of 1 + 3 = 4.
// In the second round, your opponent will choose Paper (B), and you choose Rock so you lose (X) with a score of 1 + 0 = 1.
// In the third round, you will defeat your opponent's Scissors with Rock for a score of 1 + 6 = 7.
// Now that you're correctly decrypting the ultra top secret strategy guide, you would get a total score of 12.
// 
// Following the Elf's instructions for the second column, what would your total score be if everything goes exactly according to your strategy guide?

#include<iostream>
#include<fstream>
using namespace std;

int main() {
    fstream input;
    input.open("day2_input.txt");
    char a, b;
    long sum = 0;
    while(input >> a >> b) {
        int x = a == 'A' ? 0 : (a == 'B' ? 1 : 2);
	int y = b == 'X' ? (x + 2) % 3 : (b == 'Y' ? x : (x + 1) % 3);
	int w = x == y ? 3 : (y == (x + 1) % 3 ? 6 : 0);
        sum += y + 1 + w;
    }
    cout << sum << endl;
    return 0;
}
