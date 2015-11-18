#include "NganHang.h"

class ChuyenKhoan : public GiaoDich{
protected:
	string MaATM;
	string MaNHTT;
	string MaThe;
	string PIN;
	string MaTKTT;
	double SoTien;

	string MaNHNT;
	string MaTKNT;
	void LichSuGiaoDich();
	void XuatLichSu(TaiKhoan *tk) const;
private:
	void ChuanBiThongTin(const void *atm, The *the, string pass, string MSTK);
	bool KTVBnet() const;
	void NganHangXuLy(NganHang *bank);
public:
	bool ThanhCong() const;
	ChuyenKhoan(string MaNHNT, string MaTKNT, double SoTien, HoaDon hoadon);
	void InBienLai() const;
};