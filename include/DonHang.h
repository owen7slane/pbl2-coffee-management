#pragma once

#include "ChiTietDonHang.h"
#include <string>
#include <vector>
using namespace std;
class DonHang {
private:
    string maDH;
    string maKH;
    string maNV;
    string maBan;
    string thoiGianLap;
    string trangThai;
    double giamGia = 0.0;

public:
    DonHang() = default;
    DonHang(const string& maDH,
            const string& maKH,
            const string& maNV,
            const string& maBan,
            const string& thoiGianLap,
            const string& trangThai,
            double giamGia);

    const string& getMaDH() const;
    void setMaDH(const string& value);

    const string& getMaKH() const;
    void setMaKH(const string& value);

    const string& getMaNV() const;
    void setMaNV(const string& value);

    const string& getMaBan() const;
    void setMaBan(const string& value);

    const string& getThoiGianLap() const;
    void setThoiGianLap(const string& value);

    const string& getTrangThai() const;
    void setTrangThai(const string& value);

    double getGiamGia() const;
    void setGiamGia(double value);

    void themMon(vector<ChiTietDonHang>& details, const ChiTietDonHang& chiTiet) const;
    void xoaMon(vector<ChiTietDonHang>& details, const string& maCT) const;
    double tinhTamTinh(const vector<ChiTietDonHang>& details) const;
    double tinhTongTien(const vector<ChiTietDonHang>& details) const;
    void apDungGiamGia(double giamGiaMoi);
    void huyDon();
    void thanhToan();
};

