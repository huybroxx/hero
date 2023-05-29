#include<bits/stdc++.h>
using namespace std;

class Vehicle{
public:
    int wheels;
    double weight;
    virtual void input(){
        cout << "\nNhap so luuong banh xe: "; cin >> this->wheels;
        cout << "\nNhap trong luong: "; cin >> this->weight;
    }
    virtual void output(){
        cout << "Banh xa: " << this->wheels << " - Trong Luong: " << this->weight;
    }
};

class Car: public Vehicle{
public:
    int passenger_load;
    void input(){
        Vehicle::input();
        cout << "\nNhap tai trong khach: "; cin >> this->passenger_load;
    }
    void output(){
        Vehicle::output();
        cout << " - Tai trong khach: " << this->passenger_load; 
    }
    void giamkhach(){
        if(passenger_load >= 2){
            passenger_load = 2;
        } else {
            cout << "Khong the giam so khach nua!" << endl;
        }
    }
};

class Truck: public Vehicle{
public:
    int pay_load;
    void input(){
        Vehicle::input();
        cout << "\nNhap tai trong ahng hoa: "; cin >> this->pay_load;
    }
    void output(){
        Vehicle::output();
        cout << " - Tai trong hang hoa: " << this->pay_load; 
    }
    void giamtrong(){
        if(pay_load >= 50){
            pay_load = 50;
        } else {
            cout << "Khong the giam tai trong hang hoa nua!" << endl;
        }
    }
};

class ListVehicle{
public:
    vector<Vehicle*> vehicles;
    void input(){
        int n;
        cout << "Nhap so luong phuong tien: ";
        cin >> n;
        for(int i = 0; i < n; i++){
            int type;
            cout << "Nhap loai phuong tien('1'-> oto | '2' -> xe tai): ";
            cin >> type;
            if(type == 1){
                Car* car = new Car();
                car->input();
                vehicles.push_back(car);
            } else if(type == 2){
                Truck* truck = new Truck();
                truck->input();
                vehicles.push_back(truck);
            } else {
                cout << "Loai phuong tien khong hop le, vui long thu lai." << endl;
                i--;
            }
        }
    }
    void output(){
        for(int i = 0; i <vehicles.size(); i++){
            vehicles[i]->output();
            cout << endl;
        }
    }
    
    static bool compare_weight(Vehicle* v1, Vehicle* v2){
        return v1->weight > v2->weight;
    }
    
    void sapxepgiamdan(){
        sort(vehicles.begin(), vehicles.end(), compare_weight);
        reverse(vehicles.begin(), vehicles.end());
    }
    int demxe(){
        int temp = 0;
        for(int i = 0; i < vehicles.size(); i++){
            if(vehicles[i]->wheels > 7){
                temp++;
            }
        }
        return temp;
    }
    
};

int main(){
    ListVehicle list;
    list.input();
    list.output();
    list.sapxepgiamdan();
    list.output();
    cout << "So xe tren 7 banh la: " << list.demxe() << endl;
    for(auto vehicle : list.vehicles){
    if(Car* car = dynamic_cast<Car*>(vehicle)){
        car->giamkhach();
    }
    if(Truck* truck = dynamic_cast<Truck*>(vehicle)){
        truck->giamtrong();
    }
    cout << "Danh sach phuong tien sau khi giam so khach cua xe khach va giam tai trong hang hoa cua xe tai: " << endl;
    list.output();
    return 0;
}
}