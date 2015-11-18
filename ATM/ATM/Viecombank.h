#include "NganHang.h"

class Viecombank : public NganHang{
private:
	Viecombank();
	static Viecombank init;
public:
	string TenGiaoDich() const;
	string XemMaNH() const;
	double PhiPos() const;
};

class TKTGTT_Viecombank : public TaiKhoan{
private:
	string TenKH;
	string CMND;
public:
	TKTGTT_Viecombank(string input);
	string XemMaNH() const;
	bool KTMaTK(string MaTK) const;
	void XuatThongTin() const;
};

class TKT_Viecombank : public TaiKhoan{
private:
	string TenDN;
	string DiaChi;
	string MaThue;
public:
	TKT_Viecombank(string input);
	string XemMaNH() const;
	bool KTMaTK(string MaTK) const;
	void XuatThongTin() const;
};

class TheThanhToan_Viecombank : public The{
public:
	bool KiemTraRutTien(TaiKhoan *tk, double SoTien) const;
	TheThanhToan_Viecombank(string input);
	bool KTMaThe(string MaTK) const;
};

class ThePhu_Viecombank : public The{
private:
	double HanMuc;
public:
	bool KiemTraRutTien(TaiKhoan *tk, double SoTien) const;
	ThePhu_Viecombank(string input);
	bool KTMaThe(string MaTK) const;
};

class Pos_Viecombank : public Pos{
public:
	Pos_Viecombank(string input);
	string XemMaNH() const;
	bool KTMaPos(string MaPos) const;
	void NhanThe(The *the, string PIN, GiaoDich *giaodich) const;
};