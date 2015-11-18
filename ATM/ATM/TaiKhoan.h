#ifndef _TaiKhoan
#define _TaiKHoan

#include <string>
#include <set>
using namespace std;

class GiaoDich;

class TaiKhoan{
protected:
	string MaTK;
	double SoDu;
	set <GiaoDich*> DSGiaoDich;
private:
	void CapNhatSoTien(double SoTien){
		SoDu = SoTien;
	}
public:
	void ThemGiaoDich(GiaoDich *giaodich){
		DSGiaoDich.insert(giaodich);
	}

	string XemMaTK() const{
		return MaTK;
	}

	double XemSoDu() const{
		return SoDu;
	}

	virtual string XemMaNH() const = 0;
	virtual bool KTMaTK(string MaTK) const = 0;
	virtual void XuatThongTin() const = 0;

	friend class GiaoDich;
};

#endif