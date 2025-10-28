#pragma once

#include <string>
using namespace std;
class ChiTietDonHang {
private:
    string maCT;
    string maDH;
    string maSP;
    int soLuong = 0;
    double donGia = 0.0;

public:
    ChiTietDonHang() = default;
    ChiTietDonHang(const string& maCT,
                   const string& maDH,
                   const string& maSP,
                   int soLuong,
                   double donGia);

    const string& getMaCT() const;
    void setMaCT(const string& value);

    const string& getMaDH() const;
    void setMaDH(const string& value);

    const string& getMaSP() const;
    void setMaSP(const string& value);

    int getSoLuong() const;
    void setSoLuong(int value);

    double getDonGia() const;
    void setDonGia(double value);

    double tinhThanhTien() const;
};

