#include <iostream>
#include "DaThuc.h"
#include <vector>
using namespace std;
//Chuong trinh khai bao cac phuong thuc cua Da Thuc
DaThuc::DaThuc()
{
	iBacDaThuc = 0;
}
DaThuc::DaThuc(int x)
{
	iBacDaThuc = x;
	vector<double> b(x+1,0);
	dHeSo = b;
}
void DaThuc::Nhap()
{
	cin >> iBacDaThuc;
	vector<double> b(iBacDaThuc + 1);
	dHeSo = b;
	for (int i = iBacDaThuc; i >= 0; i--) {
		cin >> dHeSo[i];
	}
}
void DaThuc::Xuat()
{
	if (iBacDaThuc == 0) return;
	int minimum = 0;
	for (minimum = 0; minimum <= iBacDaThuc; minimum++) {
		if (dHeSo[minimum] != 0) break;
	}
	for (int i = iBacDaThuc; i >= minimum; i--) {
		if (i != minimum) {
			if (dHeSo[i] > 0) {
				cout << dHeSo[i] << "*x^" << i << " + ";
			}
			else {
				if (dHeSo[i] < 0)
					cout << "(" << dHeSo[i] << ")*x^" << i << " + ";
				else continue;
			}
		}
		else {
			if (minimum == 0) {
				if (dHeSo[i] > 0) {
					cout << dHeSo[i];
				}
				else {
					if (dHeSo[i] < 0)
						cout << "(" << dHeSo[i] << ")";
					else continue;
				}
			}
			else {
				if (dHeSo[i] > 0) {
					cout << dHeSo[i]<< "*x^"<<i;
				}
				else {
					if (dHeSo[i] < 0)
						cout << "(" << dHeSo[i] << ")*x^"<<i;
					else continue;
				}
			}
		}
	}
}
DaThuc DaThuc::operator+(const DaThuc& b)
{
	int m = max(iBacDaThuc, b.iBacDaThuc);
	int n = min(iBacDaThuc, b.iBacDaThuc);
	DaThuc c(m);
	int i;
	for (i = 0; i <= n; i++) {
		c.dHeSo[i] += dHeSo[i] + b.dHeSo[i];
	}
	if (b.iBacDaThuc > iBacDaThuc) {
		while (i <= m) {
			c.dHeSo[i] = b.dHeSo[i];
			i++;
		}
	}
	else {
		while (i <= m) {
			c.dHeSo[i] = dHeSo[i];
			i++;
		}
	}
	return c;
}
DaThuc DaThuc::operator-(const DaThuc& b)
{
	int m = max(iBacDaThuc, b.iBacDaThuc);
	int n = min(iBacDaThuc, b.iBacDaThuc);
	DaThuc c(m);
	int i;
	for (i = 0; i <=n; i++) {
		c.dHeSo[i] += dHeSo[i] - b.dHeSo[i];
	}
	if (b.iBacDaThuc > iBacDaThuc) {
		while (i <= m) {
			c.dHeSo[i] = b.dHeSo[i];
			i++;
		}
	}
	else {
		while (i <= m) {
			c.dHeSo[i] = dHeSo[i];
			i++;
		}
	}
	return c;
}
DaThuc DaThuc::operator*(const DaThuc& b)
{
	int m = iBacDaThuc * b.iBacDaThuc;
	DaThuc c(m);
	for (int i = 0; i <= iBacDaThuc; i++) {
		for (int j = 0; j <= b.iBacDaThuc; j++) {
			c.dHeSo[i + j] += dHeSo[i] * b.dHeSo[j];
		}
	}
	return c;
}
DaThuc DaThuc::DaoHam()
{
	DaThuc c(this->iBacDaThuc - 1);
	for (int i = this->iBacDaThuc; i >= 1; i--) {
		c.dHeSo[i - 1] += this->dHeSo[i] * i;
	}
	return c;
}
DaThuc DaThuc::NguyenHam()
{
	DaThuc c(this->iBacDaThuc + 1);
	for (int i = 0;i <= this->iBacDaThuc; i++) {
		c.dHeSo[i + 1] += dHeSo[i] / (i + 1);
	}
	return c;
}
