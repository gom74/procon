#include <bits/stdc++.h>
using namespace std;

class Dictionary {
private:
    set<string> word;

public:
    void insert(string str) {
        word.insert(str);
    };
    void find(string str) {
        auto itr = word.find(str);
        cout << ((itr != word.end()) ? "yes" : "no") << endl;
    };
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    Dictionary dic;
    while (n--) {
        string order, str;
        cin >> order >> str;
        if (order == "insert") {
            dic.insert(str);
        } else if (order == "find") {
            dic.find(str);
        }
    }

    return 0;
}