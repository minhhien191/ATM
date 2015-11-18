#include "NopTien.h"

void NopTien::ChuanBiThongTin(const void *atm, The *the, string pass, string MaTKLuaChon){
	MaATM = ((ATM*)atm)->XemMaATM();
	MaNH = the->XemMaNH();
	MaThe = the->XemMaThe();
	PIN = pass;
	MaTK = MaTKLuaChon;
	if (MaTK == "")
		MaTK = the->XemMaTKMacDinh();

	MaBenNhan = MaNH;
}

bool NopTien::KTVBnet() const{
	set <NganHang*> DSNganHang = VBnet::LayDSNganHang();
	for (set <NganHang*>::iterator it = DSNganHang.begin(); it != DSNganHang.end(); ++it)
	if ((*it)->XemMaNH() == MaNH)
		return true;
	return false;
}

void NopTien::NganHangXuLy(NganHang *bank){
	HoanThanh = true;
	if (bank->PassWord[MaThe] != PIN){
		CapNhatKQ("Sai ma pin");
		return;
	}

	if (!bank->KTThe_TaiKhoan(MaThe, MaTK)){
		CapNhatKQ("Tai khoan khong khop voi the");
		return;
	}

	TaiKhoan *tk = bank->TimTaiKhoan(MaTK);
	CapNhatTK(tk, tk->XemSoDu() + SoTien);
	CapNhatKQ("Nop tien thanh cong");
}

bool NopTien::ThanhCong() const{
	return KetQua == "Nop tien thanh cong";
}

NopTien::NopTien(double SoTien, HoaDon hoadon) : GiaoDich(hoadon, "", false), SoTien(SoTien) {}

void NopTien::InBienLai() const{
	cout << KetQua << endl;
	if (ThanhCong()){
		NganHang *bank = VBnet::TimNganHang(MaNH);
		cout << "Bien lai nop tien" << endl;
		cout << "So tien da nop: " << SoTien << endl;
		TaiKhoan *tk = bank->TimTaiKhoan(MaTK);
		The *the = bank->TimThe(MaThe);
		cout << "So du truoc khi nop: " << tk->XemSoDu() - SoTien << endl;
		cout << "So du sau khi nop: " << tk->XemSoDu() << endl;
		cout << "Thoi gian giao dich: " << endl;
		cout << "Ma so the: " << the->MaTheRutGon() << endl;
	}	
}

void NopTien::LichSuGiaoDich(){
	NganHang *bank = VBnet::TimNganHang(MaNH);
	TaiKhoan *tk = bank->TimTaiKhoan(MaTK);
	tk->ThemGiaoDich(this);
}

void NopTien::XuatLichSu(TaiKhoan *tk) const{
	cout << "Ma so the: " << MaThe << endl;
	cout << "Ma PIN: " << PIN << endl;
	cout << "So tien nop: " << SoTien << endl;
	cout << "Ma may ATM: " << MaATM << endl;
	cout << "Ket qua: " << KetQua << endl;
}