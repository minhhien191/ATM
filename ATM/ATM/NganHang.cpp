#include "NganHang.h"

/*VBnet*/

set <NganHang*> VBnet::DSNganHang;
set <ATM*> VBnet::DSATM;
set <GiaoDich*> VBnet::DSGiaoDich;
VBnet VBnet::init;

VBnet::VBnet(){
	DSATM.clear();
	DSNganHang.clear();
	DSGiaoDich.clear();

	ifstream fi("DuLieu/ATM.csv");
	string input;
	while (getline(fi, input)){
		ATM *ATMMoi = new ATM_VBnet(input);
		DSATM.insert(ATMMoi);
	}
}

VBnet::~VBnet(){
	for (set <ATM*>::iterator it = DSATM.begin(); it != DSATM.end(); ++it)
		delete (*it);
	for (set <GiaoDich*>::iterator it = DSGiaoDich.begin(); it != DSGiaoDich.end(); ++it)
		delete (*it);
}

set <NganHang*> VBnet::LayDSNganHang(){
	return DSNganHang;
}

set <ATM*> VBnet::LayDSATM(){
	return DSATM;
}

NganHang *VBnet::TimNganHang(string MaNH){
	for (set <NganHang*>::iterator it = DSNganHang.begin(); it != DSNganHang.end(); ++it)
	if ((*it)->XemMaNH() == MaNH)
		return (*it);
	return NULL;
}

ATM *VBnet::TimATM(string MaATM){
	for (set <ATM*>::iterator it = DSATM.begin(); it != DSATM.end(); ++it)
	if ((*it)->XemMaATM() == MaATM)
		return (*it);
	return NULL;
}

void VBnet::NhanGiaoDich(GiaoDich *giaodich){
	if (giaodich->KTVBnet()){
		NganHang *bank;
		while (!giaodich->HoanThanh){
			bank = TimNganHang(giaodich->MaBenNhan);
			bank->NhanGiaoDich(giaodich);
		}
	}
	else
		giaodich->CapNhatKQ("Ngan hang khong thuoc he thong VBnet");
	VBnet::DSGiaoDich.insert(giaodich);
	if (giaodich->ThanhCong())
		giaodich->LichSuGiaoDich();
}

/*NganHang*/

TaiKhoan *NganHang::TimTaiKhoan(string MaTK){
	for (set <TaiKhoan*>::iterator it = DSTaiKhoan.begin(); it != DSTaiKhoan.end(); ++it)
	if ((*it)->XemMaTK() == MaTK)
		return (*it);
	return NULL;
}

The *NganHang::TimThe(string MaThe){
	for (set <The*>::iterator it = DSThe.begin(); it != DSThe.end(); ++it)
	if ((*it)->XemMaThe() == MaThe)
		return (*it);
	return NULL;
}

Pos *NganHang::TimPos(string MaPos){
	for (set <Pos*>::iterator it = DSPos.begin(); it != DSPos.end(); ++it)
	if ((*it)->XemMaPos() == MaPos)
		return (*it);
	return NULL;
}

bool NganHang::KTThe_TaiKhoan(string MaThe, string MaTK){
	return Link_The_TaiKhoan.find(pair <string, string>(MaThe, MaTK)) != Link_The_TaiKhoan.end();
}

void NganHang::addSample(NganHang *add){
	VBnet::DSNganHang.insert(add);
}

void NganHang::NhanGiaoDich(GiaoDich *giaodich){
	giaodich->NganHangXuLy(this);
}

NganHang::~NganHang(){
	for (set <TaiKhoan*>::iterator it = DSTaiKhoan.begin(); it != DSTaiKhoan.end(); ++it)
		delete (*it);
	for (set <The*>::iterator it = DSThe.begin(); it != DSThe.end(); ++it)
		delete (*it);
	for (set <Pos*>::iterator it = DSPos.begin(); it != DSPos.end(); ++it)
		delete (*it);
}

/*ATM_VBnet*/

ATM_VBnet::ATM_VBnet(string input){
	int pos = input.find(',');
	MaATM = input.substr(0, pos);
	input.erase(0, pos + 1);

	pos = input.find(',');
	SoDu = atof(input.substr(0, pos).c_str());
	input.erase(0, pos + 1);

	DiaChi = input;
}

string ATM_VBnet::XemMaATM() const{
	return MaATM;
}

bool ATM_VBnet::KTMaATM(string MaATM) const{
	return (MaATM.length() == 20 && MaATM.substr(0, 4) == "9012");
}

void ATM_VBnet::NhanThe(The *the, string PIN, string MaTKLuaChon, GiaoDich *giaodich) const{
	giaodich->ChuanBiThongTin(this, the, PIN, MaTKLuaChon);
	VBnet::NhanGiaoDich(giaodich);
	if (giaodich->InHoaDon == In)
		giaodich->InBienLai();
}