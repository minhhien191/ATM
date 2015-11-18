#include <string>
#include "The.h"
#include "GiaoDich.h"
using namespace std;

class Pos{
protected:
	string MaPos;
	string MaTKDN;
public:
	string XemMaPos() const{
		return MaPos;
	}
	string XemMaTKDN() const{
		return MaTKDN;
	}
	virtual string XemMaNH() const = 0;
	virtual bool KTMaPos(string MaPos) const = 0;
	virtual void NhanThe(The *the, string PIN, GiaoDich *giaodich) const = 0;
};