#include "NganHang.h"

class TruyVan : public GiaoDich{
protected:
	string MaATM;
	string MaNH;
	string MaThe;
	string PIN;
	string MaTK;
	void LichSuGiaoDich();
	void XuatLichSu(TaiKhoan *tk) const;
private:
	void ChuanBiThongTin(const void *atm, The *the, string pass, string MaTKLuaChon);
	bool KTVBnet() const;
	void NganHangXuLy(NganHang *bank);
public:
	bool ThanhCong() const;
	TruyVan();
	void InBienLai() const;
};