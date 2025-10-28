#include "NhanVien.h"

using namespace std;

NhanVien::NhanVien(const string& maNV,
                   const string& hoTen,
                   const string& chucVu,
                   const string& soDienThoai,
                   const string& email)
    : Nguoi(hoTen, soDienThoai, email), maNV(maNV), chucVu(chucVu) {}

const string& NhanVien::getMaNV() const {
    return maNV;
}

void NhanVien::setMaNV(const string& value) {
    maNV = value;
}

const string& NhanVien::getChucVu() const {
    return chucVu;
}

void NhanVien::setChucVu(const string& value) {
    chucVu = value;
}

string NhanVien::phanCongBan(const string& maBan) const {
    return "Nhan vien " + maNV + " duoc phan cong phu trach ban " + maBan + ".";
}

string NhanVien::ketCa() const {
    return "Nhan vien " + maNV + " da ket ca.";
}

