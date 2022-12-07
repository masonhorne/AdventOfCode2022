// --- Part Two ---
// 
// Now, you're ready to choose a directory to delete.
// 
// The total disk space available to the filesystem is 70000000. To run the update, you need unused space of at least 30000000. You need to find a directory you can delete that will free up enough space to run the update.
// 
// In the example above, the total size of the outermost directory (and thus the total amount of used space) is 48381165; this means that the size of the unused space must currently be 21618835, which isn't quite the 30000000 required by the update. Therefore, the update still requires a directory with total size of at least 8381165 to be deleted before it can run.
// 
// To achieve this, you have the following options:
// 
// Delete directory e, which would increase unused space by 584.
// Delete directory a, which would increase unused space by 94853.
// Delete directory d, which would increase unused space by 24933642.
// Delete directory /, which would increase unused space by 48381165.
// Directories e and a are both too small; deleting them would not free up enough space. However, directories d and / are both big enough! Between these, choose the smallest: d, increasing unused space by 24933642.
// 
// Find the smallest directory that, if deleted, would free up enough space on the filesystem to run the update. What is the total size of that directory?

#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
    public:
    unordered_map<string, Node*> subDirs, files;
    int size;
    Node *parent;
    Node(int sz, Node *par) {
        this->size = sz;
        this->parent = par;
    }
};

typedef unordered_map<string, Node*>::iterator mpit;

int dfs(Node *root, vector<int> &t){
    int sz = 0;
    for(mpit it = root->subDirs.begin(); it != root->subDirs.end(); it++) sz += dfs(it->second, t);
    for(mpit it = root->files.begin(); it != root->files.end(); it++) sz += it->second->size;
    t.push_back(sz);
    return sz;
}

Node* parse(ifstream &input) {
    string s; getline(input, s);
    Node *root = nullptr;
    Node *cur = root;
    while(s[0] == '$') {
        if(s[2] == 'c') {
            if(!cur) cur = new Node(0, nullptr), root = cur;
            else {
                string d = s.substr(5, s.size() - 5);
                cur = d == ".." ? cur = cur->parent : cur = cur->subDirs[d];
            }
            getline(input, s);
        } else {
            while(getline(input, s) && s[0] != '$'){
                int c = 0;
                while(s[c] != ' ') c++;
                if(s[0] >= '0' && s[0] <= '9') cur->files[s.substr(c + 1, s.size() - c - 1)] = new Node(stoi(s.substr(0, c)), cur);
                else cur->subDirs[s.substr(c + 1, s.size() - c - 1)] = new Node(0, cur);
            }     
        }
    }
    return root;
}

int main () {
    ifstream input;
    input.open("day7_input.txt");
    Node *root = parse(input);
    vector<int> dirs;
    int used = dfs(root, dirs);
    int target = 30000000 - (70000000 - used);
    sort(dirs.begin(), dirs.end());
    int ans = 0;
    while(dirs[ans] < target) ans++;
    cout << dirs[ans] << endl;
    return 0;
}

