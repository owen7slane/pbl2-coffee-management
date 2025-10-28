#include "NhaCungCap.h"

using namespace std;

NhaCungCap::NhaCungCap(const string& maNCC,
                       const string& tenNCC,
                       const string& soDienThoai,
                       const string& email)
    : maNCC(maNCC), tenNCC(tenNCC), soDienThoai(soDienThoai), email(email) {}

const string& NhaCungCap::getMaNCC() const {
    return maNCC;
}

void NhaCungCap::setMaNCC(const string& value) {
    maNCC = value;
}

const string& NhaCungCap::getTenNCC() const {
    return tenNCC;
}

void NhaCungCap::setTenNCC(const string& value) {
    tenNCC = value;
}

const string& NhaCungCap::getSoDienThoai() const {
    return soDienThoai;
}

void NhaCungCap::setSoDienThoai(const string& value) {
    soDienThoai = value;
}

const string& NhaCungCap::getEmail() const {
    return email;
}

void NhaCungCap::setEmail(const string& value) {
    email = value;
}

void NhaCungCap::capNhatLienHe(const string& soDienThoaiMoi, const string& emailMoi) {
    soDienThoai = soDienThoaiMoi;
    email = emailMoi;
}

