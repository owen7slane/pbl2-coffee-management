#pragma once

#include <string>
using namespace std;
class SanPham {
private:
    string maSP;
    string tenSP;
    string maDM;
    double donGia = 0.0;
    bool dangBan = true;

public:
    SanPham() = default;
    SanPham(const string& maSP,
            const string& tenSP,
            const string& maDM,
            double donGia,
            bool dangBan);

    const string& getMaSP() const;
    void setMaSP(const string& value);

    const string& getTenSP() const;
    void setTenSP(const string& value);

    const string& getMaDM() const;
    void setMaDM(const string& value);

    double getDonGia() const;
    void setDonGia(double value);

    bool getDangBan() const;
    void setDangBan(bool value);

    void doiGia(double giaMoi);
    void ngungBan();
};

