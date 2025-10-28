#pragma once

#include <string>
using namespace std;
class ThanhToan {
private:
    string maTT;
    string maDH;
    double soTien = 0.0;
    string hinhThuc;
    string thoiGianTT;

public:
    ThanhToan() = default;
    ThanhToan(const string& maTT,
              const string& maDH,
              double soTien,
              const string& hinhThuc,
              const string& thoiGianTT);

    const string& getMaTT() const;
    void setMaTT(const string& value);

    const string& getMaDH() const;
    void setMaDH(const string& value);

    double getSoTien() const;
    void setSoTien(double value);

    const string& getHinhThuc() const;
    void setHinhThuc(const string& value);

    const string& getThoiGianTT() const;
    void setThoiGianTT(const string& value);

    void hoanTien();
};

