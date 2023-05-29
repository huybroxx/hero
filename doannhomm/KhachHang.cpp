#include"KhachHang.h"
#include<bits/stdc++.h>
using namespace std;
void KhachHang::input()
{
	PerSon::input();
	cout<<" nhap tich diem : ";cin>>tichDiem;
	fflush(stdin);
	cout<<" nhap loai khach hang : ";
	getline(cin, loaiKhachHang);
	cout<<" nhap tien khach hang : ";cin>>tienKhachHang;
}
void KhachHang::output()
{
	PerSon::output();
	cout<<" tich diem : "<<tichDiem<<endl;
	cout<<" loai khach hang : "<<loaiKhachHang<<endl;
	cout<<" tien khach hang : "<<tienKhachHang<<endl;
}
