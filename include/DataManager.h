#pragma once

#include "Ban.h"
#include "ChiTietDonHang.h"
#include "DanhMuc.h"
#include "DatCho.h"
#include "DonHang.h"
#include "KhachHang.h"
#include "NhanVien.h"
#include "NhaCungCap.h"
#include "SanPham.h"
#include "ThanhToan.h"
#include "TonKho.h"
#include <optional>
#include <string>
#include <vector>
using namespace std;
class DataManager {
private:
    string dataDirectory;

    bool loadNhanVien();
    bool loadKhachHang();
    bool loadDanhMuc();
    bool loadSanPham();
    bool loadBan();
    bool loadDonHang();
    bool loadChiTietDonHang();
    bool loadThanhToan();
    bool loadDatCho();
    bool loadNhaCungCap();
    bool loadTonKho();

    bool saveNhanVien() const;
    bool saveKhachHang() const;
    bool saveDanhMuc() const;
    bool saveSanPham() const;
    bool saveBan() const;
    bool saveDonHang() const;
    bool saveChiTietDonHang() const;
    bool saveThanhToan() const;
    bool saveDatCho() const;
    bool saveNhaCungCap() const;
    bool saveTonKho() const;

public:
    vector<NhanVien> nhanViens;
    vector<KhachHang> khachHangs;
    vector<DanhMuc> danhMucs;
    vector<SanPham> sanPhams;
    vector<Ban> bans;
    vector<DonHang> donHangs;
    vector<ChiTietDonHang> chiTietDonHangs;
    vector<ThanhToan> thanhToans;
    vector<DatCho> datChos;
    vector<NhaCungCap> nhaCungCaps;
    vector<TonKho> tonKhos;

    explicit DataManager(string dataDirectory);

    bool loadAll();
    bool saveAll() const;

    NhanVien* timNhanVien(const string& maNV);
    KhachHang* timKhachHang(const string& maKH);
    SanPham* timSanPham(const string& maSP);
    Ban* timBan(const string& maBan);
    DonHang* timDonHang(const string& maDH);
    TonKho* timTonKhoTheoSanPham(const string& maSP);
};

