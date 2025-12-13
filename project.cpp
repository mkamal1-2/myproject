#include <bits/stdc++.h>
using namespace std;
struct Patient {
    string name, status;
};
int main() {
    int choice, spec, stat; string name, statu; vector<deque<Patient>> v(21);
    while (true) {
        bool empty = true;
        cout << "Enter your choice:\n" << "1) Add a new patient\n"
        << "2) Print all the patients\n" << "3) Get the next patient\n"
        << "4) Exit\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter specialization, name, status: ";
            cin >> spec >> name >> stat;
            if (stat == 1) {
                statu = "urgent";
            }
            else {
                statu = "regular";
            }
            Patient z;
            z.name = name; z.status = statu;
            if (stat == 1) {
                v[spec].push_front(z);
            }
            else {
                v[spec].push_back(z);
            }
        }
        else if (choice == 2) {
            for (int i = 0; i < v.size(); i++) {
                if (!v[i].empty()) {
                    empty = false;
                    if (v[i].size() == 1) {
                        cout << "There is 1 patient in specialization " << i << '\n';
                    }
                    else {
                        cout << "There are " << v[i].size() << " patients in specialization "<< i << '\n';
                    }
                    for (auto &x: v[i]) {
                        cout << x.name << ' ' << x.status << '\n';
                    }
                    cout << '\n';
                }
            }
            if (empty) {
                cout << "There are no patients." << '\n';
            }
        }
        else if (choice == 3) {
            cout << "Enter specialization: ";
            cin >> spec;
            if (v[spec].empty()) {
                cout << "No patients at the moment. Have rest, Dr." << '\n';
            }
            else {
                cout << v[spec].front().name << " please go with the Doctor." << '\n';
            }
        }
        else if (choice == 4) return 0;
        else {
           cout << "Enter a valid choice!" << '\n';
        }
    }
}