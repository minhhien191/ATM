#include "ChuyenKhoan.h"

void ChuyenKhoan::ChuanBiThongTin(const void *atm, The *the, string pass, string MaTKLuaChon){
	MaATM = ((ATM*)atm)->XemMaATM();
	MaNHTT = the->XemMaNH();
	MaThe = the->XemMaThe();
	PIN = pass;
	MaTKTT = MaTKLuaChon;
	if (MaTKTT == "")
		MaTKTT = the->XemMaTKMacDinh();

	MaBenNhan = MaNHTT;
}

bool ChuyenKhoan::KTVBnet() const{
	set <NganHang*> DSNganHang = VBnet::LayDSNganHang();
	int cnt = 0;
	for (set <NganHang*>::iterator it = DSNganHang.begin(); it != DSNganHang.end(); ++it){
		if ((*it)->XemMaNH() == MaNHTT || (*it)->XemMaNH() == MaNHNT)
			++cnt;
		if (cnt == 2 || (MaNHTT == MaNHNT && cnt == 1))
			return true;
	}
	return false;
}

void ChuyenKhoan::NganHangXuLy(NganHang *bank){
	if (bank->XemMaNH() == MaNHTT){
		if (CoKetQua()){
			if (ThanhCong()){
				TaiKhoan *tk = bank->TimTaiKhoan(MaTKTT);
				CapNhatTK(tk, tk->XemSoDu() - SoTien);
			}
			HoanThanh = true;
			return;
		}

		if (bank->PassWord[MaThe] != PIN)
			CapNhatKQ("Sai ma pin");
		
		if (!CoKetQua() && !bank->KTThe_TaiKhoan(MaThe, MaTKTT))
			CapNhatKQ("Tai khoan trich tien khong khop voi the");

		if (!CoKetQua() && bank->TimTaiKhoan(MaTKTT)->XemSoDu() < SoTien)
			CapNhatKQ("So du tai khoan trich tien khong du de chuyen khoan");

		The *the = bank->TimThe(MaThe);
		TaiKhoan *tk = bank->TimTaiKhoan(MaTKTT);
		if (!the->KiemTraRutTien(tk, SoTien)){
			CapNhatKQ("Vut qua han muc");
			return;
		}
	}

	if (bank->XemMaNH() == MaNHNT){
		MaBenNhan = MaNHTT;
		TaiKhoan *tk = bank->TimTaiKhoan(MaTKNT);
		if (tk == NULL)
			CapNhatKQ("Tai khoan nhan tien khong ton tai");
		else{
			CapNhatKQ("Chuyen khoan thanh cong");
			CapNhatTK(tk, tk->XemSoDu() + SoTien);
		}
	}
	else
		MaBenNhan = MaNHNT;
}

bool ChuyenKhoan::ThanhCong() const{
	return KetQua == "Chuyen khoan thanh cong";
}

ChuyenKhoan::ChuyenKhoan(string MaNHNT, string MaTKNT, double SoTien, HoaDon hoadon) :
	GiaoDich(hoadon, "", false), SoTien(SoTien), MaNHNT(MaNHNT), MaTKNT(MaTKNT) {}

void ChuyenKhoan::InBienLai() const{
	cout << KetQua << endl;
	if (ThanhCong()){
		cout << "Bien lai rut tien" << endl;
		cout << "Ma tai khoan trich tien: " << MaTKTT << endl;
		cout << "Ma tai khoan nhan tien: " << MaTKNT << endl;
		cout << "So tien da chuyen khoan: " << SoTien << endl;
		NganHang *bank = VBnet::TimNganHang(MaNHTT);
		TaiKhoan *tk = bank->TimTaiKhoan(MaTKTT);
		The *the = bank->TimThe(MaThe);
		cout << "So du tai khoan trich tien truoc khi chuyen: " << tk->XemSoDu() + SoTien << endl;
		cout << "So du tai khoan trich tien sau khi chuyen: " << tk->XemSoDu() << endl;
		cout << "Thoi gian giao dich: " << endl;
		cout << "Ma so the: " << the->MaTheRutGon() << endl;
	}
}

void ChuyenKhoan::LichSuGiaoDich(){
	NganHang *bank = VBnet::TimNganHang(MaNHTT);
	TaiKhoan *tk = bank->TimTaiKhoan(MaTKTT);
	tk->ThemGiaoDich(this);

	bank = VBnet::TimNganHang(MaNHNT);
	tk = bank->TimTaiKhoan(MaTKNT);
	tk->ThemGiaoDich(this);
}

void ChuyenKhoan::XuatLichSu(TaiKhoan *tk) const{
	if (tk->XemMaTK() == MaTKTT){
		cout << "Ma so the: " << MaThe << endl;
		cout << "Ma PIN: " << PIN << endl;
		cout << "So tien can chuyen: " << SoTien << endl;
		cout << "Ma may ATM" << MaATM << endl;
		cout << "Ket qua: " << KetQua << endl;
	}
	else{
		cout << "Ma ngan hang trich tien: " << MaNHTT << endl;
		cout << "Ma tai khoan gui tien: " << MaTKTT << endl;
		cout << "So tien can nhan: " << SoTien << endl;
		cout << "Ket qua: " << KetQua << endl;
	}
}