#include "NganHang.h"

class Xacombank : public NganHang{
private:
	Xacombank();
	static Xacombank init;
public:
	string TenGiaoDich() const;
	string XemMaNH() const;
	double PhiPos() const;
};

class TKTGTT_Xacombank : public TaiKhoan{
private:
	string TenKH;
	string CMND;
public:
	TKTGTT_Xacombank(string input);
	string XemMaNH() const;
	bool KTMaTK(string MaTK) const;
	void XuatThongTin() const;
};

class TKT_Xacombank : public TaiKhoan{
private:
	string TenDN;
	string DiaChi;
	string MaThue;
public:
	TKT_Xacombank(string input);
	string XemMaNH() const;
	bool KTMaTK(string MaTK) const;
	void XuatThongTin() const;
};

class TheThanhToan_Xacombank : public The{
public:
	bool KiemTraRutTien(TaiKhoan *tk, double SoTien) const;
	TheThanhToan_Xacombank(string input);
	bool KTMaThe(string MaTK) const;
};

class ThePhu_Xacombank : public The{
private:
	double HanMuc;
public:
	bool KiemTraRutTien(TaiKhoan *tk, double SoTien) const;
	ThePhu_Xacombank(string input);
	bool KTMaThe(string MaTK) const;
};

class Pos_Xacombank : public Pos{
public:
	Pos_Xacombank(string input);
	string XemMaNH() const;
	bool KTMaPos(string MaTK) const;
	void NhanThe(The *the, string PIN, GiaoDich *giaodich) const;
};