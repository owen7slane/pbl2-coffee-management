#include "SanPham.h"

using namespace std;

SanPham::SanPham(const string& maSP,
                 const string& tenSP,
                 const string& maDM,
                 double donGia,
                 bool dangBan)
    : maSP(maSP), tenSP(tenSP), maDM(maDM), donGia(donGia), dangBan(dangBan) {}

const string& SanPham::getMaSP() const {
    return maSP;
}

void SanPham::setMaSP(const string& value) {
    maSP = value;
}

const string& SanPham::getTenSP() const {
    return tenSP;
}

void SanPham::setTenSP(const string& value) {
    tenSP = value;
}

const string& SanPham::getMaDM() const {
    return maDM;
}

void SanPham::setMaDM(const string& value) {
    maDM = value;
}

double SanPham::getDonGia() const {
    return donGia;
}

void SanPham::setDonGia(double value) {
    donGia = value;
}

bool SanPham::getDangBan() const {
    return dangBan;
}

void SanPham::setDangBan(bool value) {
    dangBan = value;
}

void SanPham::doiGia(double giaMoi) {
    donGia = giaMoi;
}

void SanPham::ngungBan() {
    dangBan = false;
}

