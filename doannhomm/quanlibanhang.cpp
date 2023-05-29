#include<bits/stdc++.h>
#include "quanlibanhang.h"
using namespace std;
int main()
{
	//==================================================================================================================
   	ListKhachHang dskh;
	KhachHang kh1("Nguyen vy", 2004, "00011642", "0505","Da Nang", "VIP", 5000, 0 );
	KhachHang BOSS("Ngo Ngoc Huy", 2004, "0359811642", "Admin", "Quang Nam", "VIP Pro (tai khoan Admin)", 9999, 9999);
	dskh.themKhachhang(BOSS);
	dskh.themKhachhang(kh1);
	ListHoaDon dshoadon;
	//system("color f5" );
	//==================================================================================================================
	ListNuocUong ListNuocUong;
	NuocUong nuoc1("Tra da", 15000, 50, CongThuc{"Tra", 10,100});
   	NuocUong nuoc2("Nuoc cam", 20000, 30, CongThuc{"Cam", 60, 60});
   	NuocUong nuoc3("Soda chanh", 18000, 40, CongThuc{" Soda+Chanh", 15, 120});
   	NuocUong nuoc4("Nuoc dua", 25000, 20, CongThuc{"Dua", 150, 0});
	ListNuocUong.themNuocUong(nuoc1);
  	ListNuocUong.themNuocUong(nuoc2);
   	ListNuocUong.themNuocUong(nuoc3);
   	ListNuocUong.themNuocUong(nuoc4);
   	int temp;
   	do{
   	cout << "\t\2***MENU CHUC NANG***\2\n";
   	cout << "1. Quan li nuoc uong\n";
   	cout << "2. Quan li khach hang\n";
   	cout << "3. Quan li nhan vien\n";
   	cout << "4. Quan li hoa don\n";
   	cout << "0. Thoat chuong trinh\n";
   	cout << "Nhap lua chon cua ban: ";
   	cin >> temp;
   	amthanh();
   	system("cls");   	
   	switch(temp){
   		case 1: {
   				//===================================================================================================================
		int choice;
		do {
        	cout << "\t\2***QUAN LY NUOC UONG***\2\n";
        	cout << "1. Them nuoc uong\n";
        	cout << "2. Them so luong nuoc uong trong kho\n";
        	cout << "3. Xoa nuoc uong\n";
        	cout << "4. Hien thi danh sach nuoc uong trong kho\n";
        	cout << "0. Quay ve menu quan ly  ( <-- )\n";
        	cout << "Nhap lua chon cua ban: ";
        	cin >> choice;
        	amthanh();
        	system("cls");
			switch (choice) 
			{
            case 1: {
            		NuocUong a;
            		cout<<"\n***THEM NUOC UONG***	\n";
            		a.input();
            		ListNuocUong.themNuocUong(a);
            		cout<<"\nDa them nuoc uong "<<a.name<<" vao kho! \n";
            		system("pause");
            		system("cls");
            		break;
            	}
            	case 2: {
            		cout<<"\n***THEM SO LUONG NUOC UONG VAO KHO***\n";
            		ListNuocUong.themSLnuocuong();
            		system("pause");
            		system("cls");
					break;
				}
				case 3: {
					cout<<"\n***XOA NUOC UONG TRONG KHO***\n";
					ListNuocUong.xoanuocuongtrongkho();
					system("pause");
            		system("cls");
					break;
				}
				case 4: {
					cout<<"\n\t\t***DANH SACH NUOC UONG TRONG KHO\2***\n";
					ListNuocUong.hienThiDanhSachNuocUong();
					system("pause");
            		system("cls");
					break;
				}
				case 0: {
                	cout << "\nThoat chuong trinh.\n";
                	break;
            	}
            	default: {
                	cout << "\nLua chon khong hop le. Vui long nhap lai.\n";
                	break;
            	}
       			}
    			} while (choice != 0);
   	//==================================================================================================================
			break;
		   }
		   case 4: {
		   	int choice2;
			do {
        	cout << "\t\2***QUAN LY Hoa Don***\2\n";
        	cout << "1. Tao hoa don moi (mua hang)^^\n";
        	cout << "2. In hoa don\n";
        	cout << "3. Xoa tat ca hoa don\n";
       		cout << "4. Xoa hoa don duoc chon\n";
        	cout << "5. Hien thi danh sach hoa don\n";
        	cout << "6. In tong doanh thu\n";
        	cout << "0. Quay ve menu quan ly  ( <-- )\n";
        	cout << "Nhap lua chon cua ban: ";
      	  	cin >> choice2;
      	  	amthanh();
      		system("cls");
			switch (choice2) 
			{
            	case 1: {
            		KhachHang kh;
            		HoaDon a(dskh,kh,ListNuocUong);
            		cout<<"\n***TAO HOA DON***	\n";
            		a.taohoadon();
            		dshoadon.themHoaDon(a);
            		system("pause");
            		system("cls");
            		break;
           		}
          		case 3: {
            		cout<<"\n***XOA 'TAT CA' HOA DON***\n";
          		  	dshoadon.xoaAllHoaDon();
          		  	system("pause");
         		   	system("cls");
					break;
				}
				case 4: {
					cout<<"\n***XOA HOA DON***\n";
					int n;
					cout<<"Nhap so thu tu hoa don can xoa: "; cin>>n;
					dshoadon.xoaHoaDon(n);
					system("pause");
         		   	system("cls");
					break;
				}
				case 5: {
					cout<<"\n\t\t***DANH SACH HOA DON\2***\n";
					dshoadon.inDanhSachHoaDon();
					system("pause");
          		  	system("cls");
					break;
				}
				case 6: {
					cout<<"\n\t\t***TONG DOANH THU***\n";
					cout<<"Tong doanh thu la: "<<dshoadon.Tongtienhoadon()<<" VND"<<endl;
					system("pause");
         	 	  	system("cls");
					break;
				}
				case 2: {
					cout<<"\n\t\t***IN HOA DON VUA THEM***\n";
					dshoadon.inHoaDonMoi();
					system("pause");
            		system("cls");
					break;
				}
				case 0: {
                	cout << "\nThoat chuong trinh.\n";
                	break;
            	}
            	default: {
                	cout << "\nLua chon khong hop le. Vui long nhap lai.\n";
                	break;
            	}
        	}
    		} while (choice2!=0);
			break;
		   }
		   case 0: {
		   	cout<<"\nCAM ON BAN DA SU DUNG CHUONG TRINH! ";
		   	system("pause");
			break;
		   }
		   
	   		}
		}while (temp!=0);
	//===================================================================================================================
	
   	//==================================================================================================================
   	
	return 0;
}