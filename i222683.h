#pragma once
using namespace std;
class friendclass {
    char name[20];
    char friendname[20];
    char friendarray[100];
    bool frn;
public:
    void setfriendname(const char* newName) {
        strcpy_s(friendname, newName);
        name[sizeof(friendname) - 1] = '\0';
    }

    const char* getfriendname() const {
        return friendname;
    }

    void getrequest() {
        cout << "You got friend request from " << friendname << endl;
        cout << "Press 1 to accept or 0 to decline" << endl;
        int option = 0;
        cin >> option;
        if (option == 1) {
            cout << "Friend Request Accepted";
            frn = true;
            strcpy_s(friendarray, friendname);
            friendarray[sizeof(name) - 1] = '\0';
            return;
        }
        else {
            cout << "Friend Reuqest declined" << endl;
            return;
        }

    }
    bool confirmfriend() {
        return frn;
    }
    void setfriendmessage(char* mess) {
        int i = 0;
        for (; mess[i] != '\0'; i++) {
            friendarray[i] = mess[i];
        }
        friendarray[i] = '\0';
    }
    char* getfriendmessage() {
        return friendarray;
    }

};

class user {
    char userid[20];
    char name[20];
    char email[20];
    char password[20];
    int birthdate;
    friendclass* frnd;
    char loginid[20];
    char loginpass[20];
    char data[20];
public:
    int red = 12;
    void setUserId(const char* newUserId) {
        strcpy_s(userid, newUserId);
        userid[sizeof(userid) - 1] = '\0';
    }
    const char* getUserId() const {
        return userid;
    }

    void setname(const char* newName) {
        strcpy_s(name, newName);
        name[sizeof(name) - 1] = '\0';
    }

    const char* getname() const {
        return name;
    }


    void setpassword(const char* newPassword) {
        strcpy_s(password, newPassword);
        password[sizeof(password) - 1] = '\0';
    }

    const char* getpassword() const {
        return password;
    }


    void showprofilepic() {
        // string userProfilePic = "C:\\Users\\hp\\OneDrive\\Desktop\\c++\\pics\\Desktop-Wallpaper-4k-Cars.png";
        string imgpath;
        string picname;
        picname = "image.jpg";
        fstream ifile;
        cout << "Enter image path" << endl;
        cin >> imgpath;
        ifile.open(imgpath, ios::binary | ios::in);
        if (!ifile.is_open()) {
            cout << "Cant open file" << endl;
            return;
        }
        ofstream oimage(picname, ios::binary | ios::out);
        oimage << ifile.rdbuf();
        oimage.close();
        system("Image.jpg");
        cout << "Enter new Path of the image\n";
        cin >> imgpath;
        ifile.open(imgpath, ios::binary | ios::in);
        if (!ifile.is_open()) {
            cout << "Cant open file" << endl;
            return;
        }
        ofstream outimg(picname, ios::binary | ios::out);
        outimg << ifile.rdbuf();
        outimg.close();
        ifile.close();
        system("Image.jpg");
    }





    void updateinfo(const char* id, const char* pass) {
        int option;
        int i = 0;
        char arr[20];

        bool c;
        c = false;
        fstream fs;
        // system("CLS");
        char key;
        bool check;
        check = true;
        cout << "1)To Update Password\n";
        cout << "2)To Update Username\n";
        cout << "3)To Update Profile Pic\n";
        cin >> option;
        switch (option) {
        case 1:
            char newpass[20];
            cout << "Enter Your old password" << endl;
            cin.ignore();
            cin >> arr;
            cout << "Enter new password" << endl;
            cin >> newpass;
            fs.open("./credential.dat", ios::binary | ios::in | ios::out);
            fs << id << '|' << newpass << "\n";
            c = true;

                if (c) {
                    cout << "Password Updated";
                }

                break;

        case 2:
            char newname[20];
            cout << "Enter Your old name" << endl;
            cin.ignore();
            cin >> arr;
            cout << "Enter new na,e" << endl;
            cin >> newname;
            fs.open("./credential.dat", ios::binary | ios::in | ios::out);
            fs << newname << '|' << pass << "\n";
            c = true;

            if (c) {
                cout << "Password Updated";
            }


            break;

        case 3:
            showprofilepic();

            break;



            }

        }
    
    bool forgotpassword(char* f) {
        fstream file;
        char name[20];
        string pass;
        bool cond;
        
        char* c;
        char* l;
        file.open("credential.txt", ios::binary | ios::in);
        if (file.is_open() == 0) {
            cout << "Cannot open file" << endl;
            return false;
        }
        for (; file.read((char*)&name, sizeof(name)) &&
            file>>pass;) {
            c = name;
           
            if (*c == *f) {
                cond = true;
            }

        }
        if (cond) {
            cout << "Your password is" << pass<<endl;
        }
        else {
            cout << "Cant find your password";
        }
    }

