#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream global("Global.txt", ios::app);

class Arhiv {
private:
    string name;
    string system;
    int rosmir;
    string date;
    
public:
    Arhiv(string name1, string system1, int rosmir1, string date1) : name(name1), system(system1), rosmir(rosmir1), date(date1) {
        if (!global.is_open()) {
            cerr << "Error!";
        }
        else {
            global << name << endl;
            global << system << endl;
            global << rosmir << endl;
            global << date << endl;
        }
        global.close();
    }

    void set_name() {
        cout << "Set name: ";
        cin >> name;
        if (!global.is_open()) {
            cerr << "Error!";
        }
        else {
            global << name << endl;
        }
    }
    void set_system() {
        cout << "Set system: ";
        cin >> system;
        if (!global.is_open()) {
            cerr << "Error!";
        }
        else {
            global << system << endl;
        }
    }
    void set_ros() {
        cout << "Set rosmir: ";
        cin >> rosmir;
        if (!global.is_open()) {
            cerr << "Error!";
        }
        else {
            global << rosmir << endl;
        }
    }
    void set_date() {
        cout << "Set date: ";
        cin >> date;
        if (!global.is_open()) {
            cerr << "Error!";
        }
        else {
            global << date << endl;
        }
    }
    void search_system() {
        string nam, sys;
        bool found = false;

        for (int attempt = 1; attempt <= 5; ++attempt) {
            cout << "Sproba " << attempt << endl;
            cout << "name system: ";
            cin >> sys;
            cout << "Get name: ";
            cin >> nam;

            if (sys == system && nam == name) {
                found = true;
                get_info();
                break;
            }
            else {
                cerr << "error, try again ";
                if (attempt < 5)
                    cout << "try again." << endl;
                else
                    cout << "Maximum number of attempts reached." << endl;
            }
        }
    }


    
    Arhiv() {
        set_name();
        set_system();
        set_ros();
        set_date();
    };
    void get_info() {
        cout << name << endl;
        cout << system << endl;
        cout << rosmir << endl;
        cout << date << endl;
        
    }
    
    ~Arhiv() {

    }
};



int main() {
    string na;
    cout << "Arhiv: ";
    cin >> na;

    Arhiv n{na, "Windows", 322, "12.12.2024"};
    n.get_info();

    short f;
    cout << "Seath Arhiv to system?" << endl;
    cout << "1. yes, 2.no" << endl;
    cin >> f;

    if (f == 1) {
        string system;
        cout << "get system to seath: ";
        cin >> system;
        n.search_system();
    }
    if (f == 2) {
        return 1;
    }
    else {
        cerr << "Error";
    }

}
