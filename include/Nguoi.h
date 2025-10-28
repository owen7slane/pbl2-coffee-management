#pragma once

#include <string>
using namespace std;
class Nguoi {
protected:
    string hoTen;
    string soDienThoai;
    string email;

public:
    Nguoi() = default;
    Nguoi(const string& hoTen, const string& soDienThoai, const string& email);

    virtual ~Nguoi() = default;

    const string& getHoTen() const;
    void setHoTen(const string& value);

    const string& getSoDienThoai() const;
    void setSoDienThoai(const string& value);

    const string& getEmail() const;
    void setEmail(const string& value);
};

