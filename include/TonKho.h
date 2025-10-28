#pragma once

#include <string>
using namespace std;
class TonKho {
private:
    string maTK;
    string maSP;
    string maNCC;
    int soLuongTon = 0;
    int mucDatHangLai = 0;

public:
    TonKho() = default;
    TonKho(const string& maTK,
           const string& maSP,
           const string& maNCC,
           int soLuongTon,
           int mucDatHangLai);

    const string& getMaTK() const;
    void setMaTK(const string& value);

    const string& getMaSP() const;
    void setMaSP(const string& value);

    const string& getMaNCC() const;
    void setMaNCC(const string& value);

    int getSoLuongTon() const;
    void setSoLuongTon(int value);

    int getMucDatHangLai() const;
    void setMucDatHangLai(int value);

    void nhapThem(int soLuong);
    bool xuatBot(int soLuong);
    bool canDatHang() const;
};

