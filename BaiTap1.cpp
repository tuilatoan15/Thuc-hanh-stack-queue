#include <iostream>
#include <stack>

using namespace std;

void doiThapPhanSangNhiPhan(int soThapPhan) {
    stack<int> nganXepNhiPhan;

    while (soThapPhan > 0) {
        nganXepNhiPhan.push(soThapPhan % 2);
        soThapPhan /= 2;
    }

    cout << "Chuyen so tu thap phan sang nhi phan: ";
    while (!nganXepNhiPhan.empty()) {
        cout << nganXepNhiPhan.top();
        nganXepNhiPhan.pop();
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
