//
// Created by Ikbal Hussain on 10/4/23.
//

#include "UserLogin.h"

#include <fstream>
#include <vector>
using namespace std;




void UserLogin::Registration(string userName, string Password) {

    ofstream file("records.txt", ios::app);

    string cUserName, cPassword;

    while(true) {

        cout << "\nEnter your Username : ";
        cin >> userName;

        if (UserLogin::userExist(userName)) {

            cout << "\nEnter your Password : ";
            cin >> Password;

            if (file.is_open()) {
                file << userName << " " << Password << endl;
                cout << endl;
                cout << endl;

                cout << "\n         Sucessfully Registered\n";
                cout << "\t--------------------------------\n";
                cout << endl;
                cout << endl;


                file.close();
                break;
            } else {

                cout << endl;
                cout << endl;

                cout << "\n         Registered Unsuccessful\n";
                cout << "\t--------------------------------\n";
                cout << endl;

                break;

            }
        } else {
            cout << "\n         Username Already Exist!\n\n";
            cout << "         Try different Username\n";
            cout << "\t--------------------------------\n";
        }
    }

}




void UserLogin::login(const string& userName, string Password) {

    ifstream file("records.txt");

    string cUserName, cPassword;


    int count = 0;
    while(file >> cUserName >> cPassword){
        if(userName == cUserName && Password == cPassword){
            count ++;
        }
    }
    file.close();
    if(count == 1){
        cout << endl;
        cout <<"\n  \t\t    Login Successful!  \n";
        cout << "\t--------------------------------\n";
        cout << endl;
    }else{

        cout << endl;
        cout <<"\n  \t\t    Login UnSuccessful!  \n";
        cout << "\t--------------------------------\n";

        cout << "\t        Please try Again!\n";


        }



    }









bool UserLogin::isRegistered(const string& username) {

    ifstream file("records.txt");

    string cUsername, cPassword;

    while(file>>cUsername>> cPassword){

        if(username == cUsername){
            return true;
        }
    }
    return false;
}




void UserLogin::welcome() {


        cout << "\t\t" <<"  W   W  EEEEE  L      CCCCC  OOOO   M     M  EEEEE" <<endl;
        cout << "\t\t"<< "  W   W  E      L     C      O    O  MM   MM  E" << endl;
        cout << "\t\t"<< "  W W W  EEEE   L     C      O    O  M M M M  EEEE" <<endl;
        cout << "\t\t"<< "  W W W  E      L     C      O    O  M  M  M  E" <<endl;
        cout << "\t\t"<< "   W W   EEEEE  LLLLL  CCCCC  OOOO   M     M  EEEEE" << endl;

        cout << endl;

    cout << "         --------------------------------------------------\n";
    cout << "\t\t"<<" |        Login and registration System           |\n";
    cout << "         --------------------------------------------------\n";
}





void UserLogin:: ResetPassword(string name) {

    cout <<"\n          Reset your Password\n";
    cout << "\t--------------------------------\n";


    string password;
    cout << "Please Enter your Username : ";
    cin >> name;

    if(!UserLogin::userExist(name)){
cout << "Enter New Password : ";
    cin >> password;
        vector<string> userData;

        string cData;
        ifstream file("records.txt");

        while(file >> cData){
            userData.push_back(cData);
        }

        for(int i=0; i< userData.size(); i++){
            if(userData[i] == name){
                userData[i+1] = password;
            }
        }


        ofstream newfile("records.txt");

        int x =0;
        int y = 1;
        for(int i=0; i<userData.size(); i++){
            if( y < userData.size()){
                newfile<< userData[x] << " " << userData[y] <<endl;
                x=x+2;
                y = y+2;
            }
        }
        cout <<"\n       Password Reset Successful\n";
        cout << "\t--------------------------------\n";
    }else{
            cout<< "\n          User Name not found! \n";
            cout << "\t--------------------------------\n";
            cout << "      Please Register an Account\n";
        }
}

bool UserLogin:: userExist(const string& name) {
    string cName, cPass;
    ifstream file("records.txt");

    while(file>>cName>>cPass){
        if(name == cName){
            return false;
        }
    }return true;


}
