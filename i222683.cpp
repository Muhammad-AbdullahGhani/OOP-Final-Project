
#include <iostream>
#include<Windows.h>
#include <conio.h>
#include<fstream>
#include<string>
#include<ctime>
#include"i222683.h"
using namespace std;
int main() {
    char loginid[20];
    char loginpass[20];
    friendclass fri;
    char text[100];
    int regcheck = 0;
    int findcheck = 0;
    int check;
    char finduser[100];
    Post p;
    int cha;
    Groupchat gp;
    bool upper = false;
    bool lower = false;
    char verf[20];
    bool num = false;
    bool l = false;
    bool len = false;
    bool checkblank = false;
    Message m;
    user ob;
    int ch = 0;
    displaying d;
    char choice;
    int c = 0;
    int op = 0;
    int choose;
    comments cm;
    char blank = ' ';
   
    do {
        cout << "-----------------------------------------\n";
        cout << "Do you want to register again or login \nPress 1 to register or else \nPress 0 to login\nPress 2 for forgot password or Press 9 to exit" << endl;
        cin >> op;
        if (op == 1) {
           
                cout << "Enter your name\n";
                cin >> loginid;
                ob.setname(loginid);
                cout << "Enter your Password\n Password must contain uppercase lower case number and minimun length of 6\n";
                cin >> loginpass;
                for (int i = 0; loginpass[i] != '\0'; i++) {
                    if (isupper(loginpass[i])) {
                        upper = true;
                    }
                    if (islower(loginpass[i])) {
                        lower = true;
                    }
                    if (isdigit(loginpass[i])) {
                        num = true;
                    }
                    if (loginpass[i] > 6) {
                        len = true;

                    }
                    if (loginpass[i] != blank) {
                        checkblank = true;
                    }
                }
                if (upper && lower && num && len&&checkblank) {
                    regcheck = ob.registerUser(loginid, loginpass);
                }

                if (regcheck == 1) {
                    cout << "you have been registered\n";
                }
                else {
                    cout << "Registeration failed\n";
                }
            
        }
        else if (op == 0) {

            cout << "Enter your name\n";
            cin.ignore();
            cin >> loginid;
            cout << "Enter your Password\n ";
            cin >> loginpass;
            for (int i = 0; loginpass[i] != '\0'; i++) {
                if (isupper(loginpass[i])) {
                    upper = true;
                }
                if (islower(loginpass[i])) {
                    lower = true;
                }
                if (isdigit(loginpass[i])) {
                    num = true;
                }
                if (loginpass[i] > 6) {
                    len = true;
                }
                if (loginpass[i] != blank) {
                    checkblank = true;
                }
            }
            if (upper && lower && num && len&&checkblank) {
                check = ob.login(loginid, loginpass);
            }
            else {
                cout << "Password doesnot meet requirments";
                break;
           }

            if (check == 1) {
                cout << "Successfully loggedin";
                cout << "\n";
            }
            else {
                cout << "Couldnot login" << endl;
            }
            cout << "Enter the name of the user to find" << endl;
            cin.ignore();
            cin >> finduser;
            findcheck = ob.findUser(finduser);
            if (findcheck == 1) {
                cout << "User found" << endl;
                cout << "Do you want to send friend Request\nPress 1 to send else press 0" << endl;
                cin >> c;
                if (c == 1) {
                    fri.setfriendname(finduser);


                }
                cout << "1)Check friend Requests" << endl;
                cout << "2)Posts" << endl;

                cout << "3)Display Posts" << endl;
                cout << "4)Update Information" << endl;
                cout << "5)Send Message" << endl;
                cout << "6)GroupChats\n";
                cout << "7)Forgot Password\n";
                cin >> choose;
                if (choose == 1) {
                    fri.getrequest();
                }
                else
                    if (choose == 2) {
                        p.posting();

                    }
                    else if (choose == 3) {
                        d.showpost();
                        cm.writecomment();
                    }
                    else if (choose == 4) {
                        // system("CLS");
                        ob.updateinfo(loginid, loginpass);
                    }
                    else if (choose == 5) {

                        do {
                            cout << "\nPress 1 to text else press 0\n";
                            cin >> ch;
                            cout << "Enter the name of the user to find\n";
                            cin.ignore();
                            cin >> finduser;
                            findcheck = ob.findUser(finduser);
                            if (findcheck) {
                                cout << "Enter the text" << endl;
                                cin.ignore();
                                cin.getline(text, 100);
                                ofstream fs("Message.txt", ios::binary | ios::app);
                                if (!fs.is_open()) {
                                    cout << "Cant open file\n";
                                    return false;
                                }
                                else {

                                    fs.write((char*)&text, sizeof(text));
                                    fs << '\n';
                                }
                                cout << m.getfriendname(finduser);
                                m.setmessage(text);
                                m.displaymessage(text);


                            }
                            else {
                                cout << "user not found" << endl;
                                break;
                            }



                            }while (ch != 0);
                        }
                    
            

                    else if (choose == 6) {

                        gp.groupchats(loginid);

                        break;

                    }
                   
            }
          
            else {
                cout << "Cant find user" << endl;
            }



        }
        else if (op == 2) {
            cout << "Enter your name for verification" << endl;
            cin >> verf;
            ob.forgotpassword(verf);
        }

    } while (op != 9);



    return 0;
}
