#ifndef _NganHang
#define _NganHang

#include <algorithm>
#include <map>
#include <fstream>
#include <utility>
#include "Pos.h"
#include "ATM.h"
#include "GiaoDich.h"
using namespace std;

class ATM_VBnet;

class VBnet{
private:
	static set <NganHang*> DSNganHang;
	static set <ATM*> DSATM;
	static set <GiaoDich*> DSGiaoDich;
	
	VBnet();
	static VBnet init;
	~VBnet();
public:
	static set <NganHang*> LayDSNganHang();
	static set <ATM*> LayDSATM();

	static NganHang *TimNganHang(string MaNH);
	static ATM *TimATM(string MaATM);
	static void NhanGiaoDich(GiaoDich *giaodich);

	friend class NganHang;
};

class NganHang{
protected:
	set <TaiKhoan*> DSTaiKhoan;
	set <The*> DSThe;
	set <Pos*> DSPos;
	map <string, string> PassWord;
	set <pair <string, string> > Link_The_TaiKhoan;
public:
	TaiKhoan *TimTaiKhoan(string MaTK);
	The *TimThe(string MaThe);
	Pos *TimPos(string MaPos);
	bool KTThe_TaiKhoan(string MaThe, string MaTK);
	void NhanGiaoDich(GiaoDich *giaodich);

	virtual string TenGiaoDich() const = 0;
	virtual string XemMaNH() const = 0;
	virtual double PhiPos() const = 0;
	virtual ~NganHang();

	friend class VBnet;
	friend class GiaoDich;
	friend class GiaoDichPos;
	friend class RutTien;
	friend class NopTien;
	friend class TruyVan;
	friend class ChuyenKhoan;
protected:
	void addSample(NganHang *add);
};

class ATM_VBnet : public ATM{
public:
	ATM_VBnet(string input);
	string XemMaATM() const;
	bool KTMaATM(string input) const;
	void NhanThe(The *the, string PIN, string MaTKLuaChon, GiaoDich *giaodich) const;
};

#endif