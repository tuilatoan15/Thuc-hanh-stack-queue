#include <iostream>
#include <cctype>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

bool laToanTu(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string trungToSangHauTo(const string& bieuThucTrungTo) {
    char nganXepToanTu[MAX_SIZE];
    int top = -1;
    string bieuThucHauTo = "";

    for (char c : bieuThucTrungTo) {
        if (isalnum(c)) {
            bieuThucHauTo += c;
        } else if (c == '(') {
            nganXepToanTu[++top] = c;
        } else if (c == ')') {
            while (top != -1 && nganXepToanTu[top] != '(') {
                bieuThucHauTo += nganXepToanTu[top--];
            }
            --top;
        } else if (laToanTu(c)) {
            while (top != -1 && laToanTu(nganXepToanTu[top]) && nganXepToanTu[top] != '(') {
                bieuThucHauTo += nganXepToanTu[top--];
            }
            nganXepToanTu[++top] = c;
        }
    }

    while (top != -1) {
        bieuThucHauTo += nganXepToanTu[top--];
    }

    return bieuThucHauTo;
}

int main() {
    string bieuThucTrungTo, bieuThucHauTo;

    cout << "Nhap bieu thuc trung to: ";
    getline(cin, bieuThucTrungTo);

    bieuThucHauTo = trungToSangHauTo(bieuThucTrungTo);

    cout << "Bieu thuc hau to duoc chuyen doi tu bieu thuc tren: " << bieuThucHauTo << endl;

    return 0;
}
