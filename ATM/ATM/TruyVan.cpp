#include "TruyVan.h"

void TruyVan::ChuanBiThongTin(const void *atm, The *the, string pass, string MaTKLuaChon){
	MaATM = ((ATM*)atm)->XemMaATM();
	MaNH = the->XemMaNH();
	MaThe = the->XemMaThe();
	PIN = pass;
	MaTK = MaTKLuaChon;
	if (MaTK == "")
		MaTK = the->XemMaTKMacDinh();

	MaBenNhan = MaNH;
}

bool TruyVan::KTVBnet() const{
	set <NganHang*> DSNganHang = VBnet::LayDSNganHang();
	for (set <NganHang*>::iterator it = DSNganHang.begin(); it != DSNganHang.end(); ++it)
	if ((*it)->XemMaNH() == MaNH)
		return true;
	return false;
}

void TruyVan::NganHangXuLy(NganHang *bank){
	HoanThanh = true;
	if (bank->PassWord[MaThe] != PIN){
		CapNhatKQ("Sai ma pin");
		return;
	}

	The *the = bank->TimThe(MaThe);
	if (MaTK == "")
		MaTK = the->XemMaTKMacDinh();
	else
	if (!bank->KTThe_TaiKhoan(MaThe, MaTK)){
		CapNhatKQ("Tai khoan khong khop voi the");
		return;
	}

	CapNhatKQ("Truy van thanh cong");
}

bool TruyVan::ThanhCong() const{
	return KetQua == "Truy van thanh cong";
}

TruyVan::TruyVan() : GiaoDich(In, "", false) {}

void TruyVan::InBienLai() const{

}

void TruyVan::LichSuGiaoDich(){
	NganHang *bank = VBnet::TimNganHang(MaNH);
	TaiKhoan *tk = bank->TimTaiKhoan(MaTK);
	tk->ThemGiaoDich(this);
}

void TruyVan::XuatLichSu(TaiKhoan *tk) const{
	cout << "Ma so tai khoan: " << MaTK << endl;
	cout << "Thoi gian giao dich: " << endl;
	cout << "Ma so the: " << VBnet::TimNganHang(MaNH)->TimThe(MaThe)->MaTheRutGon() << endl;
	cout << "Ma PIN: " << PIN << endl;
	cout << "Ma may ATM: " << MaATM << endl;
	cout << "Ket qua: " << KetQua << endl;
}