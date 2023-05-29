#include<bits/stdc++.h>
using namespace std;
void khung(){
	cout<<"\n================================================================\n";
}
class Dog{
    public:
        string name, breed;
        int birthYear;
        Dog(){
            this->name="";
            this->breed="";
            this->birthYear=0;
        }
        Dog(string ten, string loai, int tuoi){
            this->name=ten;
            this->breed=loai;
            this->birthYear=tuoi;
        }
        Dog(const Dog& otherDog) {
            this->name = otherDog.name;
            this->breed = otherDog.breed;
            this->birthYear = otherDog.birthYear;
        }
        friend istream& operator>>(istream& is, Dog& dog) {
            cout << "Enter name: ";
            is >> dog.name;
            cout << "Enter breed: ";
            is >> dog.breed;
            cout << "Enter birth year: ";
            is >> dog.birthYear;
            return is;
        }
        friend ostream& operator<<(ostream& os, const Dog& dog) {
            os << "Name: " << dog.name << endl;
            os << "Breed: " << dog.breed << endl;
            os << "Birth Year: " << dog.birthYear << endl;
            return os;
        }
		friend bool operator==(Dog& dog1, Dog& dog2) {
            return dog1.breed == dog2.breed;
        }
        void sinh(){
        	int age=2023-this->birthYear;
        	if(age>=1&&age<=3){
        		cout<<"Du tuoi sinh san";
			}
			else cout<<"Khong phai tuoi sinh san";
		}
		void reName(){
            string newName;
            cout<<"Nhap new name: ";
            cin>>newName;
            this->name=newName;
        }
		~Dog() {
			this->name="";
            this->breed="";
            this->birthYear=0            
			cout << "\nDa huy thanh cong\n";
        }
};
int main(){
    //  mặc định
    Dog dog1;
    cout << "Dog 1 ( mac dinh):\n" << dog1 << endl;
	khung();
    // Tạo một Dog bằng tham số
    Dog dog2("GauGau", "cai", 2015);
    cout << "Dog 2 ( tham so): \n" << dog2 << endl;
	khung();
    // Tạo một Dog sao chép
    Dog dog3 = dog2;
    cout << "Dog 3 (ccopy):\n" << dog3 << endl;
	khung();
    // Thay đổi tên của dog3
    dog3.reName();
    cout << "Dog 3 (sau khi rename):\n" << dog3 << endl;
	khung();
    // So sánh breed của dog2 và dog3
    if (dog2 == dog3) {
        cout << "Dog 2 và Dog 3 co cung breed.\n";
    } else {
        cout << "Dog 2 và Dog 3 khac breed.\n";
    }
	khung();
    // Tạo một đối tượng Dog bằng toán tử nhập
    Dog dog4;
    cin >> dog4;
    cout << "Dog 4 (nhap):\n" << dog4 << endl;
	khung();
    // Gọi phương thức "sinh" của dog4 để kiểm tra xem nó có đủ tuổi sinh sản không
    dog4.sinh();
	khung();
    // Kiểm tra toán tử xuất
    cout << "Dog 2 (xuat):\n" << dog2 << endl;
	khung();
    // Kiểm tra hàm hủy
    Dog dog5("MeoMeo", "Duc", 2010);
    cout << "Dog 5 (truoc khi huy):\n" << dog5 << endl;
    dog5.~Dog();
    cout << "Dog 5 (sau khi huy):\n" << dog5 << endl;
	khung();
    return 0;
}