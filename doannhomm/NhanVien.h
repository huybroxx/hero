#include<bits/stdc++.h>
#include "person.cpp"
using namespace std;
class NhanVien:public PerSon{
	public:
		string xepLoai, lichLamViec;
		double luongChuaThuong, luongCoThuong;
		int stk;
	void input();
	void output();
	double tinhLuong();
};
void NhanVien::input()
{
	PerSon::input();
	fflush(stdin);
	cout<<" nhap xep loai : ";
	getline(cin, xepLoai);
	fflush(stdin);
	cout<<" nhap lich lam viec : ";
	getline(cin, lichLamViec);
	cout<<" nhap luong chua thuong : ";cin>>luongChuaThuong;
	cout<<" nhap luong co thuong : ";cin>>luongCoThuong;
}
void NhanVien::output()
{
	PerSon::output();
	cout<<" xep loai : "<<xepLoai<<endl;
	cout<<" lich lam viec : "<<lichLamViec<<endl;
	cout<<" luong chua thuong : "<<luongChuaThuong<<endl;
	cout<<" luong co thuong : "<<luongCoThuong<<endl;
}
double NhanVien::tinhLuong()
{
	double Tong=0;
	if(luongChuaThuong>5)
	{
		luongChuaThuong=10000;
		Tong = luongChuaThuong+luongCoThuong;
		cout<<" tong luong nhan vien : "<<Tong<<endl;
	}
	else 
	{
		luongChuaThuong=5000;
		Tong = luongChuaThuong+luongCoThuong;
		cout<<" tong luong nhan vien : "<<Tong<<endl;
	}
}
