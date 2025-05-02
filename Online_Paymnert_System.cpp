#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

struct Payment {
    double amount;
    string method;
};

class User {
private:
    string name;
    string userID;
    vector<Payment> payments;

public:
    User(string userName, string id) {
        name = userName;
        userID = id;
    }

    void makePayment(double amount, string method) {
        Payment p = {amount, method};
        payments.push_back(p);
        cout << "Payment of ₹" << amount << " done successfully using " << method << ".\n";
    }

    void showHistory() {
        cout << "\nPayment History for " << name << " (ID: " << userID << "):\n";
        if (payments.empty()) {
            cout << "No transactions found.\n";
        } else {
            for (Payment p : payments) {
                cout << "- Amount: ₹" << p.amount << ", Method: " << p.method << endl;
            }
        }
    }

    string getUserID() {
        return userID;
    }
};

bool isAlphanumeric(const string& str) {
    bool hasLetter = false, hasDigit = false;
    for (char ch : str) {
        if (isalpha(ch)) hasLetter = true;
        if (isdigit(ch)) hasDigit = true;
    }
    return hasLetter && hasDigit;
}

int main() {
    vector<User> users;
    int choice;
    string id, name, method;
    double amount;

    while (true) {
        cout << "\n==== Online Payment Management ====\n";
        cout << "1. Add User\n2. Make Payment\n3. View Payment History\n4. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter user name: ";
            cin >> name;
            cout << "Enter alphanumeric user ID (e.g., user123): ";
            cin >> id;

            if (!isAlphanumeric(id)) {
                cout << "Error: User ID must contain both letters and numbers.\n";
                continue;
            }

            users.push_back(User(name, id));
            cout << "User added successfully.\n";
        } 
        else if (choice == 2) {
            cout << "Enter user ID: ";
            cin >> id;
            bool found = false;
            for (User &u : users) {
                if (u.getUserID() == id) {
                    cout << "Enter amount: ₹";
                    cin >> amount;
                    cout << "Enter payment method (e.g., UPI / CreditCard / NetBanking): ";
                    cin >> method;
                    u.makePayment(amount, method);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "User not found.\n";
        } 
        else if (choice == 3) {
            cout << "Enter user ID: ";
            cin >> id;
            bool found = false;
            for (User &u : users) {
                if (u.getUserID() == id) {
                    u.showHistory();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "User not found.\n";
        } 
        else if (choice == 4) {
            cout << "Thank you for using the system.\n";
            break;
        } 
        else {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
