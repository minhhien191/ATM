#include "Viecombank.h"

/*NganHang*/

Viecombank Viecombank::init;

Viecombank::Viecombank(){
	DSTaiKhoan.clear();
	DSThe.clear();
	DSPos.clear();
	Link_The_TaiKhoan.clear();

	ifstream fi("DuLieu/Viecombank/TheThanhToan.csv");
	string input;
	while (getline(fi, input)){
		The *TheMoi = new TheThanhToan_Viecombank(input);
		DSThe.insert(TheMoi);
		Link_The_TaiKhoan.insert(pair <string, string>(TheMoi->XemMaThe(), TheMoi->XemMaTKMacDinh()));
	}
	fi.close();

	fi.open("DuLieu/Viecombank/ThePhu.csv");
	while (getline(fi, input)){
		ThePhu_Viecombank *TheMoi = new ThePhu_Viecombank(input);
		DSThe.insert(TheMoi);
		Link_The_TaiKhoan.insert(pair <string, string>(TheMoi->XemMaThe(), TheMoi->XemMaTKMacDinh()));
	}
	fi.close();

	fi.open("DuLieu/Viecombank/TKTGTT.csv");
	while (getline(fi, input)){
		TaiKhoan *TKMoi = new TKTGTT_Viecombank(input);
		DSTaiKhoan.insert(TKMoi);
	}
	fi.close();

	fi.open("DuLieu/Viecombank/The_PIN.csv");
	while (getline(fi, input)){
		int pos = input.find(',');
		string MaThe = input.substr(0, pos);
		input.erase(0, pos + 1);
		string PIN = input;
		PassWord[MaThe] = PIN;
	}
	fi.close();

	fi.open("DuLieu/Viecombank/TKT.csv");
	while (getline(fi, input)){
		TaiKhoan *TKMoi = new TKT_Viecombank(input);
		DSTaiKhoan.insert(TKMoi);
	}
	fi.close();

	fi.open("DuLieu/Viecombank/Pos.csv");
	while (getline(fi, input)){
		Pos *PosMoi = new Pos_Viecombank(input);
		DSPos.insert(PosMoi);
	}
	fi.close();

	addSample(this);
}

string Viecombank::TenGiaoDich() const{
	return "Viecombank";
}

string Viecombank::XemMaNH() const{
	return "VICBVNVX";
}

double Viecombank::PhiPos() const{
	return 0.03;
}

/*TKTGTT*/

TKTGTT_Viecombank::TKTGTT_Viecombank(string input){
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

string TKTGTT_Viecombank::XemMaNH() const{
	return "VICBVNVX";
}

bool TKTGTT_Viecombank::KTMaTK(string MaTK) const{
	return (MaTK.length() == 19 && MaTK.substr(0, 4) == "1789");
}

void TKTGTT_Viecombank::XuatThongTin() const{
	cout << "Ma so tai khoan khach hang: " << MaTK << endl;
	cout << "Ho ten khach hang: " << TenKH << endl;
	cout << "CMND: " << CMND << endl;
}

/*TKT*/

TKT_Viecombank::TKT_Viecombank(string input){
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

string TKT_Viecombank::XemMaNH() const{
	return "VICBVNVX";
}

bool TKT_Viecombank::KTMaTK(string MaTK) const{
	return (MaTK.length() == 19 && MaTK.substr(0, 4) == "1989");
}

void TKT_Viecombank::XuatThongTin() const{
	cout << "Ma so tai khoan doanh nghiep: " << MaTK << endl;
	cout << "Ten doanh nghiep: " << TenDN << endl;
	cout << "Ma so thue: " << MaThue << endl;
}

/*The*/

bool TheThanhToan_Viecombank::KiemTraRutTien(TaiKhoan *tk, double SoTien) const{
	return SoTien <= tk->XemSoDu();
}

TheThanhToan_Viecombank::TheThanhToan_Viecombank(string input){
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

bool TheThanhToan_Viecombank::KTMaThe(string MaTK) const{
	return (MaTK.length() == 16 && MaTK.substr(0, 4) == "9438");
}

bool ThePhu_Viecombank::KiemTraRutTien(TaiKhoan *tk, double SoTien) const{
	return SoTien <= min(tk->XemSoDu(), HanMuc);
}

ThePhu_Viecombank::ThePhu_Viecombank(string input){
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

bool ThePhu_Viecombank::KTMaThe(string MaTK) const{
	return (MaTK.length() == 16 && MaTK.substr(0, 4) == "9439");
}

/*Pos*/

Pos_Viecombank::Pos_Viecombank(string input){
	int pos = input.find(',');
	MaPos = input.substr(0, pos);
	input.erase(0, pos + 1);

	MaTKDN = input;
}

string Pos_Viecombank::XemMaNH() const{
	return "VICBVNVX";
}

bool Pos_Viecombank::KTMaPos(string MaPos) const{
	return (MaPos.length() == 20 && MaPos.substr(0, 4) == "9034");
}

void Pos_Viecombank::NhanThe(The *the, string PIN, GiaoDich *giaodich) const{
	giaodich->ChuanBiThongTin(this, the, PIN, "");
	NganHang *bank = VBnet::TimNganHang("VICBVNVX");
	bank->NhanGiaoDich(giaodich);
	giaodich->InBienLai();
}