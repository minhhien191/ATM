#include "NganHang.h"

class NopTien : public GiaoDich{
protected:
	string MaATM;
	string MaNH;
	string MaThe;
	string PIN;
	string MaTK;
	double SoTien;
	void LichSuGiaoDich();
	void XuatLichSu(TaiKhoan *tk) const;
private:
	void ChuanBiThongTin(const void *atm, The *the, string pass, string MSTK);
	bool KTVBnet() const;
	void NganHangXuLy(NganHang *bank);
public:
	bool ThanhCong() const;
	NopTien(double SoTien, HoaDon hoadon);
	void InBienLai() const;
};