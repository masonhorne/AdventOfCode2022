// --- Day 17: Pyroclastic Flow ---
// 
// Your handheld device has located an alternative exit from the cave for you and the elephants. The ground is rumbling almost continuously now, but the strange valves bought you some time. It's definitely getting warmer in here, though.
// 
// The tunnels eventually open into a very tall, narrow chamber. Large, oddly-shaped rocks are falling into the chamber from above, presumably due to all the rumbling. If you can't work out where the rocks will fall next, you might be crushed!
// 
// The five types of rocks have the following peculiar shapes, where # is rock and . is empty space:
// 
// ####
// 
// .#.
// ###
// .#.
// 
// ..#
// ..#
// ###
// 
// #
// #
// #
// #
// 
// ##
// ##
// The rocks fall in the order shown above: first the - shape, then the + shape, and so on. Once the end of the list is reached, the same order repeats: the - shape falls first, sixth, 11th, 16th, etc.
// 
// The rocks don't spin, but they do get pushed around by jets of hot gas coming out of the walls themselves. A quick scan reveals the effect the jets of hot gas will have on the rocks as they fall (your puzzle input).
// 
// For example, suppose this was the jet pattern in your cave:
// 
// >>><<><>><<<>><>>><<<>>><<<><<<>><>><<>>
// In jet patterns, < means a push to the left, while > means a push to the right. The pattern above means that the jets will push a falling rock right, then right, then right, then left, then left, then right, and so on. If the end of the list is reached, it repeats.
// 
// The tall, vertical chamber is exactly seven units wide. Each rock appears so that its left edge is two units away from the left wall and its bottom edge is three units above the highest rock in the room (or the floor, if there isn't one).
// 
// After a rock appears, it alternates between being pushed by a jet of hot gas one unit (in the direction indicated by the next symbol in the jet pattern) and then falling one unit down. If any movement would cause any part of the rock to move into the walls, floor, or a stopped rock, the movement instead does not occur. If a downward movement would have caused a falling rock to move into the floor or an already-fallen rock, the falling rock stops where it is (having landed on something) and a new rock immediately begins falling.
// 
// Drawing falling rocks with @ and stopped rocks with #, the jet pattern in the example above manifests as follows:
// 
// The first rock begins falling:
// |..@@@@.|
// |.......|
// |.......|
// |.......|
// +-------+
// 
// Jet of gas pushes rock right:
// |...@@@@|
// |.......|
// |.......|
// |.......|
// +-------+
// 
// Rock falls 1 unit:
// |...@@@@|
// |.......|
// |.......|
// +-------+
// 
// Jet of gas pushes rock right, but nothing happens:
// |...@@@@|
// |.......|
// |.......|
// +-------+
// 
// Rock falls 1 unit:
// |...@@@@|
// |.......|
// +-------+
// 
// Jet of gas pushes rock right, but nothing happens:
// |...@@@@|
// |.......|
// +-------+
// 
// Rock falls 1 unit:
// |...@@@@|
// +-------+
// 
// Jet of gas pushes rock left:
// |..@@@@.|
// +-------+
// 
// Rock falls 1 unit, causing it to come to rest:
// |..####.|
// +-------+
// 
// A new rock begins falling:
// |...@...|
// |..@@@..|
// |...@...|
// |.......|
// |.......|
// |.......|
// |..####.|
// +-------+
// 
// Jet of gas pushes rock left:
// |..@....|
// |.@@@...|
// |..@....|
// |.......|
// |.......|
// |.......|
// |..####.|
// +-------+
// 
// Rock falls 1 unit:
// |..@....|
// |.@@@...|
// |..@....|
// |.......|
// |.......|
// |..####.|
// +-------+
// 
// Jet of gas pushes rock right:
// |...@...|
// |..@@@..|
// |...@...|
// |.......|
// |.......|
// |..####.|
// +-------+
// 
// Rock falls 1 unit:
// |...@...|
// |..@@@..|
// |...@...|
// |.......|
// |..####.|
// +-------+
// 
// Jet of gas pushes rock left:
// |..@....|
// |.@@@...|
// |..@....|
// |.......|
// |..####.|
// +-------+
// 
// Rock falls 1 unit:
// |..@....|
// |.@@@...|
// |..@....|
// |..####.|
// +-------+
// 
// Jet of gas pushes rock right:
// |...@...|
// |..@@@..|
// |...@...|
// |..####.|
// +-------+
// 
// Rock falls 1 unit, causing it to come to rest:
// |...#...|
// |..###..|
// |...#...|
// |..####.|
// +-------+
// 
// A new rock begins falling:
// |....@..|
// |....@..|
// |..@@@..|
// |.......|
// |.......|
// |.......|
// |...#...|
// |..###..|
// |...#...|
// |..####.|
// +-------+
// The moment each of the next few rocks begins falling, you would see this:
// 
// |..@....|
// |..@....|
// |..@....|
// |..@....|
// |.......|
// |.......|
// |.......|
// |..#....|
// |..#....|
// |####...|
// |..###..|
// |...#...|
// |..####.|
// +-------+
// 
// |..@@...|
// |..@@...|
// |.......|
// |.......|
// |.......|
// |....#..|
// |..#.#..|
// |..#.#..|
// |#####..|
// |..###..|
// |...#...|
// |..####.|
// +-------+
// 
// |..@@@@.|
// |.......|
// |.......|
// |.......|
// |....##.|
// |....##.|
// |....#..|
// |..#.#..|
// |..#.#..|
// |#####..|
// |..###..|
// |...#...|
// |..####.|
// +-------+
// 
// |...@...|
// |..@@@..|
// |...@...|
// |.......|
// |.......|
// |.......|
// |.####..|
// |....##.|
// |....##.|
// |....#..|
// |..#.#..|
// |..#.#..|
// |#####..|
// |..###..|
// |...#...|
// |..####.|
// +-------+
// 
// |....@..|
// |....@..|
// |..@@@..|
// |.......|
// |.......|
// |.......|
// |..#....|
// |.###...|
// |..#....|
// |.####..|
// |....##.|
// |....##.|
// |....#..|
// |..#.#..|
// |..#.#..|
// |#####..|
// |..###..|
// |...#...|
// |..####.|
// +-------+
// 
// |..@....|
// |..@....|
// |..@....|
// |..@....|
// |.......|
// |.......|
// |.......|
// |.....#.|
// |.....#.|
// |..####.|
// |.###...|
// |..#....|
// |.####..|
// |....##.|
// |....##.|
// |....#..|
// |..#.#..|
// |..#.#..|
// |#####..|
// |..###..|
// |...#...|
// |..####.|
// +-------+
// 
// |..@@...|
// |..@@...|
// |.......|
// |.......|
// |.......|
// |....#..|
// |....#..|
// |....##.|
// |....##.|
// |..####.|
// |.###...|
// |..#....|
// |.####..|
// |....##.|
// |....##.|
// |....#..|
// |..#.#..|
// |..#.#..|
// |#####..|
// |..###..|
// |...#...|
// |..####.|
// +-------+
// 
// |..@@@@.|
// |.......|
// |.......|
// |.......|
// |....#..|
// |....#..|
// |....##.|
// |##..##.|
// |######.|
// |.###...|
// |..#....|
// |.####..|
// |....##.|
// |....##.|
// |....#..|
// |..#.#..|
// |..#.#..|
// |#####..|
// |..###..|
// |...#...|
// |..####.|
// +-------+
// To prove to the elephants your simulation is accurate, they want to know how tall the tower will get after 2022 rocks have stopped (but before the 2023rd rock begins falling). In this example, the tower of rocks will be 3068 units tall.
// 
// How many units tall will the tower of rocks be after 2022 rocks have stopped falling?

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

