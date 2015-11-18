#include <iostream>
#include "HeThongNganHang.h"
using namespace std;

int main(){
	set <ATM*> DSATM = VBnet::LayDSATM();
	ATM *atm = VBnet::TimATM("90121111111111111111");
	NganHang *Viecombank = VBnet::TimNganHang("VICBVNVX");
	NganHang *Xacombank = VBnet::TimNganHang("XACBVNVX");

	/*Sprint1*/
	
	cout << "Giao dich thanh cong noi mang tai may Pos tai Viecombank" << endl;
	Pos *pos = Viecombank->TimPos("90341111111111111111");
	The *the = Viecombank->TimThe("9438555555555555");
	GiaoDich *giaodichpos = new GiaoDichPos("Nguyen Van E", 50000, "Bun bo hue");
	pos->NhanThe(the, "555555", giaodichpos);
	cout << endl;

	cout << "Giao dich that bai noi mang tai may Pos Viecombank, sai ma PIN" << endl;
	giaodichpos = new GiaoDichPos("Nguyen Van E", 50000, "Ba lo");
	pos->NhanThe(the, "666666", giaodichpos);
	cout << endl;

	cout << "Giao dich that bai noi mang tai may Pos Viecombank, so du khong du" << endl;
	giaodichpos = new GiaoDichPos("Nguyen Van E", 50001, "Ba lo");
	pos->NhanThe(the, "555555", giaodichpos);
	cout << endl;

	/*Sprint2*/

	cout << "Giao dich thanh cong noi mang tai may Pos tai Xacombank" << endl;
	pos = Xacombank->TimPos("7832111111111111");
	the = Xacombank->TimThe("9012111111111111");
	giaodichpos = new GiaoDichPos("Nguyen Van 1", 20000, "Snack");
	pos->NhanThe(the, "111111", giaodichpos);
	cout << endl;

	cout << "Giao dich rut tien Viecombank thanh cong" << endl;
	the = Viecombank->TimThe("9438111111111111");
	GiaoDich *ruttien = new RutTien(10000, In);
	atm->NhanThe(the, "111111", "", ruttien);
	cout << endl;
	
	cout << "Giao dich rut tien Viecombank that bai, sai ma PIN" << endl;
	the = Viecombank->TimThe("9438222222222222");
	ruttien = new RutTien(100000, In);
	atm->NhanThe(the, "111111", "", ruttien);
	cout << endl;

	cout << "Giao dich rut tien Viecombank that bai, so du khong du de rut" << endl;
	ruttien = new RutTien(1000000, In);
	atm->NhanThe(the, "222222", "", ruttien);
	cout << endl;

	cout << "Giao dich nop tien Xacombank thanh cong" << endl;
	the = Xacombank->TimThe("9012111111111111");
	GiaoDich *noptien = new NopTien(1000, In);
	atm->NhanThe(the, "111111", "", noptien);
	cout << endl;

	cout << "Giao dich chuyen khoan noi mang thanh cong tai Viecombank" << endl;
	the = Viecombank->TimThe("9438444444444444");
	GiaoDich *chuyenkhoan = new ChuyenKhoan("VICBVNVX", "1789555555555555555", 2000, In);
	atm->NhanThe(the, "444444", "", chuyenkhoan);
	cout << endl;

	cout << "Giao dich chuyen khoan thanh cong tu Xacombank qua Viecombank" << endl;
	the = Xacombank->TimThe("9012111111111111");
	chuyenkhoan = new ChuyenKhoan("VICBVNVX", "1789111111111111111", 2000, In);
	atm->NhanThe(the, "111111", "162922222222", chuyenkhoan);
	cout << endl;

	cout << "Giao dich chuyen khoan that bai do ngan hang khong thuoc VBnet" << endl;
	the = Viecombank->TimThe("9438333333333333");
	chuyenkhoan = new ChuyenKhoan("AGCBVNVX", "162933333333", 10000, In);
	atm->NhanThe(the, "333333", "", chuyenkhoan);
	cout << endl;

	cout << "Giao dich chuyen khoan that bai do khong ton tai MaTKNT tu Viecombank qua Xacombank" << endl;
	the = Viecombank->TimThe("9438333333333333");
	chuyenkhoan = new ChuyenKhoan("XACBVNVX", "162944444444", 10000, In);
	atm->NhanThe(the, "333333", "", chuyenkhoan);
	cout << endl;

	/*Sprint3*/

	cout << "Giao dich thanh cong tai may Pos Xacombank voi the Viecombank" << endl;
	pos = Xacombank->TimPos("7832222222222222");
	the = Viecombank->TimThe("9438444444444444");
	giaodichpos = new GiaoDichPos("Nguyen Van D", 20000, "Mi goi");
	pos->NhanThe(the, "444444", giaodichpos);
	cout << endl;

	cout << "Giao dich that bai tai may Pos Viecombank voi the Xacombank, sai ma PIN" << endl;
	pos = Viecombank->TimPos("90341111111111111111");
	the = Xacombank->TimThe("9012111111111111");
	giaodichpos = new GiaoDichPos("Nguyen Van 1", 10000, "Xa phong");
	pos->NhanThe(the, "222222", giaodichpos);
	cout << endl;

	cout << "Giao dich that bai tai may Pos Xacombank voi the Viecombank, so du khong du" << endl;
	pos = Xacombank->TimPos("7832222222222222");
	the = Viecombank->TimThe("9438444444444444");
	giaodichpos = new GiaoDichPos("Nguyen Van D", 80001, "Sach vo");
	pos->NhanThe(the, "444444", giaodichpos);
	cout << endl;

	cout << "Giao dich rut tien thanh cong the phu cua Viecombank" << endl;
	the = Viecombank->TimThe("9439111111111111");
	ruttien = new RutTien(1000, In);
	atm->NhanThe(the, "666666", "", ruttien);
	cout << endl;

	cout << "Giao dich rut tien that bai the phu cua Viecombank, vuot han muc" << endl;
	the = Viecombank->TimThe("9439111111111111");
	ruttien = new RutTien(10000, In);
	atm->NhanThe(the, "666666", "", ruttien);
	cout << endl;

	return 0;
}