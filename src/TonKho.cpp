#include "TonKho.h"

using namespace std;

TonKho::TonKho(const string& maTK,
               const string& maSP,
               const string& maNCC,
               int soLuongTon,
               int mucDatHangLai)
    : maTK(maTK),
      maSP(maSP),
      maNCC(maNCC),
      soLuongTon(soLuongTon),
      mucDatHangLai(mucDatHangLai) {}

const string& TonKho::getMaTK() const {
    return maTK;
}

void TonKho::setMaTK(const string& value) {
    maTK = value;
}

const string& TonKho::getMaSP() const {
    return maSP;
}

void TonKho::setMaSP(const string& value) {
    maSP = value;
}

const string& TonKho::getMaNCC() const {
    return maNCC;
}

void TonKho::setMaNCC(const string& value) {
    maNCC = value;
}

int TonKho::getSoLuongTon() const {
    return soLuongTon;
}

void TonKho::setSoLuongTon(int value) {
    soLuongTon = value;
}

int TonKho::getMucDatHangLai() const {
    return mucDatHangLai;
}

void TonKho::setMucDatHangLai(int value) {
    mucDatHangLai = value;
}

void TonKho::nhapThem(int soLuong) {
    soLuongTon += soLuong;
}

bool TonKho::xuatBot(int soLuong) {
    if (soLuong > soLuongTon) {
        return false;
    }
    soLuongTon -= soLuong;
    return true;
}

bool TonKho::canDatHang() const {
    return soLuongTon <= mucDatHangLai;
}

