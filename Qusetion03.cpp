#include <iostream>
#include <string>
using namespace std;
class User 
{
public:
    int iD;
    int aGE;
    string naME;
    string license_tYPE;
    string contACT;
    User(int id, const string& n, int a, const string& license, const string& c) 
        : iD(id), naME(n), aGE(a), license_tYPE(license), contACT(c) {}
    void updateDetails(const string& n, int a, const string& license, const string& c) {
        naME = n;
        aGE = a;
        license_tYPE = license;
        contACT = c; }
};
class Vehicle 
{
public:
    string modEL;
    string license_RequiRED;
    double rental_PrICE;
    Vehicle(const string& m, double price, const string& license) 
        : modEL(m), rental_PrICE(price), license_RequiRED(license) {}
    bool isValidLicense(const string& license) const {
        return license == license_RequiRED;  }
};
class RentalSystem 
{
private:
    User* usERS[100];
    Vehicle* vehicLES[50];
    int user_couNT;
    int vehicle_CouNT;
public:
    RentalSystem() : user_couNT(0), vehicle_CouNT(0) {}
    void register_usER (int id, const string& naME, int aGE, const string& license, const string& contACT) {
        usERS[user_couNT++] = new User(id, naME, aGE, license, contACT); }
    void add_VehicLE(const string& modEL, double price, const string& license) {
        vehicLES[vehicle_CouNT++] = new Vehicle(modEL, price, license); }
    void rent_VehicLE(int iD, const string& modEL) {
        User* user = findUser ById(iD);
        if (!user) {
            cout << "User  not found." << endl;
            return;}
        Vehicle* vehicle = findVehicleBymodEL(modEL);
        if (!vehicle) {
            cout << "Vehicle not found." << endl;
            return;}
        if (vehicle->isValidLicense(user->license_tYPE)) {
            cout << user->naME << " rented " << vehicle->modEL 
                 << " for Rs " << vehicle->rental_PrICE << " per day." << endl;} 
                 else {
            cout << user->naME << " is not eligible to rent this vehicle." << endl;}
    }
private:
    User* findUser ById(int iD) {
        for (int i = 0; i < user_couNT; i++) {
            if (usERS[i]->iD == iD) {
                return usERS[i]; }
        }
        return nullptr; 
    Vehicle* findVehicleBymodEL(const string& modEL) {
        for (int j = 0; j < vehicle_CouNT; j++) {
            if (vehicLES[j]->modEL == modEL) {
                return vehicLES[j]; }
        }
        return nullptr; 
    }
};
int main() 
{
    RentalSystem rentalSystem;
    rentalSystem.register_usER (1, "Kashif", 40, "FUll", "03000040020");
    rentalSystem.add_VehicLE("Mehran", 200, "Learner");
    rentalSystem.add_VehicLE("Lexus", 100000, "Full");
    rentalSystem.rent_VehicLE(1, "Mehran");  
    rentalSystem.rent_VehicLE(1, "Lexus");
    return 0;
}
