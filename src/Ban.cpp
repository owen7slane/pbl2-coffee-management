#include "Ban.h"

using namespace std;

Ban::Ban(const string& maBan, const string& tenBan, int sucChua, const string& trangThai)
    : maBan(maBan), tenBan(tenBan), sucChua(sucChua), trangThai(trangThai) {}

const string& Ban::getMaBan() const {
    return maBan;
}

void Ban::setMaBan(const string& value) {
    maBan = value;
}

const string& Ban::getTenBan() const {
    return tenBan;
}

void Ban::setTenBan(const string& value) {
    tenBan = value;
}

int Ban::getSucChua() const {
    return sucChua;
}

void Ban::setSucChua(int value) {
    sucChua = value;
}

const string& Ban::getTrangThai() const {
    return trangThai;
}

void Ban::setTrangThai(const string& value) {
    trangThai = value;
}

void Ban::datTruoc() {
    trangThai = "Da dat truoc";
}

void Ban::choKhach() {
    trangThai = "Dang su dung";
}

void Ban::giaiPhong() {
    trangThai = "Trong";
}

