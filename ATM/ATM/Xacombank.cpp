#include "Xacombank.h"

/*NganHang*/

Xacombank Xacombank::init;

Xacombank::Xacombank(){
	DSTaiKhoan.clear();
	DSThe.clear();
	DSPos.clear();
	Link_The_TaiKhoan.clear();

	ifstream fi("DuLieu/Xacombank/TheThanhToan.csv");
	string input;
	while (getline(fi, input)){
		The *TheMoi = new TheThanhToan_Xacombank(input);
		DSThe.insert(TheMoi);
	}
	fi.close();

	fi.open("DuLieu/Viecombank/ThePhu.csv");
	while (getline(fi, input)){
		ThePhu_Xacombank *TheMoi = new ThePhu_Xacombank(input);
		DSThe.insert(TheMoi);
		Link_The_TaiKhoan.insert(pair <string, string>(TheMoi->XemMaThe(), TheMoi->XemMaTKMacDinh()));
	}
	fi.close();

	fi.open("DuLieu/Xacombank/TKTGTT.csv");
	while (getline(fi, input)){
		TaiKhoan *TKMoi = new TKTGTT_Xacombank(input);
		DSTaiKhoan.insert(TKMoi);
	}
	fi.close();

	fi.open("DuLieu/Xacombank/Link_The_TKTGTT.csv");
	while (getline(fi, input)){
		int pos = input.find(',');
		string MaThe = input.substr(0, pos);
		input.erase(0, pos + 1);
		string MaTKKH = input;
		Link_The_TaiKhoan.insert(pair <string, string>(MaThe, MaTKKH));
	}
	fi.close();

	fi.open("DuLieu/Xacombank/The_PIN.csv");
	while (getline(fi, input)){
		int pos = input.find(',');
		string MaThe = input.substr(0, pos);
		input.erase(0, pos + 1);
		string PIN = input;
		PassWord[MaThe] = PIN;
	}
	fi.close();

	fi.open("DuLieu/Xacombank/TKT.csv");
	while (getline(fi, input)){
		TaiKhoan *TKMoi = new TKT_Xacombank(input);
		DSTaiKhoan.insert(TKMoi);
	}
	fi.close();

	fi.open("DuLieu/Xacombank/Pos.csv");
	while (getline(fi, input)){
		Pos *PosMoi = new Pos_Xacombank(input);
		DSPos.insert(PosMoi);
	}
	fi.close();

	addSample(this);
}

string Xacombank::TenGiaoDich() const{
	return "Xacombank";
}

string Xacombank::XemMaNH() const{
	return "XACBVNVX";
}

double Xacombank::PhiPos() const{
	return 0.02;
}

/*TKTGTT*/

TKTGTT_Xacombank::TKTGTT_Xacombank(string input){
	int pos = input.find(',');
	MaTK = input.substr(0, pos);
	input.erase(0, pos + 1);

	pos = input.find(',');
	SoDu = atof(input.substr(0, pos).c_str());
	input.erase(0, pos + 1);

	pos = input.find(',');
	TenKH = input.substr(0, pos);
	input.erase(0, pos + 1);

	CMND = input;
}

string TKTGTT_Xacombank::XemMaNH() const{
	return "XACBVNVX";
}

bool TKTGTT_Xacombank::KTMaTK(string MaTK) const{
	return (MaTK.length() == 19 && MaTK.substr(0, 4) == "1789");
}

void TKTGTT_Xacombank::XuatThongTin() const{
	cout << "Ma so tai khoan khach hang: " << MaTK << endl;
	cout << "Ho ten khach hang: " << TenKH << endl;
	cout << "CMND: " << CMND << endl;
}

/*TKT*/

TKT_Xacombank::TKT_Xacombank(string input){
	int pos = input.find(',');
	MaTK = input.substr(0, pos);
	input.erase(0, pos + 1);

	pos = input.find(',');
	SoDu = atof(input.substr(0, pos).c_str());
	input.erase(0, pos + 1);

	pos = input.find(',');
	TenDN = input.substr(0, pos);
	input.erase(0, pos + 1);

	MaThue = input;
}

string TKT_Xacombank::XemMaNH() const{
	return "XACBVNVX";
}

bool TKT_Xacombank::KTMaTK(string MaTK) const{
	return (MaTK.length() == 19 && MaTK.substr(0, 4) == "1989");
}

void TKT_Xacombank::XuatThongTin() const{
	cout << "Ma so tai khoan doanh nghiep: " << MaTK << endl;
	cout << "Ten doanh nghiep: " << TenDN << endl;
	cout << "Ma so thue: " << MaThue << endl;
}

/*The*/

bool TheThanhToan_Xacombank::KiemTraRutTien(TaiKhoan *tk, double SoTien) const{
	return SoTien <= tk->XemSoDu();
}

TheThanhToan_Xacombank::TheThanhToan_Xacombank(string input){
	int pos = input.find(',');
	MaThe = input.substr(0, pos);
	input.erase(0, pos + 1);

	pos = input.find(',');
	MaNH = input.substr(0, pos);
	input.erase(0, pos + 1);

	pos = input.find(',');
	MaTKMacDinh = input.substr(0, pos);
	input.erase(0, pos + 1);

	pos = input.find(',');
	TenKH = input.substr(0, pos);
	input.erase(0, pos + 1);

	HSD = input;
}

bool TheThanhToan_Xacombank::KTMaThe(string MaTK) const{
	return (MaTK.length() == 16 && MaTK.substr(0, 4) == "9012");
}

bool ThePhu_Xacombank::KiemTraRutTien(TaiKhoan *tk, double SoTien) const{
	return SoTien <= min(tk->XemSoDu(), HanMuc);
}

ThePhu_Xacombank::ThePhu_Xacombank(string input){
	int pos = input.find(',');
	MaThe = input.substr(0, pos);
	input.erase(0, pos + 1);

	pos = input.find(',');
	HanMuc = atof(input.substr(0, pos).c_str());
	input.erase(0, pos + 1);

	pos = input.find(',');
	MaNH = input.substr(0, pos);
	input.erase(0, pos + 1);

	pos = input.find(',');
	MaTKMacDinh = input.substr(0, pos);
	input.erase(0, pos + 1);

	pos = input.find(',');
	TenKH = input.substr(0, pos);
	input.erase(0, pos + 1);

	HSD = input;
}

bool ThePhu_Xacombank::KTMaThe(string MaTK) const{
	return (MaTK.length() == 16 && MaTK.substr(0, 4) == "9015");
}

/*Pos*/

Pos_Xacombank::Pos_Xacombank(string input){
	int pos = input.find(',');
	MaPos = input.substr(0, pos);
	input.erase(0, pos + 1);

	MaTKDN = input;
}

string Pos_Xacombank::XemMaNH() const{
	return "XACBVNVX";
}

bool Pos_Xacombank::KTMaPos(string MaPos) const{
	return (MaPos.length() == 20 && MaPos.substr(0, 4) == "9034");
}

void Pos_Xacombank::NhanThe(The *the, string PIN, GiaoDich *giaodich) const{
	giaodich->ChuanBiThongTin(this, the, PIN, "");
	NganHang *bank = VBnet::TimNganHang("XACBVNVX");
	bank->NhanGiaoDich(giaodich);
	giaodich->InBienLai();
}