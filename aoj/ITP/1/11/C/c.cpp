#include <bits/stdc++.h>
using namespace std;

class Dice {
private:
    int* face;
    void SetNumber(int n0, int n1, int n2, int n3, int n4, int n5) {
        face[0] = n0;
        face[1] = n1;
        face[2] = n2;
        face[3] = n3;
        face[4] = n4;
        face[5] = n5;
    };

public:
    Dice(int number[]) {
        face = new int[6];
        for (int i = 0; i < 6; ++i) {
            face[i] = number[i];
        }
    };
    ~Dice() {
        delete[] face;
    };
    void Roll(char order) {
        switch (order) {
            case 'E':
                SetNumber(face[3], face[1], face[0], face[5], face[4], face[2]);
                break;
            case 'N':
                SetNumber(face[1], face[5], face[2], face[3], face[0], face[4]);
                break;
            case 'S':
                SetNumber(face[4], face[0], face[2], face[3], face[5], face[1]);
                break;
            case 'W':
                SetNumber(face[2], face[1], face[5], face[0], face[4], face[3]);
                break;
        }
    };
    bool isSame(int face2[]) {
        char order[25] = "NNNNWNNNWNNNENNNENNNWNNN";
        for (int i = 0; i < 24; ++i) {
            Roll(order[i]);
            for (int j = 0; j < 6; ++j) {
                if (face[j] != face2[j]) {
                    break;
                }
                if (j == 5) {
                    return true;
                }
            }
        }
        return false;
    };
};

int main() {
    int number[6];
    int res;
    for (int i = 0; i < 6; ++i) {
        cin >> res;
        number[i] = res;
    }
    Dice dice(number);
    for (int i = 0; i < 6; ++i) {
        cin >> res;
        number[i] = res;
    }
    if (dice.isSame(number)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}