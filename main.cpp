
//Login and Registration System

#include <iostream>
#include "UserLogin.h"
using namespace std;
int main() {

    string username , password ;

    UserLogin user;


    UserLogin::welcome();

    int choice;

    cout<< endl;
    cout <<"         Enter 1 to Login\n";
    cout <<"         Enter 2 to Register\n";
    cout <<"         Enter 3 to Reset Password\n";
    cout << endl;
    cout << "Please Enter your Choice: ";
    cin >> choice;

    switch(choice) {

        case 1:
            cout << endl;
            cout << "Please Enter your Username : ";
            cin >> username;
            if(user.isRegistered(username)){
                cout << "Enter Your Passsword :";
                cin >> password;
                UserLogin::login(username, password);
                break;
            }{
                cout<< "\n          User Name not found! \n";
                cout << "\t--------------------------------\n";
                cout << "      Please Register an Account\n";
                cout <<endl;
            }

        case 2:
            user.Registration(username, password);
            break;
        case 3:
            user.ResetPassword(username);
            break;
        default:
            cout << endl;
            cout << "\n       Please Enter a valid option \n";
            cout << "\t--------------------------------\n";


    }

    return 0;
}
