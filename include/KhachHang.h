#pragma once

#include "Nguoi.h"
#include <string>
using namespace std;
class KhachHang : public Nguoi {
private:
    string maKH;
    string hangThanhVien;

public:
    KhachHang() = default;
    KhachHang(const string& maKH,
              const string& hoTen,
              const string& hangThanhVien,
              const string& soDienThoai,
              const string& email);

    const string& getMaKH() const;
    void setMaKH(const string& value);

    const string& getHangThanhVien() const;
    void setHangThanhVien(const string& value);

    void capNhatThongTin(const string& hoTenMoi,
                         const string& soDienThoaiMoi,
                         const string& emailMoi);

    string xemLichSuDonHang() const;
};

