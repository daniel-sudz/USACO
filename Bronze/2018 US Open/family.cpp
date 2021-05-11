#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
using namespace std;
ifstream fin("family.in");
ofstream fout("family.out");

int N;
string a, b;

struct Node {
    vector<Node*> children = {};
    Node* parent = nullptr;
    bool visited = false;
};
unordered_map<string, Node*> graph;

int parentCount = 0;
int childCount = 0;

void dfs(Node* node, int childCountTmp, int parentCountTmp ) {
    if (node && !node->visited) {
        if (graph[b] == node) {
            parentCount = parentCountTmp;
            childCount = childCountTmp;
        }
        else {
            node->visited = true;
            for (Node* child: node->children) {
                dfs(child, childCountTmp + 1, parentCountTmp);
            }
            dfs(node->parent, childCountTmp, parentCountTmp + 1);
        }
    }
}

string returnContructor(int greatCount, string secondary, string input1, string input2) {
    string retString = input1 + " is the ";
    for (int i = 1; i < greatCount; i ++) {
        if (secondary == "mother" && i == greatCount - 1) retString += "grand-";
        else retString += "great-";
    }
    return retString + secondary + " of " + input2;
}

int main () {
    read >> N >> a >> b;
    // build graph
    for (int i = 0; i < N; i ++) {
        string mother, child;
        read >> mother >> child;
        if (!graph[child]) graph[child] = new Node();
        if (!graph[mother]) graph[mother] = new Node();
        graph[child]->parent = graph[mother];
        graph[mother]->children.pb(graph[child]);
    }
    // dfs to determine location a is from b
    dfs(graph[a], 0, 0);
    // output relationship
    if (childCount == 0 && parentCount == 0) {
        write << "NOT RELATED" << endl;
    }
    else if (childCount == 1 && parentCount == 1) {
        write << "SIBLINGS" << endl;
    }
    else if (childCount > 1 && parentCount > 1) {
        write << "COUSINS" << endl;
    }
    else if (childCount == 0) {
        write << returnContructor(parentCount, "mother", b, a) << endl;
    }
    else if (parentCount == 0) {
        write << returnContructor(childCount, "mother", a, b) << endl;
    }
    else if (childCount == 1) {
        write << returnContructor(parentCount - 1, "aunt", b, a) << endl;
    }
    else if (parentCount == 1) {
        write << returnContructor(childCount - 1, "aunt", a, b) << endl;
    }
}
