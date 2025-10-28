#include "DatCho.h"

using namespace std;

DatCho::DatCho(const string& maDC,
               const string& maKH,
               const string& maBan,
               const string& thoiGianDat,
               int soNguoi)
    : maDC(maDC), maKH(maKH), maBan(maBan), thoiGianDat(thoiGianDat), soNguoi(soNguoi) {}

const string& DatCho::getMaDC() const {
    return maDC;
}

void DatCho::setMaDC(const string& value) {
    maDC = value;
}

const string& DatCho::getMaKH() const {
    return maKH;
}

void DatCho::setMaKH(const string& value) {
    maKH = value;
}

const string& DatCho::getMaBan() const {
    return maBan;
}

void DatCho::setMaBan(const string& value) {
    maBan = value;
}

const string& DatCho::getThoiGianDat() const {
    return thoiGianDat;
}

void DatCho::setThoiGianDat(const string& value) {
    thoiGianDat = value;
}

int DatCho::getSoNguoi() const {
    return soNguoi;
}

void DatCho::setSoNguoi(int value) {
    soNguoi = value;
}

void DatCho::huyDat() {
    thoiGianDat.clear();
}

void DatCho::doiLich(const string& thoiGianMoi) {
    thoiGianDat = thoiGianMoi;
}

