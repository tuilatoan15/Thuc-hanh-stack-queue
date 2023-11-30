#include <iostream>
#include <cctype>

using namespace std;

bool laToanTu(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int tinhGiaTriHauTo(const string& bieuThucHauTo) {
    const int MAX_SIZE = 100;
    int nganXepToanHang[MAX_SIZE];
    int top = -1;

    for (char c : bieuThucHauTo) {
        if (isdigit(c)) {
            nganXepToanHang[++top] = c - '0';
        } else if (laToanTu(c)) {
            int toanHang2 = nganXepToanHang[top--];
            int toanHang1 = nganXepToanHang[top--];

            switch (c) {
                case '+':
                    nganXepToanHang[++top] = toanHang1 + toanHang2;
                    break;
                case '-':
                    nganXepToanHang[++top] = toanHang1 - toanHang2;
                    break;
                case '*':
                    nganXepToanHang[++top] = toanHang1 * toanHang2;
                    break;
                case '/':
                    nganXepToanHang[++top] = toanHang1 / toanHang2;
                    break;
            }
        }
    }

    return nganXepToanHang[top];
}

int main() {
    string bieuThucHauTo;

    cout << "Nhap bieu thuc hau to: ";
    cin >> bieuThucHauTo;

    int ketQua = tinhGiaTriHauTo(bieuThucHauTo);

    cout << "Gia tri cua bieu thuc hau to vua nhap: " << ketQua << endl;

    return 0;
}
