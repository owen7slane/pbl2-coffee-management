#pragma once

#include "Nguoi.h"
#include <string>
using namespace std;
class NhanVien : public Nguoi {
private:
    string maNV;
    string chucVu;

public:
    NhanVien() = default;
    NhanVien(const string& maNV,
             const string& hoTen,
             const string& chucVu,
             const string& soDienThoai,
             const string& email);

    const string& getMaNV() const;
    void setMaNV(const string& value);

    const string& getChucVu() const;
    void setChucVu(const string& value);

    string phanCongBan(const string& maBan) const;
    string ketCa() const;
};

