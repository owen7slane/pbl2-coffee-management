#include "ThanhToan.h"

using namespace std;

ThanhToan::ThanhToan(const string& maTT,
                     const string& maDH,
                     double soTien,
                     const string& hinhThuc,
                     const string& thoiGianTT)
    : maTT(maTT), maDH(maDH), soTien(soTien), hinhThuc(hinhThuc), thoiGianTT(thoiGianTT) {}

const string& ThanhToan::getMaTT() const {
    return maTT;
}

void ThanhToan::setMaTT(const string& value) {
    maTT = value;
}

const string& ThanhToan::getMaDH() const {
    return maDH;
}

void ThanhToan::setMaDH(const string& value) {
    maDH = value;
}

double ThanhToan::getSoTien() const {
    return soTien;
}

void ThanhToan::setSoTien(double value) {
    soTien = value;
}

const string& ThanhToan::getHinhThuc() const {
    return hinhThuc;
}

void ThanhToan::setHinhThuc(const string& value) {
    hinhThuc = value;
}

const string& ThanhToan::getThoiGianTT() const {
    return thoiGianTT;
}

void ThanhToan::setThoiGianTT(const string& value) {
    thoiGianTT = value;
}

void ThanhToan::hoanTien() {
    hinhThuc = "Hoan tien";
    soTien = 0.0;
}

