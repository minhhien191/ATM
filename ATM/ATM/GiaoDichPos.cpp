#include "GiaoDichPos.h"

void GiaoDichPos::ChuanBiThongTin(const void *pos, The *the, string pass, string TenKH){
	MaPos = ((Pos*)pos)->XemMaPos();
	MaNHNT = ((Pos*)pos)->XemMaNH();
	MaThe = the->XemMaThe();
	PIN = pass;
	HSD = the->XemHSD();
	MaNHTT = the->XemMaNH();

	MaBenNhan = MaNHNT;
}

bool GiaoDichPos::KTVBnet() const{
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

void GiaoDichPos::NganHangXuLy(NganHang *bank){
	if (bank->XemMaNH() != MaNHTT || CoKetQua()){
		if (CoKetQua()){
			HoanThanh = true;

			if (ThanhCong()){
				Pos *pos = bank->TimPos(MaPos);
				string MaTKDN = pos->XemMaTKDN();
				TaiKhoan *tkdn = bank->TimTaiKhoan(MaTKDN);
				CapNhatTK(tkdn, tkdn->XemSoDu() + (1 - bank->PhiPos()) * SoTien);
			}

			return;
		}

		MaBenNhan = MaNHTT;
		VBnet::NhanGiaoDich(this);
	}
	else{
		MaBenNhan = MaNHNT;
		if (!CoKetQua() && bank->PassWord[MaThe] != PIN)
			CapNhatKQ("Sai ma pin");

		The *the = bank->TimThe(MaThe);
		string MaTKKH = the->XemMaTKMacDinh();
		TaiKhoan *tkkh = bank->TimTaiKhoan(MaTKKH);

		if (!CoKetQua() && the->XemTenKH() != TenKH)
			CapNhatKQ("The khong khop voi ten khach hang");

		if (!CoKetQua() && tkkh->XemSoDu() < SoTien)
			CapNhatKQ("So du khong du");

		if (!CoKetQua()){
			CapNhatTK(tkkh, tkkh->XemSoDu() - SoTien);
			CapNhatKQ("Giao dich may Pos thanh cong");
		}

		VBnet::NhanGiaoDich(this);
	}
}

bool GiaoDichPos::ThanhCong() const{
	return KetQua == "Giao dich may Pos thanh cong";
}

GiaoDichPos::GiaoDichPos(string TenKH, double SoTien, string MoTa) :
	GiaoDich(In, "", false), TenKH(TenKH), SoTien(SoTien), MoTa(MoTa) {}

void GiaoDichPos::InBienLai() const{
	cout << KetQua << endl;
	if (ThanhCong()){
		cout << "Bien lai rut tien" << endl;
		cout << "So tien giao dich: " << SoTien << endl;
		cout << "Mo ta: " << MoTa << endl;
		cout << "Ma may Pos: " << MaPos << endl;
		NganHang *bank = VBnet::TimNganHang(MaNHNT);
		Pos *pos = bank->TimPos(MaPos);
		TaiKhoan *tkdn = bank->TimTaiKhoan(pos->XemMaTKDN());
		tkdn->XuatThongTin();
		bank = VBnet::TimNganHang(MaNHTT);
		The *the = bank->TimThe(MaThe);
		cout << "Ma so the: " << the->MaTheRutGon() << endl;
	}
}

void GiaoDichPos::LichSuGiaoDich(){
	NganHang *bank = VBnet::TimNganHang(MaNHTT);
	The *the = bank->TimThe(MaThe);
	TaiKhoan *tk = bank->TimTaiKhoan(the->XemMaTKMacDinh());
	tk->ThemGiaoDich(this);

	bank = VBnet::TimNganHang(MaNHNT);
	Pos *pos = bank->TimPos(MaPos);
	tk = bank->TimTaiKhoan(pos->XemMaTKDN());
	tk->ThemGiaoDich(this);

}

void GiaoDichPos::XuatLichSu(TaiKhoan *tk) const{
	string MaTKTT = VBnet::TimNganHang(MaNHTT)->TimThe(MaThe)->XemMaTKMacDinh();
	string MaTKNT = VBnet::TimNganHang(MaNHNT)->TimPos(MaPos)->XemMaTKDN();

	if (tk->XemMaTK() == MaTKTT){
		cout << "Ma so the: " << MaThe << endl;
		cout << "So tien can chuyen: " << SoTien << endl;
		cout << "Ma ngan hang nhan tien: " << MaNHNT << endl;
		cout << "Ma tai khoan nhan tien: " << MaTKNT << endl;
		cout << "Ket qua: " << KetQua << endl;
	}
	else{
		cout << "Ma ngan hang trich tien: " << MaNHTT << endl;
		cout << "Ma so the: " << VBnet::TimNganHang(MaNHTT)->TimThe(MaThe)->MaTheRutGon() << endl;
		cout << "Ho ten khach hang " << VBnet::TimNganHang(MaNHTT)->TimThe(MaThe)->XemTenKH() << endl;
		cout << "So tien can nhan: " << SoTien << endl;
		cout << "Ket qua: " << KetQua << endl;
	}
}