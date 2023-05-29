#include<bits/stdc++.h>
#include"personn.h"
using namespace std;
class KhachHang:public PerSonn{
	public:
		string loaiKhachHang;
		double  tichDiem, tienKhachHang;
	void input();
	void output();	
};
void KhachHang::input()
{
	PerSonn::input();
	cout<<" nhap tich diem : ";cin>>tichDiem;
	fflush(stdin);
	cout<<" nhap loai khach hang : ";
	getline(cin, loaiKhachHang);
	cout<<" nhap tien khach hang : ";cin>>tienKhachHang;
}
void KhachHang::output()
{
	PerSonn::output();
	cout<<" tich diem : "<<tichDiem<<endl;
	cout<<" loai khach hang : "<<loaiKhachHang<<endl;
	cout<<" tien khach hang : "<<tienKhachHang<<endl;
}

