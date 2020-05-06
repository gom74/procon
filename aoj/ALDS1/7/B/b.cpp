#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int id;
    int parent = -1;
    int sibling = -1;
    int degree = 0;
    int depth;
    int height;
    string type;
    vector<int> children;
};

void checkDepth(vector<node> &tree, int idx, int dep) {
    if (tree.at(idx).parent != -1) {
        if (tree.at(idx).degree == 0) {
            tree.at(idx).depth = dep;
            tree.at(idx).type = "leaf";
            return;
        } else {
            tree.at(idx).depth = dep;
            tree.at(idx).type = "internal node";
        }
    }
    for (auto &x : tree.at(idx).children) {
        checkDepth(tree, x, dep + 1);
    }
    return;
}

void checkHeight(vector<node> &tree, int idx, int h) {
    tree.at(idx).height = max(tree.at(idx).height, h);
    if (tree.at(idx).parent != -1) {
        checkHeight(tree, tree.at(idx).parent, h + 1);
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
        int idx;
        cin >> idx;
        tree.at(idx).id = idx;
        int left, right;
        cin >> left >> right;
        if (left != -1) {
            tree.at(idx).children.push_back(left);
            tree.at(left).parent = idx;
            tree.at(idx).degree++;
            if (right != -1) {
                tree.at(left).sibling = right;
            }
        }
        if (right != -1) {
            tree.at(idx).children.push_back(right);
            tree.at(right).parent = idx;
            tree.at(idx).degree++;
            if (left != -1) {
                tree.at(right).sibling = left;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (tree.at(i).parent == -1) {
            tree.at(i).depth = 0;
            tree.at(i).type = "root";
            checkDepth(tree, i, 0);
        }
        if (tree.at(i).degree == 0) {
            checkHeight(tree, i, 0);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << "node " << tree.at(i).id;
        cout << ": parent = " << tree.at(i).parent;
        cout << ", sibling = " << tree.at(i).sibling;
        cout << ", degree = " << tree.at(i).degree;
        cout << ", depth = " << tree.at(i).depth;
        cout << ", height = " << tree.at(i).height;
        cout << ", " << tree.at(i).type << endl;
    }

    return 0;
}