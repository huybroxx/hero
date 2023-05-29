#include<bits/stdc++.h>
#include <Windows.h>
using namespace std;
//==============================================================================================================
class PerSon {
	public:
		int  birtday ;
		string name , address, id, tel;
		virtual void input();
		virtual void output();
};
void PerSon::input()
{
	fflush(stdin);
	cout<<"|  Nhap name : ";
	getline(cin, name);
	fflush(stdin);
	cout<<"|  Nhap address : ";
	getline(cin, address);
	cout<<"|  Nhap id : ";cin>>id;
	cout<<"|  Nhap birtday : ";cin>>birtday;
	cout<<"|  Nhap tel : ";cin>>tel;
}
void PerSon::output()
{
	cout<<"+---------------------------------------------------------------+\n";
	cout << "|" << left << setw(35) << "ID:" << setw(20) << this->id << right << setw(10) << " |" << endl;
	cout << "|" << left << setw(35) << "Name:" << setw(20) << this->name << right << setw(10) << " |" << endl;
	cout << "|" << left << setw(35) << "Address:" << setw(20) << this->address << right << setw(10) << " |" << endl;
	cout << "|" << left << setw(35) << "Tel:" << setw(20) << this->tel << right << setw(10) << " |" << endl;
	cout << "|" << left << setw(35) << "Birthday:" << setw(20) << this->birtday << right << setw(10) << " |" << endl;
	cout<<"--  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  --\n";
}
//=============================================================================================================
class KhachHang:public PerSon{
	public:
	string loaiKhachHang;
	int  tichDiem, tienKhachHang;
	KhachHang(string ten, int sn, string tel, string id, string addr, string loai, double tichdiem, double tien){
		this->name=ten;
		this->birtday=sn;
		this->tel=tel;
		this->id=id;
		this->address=addr;
		this->loaiKhachHang=loai;
		this->tichDiem=tichdiem;
		this->tienKhachHang=tien;
	}
	KhachHang(){
	}
	void input();
	void output();	
};
void KhachHang::input()
{
	
	PerSon::input();
	cout<<"|  Nhap tich diem mac dinh : ";cin>>tichDiem;
	fflush(stdin);
	cout<<"|  Nhap loai khach hang : ";
	getline(cin, loaiKhachHang);
	cout<<"|  Nhap tien khach hang mac dinh : ";cin>>tienKhachHang;
}
void KhachHang::output()
{
	PerSon::output();

	//cout << setfill(' ') << "+" << setw(22) << "" << setfill(' ') << setw(20) << "" << setfill(' ') << setw(25) << "" << "+" << endl;

	cout << "|" << left << setw(35) << "Tich diem:" << setw(20) << tichDiem << right << setw(10) << " |" << endl;
    cout << "|" << left << setw(35) << "Loai khach hang:" << setw(20) << loaiKhachHang << right << setw(10) << " |" << endl;
	cout << "|" << left << setw(35) << "Tien khach hang da mua:" << setw(20) << tienKhachHang << right << setw(10) << " |" << endl;
    //cout << setfill(' ') << "+" << setw(22) << "" << setfill(' ') << setw(18) << "" << setfill(' ') << setw(22) << "" << "+" << endl;
}
class ListKhachHang{
	public: 
	vector<KhachHang> dskh;
	
	void themKhachhang(KhachHang hk) {
        dskh.push_back(hk);
    }
	
    void xoaKhachHang(int index) {
        dskh.erase(dskh.begin() + index);
    }
    void xoaAllKhachHang(){
		dskh.clear();
	}
    int getsoluongkh(){
    	return dskh.size();
	}
	void inkhachhangnew(){
		dskh[dskh.size()-1].output();
	}
	void danhSachKhachHang(){
		cout << "+================================================================+\n";
        for (int i = 0; i < dskh.size(); i++) {
        	cout<<"\nThong tin khach hang thu "<<i+1<<": \n";
           	dskh[i].output();
			cout << "+---------------------------------------------------------------+\n";
        }
        //cout << "+================================================================+\n";
	}
	void khachHangVipNhat(){
		KhachHang vip= dskh[0];
		for(int i=0; i< dskh.size(); i++){
			if (dskh[i].tienKhachHang>vip.tienKhachHang)
				vip=dskh[i];
		}
		vip.output();
	}
};
//===================================================================================================================
//=============================================================================================
class CongThuc {
public:
    string nguyenlieu;
    double nuoc;
    double gam;
    CongThuc(string nl = "", double g = 0, double n = 0) {
        nguyenlieu = nl;
        nuoc = n;
        gam = g;
    }
    void incongthuc(){
		cout<<"     | Cong thuc: \t\t"<<this->nguyenlieu<<": "<<this->gam<<"(g) - Nuoc: "<<this->nuoc<<"(ml)\n";
	}
	void nhapcongthuc(){
		cout<<"\n|  - Nhap cong thuc - "; 
		cout<<"\n|   +Nhap nguyen lieu: "; 
		cin.ignore();
		getline(cin, this->nguyenlieu);
		cout<<"|   +Nhap (gam) nguyen lieu: ";
		cin>>this->gam;
		cout<<"|   +Nhap luong nuoc(ml): ";
		cin>>this->nuoc;
	}
};
class NuocUong
{
	public:
		string name;
        double gia;
        int soluong;
        CongThuc x;
        
