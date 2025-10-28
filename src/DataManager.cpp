#include "DataManager.h"

#include "Utils.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

namespace {

filesystem::path makePath(const string& root, const string& fileName) {
    return filesystem::path(root) / fileName;
}

int toInt(const string& value) {
    try {
        return stoi(value);
    } catch (...) {
        return 0;
    }
}

double toDouble(const string& value) {
    try {
        return stod(value);
    } catch (...) {
        return 0.0;
    }
}

string clean(const string& value) {
    return Utils::trim(value);
}

}  // namespace

DataManager::DataManager(string dataDirectory) : dataDirectory(move(dataDirectory)) {}

bool DataManager::loadAll() {
    bool ok = true;
    ok = loadNhanVien() && ok;
    ok = loadKhachHang() && ok;
    ok = loadDanhMuc() && ok;
    ok = loadSanPham() && ok;
    ok = loadBan() && ok;
    ok = loadDonHang() && ok;
    ok = loadChiTietDonHang() && ok;
    ok = loadThanhToan() && ok;
    ok = loadDatCho() && ok;
    ok = loadNhaCungCap() && ok;
    ok = loadTonKho() && ok;
    return ok;
}

bool DataManager::saveAll() const {
    bool ok = true;
    ok = saveNhanVien() && ok;
    ok = saveKhachHang() && ok;
    ok = saveDanhMuc() && ok;
    ok = saveSanPham() && ok;
    ok = saveBan() && ok;
    ok = saveDonHang() && ok;
    ok = saveChiTietDonHang() && ok;
    ok = saveThanhToan() && ok;
    ok = saveDatCho() && ok;
    ok = saveNhaCungCap() && ok;
    ok = saveTonKho() && ok;
    return ok;
}

NhanVien* DataManager::timNhanVien(const string& maNV) {
    for (auto& nv : nhanViens) {
        if (nv.getMaNV() == maNV) {
            return &nv;
        }
    }
    return nullptr;
}

KhachHang* DataManager::timKhachHang(const string& maKH) {
    for (auto& kh : khachHangs) {
        if (kh.getMaKH() == maKH) {
            return &kh;
        }
    }
    return nullptr;
}

SanPham* DataManager::timSanPham(const string& maSP) {
    for (auto& sp : sanPhams) {
        if (sp.getMaSP() == maSP) {
            return &sp;
        }
    }
    return nullptr;
}

Ban* DataManager::timBan(const string& maBan) {
    for (auto& ban : bans) {
        if (ban.getMaBan() == maBan) {
            return &ban;
        }
    }
    return nullptr;
}

DonHang* DataManager::timDonHang(const string& maDH) {
    for (auto& dh : donHangs) {
        if (dh.getMaDH() == maDH) {
            return &dh;
        }
    }
    return nullptr;
}

TonKho* DataManager::timTonKhoTheoSanPham(const string& maSP) {
    for (auto& tk : tonKhos) {
        if (tk.getMaSP() == maSP) {
            return &tk;
        }
    }
    return nullptr;
}

bool DataManager::loadNhanVien() {
    nhanViens.clear();
    ifstream ifs(makePath(dataDirectory, "nhanvien.txt"));
    if (!ifs.is_open()) {
        return true;
    }
    string line;
    while (getline(ifs, line)) {
        auto parts = Utils::split(line, '|');
        if (parts.size() < 5) {
            continue;
        }
        nhanViens.emplace_back(clean(parts[0]),
                               clean(parts[1]),
                               clean(parts[2]),
                               clean(parts[3]),
                               clean(parts[4]));
    }
    return true;
}

bool DataManager::loadKhachHang() {
    khachHangs.clear();
    ifstream ifs(makePath(dataDirectory, "khachhang.txt"));
    if (!ifs.is_open()) {
        return true;
    }
    string line;
    while (getline(ifs, line)) {
        auto parts = Utils::split(line, '|');
        if (parts.size() < 5) {
            continue;
        }
        khachHangs.emplace_back(clean(parts[0]),
                                clean(parts[1]),
                                clean(parts[2]),
                                clean(parts[3]),
                                clean(parts[4]));
    }
    return true;
}

bool DataManager::loadDanhMuc() {
    danhMucs.clear();
    ifstream ifs(makePath(dataDirectory, "danhmuc.txt"));
    if (!ifs.is_open()) {
        return true;
    }
    string line;
    while (getline(ifs, line)) {
        auto parts = Utils::split(line, '|');
        if (parts.size() < 2) {
            continue;
        }
        danhMucs.emplace_back(clean(parts[0]), clean(parts[1]));
    }
    return true;
}

bool DataManager::loadSanPham() {
    sanPhams.clear();
    ifstream ifs(makePath(dataDirectory, "sanpham.txt"));
    if (!ifs.is_open()) {
        return true;
    }
    string line;
    while (getline(ifs, line)) {
        auto parts = Utils::split(line, '|');
        if (parts.size() < 5) {
            continue;
        }
        sanPhams.emplace_back(clean(parts[0]),
                              clean(parts[1]),
                              clean(parts[2]),
                              toDouble(parts[3]),
                              Utils::stringToBool(parts[4]));
    }
    return true;
}

