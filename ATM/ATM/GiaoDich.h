#ifndef _GiaoDich
#define _GiaoDich

#include <iostream>
#include <string>
#include <time.h>
#include "The.h"
using namespace std;

class NganHang;

enum HoaDon{
	KhongIn,
	In
};

class GiaoDich{
protected:
	string MaBenNhan;
	string KetQua;
	HoaDon InHoaDon;

	GiaoDich(HoaDon hoadon, string ketqua, bool hoanthanh);
	void CapNhatTK(TaiKhoan *tk, double SoTien);
	virtual void LichSuGiaoDich() = 0;
	virtual void XuatLichSu(TaiKhoan *tk) const = 0;
private:
	virtual bool KTVBnet() const = 0;
	virtual void NganHangXuLy(NganHang *bank) = 0;
public:
	bool HoanThanh;
	bool CoKetQua(){
		return KetQua != "";
	}
	virtual void ChuanBiThongTin(const void *pos_atm, The *the, string PIN, string MaTKLuaChon) = 0;
	virtual void InBienLai() const = 0;
	void CapNhatKQ(string KQ);
	virtual bool ThanhCong() const = 0;

	friend class ATM;
	friend class ATM_VBnet;
	friend class Pos;
	friend class VBnet;
	friend class NganHang;
};

string Now();
int TimThang(string Date);
int TimNam(string Date);
bool KiemTraHSD(string Now, string HSD);

#endif