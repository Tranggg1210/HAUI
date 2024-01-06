#include <iostream>
using namespace std;

void moveTower(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << from << " to rod " << to << endl;
        return;
    }
    moveTower(n-1, from, aux, to);
    cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
    moveTower(n-1, aux, to, from);
}

int main() {
    int n = 2;
    moveTower(n, 'A', 'C', 'B');
    return 0;
}

