#ifndef _The
#define _The

#include <string>
#include "TaiKhoan.h"
using namespace std;

class The{
protected:
	string MaThe;
	string MaNH;
	string MaTKMacDinh;
	string TenKH;
	string HSD;
public:
	virtual bool KiemTraRutTien(TaiKhoan *tk, double tien) const = 0;

	string XemMaThe() const{
		return MaThe;
	}

	string XemMaNH() const {
		return MaNH;
	}

	string XemMaTKMacDinh() const{
		return MaTKMacDinh;
	}

	string XemTenKH() const{
		return TenKH;
	}

	string XemHSD() const{
		return HSD;
	}

	string MaTheRutGon() const{
		string res = MaThe;
		for (int i = 4; i < MaThe.length() - 5; ++i)
			res[i] = 'X';
		return res;
	}

	virtual bool KTMaThe(string MaTK) const = 0;
};

#endif