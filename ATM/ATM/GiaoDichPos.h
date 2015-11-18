#include "NganHang.h"

class GiaoDichPos : public GiaoDich{
protected:
	string MaPos;
	string MaNHNT;
	string MaThe;
	string PIN;
	string TenKH;
	string HSD;
	string MaNHTT;
	double SoTien;
	string MoTa;
	void LichSuGiaoDich();
	void XuatLichSu(TaiKhoan *tk) const;
private:
	void ChuanBiThongTin(const void *pos, The *the, string pass, string TenKH);
	bool KTVBnet() const;
	void NganHangXuLy(NganHang *bank);
public:
	bool ThanhCong() const;
	GiaoDichPos(string TenKH, double SoTien, string MoTa);
	void InBienLai() const;
};