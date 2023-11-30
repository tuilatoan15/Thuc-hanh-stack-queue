#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

void doiThapPhanSangNhiPhan(int num) {
    int nganXepNhiPhan[MAX_SIZE];
    int top = -1;

    while (num > 0) {
        nganXepNhiPhan[++top] = num % 2;
        num /= 2;
    }

    cout << "Chuyen so tu thap phan sang nhi phan: ";

    while (top != -1) {
        cout << nganXepNhiPhan[top--];
    }

    cout << endl;
}

int main() {
    int soThapPhan;

    cout << "Nhap so Thap phan can chuyen doi: ";
    cin >> soThapPhan;

    doiThapPhanSangNhiPhan(soThapPhan);

    return 0;
}
