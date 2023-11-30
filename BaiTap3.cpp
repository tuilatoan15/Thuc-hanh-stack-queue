#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

bool laToanTu(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int tinhGiaTriHauTo(const string& bieuThucHauTo) {
    stack<int> nganXepToanHang;

    for (char c : bieuThucHauTo) {
        if (isdigit(c)) {
            nganXepToanHang.push(c - '0');
        } else if (laToanTu(c)) {
            int toanHang2 = nganXepToanHang.top();
            nganXepToanHang.pop();
            int toanHang1 = nganXepToanHang.top();
            nganXepToanHang.pop();

            switch (c) {
                case '+':
                    nganXepToanHang.push(toanHang1 + toanHang2);
                    break;
                case '-':
                    nganXepToanHang.push(toanHang1 - toanHang2);
                    break;
                case '*':
                    nganXepToanHang.push(toanHang1 * toanHang2);
                    break;
                case '/':
                    nganXepToanHang.push(toanHang1 / toanHang2);
                    break;
            }
        }
    }

    return nganXepToanHang.top();
}

int main() {
    string bieuThucHauTo;

    cout << "Nhập biểu thức hậu tố: ";
    cin >> bieuThucHauTo;

    int ketQua = tinhGiaTriHauTo(bieuThucHauTo);

    cout << "Giá trị của biểu thức hậu tố: " << ketQua << endl;

    return 0;
}
