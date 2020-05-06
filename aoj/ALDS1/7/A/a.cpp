#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int id;
    int parent = -1;
    int depth;
    string type;
    vector<int> children;
};

void search(vector<node> &tree, int idx, int dep) {
    if (tree.at(idx).parent != -1) {
        if (tree.at(idx).children.size() == 0) {
            tree.at(idx).depth = dep;
            tree.at(idx).type = "leaf";
            return;
        } else {
            tree.at(idx).depth = dep;
            tree.at(idx).type = "internal node";
        }
    }
    for (auto &x : tree.at(idx).children) {
        search(tree, x, dep + 1);
    }
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<node> tree(n);
    for (int i = 0; i < n; ++i) {
        int ii;
        cin >> ii;
        tree.at(ii).id = ii;
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int c;
            cin >> c;
            tree.at(ii).children.push_back(c);
            tree.at(c).parent = ii;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (tree.at(i).parent == -1) {
            tree.at(i).depth = 0;
            tree.at(i).type = "root";
            search(tree, i, 0);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << "node " << tree.at(i).id;
        cout << ": parent = " << tree.at(i).parent;
        cout << ", depth = " << tree.at(i).depth;
        cout << ", " << tree.at(i).type;
        cout << ", [";
        for (int j = 0; j < tree.at(i).children.size(); ++j) {
            if (j) cout << ", ";
            cout << tree.at(i).children.at(j);
        }
        cout << ']' << endl;
    }

    return 0;
}