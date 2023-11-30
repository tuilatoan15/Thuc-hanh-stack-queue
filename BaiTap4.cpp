#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct KhachHang {
    int soThuTu;
    string ten;
    string dichVu;
};

class HangDoiNganHang {
private:
    queue<KhachHang> hangDoiKhachHang;
    int soKhachDaPhucVu;

public:
    HangDoiNganHang() : soKhachDaPhucVu(0) {}

    void themKhachHang(const KhachHang& khachHang) {
        hangDoiKhachHang.push(khachHang);
        cout << "Them khach hang " << khachHang.ten << " voi so thu tu " << khachHang.soThuTu << " vao hang doi.\n";
    }

    void phucVuKhachHangTiepTheo() {
        if (!hangDoiKhachHang.empty()) {
            KhachHang khachHangTiepTheo = hangDoiKhachHang.front();
            hangDoiKhachHang.pop();
            soKhachDaPhucVu++;
            cout << "Dang phuc vu khach hang " << khachHangTiepTheo.ten << " voi so thu tu " << khachHangTiepTheo.soThuTu << ".\n";
        } else {
            cout << "Khong co khach hang trong hang doi.\n";
        }
    }

    int laySoKhachHangChoPhucVu() const {
        return hangDoiKhachHang.size();
    }

    int laySoKhachHangDaPhucVu() const {
        return soKhachDaPhucVu;
    }
};

int main() {
    HangDoiNganHang hangDoiNganHang;

    hangDoiNganHang.themKhachHang({1, "Nguyen Huu Toan", "Gui tien"});
    hangDoiNganHang.themKhachHang({2, "Nguyen Thanh Luan", "Rut tien"});
    hangDoiNganHang.themKhachHang({3, "Nguyen Trung Tin", "Chuyen khoan"});
    hangDoiNganHang.themKhachHang({1, "Nguyen Thanh Thuong", "An chan tien"});
    hangDoiNganHang.themKhachHang({1, "Nguyen Quang Nhat", "Cuop tien"});

    hangDoiNganHang.phucVuKhachHangTiepTheo();
    hangDoiNganHang.phucVuKhachHangTiepTheo();

    cout << "So luong khach hang dang cho: " << hangDoiNganHang.laySoKhachHangChoPhucVu() << endl;
    cout << "So luong khach hang da phuc vu: " << hangDoiNganHang.laySoKhachHangDaPhucVu() << endl;

    return 0;
}
