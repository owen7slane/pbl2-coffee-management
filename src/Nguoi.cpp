#include "Nguoi.h"

using namespace std;

Nguoi::Nguoi(const string& hoTen, const string& soDienThoai, const string& email)
    : hoTen(hoTen), soDienThoai(soDienThoai), email(email) {}

const string& Nguoi::getHoTen() const {
    return hoTen;
}

void Nguoi::setHoTen(const string& value) {
    hoTen = value;
}

const string& Nguoi::getSoDienThoai() const {
    return soDienThoai;
}

void Nguoi::setSoDienThoai(const string& value) {
    soDienThoai = value;
}

const string& Nguoi::getEmail() const {
    return email;
}

void Nguoi::setEmail(const string& value) {
    email = value;
}

