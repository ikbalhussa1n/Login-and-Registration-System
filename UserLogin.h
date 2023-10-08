//
// Created by Ikbal Hussain on 10/4/23.
//

#ifndef LOGIN_AND_REGISTRATION_SYSTEM_USERLOGIN_H
#define LOGIN_AND_REGISTRATION_SYSTEM_USERLOGIN_H
#include <iostream>
using namespace std;

class UserLogin {
public:

    void Registration(string userName, string Password);

    static  void login(const string& userName, string Password);

    static bool isRegistered(const string& username);



     static void welcome();



    void ResetPassword(string name);


    static bool userExist(const string& name);




};



#endif //LOGIN_AND_REGISTRATION_SYSTEM_USERLOGIN_H
