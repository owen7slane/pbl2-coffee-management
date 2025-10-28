#pragma once

#include <string>
using namespace std;
class NhaCungCap {
private:
    string maNCC;
    string tenNCC;
    string soDienThoai;
    string email;

public:
    NhaCungCap() = default;
    NhaCungCap(const string& maNCC,
               const string& tenNCC,
               const string& soDienThoai,
               const string& email);

    const string& getMaNCC() const;
    void setMaNCC(const string& value);

    const string& getTenNCC() const;
    void setTenNCC(const string& value);

    const string& getSoDienThoai() const;
    void setSoDienThoai(const string& value);

    const string& getEmail() const;
    void setEmail(const string& value);

    void capNhatLienHe(const string& soDienThoaiMoi, const string& emailMoi);
};

