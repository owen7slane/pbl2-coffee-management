#include "ChiTietDonHang.h"

using namespace std;

ChiTietDonHang::ChiTietDonHang(const string& maCT,
                               const string& maDH,
                               const string& maSP,
                               int soLuong,
                               double donGia)
    : maCT(maCT), maDH(maDH), maSP(maSP), soLuong(soLuong), donGia(donGia) {}

const string& ChiTietDonHang::getMaCT() const {
    return maCT;
}

void ChiTietDonHang::setMaCT(const string& value) {
    maCT = value;
}

const string& ChiTietDonHang::getMaDH() const {
    return maDH;
}

void ChiTietDonHang::setMaDH(const string& value) {
    maDH = value;
}

const string& ChiTietDonHang::getMaSP() const {
    return maSP;
}

void ChiTietDonHang::setMaSP(const string& value) {
    maSP = value;
}

int ChiTietDonHang::getSoLuong() const {
    return soLuong;
}

void ChiTietDonHang::setSoLuong(int value) {
    soLuong = value;
}

double ChiTietDonHang::getDonGia() const {
    return donGia;
}

void ChiTietDonHang::setDonGia(double value) {
    donGia = value;
}

double ChiTietDonHang::tinhThanhTien() const {
    return donGia * soLuong;
}

