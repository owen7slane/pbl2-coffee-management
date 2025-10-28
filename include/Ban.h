#pragma once

#include <string>
using namespace std;
class Ban {
private:
    string maBan;
    string tenBan;
    int sucChua = 0;
    string trangThai;

public:
    Ban() = default;
    Ban(const string& maBan, const string& tenBan, int sucChua, const string& trangThai);

    const string& getMaBan() const;
    void setMaBan(const string& value);

    const string& getTenBan() const;
    void setTenBan(const string& value);

    int getSucChua() const;
    void setSucChua(int value);

    const string& getTrangThai() const;
    void setTrangThai(const string& value);

    void datTruoc();
    void choKhach();
    void giaiPhong();
};

