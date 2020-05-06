#include <bits/stdc++.h>
using namespace std;

class Dice {
private:
    int face_top;
    int face_south;
    int face_east;
    int face_west;
    int face_north;
    int face_bottom;

public:
    Dice(int a, int b, int c, int d, int e, int f);
    void Roll(char order);
    int Get_Top();
};

Dice::Dice(int a, int b, int c, int d, int e, int f) {
    face_top = a;
    face_south = b;
    face_east = c;
    face_west = d;
    face_north = e;
    face_bottom = f;
}

void Dice::Roll(char order) {
    int res = face_top;
    if (order == 'E') {
        face_top = face_west;
        face_west = face_bottom;
        face_bottom = face_east;
        face_east = res;
    } else if (order == 'W') {
        face_top = face_east;
        face_east = face_bottom;
        face_bottom = face_west;
        face_west = res;
    } else if (order == 'S') {
        face_top = face_north;
        face_north = face_bottom;
        face_bottom = face_south;
        face_south = res;
    } else if (order = 'N') {
        face_top = face_south;
        face_south = face_bottom;
        face_bottom = face_north;
        face_north = res;
    }
}

int Dice::Get_Top() {
    return face_top;
}

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    Dice dice(a, b, c, d, e, f);
    string orders;
    cin >> orders;
    for (int i = 0; i < orders.size(); ++i) {
        dice.Roll(orders[i]);
    }
    cout << dice.Get_Top() << endl;

    return 0;
}