bool DataManager::loadBan() {
    bans.clear();
    ifstream ifs(makePath(dataDirectory, "ban.txt"));
    if (!ifs.is_open()) {
        return true;
    }
    string line;
    while (getline(ifs, line)) {
        auto parts = Utils::split(line, '|');
        if (parts.size() < 4) {
            continue;
        }
        bans.emplace_back(clean(parts[0]),
                          clean(parts[1]),
                          toInt(parts[2]),
                          clean(parts[3]));
    }
    return true;
}

bool DataManager::loadDonHang() {
    donHangs.clear();
    ifstream ifs(makePath(dataDirectory, "donhang.txt"));
    if (!ifs.is_open()) {
        return true;
    }
    string line;
    while (getline(ifs, line)) {
        auto parts = Utils::split(line, '|');
        if (parts.size() < 7) {
            continue;
        }
        donHangs.emplace_back(clean(parts[0]),
                              clean(parts[1]),
                              clean(parts[2]),
                              clean(parts[3]),
                              clean(parts[4]),
                              clean(parts[5]),
                              toDouble(parts[6]));
    }
    return true;
}

bool DataManager::loadChiTietDonHang() {
    chiTietDonHangs.clear();
    ifstream ifs(makePath(dataDirectory, "chitietdonhang.txt"));
    if (!ifs.is_open()) {
        return true;
    }
    string line;
    while (getline(ifs, line)) {
        auto parts = Utils::split(line, '|');
        if (parts.size() < 5) {
            continue;
        }
        chiTietDonHangs.emplace_back(clean(parts[0]),
                                     clean(parts[1]),
                                     clean(parts[2]),
                                     toInt(parts[3]),
                                     toDouble(parts[4]));
    }
    return true;
}

bool DataManager::loadThanhToan() {
    thanhToans.clear();
    ifstream ifs(makePath(dataDirectory, "thanhtoan.txt"));
    if (!ifs.is_open()) {
        return true;
    }
    string line;
    while (getline(ifs, line)) {
        auto parts = Utils::split(line, '|');
        if (parts.size() < 5) {
            continue;
        }
        thanhToans.emplace_back(clean(parts[0]),
                                clean(parts[1]),
                                toDouble(parts[2]),
                                clean(parts[3]),
                                clean(parts[4]));
    }
    return true;
}

bool DataManager::loadDatCho() {
    datChos.clear();
    ifstream ifs(makePath(dataDirectory, "datcho.txt"));
    if (!ifs.is_open()) {
        return true;
    }
    string line;
    while (getline(ifs, line)) {
        auto parts = Utils::split(line, '|');
        if (parts.size() < 5) {
            continue;
        }
        datChos.emplace_back(clean(parts[0]),
                             clean(parts[1]),
                             clean(parts[2]),
                             clean(parts[3]),
                             toInt(parts[4]));
    }
    return true;
}

bool DataManager::loadNhaCungCap() {
    nhaCungCaps.clear();
    ifstream ifs(makePath(dataDirectory, "nhacungcap.txt"));
    if (!ifs.is_open()) {
        return true;
    }
    string line;
    while (getline(ifs, line)) {
        auto parts = Utils::split(line, '|');
        if (parts.size() < 4) {
            continue;
        }
        nhaCungCaps.emplace_back(clean(parts[0]),
                                 clean(parts[1]),
                                 clean(parts[2]),
                                 clean(parts[3]));
    }
    return true;
}

bool DataManager::loadTonKho() {
    tonKhos.clear();
    ifstream ifs(makePath(dataDirectory, "tonkho.txt"));
    if (!ifs.is_open()) {
        return true;
    }
    string line;
    while (getline(ifs, line)) {
        auto parts = Utils::split(line, '|');
        if (parts.size() < 5) {
            continue;
        }
        tonKhos.emplace_back(clean(parts[0]),
                             clean(parts[1]),
                             clean(parts[2]),
                             toInt(parts[3]),
                             toInt(parts[4]));
    }
    return true;
}

bool DataManager::saveNhanVien() const {
    ofstream ofs(makePath(dataDirectory, "nhanvien.txt"), ios::trunc);
    if (!ofs.is_open()) {
        cerr << "Khong ghi duoc file nhanvien.txt\n";
        return false;
    }
    for (const auto& nv : nhanViens) {
        ofs << nv.getMaNV() << '|'
            << nv.getHoTen() << '|'
            << nv.getChucVu() << '|'
            << nv.getSoDienThoai() << '|'
            << nv.getEmail() << '\n';
    }
    return true;
}

bool DataManager::saveKhachHang() const {
    ofstream ofs(makePath(dataDirectory, "khachhang.txt"), ios::trunc);
    if (!ofs.is_open()) {
        cerr << "Khong ghi duoc file khachhang.txt\n";
        return false;
    }
    for (const auto& kh : khachHangs) {
        ofs << kh.getMaKH() << '|'
            << kh.getHoTen() << '|'
            << kh.getHangThanhVien() << '|'
            << kh.getSoDienThoai() << '|'
            << kh.getEmail() << '\n';
    }
    return true;
}

