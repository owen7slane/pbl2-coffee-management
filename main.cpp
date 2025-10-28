#include "DataManager.h"
#include "Utils.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

namespace {

string prompt(const string& message) {
    cout << message;
    string input;
    getline(cin, input);
    return Utils::trim(input);
}

int promptInt(const string& message) {
    while (true) {
        auto value = prompt(message);
        if (value.empty()) {
            continue;
        }
        try {
            return stoi(value);
        } catch (...) {
            cout << "Gia tri khong hop le. Vui long nhap so nguyen.\n";
        }
    }
}

double promptDouble(const string& message) {
    while (true) {
        auto value = prompt(message);
        if (value.empty()) {
            continue;
        }
        try {
            return stod(value);
        } catch (...) {
            cout << "Gia tri khong hop le. Vui long nhap so thuc.\n";
        }
    }
}

void hienThiDanhSachDonHang(const DataManager& dataManager) {
    cout << "\n--- Danh sach Don Hang ---\n";
    for (const auto& dh : dataManager.donHangs) {
        cout << "Ma DH: " << dh.getMaDH()
                  << " | KH: " << dh.getMaKH()
                  << " | NV: " << dh.getMaNV()
                  << " | Ban: " << dh.getMaBan()
                  << " | Thoi gian: " << dh.getThoiGianLap()
                  << " | Trang thai: " << dh.getTrangThai()
                  << " | Giam gia: " << dh.getGiamGia()
                  << '\n';
    }
}

void hienThiChiTietDonHang(const DataManager& dataManager, const string& maDH) {
    cout << "\n--- Chi tiet Don Hang " << maDH << " ---\n";
    for (const auto& ct : dataManager.chiTietDonHangs) {
        if (ct.getMaDH() == maDH) {
            cout << "Ma CT: " << ct.getMaCT()
                      << " | San pham: " << ct.getMaSP()
                      << " | So luong: " << ct.getSoLuong()
                      << " | Don gia: " << ct.getDonGia()
                      << " | Thanh tien: " << ct.tinhThanhTien()
                      << '\n';
        }
    }
}

void quanLyBanHang(DataManager& dataManager) {
    bool quayLai = false;
    while (!quayLai) {
        cout << "\n=== Quan ly Ban hang ===\n"
                  << "1. Xem danh sach don hang\n"
                  << "2. Tao don hang moi\n"
                  << "3. Them mon vao don hang\n"
                  << "4. Xoa mon khoi don hang\n"
                  << "5. Ap dung giam gia\n"
                  << "6. Thanh toan don hang\n"
                  << "7. Huy don hang\n"
                  << "8. Quay lai\n";
        auto chon = prompt("Chon chuc nang: ");
        if (chon == "1") {
            hienThiDanhSachDonHang(dataManager);
        } else if (chon == "2") {
            string maDH = prompt("Nhap ma don hang: ");
            string maKH = prompt("Nhap ma khach hang: ");
            string maNV = prompt("Nhap ma nhan vien: ");
            string maBan = prompt("Nhap ma ban: ");
            string thoiGian = prompt("Nhap thoi gian lap (YYYY-MM-DD HH:MM): ");
            string trangThai = prompt("Nhap trang thai ban dau: ");
            double giamGia = promptDouble("Nhap giam gia ban dau (0 neu khong co): ");

            dataManager.donHangs.emplace_back(maDH, maKH, maNV, maBan, thoiGian, trangThai, giamGia);
            cout << "Da tao don hang moi.\n";
        } else if (chon == "3") {
            string maDH = prompt("Nhap ma don hang: ");
            auto* donHang = dataManager.timDonHang(maDH);
            if (!donHang) {
                cout << "Khong tim thay don hang.\n";
                continue;
            }
            string maCT = prompt("Nhap ma chi tiet: ");
            string maSP = prompt("Nhap ma san pham: ");
            int soLuong = promptInt("Nhap so luong: ");
            double donGia = promptDouble("Nhap don gia: ");
            ChiTietDonHang chiTiet(maCT, maDH, maSP, soLuong, donGia);
            donHang->themMon(dataManager.chiTietDonHangs, chiTiet);
            cout << "Da them mon vao don hang.\n";
        } else if (chon == "4") {
            string maDH = prompt("Nhap ma don hang: ");
            auto* donHang = dataManager.timDonHang(maDH);
            if (!donHang) {
                cout << "Khong tim thay don hang.\n";
                continue;
            }
            string maCT = prompt("Nhap ma chi tiet can xoa: ");
            donHang->xoaMon(dataManager.chiTietDonHangs, maCT);
            cout << "Da xoa mon neu ton tai.\n";
        } else if (chon == "5") {
            string maDH = prompt("Nhap ma don hang: ");
            auto* donHang = dataManager.timDonHang(maDH);
            if (!donHang) {
                cout << "Khong tim thay don hang.\n";
                continue;
            }
            double giamGia = promptDouble("Nhap so tien giam gia: ");
            donHang->apDungGiamGia(giamGia);
            cout << "Da ap dung giam gia.\n";
        } else if (chon == "6") {
            string maDH = prompt("Nhap ma don hang: ");
            auto* donHang = dataManager.timDonHang(maDH);
            if (!donHang) {
                cout << "Khong tim thay don hang.\n";
                continue;
            }
            double tongTien = donHang->tinhTongTien(dataManager.chiTietDonHangs);
            cout << "Tong tien phai thu: " << tongTien << '\n';
            string maTT = prompt("Nhap ma thanh toan: ");
            string hinhThuc = prompt("Nhap hinh thuc thanh toan: ");
            string thoiGian = prompt("Nhap thoi gian thanh toan: ");
            dataManager.thanhToans.emplace_back(maTT, maDH, tongTien, hinhThuc, thoiGian);
            donHang->thanhToan();
            cout << "Da ghi nhan thanh toan va cap nhat trang thai don hang.\n";
        } else if (chon == "7") {
            string maDH = prompt("Nhap ma don hang: ");
            auto* donHang = dataManager.timDonHang(maDH);
            if (!donHang) {
                cout << "Khong tim thay don hang.\n";
                continue;
            }
            donHang->huyDon();
            cout << "Don hang da duoc huy.\n";
        } else if (chon == "8") {
            quayLai = true;
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    }
}

void quanLyBanVaDatCho(DataManager& dataManager) {
    bool quayLai = false;
    while (!quayLai) {
        cout << "\n=== Quan ly Ban & Dat cho ===\n"
                  << "1. Xem danh sach ban\n"
                  << "2. Cap nhat trang thai ban\n"
                  << "3. Xem danh sach dat cho\n"
                  << "4. Tao dat cho moi\n"
                  << "5. Huy dat cho\n"
                  << "6. Doi lich dat cho\n"
                  << "7. Quay lai\n";
        auto chon = prompt("Chon chuc nang: ");
        if (chon == "1") {
            for (const auto& ban : dataManager.bans) {
                cout << "Ma ban: " << ban.getMaBan()
                          << " | Ten ban: " << ban.getTenBan()
                          << " | Suc chua: " << ban.getSucChua()
                          << " | Trang thai: " << ban.getTrangThai()
                          << '\n';
            }
        } else if (chon == "2") {
            string maBan = prompt("Nhap ma ban: ");
            auto* ban = dataManager.timBan(maBan);
            if (!ban) {
                cout << "Khong tim thay ban.\n";
                continue;
            }
            cout << "1. Dat truoc\n2. Cho khach\n3. Giai phong\n";
            auto luaChon = prompt("Lua chon trang thai: ");
            if (luaChon == "1") {
                ban->datTruoc();
            } else if (luaChon == "2") {
                ban->choKhach();
            } else if (luaChon == "3") {
                ban->giaiPhong();
            } else {
                cout << "Lua chon khong hop le.\n";
                continue;
            }
            cout << "Da cap nhat trang thai ban.\n";
        } else if (chon == "3") {
            for (const auto& dc : dataManager.datChos) {
                cout << "Ma DC: " << dc.getMaDC()
                          << " | Khach: " << dc.getMaKH()
                          << " | Ban: " << dc.getMaBan()
                          << " | Thoi gian: " << dc.getThoiGianDat()
                          << " | So nguoi: " << dc.getSoNguoi()
                          << '\n';
            }
        } else if (chon == "4") {
            string maDC = prompt("Nhap ma dat cho: ");
            string maKH = prompt("Nhap ma khach hang: ");
            string maBan = prompt("Nhap ma ban: ");
            string thoiGian = prompt("Nhap thoi gian dat: ");
            int soNguoi = promptInt("Nhap so nguoi: ");
            dataManager.datChos.emplace_back(maDC, maKH, maBan, thoiGian, soNguoi);
            cout << "Da tao dat cho moi.\n";
        } else if (chon == "5") {
            string maDC = prompt("Nhap ma dat cho: ");
            bool timThay = false;
            for (auto& dc : dataManager.datChos) {
                if (dc.getMaDC() == maDC) {
                    dc.huyDat();
                    timThay = true;
                    break;
                }
            }
            if (timThay) {
                cout << "Da huy lich dat cho.\n";
            } else {
                cout << "Khong tim thay dat cho.\n";
            }
        } else if (chon == "6") {
            string maDC = prompt("Nhap ma dat cho: ");
            bool timThay = false;
            for (auto& dc : dataManager.datChos) {
                if (dc.getMaDC() == maDC) {
                    string thoiGianMoi = prompt("Nhap thoi gian moi: ");
                    dc.doiLich(thoiGianMoi);
                    timThay = true;
                    break;
                }
            }
            if (timThay) {
                cout << "Da doi lich dat cho.\n";
            } else {
                cout << "Khong tim thay dat cho.\n";
            }
        } else if (chon == "7") {
            quayLai = true;
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    }
}

void quanLySanPhamVaDanhMuc(DataManager& dataManager) {
    bool quayLai = false;
    while (!quayLai) {
        cout << "\n=== Quan ly San pham & Danh muc ===\n"
                  << "1. Xem danh sach danh muc\n"
                  << "2. Doi ten danh muc\n"
                  << "3. Them danh muc\n"
                  << "4. Xem danh sach san pham\n"
                  << "5. Them san pham\n"
                  << "6. Doi gia san pham\n"
                  << "7. Ngung ban san pham\n"
                  << "8. Quay lai\n";
        auto chon = prompt("Chon chuc nang: ");
        if (chon == "1") {
            for (const auto& dm : dataManager.danhMucs) {
                cout << "Ma DM: " << dm.getMaDM()
                          << " | Ten: " << dm.getTenDM()
                          << '\n';
            }
        } else if (chon == "2") {
            string maDM = prompt("Nhap ma danh muc: ");
            bool timThay = false;
            for (auto& dm : dataManager.danhMucs) {
                if (dm.getMaDM() == maDM) {
                    string tenMoi = prompt("Nhap ten moi: ");
                    dm.doiTen(tenMoi);
                    timThay = true;
                    break;
                }
            }
            if (timThay) {
                cout << "Da cap nhat ten danh muc.\n";
            } else {
                cout << "Khong tim thay danh muc.\n";
            }
        } else if (chon == "3") {
            string maDM = prompt("Nhap ma danh muc moi: ");
            string tenDM = prompt("Nhap ten danh muc: ");
            dataManager.danhMucs.emplace_back(maDM, tenDM);
            cout << "Da them danh muc.\n";
        } else if (chon == "4") {
            for (const auto& sp : dataManager.sanPhams) {
                cout << "Ma SP: " << sp.getMaSP()
                          << " | Ten: " << sp.getTenSP()
                          << " | Danh muc: " << sp.getMaDM()
                          << " | Don gia: " << sp.getDonGia()
                          << " | Dang ban: " << (sp.getDangBan() ? "Co" : "Khong")
                          << '\n';
            }
        } else if (chon == "5") {
            string maSP = prompt("Nhap ma san pham: ");
            string tenSP = prompt("Nhap ten san pham: ");
            string maDM = prompt("Nhap ma danh muc: ");
            double donGia = promptDouble("Nhap don gia: ");
            string dangBan = prompt("San pham dang ban? (1/0): ");
            bool trangThai = dangBan == "1" || dangBan == "true";
            dataManager.sanPhams.emplace_back(maSP, tenSP, maDM, donGia, trangThai);
            cout << "Da them san pham.\n";
        } else if (chon == "6") {
            string maSP = prompt("Nhap ma san pham: ");
            auto* sp = dataManager.timSanPham(maSP);
            if (!sp) {
                cout << "Khong tim thay san pham.\n";
                continue;
            }
            double giaMoi = promptDouble("Nhap gia moi: ");
            sp->doiGia(giaMoi);
            cout << "Da cap nhat gia.\n";
        } else if (chon == "7") {
            string maSP = prompt("Nhap ma san pham: ");
            auto* sp = dataManager.timSanPham(maSP);
            if (!sp) {
                cout << "Khong tim thay san pham.\n";
                continue;
            }
            sp->ngungBan();
            cout << "San pham da duoc ngung ban.\n";
        } else if (chon == "8") {
            quayLai = true;
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    }
}

void quanLyNhanSu(DataManager& dataManager) {
    bool quayLai = false;
    while (!quayLai) {
        cout << "\n=== Quan ly Nhan su ===\n"
                  << "1. Xem danh sach nhan vien\n"
                  << "2. Them nhan vien\n"
                  << "3. Phan cong ban\n"
                  << "4. Ket ca nhan vien\n"
                  << "5. Quay lai\n";
        auto chon = prompt("Chon chuc nang: ");
        if (chon == "1") {
            for (const auto& nv : dataManager.nhanViens) {
                cout << "Ma NV: " << nv.getMaNV()
                          << " | Ten: " << nv.getHoTen()
                          << " | Chuc vu: " << nv.getChucVu()
                          << " | SDT: " << nv.getSoDienThoai()
                          << " | Email: " << nv.getEmail()
                          << '\n';
            }
        } else if (chon == "2") {
            string maNV = prompt("Nhap ma nhan vien: ");
            string ten = prompt("Nhap ho ten: ");
            string chucVu = prompt("Nhap chuc vu: ");
            string sdt = prompt("Nhap so dien thoai: ");
            string email = prompt("Nhap email: ");
            dataManager.nhanViens.emplace_back(maNV, ten, chucVu, sdt, email);
            cout << "Da them nhan vien.\n";
        } else if (chon == "3") {
            string maNV = prompt("Nhap ma nhan vien: ");
            auto* nv = dataManager.timNhanVien(maNV);
            if (!nv) {
                cout << "Khong tim thay nhan vien.\n";
                continue;
            }
            string maBan = prompt("Nhap ma ban phan cong: ");
            cout << nv->phanCongBan(maBan) << '\n';
        } else if (chon == "4") {
            string maNV = prompt("Nhap ma nhan vien: ");
            auto* nv = dataManager.timNhanVien(maNV);
            if (!nv) {
                cout << "Khong tim thay nhan vien.\n";
                continue;
            }
            cout << nv->ketCa() << '\n';
        } else if (chon == "5") {
            quayLai = true;
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    }
}

void quanLyKhachHang(DataManager& dataManager) {
    bool quayLai = false;
    while (!quayLai) {
        cout << "\n=== Quan ly Khach hang ===\n"
                  << "1. Xem danh sach khach hang\n"
                  << "2. Them khach hang\n"
                  << "3. Cap nhat thong tin khach hang\n"
                  << "4. Xem lich su don hang\n"
                  << "5. Quay lai\n";
        auto chon = prompt("Chon chuc nang: ");
        if (chon == "1") {
            for (const auto& kh : dataManager.khachHangs) {
                cout << "Ma KH: " << kh.getMaKH()
                          << " | Ten: " << kh.getHoTen()
                          << " | Hang TV: " << kh.getHangThanhVien()
                          << " | SDT: " << kh.getSoDienThoai()
                          << " | Email: " << kh.getEmail()
                          << '\n';
            }
        } else if (chon == "2") {
            string maKH = prompt("Nhap ma khach hang: ");
            string ten = prompt("Nhap ho ten: ");
            string hang = prompt("Nhap hang thanh vien: ");
            string sdt = prompt("Nhap so dien thoai: ");
            string email = prompt("Nhap email: ");
            dataManager.khachHangs.emplace_back(maKH, ten, hang, sdt, email);
            cout << "Da them khach hang.\n";
        } else if (chon == "3") {
            string maKH = prompt("Nhap ma khach hang: ");
            auto* kh = dataManager.timKhachHang(maKH);
            if (!kh) {
                cout << "Khong tim thay khach hang.\n";
                continue;
            }
            string ten = prompt("Nhap ho ten moi: ");
            string sdt = prompt("Nhap so dien thoai moi: ");
            string email = prompt("Nhap email moi: ");
            string hang = prompt("Nhap hang thanh vien moi: ");
            kh->capNhatThongTin(ten, sdt, email);
            kh->setHangThanhVien(hang);
            cout << "Da cap nhat thong tin khach hang.\n";
        } else if (chon == "4") {
            string maKH = prompt("Nhap ma khach hang: ");
            auto* kh = dataManager.timKhachHang(maKH);
            if (!kh) {
                cout << "Khong tim thay khach hang.\n";
                continue;
            }
            cout << kh->xemLichSuDonHang() << '\n';
            for (const auto& dh : dataManager.donHangs) {
                if (dh.getMaKH() == maKH) {
                    cout << "Don hang: " << dh.getMaDH()
                              << " | Thoi gian: " << dh.getThoiGianLap()
                              << " | Trang thai: " << dh.getTrangThai()
                              << " | Tong tien: " << dh.tinhTongTien(dataManager.chiTietDonHangs)
                              << '\n';
                    hienThiChiTietDonHang(dataManager, dh.getMaDH());
                }
            }
        } else if (chon == "5") {
            quayLai = true;
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    }
}

void quanLyKhoVaNhaCungCap(DataManager& dataManager) {
    bool quayLai = false;
    while (!quayLai) {
        cout << "\n=== Quan ly Kho & Nha cung cap ===\n"
                  << "1. Xem ton kho\n"
                  << "2. Nhap them hang\n"
                  << "3. Xuat bot hang\n"
                  << "4. Kiem tra muc dat hang lai\n"
                  << "5. Xem danh sach nha cung cap\n"
                  << "6. Them nha cung cap\n"
                  << "7. Cap nhat lien he nha cung cap\n"
                  << "8. Quay lai\n";
        auto chon = prompt("Chon chuc nang: ");
        if (chon == "1") {
            for (const auto& tk : dataManager.tonKhos) {
                cout << "Ma TK: " << tk.getMaTK()
                          << " | San pham: " << tk.getMaSP()
                          << " | NCC: " << tk.getMaNCC()
                          << " | Ton: " << tk.getSoLuongTon()
                          << " | Muc dat hang lai: " << tk.getMucDatHangLai()
                          << '\n';
            }
        } else if (chon == "2") {
            string maSP = prompt("Nhap ma san pham: ");
            auto* tk = dataManager.timTonKhoTheoSanPham(maSP);
            if (!tk) {
                string maTK = prompt("Nhap ma ton kho moi: ");
                string maNCC = prompt("Nhap ma nha cung cap: ");
                int soLuong = promptInt("Nhap so luong ton ban dau: ");
                int mucDat = promptInt("Nhap muc dat hang lai: ");
                TonKho tonKho(maTK, maSP, maNCC, soLuong, mucDat);
                tonKho.nhapThem(promptInt("Nhap so luong nhap them: "));
                dataManager.tonKhos.push_back(tonKho);
                cout << "Da tao ban ghi ton kho moi va nhap hang.\n";
            } else {
                int soLuongNhap = promptInt("Nhap so luong nhap them: ");
                tk->nhapThem(soLuongNhap);
                cout << "Da cap nhat so luong ton.\n";
            }
        } else if (chon == "3") {
            string maSP = prompt("Nhap ma san pham: ");
            auto* tk = dataManager.timTonKhoTheoSanPham(maSP);
            if (!tk) {
                cout << "Khong tim thay ton kho cho san pham nay.\n";
                continue;
            }
            int soLuongXuat = promptInt("Nhap so luong xuat bot: ");
            if (tk->xuatBot(soLuongXuat)) {
                cout << "Da xuat hang khoi kho.\n";
            } else {
                cout << "So luong ton khong du.\n";
            }
        } else if (chon == "4") {
            string maSP = prompt("Nhap ma san pham: ");
            auto* tk = dataManager.timTonKhoTheoSanPham(maSP);
            if (!tk) {
                cout << "Khong tim thay ton kho cho san pham nay.\n";
                continue;
            }
            if (tk->canDatHang()) {
                cout << "Can dat hang lai cho san pham nay.\n";
            } else {
                cout << "Chua can dat hang lai.\n";
            }
        } else if (chon == "5") {
            for (const auto& ncc : dataManager.nhaCungCaps) {
                cout << "Ma NCC: " << ncc.getMaNCC()
                          << " | Ten: " << ncc.getTenNCC()
                          << " | SDT: " << ncc.getSoDienThoai()
                          << " | Email: " << ncc.getEmail()
                          << '\n';
            }
        } else if (chon == "6") {
            string maNCC = prompt("Nhap ma nha cung cap: ");
            string ten = prompt("Nhap ten nha cung cap: ");
            string sdt = prompt("Nhap so dien thoai: ");
            string email = prompt("Nhap email: ");
            dataManager.nhaCungCaps.emplace_back(maNCC, ten, sdt, email);
            cout << "Da them nha cung cap.\n";
        } else if (chon == "7") {
            string maNCC = prompt("Nhap ma nha cung cap: ");
            bool timThay = false;
            for (auto& ncc : dataManager.nhaCungCaps) {
                if (ncc.getMaNCC() == maNCC) {
                    string sdt = prompt("Nhap SDT moi: ");
                    string email = prompt("Nhap email moi: ");
                    ncc.capNhatLienHe(sdt, email);
                    timThay = true;
                    break;
                }
            }
            if (timThay) {
                cout << "Da cap nhat lien he nha cung cap.\n";
            } else {
                cout << "Khong tim thay nha cung cap.\n";
            }
        } else if (chon == "8") {
            quayLai = true;
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    }
}

void hienThiMenuChinh() {
    cout << "\n===== He thong Quan ly Quan Ca Phe =====\n"
              << "1. Quan ly Ban hang\n"
              << "2. Quan ly Ban & Dat cho\n"
              << "3. Quan ly San pham & Danh muc\n"
              << "4. Quan ly Nhan su\n"
              << "5. Quan ly Khach hang\n"
              << "6. Quan ly Kho & Nha cung cap\n"
              << "7. Luu va Thoat\n";
}

}  // namespace

int main() {
    DataManager dataManager("data");
    if (!dataManager.loadAll()) {
        cerr << "Co loi khi tai du lieu. Vui long kiem tra cac tep .txt.\n";
    }

    bool thoat = false;
    while (!thoat) {
        hienThiMenuChinh();
        auto chon = prompt("Chon chuc nang: ");
        if (chon == "1") {
            quanLyBanHang(dataManager);
        } else if (chon == "2") {
            quanLyBanVaDatCho(dataManager);
        } else if (chon == "3") {
            quanLySanPhamVaDanhMuc(dataManager);
        } else if (chon == "4") {
            quanLyNhanSu(dataManager);
        } else if (chon == "5") {
            quanLyKhachHang(dataManager);
        } else if (chon == "6") {
            quanLyKhoVaNhaCungCap(dataManager);
        } else if (chon == "7") {
            thoat = true;
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    }

    if (dataManager.saveAll()) {
        cout << "Da luu du lieu thanh cong. Tam biet!\n";
    } else {
        cout << "Co loi khi luu du lieu. Vui long kiem tra tep.\n";
    }

    return 0;
}