    int login(const char* userid, const char* password) {
        char user[20];
        char pass[20];
        fstream f;
        int check;
        char* p;
        char* z;
        f.open("credential.txt", ios::binary | ios::in);
        if (f.is_open() == 0) {
            cout << "Cannot open file" << endl;
            return 0;
        }
        
      
        for (; f.getline(user, 20, '|') &&
            f.getline(pass, 20);) {
            p = user;
            z = pass;
            while (*p != '\0' && *z != '\0') {
                if (*p == *userid && *z == *password) 
                    check = 1;
                break;
            }
           
        }

        f.close();

        if (check==1) {
            cout << "Login successful!" << endl;
            return 1;
        }
        else {
            cout << "Invalid Password" << endl;
            return 0;
        }
    }
    int findUser(const char* n) {
        int d;
        fstream fs;
        fs.open("credential.txt", ios::binary | ios::in);
        if (fs.is_open() == 0) {
            cout << "Cannot open file" << endl;
            return false;
        }
        d = 0;
        char User[20];
        const char* p;

        while (fs.getline(User, 20, '|')) {
            p = User;
            while (*p != '\0') {
                if (*p == *n)
                    d = 1;
                break;
            }
            fs.ignore(100, '\n');
        }
        fs.close();
        return d;
    }


    bool registerUser(const char* userid, const char* password) {
        fstream reg;

        reg.open("credential.txt", ios::binary | ios::app | ios::out);
        if (reg.is_open() == 0) {
            cout << "Cannot Open file\n";
            return false;
        }
        reg << userid << '|' << password << "\n";


        reg.close();
        return true;
    }






};
class Message {
    char message[100];

public:
    Message() {

    }
    Message(char* m) {
        int i = 0;
        for (; i != '\0'; i++) {
            message[i] = m[i];
        }
        message[i] = '\0';
    }
    void usermessage() {
        cout << "Enter Message " << endl;
        cin.getline(message, 100);

    }
    const char* getname(user& userfriend) {

        return userfriend.getname();
    }
    const char* getfriendname(char* name) {

        return name;
    }
    void setmessage(char* mess) {
        int i = 0;
        for (; i != '\0'; i++) {
            message[i] = mess[i];
        }
        message[i] = '\0';
    }
    char* getmessage() {
        return message;
    }
    void displaymessage(string txt) {
        fstream fs;
        fs.open("./Message.txt", ios::binary | ios::in);
        if (fs.is_open() == 0)
        {
            cout << "Cannot open file";
        }
        else
        {
            while (!'\n')
                getline(fs, txt);
            cout << "\t\t\t\t" << txt
                ;
        }
    }


};
class Groupchat {

public:
    void groupchats(char* n) {
        fstream f;
        int cha = 0;
        string text;
        f.open("./group.txt", ios::binary| ios::app);
        if (f.is_open() == 0)
        {
            cout << "Cannot open file";
        }
        else
        {
                cout << "Enter the text" << endl;
                cin.ignore();
                getline(cin, text)
                    ;
                f.write((char*)&text, sizeof(text));
                f << '\n';
                        
        }

        int i = 0;
        while (f.read((char*)&text, sizeof(text)) ) {
            cout << text;
            
        }
        

           
        
        
    }

};
class displaying {
protected:
    int like;
    int dislike;
    user username;
    string content;
    struct tm newtime;
    int postid = 100;
    int nooflikes;
    friendclass* fr;
    string comment;
    time_t tm;
    char* disptime;
public:
    virtual void showpost() {
        tm = time(0);
        disptime = ctime(&tm);
        fstream f;
        string txt;
        f.open("./content.txt", ios::binary | ios::in);
        if (!f.is_open()) {
            cout << "Cannot open file for reading";
            return;
        }
        cout << "Content:" << endl;
        for (; getline(f, txt);) {
            cout << txt << endl;
        }
        cout << "\t\t\t" << "Time: " << disptime;
        cout << "\n";    
        cout << "\nPress 1 to like or press 0 to dislike" << endl;
        cin >> nooflikes;
        if (nooflikes == 1) {
            like++;
        }
        else {
            dislike++;
        }
        cout << "Likes:" << like << "\t\t\t" << "Dislikes:" << dislike;

    }





};

class Post :public displaying {

    char postuser[20];
    user u;
public:
    void posting() {
        fstream fs;
        cout << "Enter the content you want to post" << endl;
        cin.ignore();
        getline(cin,content);
        fs.open("./content.txt", ios::binary | ios::app);
        if (!fs.is_open()) {
            cout << "Cannot open file for writing";
        }
        else {
            fs << content << '\n';
        }
        fs.close();

    }


};
class likes :public displaying {
public:

    likes() {
        like = 0;
        dislike = 0;
    }

    int operator++() {
        like++;
    }
    int operator++(int dislike) {
        this->dislike++;
    }
};
class comments :public displaying {

public:
    fstream fl;
    void getcomment(string cmnt) {
        cmnt = comment;
    }
    void writecomment() {
        cout << "Write comment on the post" << endl;
        cin >> comment;


        fl.open("./content.txt", ios::binary | ios::app);
        if (!fl.is_open()) {
            cout << "Cannot open file for writing";
        }
        else {

            fl.write((char*)&comment, sizeof(comments));
        }
        fl.close();
    }


};