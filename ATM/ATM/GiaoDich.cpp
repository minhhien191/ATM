#include "GiaoDich.h"
#include <stdlib.h>

GiaoDich::GiaoDich(HoaDon hoadon, string ketqua, bool hoanthanh) :
	InHoaDon(hoadon), KetQua(ketqua), HoanThanh(hoanthanh) {}

void GiaoDich::CapNhatTK(TaiKhoan *tk, double SoTien){
	tk->CapNhatSoTien(SoTien);
}

void GiaoDich::CapNhatKQ(string KQ){
	KetQua = KQ;
}

string Now(){
	char buf[10];
	return "";
}

int TimThang(string Date){
	return atoi(Date.substr(0, Date.find('/')).c_str());
}

int TimNam(string Date){
	Date.erase(Date.find('/') + 1);
	return atoi(Date.c_str());
}

bool KiemTraHSD(string Now, string HSD){
	if (TimNam(Now) != TimNam(HSD))
		return TimNam(Now) < TimNam(HSD);
	return TimThang(Now) <= TimThang(HSD);
}