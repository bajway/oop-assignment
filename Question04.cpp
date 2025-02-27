#include<iostream>
#include<string>
#include<array>
using namespace std;
class Route 
{
private:
    int route_iD;
    array<string, 10> point_stOPS;
public:
    Route(int iD, const array<string, 10>& stOPS) : route_iD(iD), point_stOPS(stOPS) {}
    string getstOP(int number) const {
        return point_stOPS[number];
    }
};
class Student 
{
private:
    int iD;
    string naME;
    string stOP;
    bool card_activaTED;
public:
    Student(int iD, const string& naME, const string& stOP) 
        : iD(iD), naME(naME), stOP(stOP), card_activaTED(false) {}
    voiD pay_chaLLAN() { card_activaTED = true;
    }
    bool iscard_activaTED() const { return card_activaTED; }
    string getstOP() const { return stOP; }
    string getnaME() const { return naME; }
};
class Bus 
{
private:
    int pointiD;
    Route* route;
public:
    Bus(int iD, Route* r) : pointiD(iD), route(r) {}
    Route* getRoute() const {
        return route;
    }
};
class TransportSystem 
{
private:
    array<Student*, 100> studenTS;
    array<Bus*, 20> busES;
    array<Route*, 10> routES;
    int student_CouNT;
    int bus_couNT;
    int route_couNT;
public:
    TransportSystem() : student_CouNT(0), bus_couNT(0), route_couNT(0) {}
    void add_studeNTS(int iD, const string& naME, const string& stOP) {
        studenTS[student_CouNT++] = new Student(iD, naME, stOP); }
    void add_rOUTE(int iD, const array<string, 10>& point_stOPS) {
        routES[route_couNT++] = new Route(iD, point_stOPS); }
    void add_BUS(int iD, Route* route) {
        busES[bus_couNT++] = new Bus(iD, route); }
    void proceess_TAPS() const {
        for (int i = 0; i < student_CouNT; i++) {
            if (studenTS[i]->iscard_activaTED()) {
            cout << "Student " << studenTS[i]->getnaME() 
                 << " checked in and will be dropped at " 
                 << studenTS[i]->getstOP() << ".\n";
            }
        }
    }
    ~TransportSystem() {
        for (int i = 0; i < student_CouNT; i++) {
            delete studenTS[i]; }
        for (int i = 0; i < bus_couNT; i++) {
            delete busES[i]; }
        for (int i = 0; i < route_couNT; i++) {
            delete routES[i]; }
    }
};
int main() {
    TransportSystem transportSystem;
    array<string, 10> point_stOPS1 = {"FAST", "Murghi khana", "Baloch Pull", "Quaidabad", "Malir", "Landhi railway", "Airport", "Shahrah-e-Faisal", "KArsaz", "Habitt"};
    transportSystem.add_rOUTE(1, point_stOPS1);
    transportSystem.add_studeNTS(2539, "Kashif", "Karsaz");
    transportSystem.studenTS[0]->pay_chaLLAN();
    transportSystem.proceess_TAPS();
    return 0;
}