int main () {
    ifstream input;
    input.open("day17_input.txt");
    string s; input >> s;
    int grid[7][5000] = {};
    for(int i = 0; i < 7; i++) grid[i][0] = 1;
    int p = 0, r = 0, h = 0;
    while(r < 2022) {
        int rl = 2, rh = h + 4;
        bool fall = true;
        while(fall) {
            if(r % 5 == 0){
                if(s[p] == '<' && rl != 0 && !grid[rl - 1][rh]) rl--;           
                else if(s[p] == '>' && rl + 4 < 7 && !grid[rl + 4][rh]) rl++;   
                for(int i = rl; i < rl + 4 && fall; i++) {                                                  ///////////////////////
                    if(grid[i][rh - 1]) {                                                                   //                   //
                        for(int j = rl; j < rl + 4; j++) grid[j][rh] = 1;                                   //        ####       //
                        h = max(h, rh);                                                                     //                   //
                        fall = false;                                                                       ///////////////////////
                    }                                                           
                }
            } else if(r % 5 == 1) {
                if(s[p] == '<' && rl != 0 && !grid[rl - 1][rh + 1] && !grid[rl][rh] && !grid[rl][rh + 2]) rl--;                     
                else if(s[p] == '>' && rl + 3 < 7 && !grid[rl + 2][rh] && !grid[rl + 3][rh + 1] && !grid[rl + 2][rh + 2]) rl++;     
                if(grid[rl][rh] || grid[rl + 1][rh - 1] || grid[rl + 2][rh]){                                                                                  
                    for(int i = rl; i < rl + 3; i++) grid[i][rh + 1] = 1;                                   //////////////////////
                    grid[rl + 1][rh] = 1, grid[rl + 1][rh + 2] = 1;                                         //         #        //
                    h = max(h, rh + 2);                                                                     //        ###       //
                    fall = false;                                                                           //         #        //
                }                                                                                           //////////////////////
            } else if(r % 5 == 2) {
                if(s[p] == '<' && rl != 0 && !grid[rl - 1][rh] && !grid[rl + 1][rh + 1] && !grid[rl + 1][rh + 2]) rl--;
                else if(s[p] == '>' && rl + 3 < 7 && !grid[rl + 3][rh] && !grid[rl + 3][rh + 1] && !grid[rl + 3][rh + 2]) rl++;
                for(int i = rl; i < rl + 3 && fall; i++) {
                    if(grid[i][rh - 1]){
                        for(int j = rl; j < rl + 3; j++) grid[j][rh] = 1;                                   ///////////////////////
                        grid[rl + 2][rh + 1] = 1, grid[rl + 2][rh + 2] = 1;                                 //          #        //
                        h = max(h, rh + 2);                                                                 //          #        //
                        fall = false;                                                                       //        ###        //
                    }                                                                                       ///////////////////////
                }
            } else if(r % 5 == 3) {
                if(s[p] == '<' && rl != 0 && !grid[rl - 1][rh] && !grid[rl - 1][rh + 1] && !grid[rl - 1][rh + 2] && !grid[rl - 1][rh + 3]) rl--;
                else if(s[p] == '>' && rl + 1 < 7 && !grid[rl + 1][rh] && !grid[rl + 1][rh + 1] && !grid[rl + 1][rh + 2] && !grid[rl + 1][rh + 3]) rl++;
                if(grid[rl][rh - 1]) {                                                                      //////////////////////
                    grid[rl][rh] = 1, grid[rl][rh + 1] = 1, grid[rl][rh + 2] = 1, grid[rl][rh + 3] = 1;     //         #        //
                    h = max(h, rh + 3);                                                                     //         #        //
                    fall = false;                                                                           //         #        //
                }                                                                                           //         #        //
            } else {                                                                                        //////////////////////
                if(s[p] == '<' && rl != 0 && !grid[rl - 1][rh] && !grid[rl - 1][rh + 1]) rl--;
                else if(s[p] == '>' && rl + 2 < 7 && !grid[rl + 2][rh] && !grid[rl + 2][rh + 1]) rl++;
                if(grid[rl][rh - 1] || grid[rl + 1][rh - 1]) {
                    for(int i = rl; i < rl + 2; i++)                                                        ///////////////////////
                        for(int j = rh; j < rh + 2; j++)                                                    //        ##         //
                            grid[i][j] = 1;                                                                 //        ##         //
                    h = max(h, rh + 1);                                                                     ///////////////////////
                    fall = false;                                                    
                }
            }
            if(fall) rh--;
            p = (p + 1) % s.size();
        }
        r++;
    }
    cout << h << endl;
    return 0;
}