        NuocUong(){
            
        }
        NuocUong(string ten, double gia, int soLuong = 0, CongThuc x = CongThuc()){
			this->name = ten;
 		 	this->gia = gia;
   			this->soluong = soLuong;
   			this->x = x;
		}
		void input(){
			cout<<"\n|  Nhap ten nuoc uong: ";
			cin.ignore();
			getline(cin, this->name);
			cout<<"|  Nhap so luong: ";
			cin>>this->soluong;
			x.nhapcongthuc();
			cout<<"|  Nhap gia: ";
			cin>>this->gia;
		}
		
		void themVaoKho(int s){
			this->soluong+=s;
		}
		void output(){
				   		
//			cout<<"================================================================\n";
//			cout<<"    | Ten nuoc uong           | Gia ban | So luong | Thanh tien |\n";
//			cout<<"================================================================\n";
			cout << left << setw(4)<<"    | "<<setw(24)<<this->name<<"| "<< setw(8)<<this->gia<<"| " << setw(9) <<this->soluong<< "| " << setw(10) <<this->gia*this->soluong<<" |\n";
			x.incongthuc();
		}
		double tinhtien(int soluongmua){
			return gia*soluongmua;
		}
		void xoakho(int n){
			this->soluong-=n;
		}
};
class ListNuocUong {
public:
    vector<NuocUong> dsNuocUong;
    
    void themNuocUong(NuocUong nuocUong) {
        dsNuocUong.push_back(nuocUong);
    }
	
    void xoaNuocUong(int index) {
        dsNuocUong.erase(dsNuocUong.begin() + index);
    }
    
	int getsoluongnuocuong(){
   	return dsNuocUong.size();
	}
    void themSLnuocuong(){
  		int stt, soLuong;
        cout << "Nhap so thu tu cua nuoc uong can them so luong: ";
        cin >> stt;
        while (stt < 1 || stt > dsNuocUong.size()) {
        	cout << "So thu tu khong hop le. Phai nhap trong khoang tu 1 den " << dsNuocUong.size() << ".\n";
            cout << "Nhap lai so thu tu: ";
            cin >> stt;
        }

        cout << "Nhap so luong can them: ";
        cin >> soLuong;
        while (soLuong < 0) {
        	cout << "So luong khong hop le. Phai nhap so khong am.\n";
            cout << "Nhap lai so luong: ";
            cin >> soLuong;
            }
        dsNuocUong[stt-1].themVaoKho(soLuong); 
        cout<<"So luong trong kho cua "<<dsNuocUong[stt-1].name<<" bay gio la: "<<dsNuocUong[stt-1].soluong<<endl;    
    }
    
    
    void hienThiDanhSachNuocUong() {

        cout << "+================================================================+\n";
		cout<<" STT | Ten nuoc uong           | Gia ban | So luong | Thanh tien |\n";
        cout << "+================================================================+\n";
        for (int i = 0; i < dsNuocUong.size(); i++) {
            cout << left << setw(2)<<" "<<i+1<<"  | "<<setw(24)<<dsNuocUong[i].name<<"| "<< setw(8)<<dsNuocUong[i].gia<<"| " << setw(9) <<dsNuocUong[i].soluong<< "| " << setw(10) <<dsNuocUong[i].gia*dsNuocUong[i].soluong<<" |\n";
			dsNuocUong[i].x.incongthuc();
			cout << "|-  -|  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  +\n";
        }
        cout << "+================================================================+\n";
    }
	void xoanuocuongtrongkho(){
		int stt;
                cout << "Nhap so thu tu cua nuoc uong can xoa: ";
                cin >> stt;
                while (stt < 1 || stt > dsNuocUong.size() ) {
                    cout << "So thu tu khong hop le. Phai nhap trong khoang tu 1 den " << dsNuocUong.size() << ".\n";
                    cout << "Nhap lai so thu tu: ";
                    cin >> stt;
                }
                dsNuocUong.erase(dsNuocUong.begin()+stt-1);
                cout << "Xoa nuoc uong thanh cong!\n";
	}
	
};
//class Hoadonnho{
//	public:
//		
//};
void khung(){
        cout<<"+-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  +\n";
    //    this_thread::sleep_for(chrono::seconds(1)); // Tạm dừng 1 giây 
        Beep(500, 1000);
}
void amthanh(){
		Beep(1000, 500);
	}
   

