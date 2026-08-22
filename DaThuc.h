#include <iostream>
#include <vector>
using namespace std;
class DaThuc
{
private:
	int iBacDaThuc;
	vector<double> dHeSo;
public:
	DaThuc();
	DaThuc(int x);
	void Nhap();
	void Xuat();
	DaThuc operator+(const DaThuc& b);
	DaThuc operator-(const DaThuc& b);
	DaThuc operator*(const DaThuc& b);
	DaThuc DaoHam();
	DaThuc NguyenHam();
};