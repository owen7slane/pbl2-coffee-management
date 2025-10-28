#include "DanhMuc.h"

using namespace std;

DanhMuc::DanhMuc(const string& maDM, const string& tenDM)
    : maDM(maDM), tenDM(tenDM) {}

const string& DanhMuc::getMaDM() const {
    return maDM;
}

void DanhMuc::setMaDM(const string& value) {
    maDM = value;
}

const string& DanhMuc::getTenDM() const {
    return tenDM;
}

void DanhMuc::setTenDM(const string& value) {
    tenDM = value;
}

void DanhMuc::doiTen(const string& tenMoi) {
    tenDM = tenMoi;
}