class HoaDon
{
	public:
		KhachHang kh;
		ListKhachHang dskhach;
		ListNuocUong listNuocUong;
		vector<NuocUong> dsNuocUong;
		vector<int> soLuong;
		int tienbill=0;
		int tiengiamgia=0;
		HoaDon(ListKhachHang c, KhachHang a, ListNuocUong b){
			this->kh=a;
			this->listNuocUong=b;
			this->dskhach=c;
		}
		void Tienbilll(NuocUong nuoc, int soluong){
    	this->tienbill+=(nuoc.gia*soluong);
		}
		bool themNuocUong(NuocUong nuocUong, int soLuongMua) {
        if (nuocUong.soluong >= soLuongMua) {
            dsNuocUong.push_back(nuocUong);
            soLuong.push_back(soLuongMua);
            Tienbilll(nuocUong, soLuongMua);
            nuocUong.xoakho(soLuongMua);
            return true;
        	}
        else 
			return false;
    	}
    	
		void taohoadon(){
		bool out;	
		char chon; 
		string id;
		cout<<"-Thong tin khach hang-";	
		cout<<"\nChon 'C' neu khach hang co san; 'K' neu khach hang moi: "; cin>>chon;
		switch (chon){
			case ('c'): {
				bool x;
				dskhach.danhSachKhachHang();
				do{
				cout<<"\nNhap id khach hang de xac thuc: "; cin>>id;
				khung();
				for(int i=0; i<dskhach.getsoluongkh(); i++){
					if(id==dskhach.dskh[i].id) {
					kh=dskhach.dskh[i] ;
					cout<<"\nXac thuc thong tin khach hang thanh cong!\n\n";
					//khung();
					x=true;
					break;
					}
					else {
					x=false;
					}
					}
					if (x==false) cout<<"\nXac thuc thong tin khach that bai!\n ";
				} while(x!=true);
				
				break;
			}
			case ('k'): {
				kh.input();
				dskhach.themKhachhang(kh);
				break;
			}
		}
		system("pause");
		system("cls");
		listNuocUong.hienThiDanhSachNuocUong();
		do{
			//listNuocUong.hienThiDanhSachNuocUong();
			int stt, soLuongMua;
            cout << "Nhap so thu tu cua nuoc uong can mua: ";
            cin>>stt;
            while (stt < 1 || stt > listNuocUong.getsoluongnuocuong()) {
            	cout << "So thu tu khong hop le. Ma so phai nam trong khoang tu 1 den " << listNuocUong.getsoluongnuocuong() << ".\n";
           	 	cout << "Nhap lai so thu tu cua nuoc uong can mua: ";
            	cin >> stt;
            }
			
            cout << "So luong nuoc uong can mua: ";
            cin >> soLuongMua;
            while (soLuongMua <= 0) {
                cout << "So luong nuoc uong khong hop le. Vui long nhap lai.\n";
                cout << "So luong nuoc uong can mua: ";
                cin >> soLuongMua;
            }
            if (themNuocUong(listNuocUong.dsNuocUong[stt-1], soLuongMua)) {
                cout << "Them nuoc uong vao hoa don thanh cong!\n";
                tienbill+=soLuongMua*listNuocUong.dsNuocUong[stt-1].gia;
            } else {
                cout << "Khong the them nuoc uong nay vao hoa don.\n";
            }
            char chon2;
            cout<<"Nhap 'T' neu muon tiep tuc mua; 'K' neu muon hoan tat!\n   -->  ";
			do{
				cin>>chon2;
				amthanh();
				switch(chon2)
				{
            		case ('t'): {
            			out=true;   
						break;
					}
					case ('k'): {
						out= false;
						break;
					}
					default: {
                	cout << "\nLua chon khong hop le. Vui long nhap lai.\n";
                	break;
            		}
				}
			} while(chon2!='t'&&chon2!='k');
		} while (out==true);
		system("pause");
		system("cls");
		//============
		char chon3;
		int diem;
		cout<<"\n    Ban co muon ap dung 'Diem tich luy' cho hoa don khong? \n     (luu y ban dang co "<<kh.tichDiem<<" diem | 10 diem = 1000 VND)";
		cout<<"\n    Nhap 'C' neu co | Nhap 'K' neu khong\n    -->  ";
		do{
				cin>>chon3;
				amthanh();
				switch(chon3)
				{
            		case ('c'): {
            		bool p;
            		do{
            			cout<<"Moi ban nhap so diem muon su dung: ";
						cin>>diem;
						if (diem>=10&&diem<=kh.tichDiem) {
							kh.tichDiem-=diem;
							tiengiamgia=diem/10*1000;
							p=true;
							cout<<"\n\nHoan tat hoa don! ";
						}
						else{
							cout<<"So diem ban nhap khong hop le!";
							p=false;
						}
					}while(p!=true);
						break;
					}
					case ('k'): {
						cout<<"\n\nHoan tat hoa don! ";
						break;
					}
					default: {
                	cout << "\nLua chon khong hop le. Vui long nhap lai.\n";
                	break;
            		}
				}
			} while(chon3!='c'&&chon3!='k');
		//===============
	}
	void inHoaDon(){
		kh.output();
		cout << "+================================================================+\n";
		cout<<" STT | Ten nuoc uong           | Gia ban | So luong | Thanh tien |\n";
        cout << "+================================================================+\n";
        for (int i = 0; i < dsNuocUong.size(); i++) {
            cout << left << setw(2)<<" "<<i+1<<"  | "<<setw(24)<<dsNuocUong[i].name<<"| "<< setw(8)<<dsNuocUong[i].gia<<"| " << setw(9) <<soLuong[i]<< "| " << setw(10) <<dsNuocUong[i].gia*soLuong[i]<<" |\n";
			cout << "|-  -|  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  +\n";
        }
        cout << "+================================================================+\n";
        cout << " Tong tien: " << setw(43) << right << "|  "<<this->tienbill/2 <<" VND |"<< endl;
        cout << " Diem tich luy cong them : " << setw(28) << right << "|   "<<this->tienbill/20 <<"     |"<< endl;
        kh.tichDiem+=this->tienbill/20;
        //cout << "------------------------------------------------------------------\n";
        cout << " Giam gia : " << setw(43) << right << "|   "<<tiengiamgia <<" VND |"<< endl;
        cout << "------------------------------------------------------------------\n";
        cout << " Thanh toan :" << setw(42) << right << "|  "<<this->tienbill/2-tiengiamgia <<" VND |"<< endl;
        cout << "+================================================================+\n";
	}
		
};
class ListHoaDon{
	public:
		vector<HoaDon> listhoadon;
		void themHoaDon(HoaDon hoadon){
			listhoadon.push_back(hoadon);
		}
		void xoaHoaDon(int index){
			listhoadon.erase(listhoadon.begin() + index);			
		}
		void xoaAllHoaDon(){
			listhoadon.clear();
		}
		int Tongtienhoadon(){
			int sum=0;
			for(int i=0; i<listhoadon.size(); i++){
				sum+=((listhoadon[i].tienbill)-(listhoadon[i].tiengiamgia));
			}
			return sum/2;
		}
		void inHoaDonMoi(){
			listhoadon[listhoadon.size()-1].inHoaDon();
		}
		void inDanhSachHoaDon(){
			for(int i=0; i<listhoadon.size(); i++){
				cout<<"\n\t-HOA DON ["<<i+1<<"]\n";
				listhoadon[i].inHoaDon();
			}
		}
};
int main()
{
	//==================================================================================================================
   	ListKhachHang dskh;
	KhachHang kh1("Nguyen vy", 2004, "00011642", "0505","Da Nang", "VIP", 5000, 5000 );
	KhachHang BOSS("Ngo Ngoc Huy", 2004, "0359811642", "admin", "Quang Nam", "VIP (Admin)", 9999, 9999);
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
	cout << "+--------------------------------------------------+\n";
    cout << "|            \2***MENU CHUC NANG***\2               |\n";
    cout << "+--------------------------------------------------+\n";
    cout << "|        1. KHO NUOC UONG                          |\n";
    cout << "+-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - +\n";
    cout << "|        2. QUAN LI HOA DON                        |\n"; 
	cout << "+-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - +\n";   
    cout << "|        3. QUAN LI NHAN VIEN                      |\n";
    cout << "+-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - +\n";
    cout << "|        4. QUAN LI KHACH HANG                     |\n";
    cout << "+-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - +\n";
    cout << "|        0. THOAT CHUONG TRINH  ( EXIT )           |\n";
    cout << "+--------------------------------------------------+\n";
       	cout << "Nhap lua chon cua ban: ";
   	cin >> temp;
   	amthanh();
   	system("cls");   	
   	switch(temp){
   		case 1: {
   				//===================================================================================================================
		int choice;
		do {
        	cout << "+--------------------------------------------------+\n";
        	cout << "|               QUAN LY NUOC UONG                  |\n";
        	cout << "+--------------------------------------------------+\n";
        	cout << "| 1. Them nuoc uong                                |\n";
        	cout << "| 2. Them so luong nuoc uong trong kho             |\n";
        	cout << "| 3. Xoa nuoc uong                                 |\n";
        	cout << "| 4. Hien thi danh sach nuoc uong trong kho        |\n";
        	cout << "| 0. Quay ve menu quan ly  ( <-- )                 |\n";
        	cout << "+--------------------------------------------------+\n";
        	cout << "    Nhap lua chon cua ban: ";
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
		   case 2: {
		   	int choice2;
			do {
        	cout << "+--------------------------------------------------+\n";
        	cout << "|                 QUAN LY HOA DON                   |\n";
        	cout << "+--------------------------------------------------+\n";
        	cout << "| 1. Tao hoa don moi (mua hang)^^                   |\n";
        	cout << "| 2. In hoa don                                     |\n";
        	cout << "| 3. Xoa tat ca hoa don                             |\n";
        	cout << "| 4. Xoa hoa don duoc chon                          |\n";
        	cout << "| 5. Hien thi danh sach hoa don                     |\n";
        	cout << "| 6. In tong doanh thu                              |\n";
        	cout << "| 0. Quay ve menu quan ly  ( <-- )                  |\n";
        	cout << "+--------------------------------------------------+\n";
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
		   case 4:{
		   	int choice3;
			do {
        	cout << "+--------------------------------------------------+\n";
        	cout << "|             QUAN LY KHACH HANG                    |\n";
        	cout << "+--------------------------------------------------+\n";
        	cout << "| 1. Them thong tin khach hang moi^^                |\n";
        	cout << "| 2. In thong tin khach hang                        |\n";
        	cout << "| 3. Xoa khach hang                                 |\n";
        	cout << "| 4. Xoa tat ca khach hang                          |\n";
        	cout << "| 5. Hien thi danh sach khach hang                  |\n";
        	cout << "| 6. In thong tin khach hang VIP nhat               |\n";
        	cout << "| 7. Cong diem tich luy cho khach hang duoc chon!   |\n";
        	cout << "| 0. Quay ve menu quan ly  ( <-- )                  |\n";
        	cout << "+--------------------------------------------------+\n";
        	cout << "Nhap lua chon cua ban: ";
      	  	cin >> choice3;
      	  	amthanh();
      		system("cls");
			switch (choice3) 
			{
				case 1: {
					KhachHang k;
					cout<<"\n\t\t***THEM THONG TIN KHACH HANG***\n";
					cout<<"\nNhap thong tin khach hang: \n";
					k.input();
					dskh.themKhachhang(k);
					cout<<"\nThem thong tin khach hang thanh cong!\n";
					system("pause");
            		system("cls");
					break;
				}
				case 2: {
					cout<<"\n\t\t***THONG TIN KHACH HANG VUA THEM***\n";
					dskh.inkhachhangnew();
					cout<<endl;
					system("pause");
            		system("cls");
					break;
				}
				case 4: {
					cout<<"\n\t\t***XOA 'TAT CA' KHACH HANG***\n";
					dskh.xoaAllKhachHang();
					cout<<"\n Xoa thong tin tat ca khach hang thanh cong!\n";
					system("pause");
            		system("cls");
					break;
				}
				case 3: {
					cout<<"\n\t\t***XOA KHACH HANG***\n";
					int n;
					cout<<"Nhap so thu tu khach hang can xoa: "; cin>>n;
					dskh.xoaKhachHang(n);
					cout<<"\n Xoa thong tin khach hang thanh cong!\n";
					system("pause");
            		system("cls");
					break;
				}
				case 5: {
					cout<<"\n\t\t***DANH SACH KHACH HANG***\n";
					dskh.danhSachKhachHang();
					system("pause");
            		system("cls");
					break;
				}
				case 6: {
					cout<<"\n\t\t***THONG TIN KHACH HANG VIP NHAT***\n";
					dskh.khachHangVipNhat();
					system("pause");
            		system("cls");
					break;
				}
				case 7: {
					cout<<"\n\t\t***CONG DIEM TICH LUY***\n";
					dskh.khachHangVipNhat();
					system("pause");
            		system("cls");
					break;
				}
			}
			} while(choice3!=0);
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
