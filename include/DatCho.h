#pragma once

#include <string>
using namespace std;
class DatCho {
private:
    string maDC;
    string maKH;
    string maBan;
    string thoiGianDat;
    int soNguoi = 0;

public:
    DatCho() = default;
    DatCho(const string& maDC,
           const string& maKH,
           const string& maBan,
           const string& thoiGianDat,
           int soNguoi);

    const string& getMaDC() const;
    void setMaDC(const string& value);

    const string& getMaKH() const;
    void setMaKH(const string& value);

    const string& getMaBan() const;
    void setMaBan(const string& value);

    const string& getThoiGianDat() const;
    void setThoiGianDat(const string& value);

    int getSoNguoi() const;
    void setSoNguoi(int value);

    void huyDat();
    void doiLich(const string& thoiGianMoi);
};

