#include <string>
#include "The.h"
#include "GiaoDich.h"
using namespace std;

class VBnet;

class ATM{
protected:
	string MaATM;
	string DiaChi;
	double SoDu;
public:
	virtual string XemMaATM() const = 0;
	virtual bool KTMaATM(string input) const = 0;
	virtual void NhanThe(The *the, string PIN, string MaTKLuaChon, GiaoDich *giaodich) const = 0;
};