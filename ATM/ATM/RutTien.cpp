#include "RutTien.h"

void RutTien::ChuanBiThongTin(const void *atm, The *the, string pass, string MaTKLuaChon){
	MaATM = ((ATM*)atm)->XemMaATM();
	MaNH = the->XemMaNH();
	MaThe = the->XemMaThe();
	PIN = pass;
	MaTK = MaTKLuaChon;
	if (MaTK == "")
		MaTK = the->XemMaTKMacDinh();

	MaBenNhan = MaNH;
}

bool RutTien::KTVBnet() const{
	set <NganHang*> DSNganHang = VBnet::LayDSNganHang();
	for (set <NganHang*>::iterator it = DSNganHang.begin(); it != DSNganHang.end(); ++it)
	if ((*it)->XemMaNH() == MaNH)
		return true;
	return false;
}

void RutTien::NganHangXuLy(NganHang *bank){
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
	if (tk->XemSoDu() < SoTien){
		CapNhatKQ("So du khong du de rut");
		return;
	}

	The *the = bank->TimThe(MaThe);
	if (!the->KiemTraRutTien(tk, SoTien)){
		CapNhatKQ("Vut qua han muc");
		return;
	}

	CapNhatTK(tk, tk->XemSoDu() - SoTien);
	CapNhatKQ("Rut tien thanh cong");
}

bool RutTien::ThanhCong() const{
	return KetQua == "Rut tien thanh cong";
}

RutTien::RutTien(double SoTien, HoaDon hoadon) : GiaoDich(hoadon, "", false), SoTien(SoTien) {}

void RutTien::InBienLai() const{
	cout << KetQua << endl;
	if (ThanhCong()){
		NganHang *bank = VBnet::TimNganHang(MaNH);
		cout << "Bien lai rut tien" << endl;
		cout << "So tien da rut: " << SoTien << endl;
		TaiKhoan *tk = bank->TimTaiKhoan(MaTK);
		The *the = bank->TimThe(MaThe);
		cout << "So du truoc khi rut: " << tk->XemSoDu() + SoTien << endl;
		cout << "So du sau khi rut: " << tk->XemSoDu() << endl;
		cout << "Thoi gian giao dich: " << endl;
		cout << "Ma so the: " << the->MaTheRutGon() << endl;
	}
}

void RutTien::LichSuGiaoDich(){
	NganHang *bank = VBnet::TimNganHang(MaNH);
	TaiKhoan *tk = bank->TimTaiKhoan(MaTK);
	tk->ThemGiaoDich(this);
}

void RutTien::XuatLichSu(TaiKhoan *tk) const{
	cout << "Ma so the: " << MaThe << endl;
	cout << "Ma PIN: " << PIN << endl;
	cout << "So tien rut: " << SoTien << endl;
	cout << "Ma may ATM: " << MaATM << endl;
	cout << "Ket qua: " << KetQua << endl;
}