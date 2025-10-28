#include "DonHang.h"
#include <algorithm>

using namespace std;

DonHang::DonHang(const string& maDH,
                 const string& maKH,
                 const string& maNV,
                 const string& maBan,
                 const string& thoiGianLap,
                 const string& trangThai,
                 double giamGia)
    : maDH(maDH),
      maKH(maKH),
      maNV(maNV),
      maBan(maBan),
      thoiGianLap(thoiGianLap),
      trangThai(trangThai),
      giamGia(giamGia) {}

const string& DonHang::getMaDH() const {
    return maDH;
}

void DonHang::setMaDH(const string& value) {
    maDH = value;
}

const string& DonHang::getMaKH() const {
    return maKH;
}

void DonHang::setMaKH(const string& value) {
    maKH = value;
}

const string& DonHang::getMaNV() const {
    return maNV;
}

void DonHang::setMaNV(const string& value) {
    maNV = value;
}

const string& DonHang::getMaBan() const {
    return maBan;
}

void DonHang::setMaBan(const string& value) {
    maBan = value;
}

const string& DonHang::getThoiGianLap() const {
    return thoiGianLap;
}

void DonHang::setThoiGianLap(const string& value) {
    thoiGianLap = value;
}

const string& DonHang::getTrangThai() const {
    return trangThai;
}

void DonHang::setTrangThai(const string& value) {
    trangThai = value;
}

double DonHang::getGiamGia() const {
    return giamGia;
}

void DonHang::setGiamGia(double value) {
    giamGia = value;
}

void DonHang::themMon(vector<ChiTietDonHang>& details, const ChiTietDonHang& chiTiet) const {
    if (chiTiet.getMaDH() == maDH) {
        details.push_back(chiTiet);
    }
}

void DonHang::xoaMon(vector<ChiTietDonHang>& details, const string& maCT) const {
    details.erase(remove_if(details.begin(),
                                 details.end(),
                                 [&](const ChiTietDonHang& ct) {
                                     return ct.getMaDH() == maDH && ct.getMaCT() == maCT;
                                 }),
                  details.end());
}

double DonHang::tinhTamTinh(const vector<ChiTietDonHang>& details) const {
    double tong = 0.0;
    for (const auto& ct : details) {
        if (ct.getMaDH() == maDH) {
            tong += ct.tinhThanhTien();
        }
    }
    return tong;
}

double DonHang::tinhTongTien(const vector<ChiTietDonHang>& details) const {
    double tamTinh = tinhTamTinh(details);
    double tong = tamTinh - giamGia;
    return tong < 0.0 ? 0.0 : tong;
}

void DonHang::apDungGiamGia(double giamGiaMoi) {
    giamGia = giamGiaMoi;
}

void DonHang::huyDon() {
    trangThai = "Da huy";
}

void DonHang::thanhToan() {
    trangThai = "Da thanh toan";
}

