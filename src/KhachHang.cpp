#include "KhachHang.h"

using namespace std;

KhachHang::KhachHang(const string& maKH,
                     const string& hoTen,
                     const string& hangThanhVien,
                     const string& soDienThoai,
                     const string& email)
    : Nguoi(hoTen, soDienThoai, email), maKH(maKH), hangThanhVien(hangThanhVien) {}

const string& KhachHang::getMaKH() const {
    return maKH;
}

void KhachHang::setMaKH(const string& value) {
    maKH = value;
}

const string& KhachHang::getHangThanhVien() const {
    return hangThanhVien;
}

void KhachHang::setHangThanhVien(const string& value) {
    hangThanhVien = value;
}

void KhachHang::capNhatThongTin(const string& hoTenMoi,
                                const string& soDienThoaiMoi,
                                const string& emailMoi) {
    hoTen = hoTenMoi;
    soDienThoai = soDienThoaiMoi;
    email = emailMoi;
}

string KhachHang::xemLichSuDonHang() const {
    return "Lich su don hang cua khach hang " + maKH + " dang duoc tong hop.";
}

