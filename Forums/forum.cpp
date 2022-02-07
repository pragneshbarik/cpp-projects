#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int confirm(){
    int x = 0;
    cout << "press 1 to confirm, else 0 : ";
    cin >> x;
    return x;
}

void mask(){
    cout << "\n----------------------------------------------------------"<<endl;
}

class post{
    public:
        string post;
        void record(string text, string username){
            ofstream forum("posts.txt");
            string text_f = "";
            text_f += text;
            text_f += " <<<" + username + "\n\n";
            forum << text_f;
            forum.close();
        }

        int write(string poster){
            string text;
            cout << "New Post : ";
            cin >> text;
            post = text;
            user = poster;
            if (confirm()){
                cout << "Posted successfully !";
                record(post,user);
                print();
            }
            else{
                cout << "Post unsuccesful";
            }
        }
        void print(){
            string posts;

            ifstream forum("posts.txt");

            while(getline(forum,posts)){
                cout << posts;
            }
        }
    private:
        string user;
};

class user{
    public:
        int signup(){
            string name_s;
            string password_s;
            cout << "Enter username : ";
            cin >> name_s;
            cout << "Enter password : " ;
            cin >> password_s;
            if (name_s == name && password == password_s){
                cout << "login successful"<< endl;
                return 1;
            }
            else {
                cout << "login error! access denied" << endl;
                return 0;
            }
        }

    private:
        const string name= "Ansah";
        const string password = "Ansah123";

};

int main(){
    user user;
    post thread;
    string user_name;
    int login = user.signup();
    while (login)
    {
        user_name = "Ansah";
        /*
        string x;
        cout << "\nPress any key to start"<< endl;
        cin >> x;
        */
        int menu;
        mask();
        cout << " Welcome to SVNIT FORUMS \n" << endl;
        mask();
        cout << "press the index:\n 1) Read posts \n 2) make a post \n 3) Quit" << endl;
        cout << ":";
        cin >> menu;
        mask();
        if (menu ==1 ){
            thread.print();
        }
        else if (menu == 2){
            thread.write(user_name);
        }
        else if (menu == 3){
            login = 0;
        }  
    }

}
