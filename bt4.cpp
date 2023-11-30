#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int MAX_KHACH_HANG = 100;

struct KhachHang {
    int soThuTu;
    string hoTen;
    string dichVu;
};

class HangDoi {
private:
    KhachHang data[MAX_KHACH_HANG];
    int front;
    int rear;
    int soLuongDaDuocPhucVu;

public:
    HangDoi() : front(-1), rear(-1), soLuongDaDuocPhucVu(0) {}

    bool rong() {
        return front == -1 && rear == -1;
    }

    bool day() {
        return (rear + 1) % MAX_KHACH_HANG == front;
    }

    void themKhachHang() {
        if (day()) {
            cout << "Hang doi day, khong the them khach hang.\n";
            return;
        }

        if (rong()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_KHACH_HANG;
        }

        KhachHang khachMoi;
        cout << "Nhap ho ten khach hang: ";
        getline(cin, khachMoi.hoTen);
        cout << "Nhap dich vu can thuc hien: ";
        getline(cin, khachMoi.dichVu);

        int soThuTuTemp = rear + 1;
        data[rear] = khachMoi;
        data[rear].soThuTu = soThuTuTemp;
        cout << "Da them khach hang thanh cong! So thu tu khach hang: " << soThuTuTemp << endl;
    }

    void phucVuKhachHangTiepTheo() {
        if (rong()) {
            cout << "Hang doi rong, khong the phuc vu khach hang.\n";
            return;
        }

        cout << "Dang phuc vu khach hang: " << data[front].hoTen << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_KHACH_HANG;
        }

        soLuongDaDuocPhucVu++;
    }

    void inSoLuongChuaDuocPhucVu() {
        cout << "So luong khach hang chua duoc phuc vu: ";
        if (rong()) {
            cout << "0";
        } else {
            int soLuongChuaDuocPhucVu = (rear - front + MAX_KHACH_HANG) % MAX_KHACH_HANG + 1;
            cout << soLuongChuaDuocPhucVu;
        }
        cout << endl;
    }

    void inSoLuongDaDuocPhucVu() {
        cout << "So luong khach hang da duoc phuc vu: " << soLuongDaDuocPhucVu << endl;
    }
};

int main() {
    HangDoi hangDoiKhachHang;
    int luaChon;

    do {
        system("cls");
        cout << "\t\t\tMENU QUAN LY KHACH HANG\n";
        cout << "\t+--------------------------------------------------+" << endl;
        cout << "\t|[1] Them khach hang                               |" << endl;
        cout << "\t|[2] Phuc vu khach hang tiep theo                  |" << endl;
        cout << "\t|[3] So luong khach hang chua duoc phuc vu         |" << endl;
        cout << "\t|[4] So luong khach hang da duoc phuc vu           |" << endl;
        cout << "\t+--------------------------------------------------+" << endl;
        cout << "\t|[0] Thoat                                         |" << endl;
        cout << "\t+--------------------------------------------------+" << endl;
        cout << "\n\t\tNhap lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon) {
        case 1: {
            hangDoiKhachHang.themKhachHang();
            system("pause");
            break;
        }
        case 2:
            hangDoiKhachHang.phucVuKhachHangTiepTheo();
            system("pause");
            break;
        case 3:
            hangDoiKhachHang.inSoLuongChuaDuocPhucVu();
            system("pause");
            break;
        case 4:
            hangDoiKhachHang.inSoLuongDaDuocPhucVu();
            system("pause");
            break;
        case 0:
            cout << "Thoat chuong trinh thanh cong\n";
            break;
        default:
            cout << "Lua chon khong hop le! Vui long nhap lai\n";
            system("pause");
            break;
        }

    } while (luaChon != 0);

    return 0;
}
