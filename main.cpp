#include <iostream>
#include <vector>
#include "DaThuc.h"
using namespace std;
int main()
{
	DaThuc a;
	cout << "Nhap da thuc a: ";
	a.Nhap();
	a.Xuat();
	cout << endl;
	DaThuc b;
	cout << "Nhap da thuc b: ";
	b.Nhap();
	b.Xuat();
	cout << endl;
	DaThuc c = a + b;
	DaThuc d = a - b;
	DaThuc e = a * b;
	c.Xuat();
	cout << endl;
	d.Xuat();
	cout << endl;
	e.Xuat();
	cout << endl;
	a.DaoHam().Xuat();
	cout << endl;
	a.NguyenHam().Xuat();
	return 0;

}