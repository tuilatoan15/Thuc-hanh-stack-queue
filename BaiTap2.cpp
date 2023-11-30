#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

bool laToanTu(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string trungToSangHauTo(const string& bieuThucTrungTo) {
    stack<char> nganXepToanTu;
    string bieuThucHauTo = "";

    for (char c : bieuThucTrungTo) {
        if (isalnum(c)) {
            bieuThucHauTo += c;
        } else if (c == '(') {
            nganXepToanTu.push(c);
        } else if (c == ')') {
            while (!nganXepToanTu.empty() && nganXepToanTu.top() != '(') {
                bieuThucHauTo += nganXepToanTu.top();
                nganXepToanTu.pop();
            }
            nganXepToanTu.pop();
        } else if (laToanTu(c)) {
            while (!nganXepToanTu.empty() && laToanTu(nganXepToanTu.top()) && nganXepToanTu.top() != '(') {
                bieuThucHauTo += nganXepToanTu.top();
                nganXepToanTu.pop();
            }
            nganXepToanTu.push(c);
        }
    }

    while (!nganXepToanTu.empty()) {
        bieuThucHauTo += nganXepToanTu.top();
        nganXepToanTu.pop();
    }

    return bieuThucHauTo;
}

int main() {
    string bieuThucTrungTo, bieuThucHauTo;

    cout << "Nhập biểu thức trung tố: ";
    getline(cin, bieuThucTrungTo);

    bieuThucHauTo = trungToSangHauTo(bieuThucTrungTo);

    cout << "Biểu thức hậu tố tương ứng: " << bieuThucHauTo << endl;

    return 0;
}
