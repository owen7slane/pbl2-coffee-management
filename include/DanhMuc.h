#pragma once

#include <string>
using namespace std;
class DanhMuc {
private:
    string maDM;
    string tenDM;

public:
    DanhMuc() = default;
    DanhMuc(const string& maDM, const string& tenDM);

    const string& getMaDM() const;
    void setMaDM(const string& value);

    const string& getTenDM() const;
    void setTenDM(const string& value);

    void doiTen(const string& tenMoi);
};