bool DataManager::saveDanhMuc() const {
    ofstream ofs(makePath(dataDirectory, "danhmuc.txt"), ios::trunc);
    if (!ofs.is_open()) {
        cerr << "Khong ghi duoc file danhmuc.txt\n";
        return false;
    }
    for (const auto& dm : danhMucs) {
        ofs << dm.getMaDM() << '|'
            << dm.getTenDM() << '\n';
    }
    return true;
}

bool DataManager::saveSanPham() const {
    ofstream ofs(makePath(dataDirectory, "sanpham.txt"), ios::trunc);
    if (!ofs.is_open()) {
        cerr << "Khong ghi duoc file sanpham.txt\n";
        return false;
    }
    for (const auto& sp : sanPhams) {
        ofs << sp.getMaSP() << '|'
            << sp.getTenSP() << '|'
            << sp.getMaDM() << '|'
            << sp.getDonGia() << '|'
            << Utils::boolToString(sp.getDangBan()) << '\n';
    }
    return true;
}

bool DataManager::saveBan() const {
    ofstream ofs(makePath(dataDirectory, "ban.txt"), ios::trunc);
    if (!ofs.is_open()) {
        cerr << "Khong ghi duoc file ban.txt\n";
        return false;
    }
    for (const auto& ban : bans) {
        ofs << ban.getMaBan() << '|'
            << ban.getTenBan() << '|'
            << ban.getSucChua() << '|'
            << ban.getTrangThai() << '\n';
    }
    return true;
}

bool DataManager::saveDonHang() const {
    ofstream ofs(makePath(dataDirectory, "donhang.txt"), ios::trunc);
    if (!ofs.is_open()) {
        cerr << "Khong ghi duoc file donhang.txt\n";
        return false;
    }
    for (const auto& dh : donHangs) {
        ofs << dh.getMaDH() << '|'
            << dh.getMaKH() << '|'
            << dh.getMaNV() << '|'
            << dh.getMaBan() << '|'
            << dh.getThoiGianLap() << '|'
            << dh.getTrangThai() << '|'
            << dh.getGiamGia() << '\n';
    }
    return true;
}

bool DataManager::saveChiTietDonHang() const {
    ofstream ofs(makePath(dataDirectory, "chitietdonhang.txt"), ios::trunc);
    if (!ofs.is_open()) {
        cerr << "Khong ghi duoc file chitietdonhang.txt\n";
        return false;
    }
    for (const auto& ct : chiTietDonHangs) {
        ofs << ct.getMaCT() << '|'
            << ct.getMaDH() << '|'
            << ct.getMaSP() << '|'
            << ct.getSoLuong() << '|'
            << ct.getDonGia() << '\n';
    }
    return true;
}

bool DataManager::saveThanhToan() const {
    ofstream ofs(makePath(dataDirectory, "thanhtoan.txt"), ios::trunc);
    if (!ofs.is_open()) {
        cerr << "Khong ghi duoc file thanhtoan.txt\n";
        return false;
    }
    for (const auto& tt : thanhToans) {
        ofs << tt.getMaTT() << '|'
            << tt.getMaDH() << '|'
            << tt.getSoTien() << '|'
            << tt.getHinhThuc() << '|'
            << tt.getThoiGianTT() << '\n';
    }
    return true;
}

bool DataManager::saveDatCho() const {
    ofstream ofs(makePath(dataDirectory, "datcho.txt"), ios::trunc);
    if (!ofs.is_open()) {
        cerr << "Khong ghi duoc file datcho.txt\n";
        return false;
    }
    for (const auto& dc : datChos) {
        ofs << dc.getMaDC() << '|'
            << dc.getMaKH() << '|'
            << dc.getMaBan() << '|'
            << dc.getThoiGianDat() << '|'
            << dc.getSoNguoi() << '\n';
    }
    return true;
}

bool DataManager::saveNhaCungCap() const {
    ofstream ofs(makePath(dataDirectory, "nhacungcap.txt"), ios::trunc);
    if (!ofs.is_open()) {
        cerr << "Khong ghi duoc file nhacungcap.txt\n";
        return false;
    }
    for (const auto& ncc : nhaCungCaps) {
        ofs << ncc.getMaNCC() << '|'
            << ncc.getTenNCC() << '|'
            << ncc.getSoDienThoai() << '|'
            << ncc.getEmail() << '\n';
    }
    return true;
}

bool DataManager::saveTonKho() const {
    ofstream ofs(makePath(dataDirectory, "tonkho.txt"), ios::trunc);
    if (!ofs.is_open()) {
        cerr << "Khong ghi duoc file tonkho.txt\n";
        return false;
    }
    for (const auto& tk : tonKhos) {
        ofs << tk.getMaTK() << '|'
            << tk.getMaSP() << '|'
            << tk.getMaNCC() << '|'
            << tk.getSoLuongTon() << '|'
            << tk.getMucDatHangLai() << '\n';
    }
    return true;
}

