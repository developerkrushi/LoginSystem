#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsloggedIn();
void SignUp();

int main(){

    int choice;

    cout<<"1.Sign Up\n2.Sign In\n\nPlease select your option: "; cin>>choice;

    if(choice == 1)
        SignUp();
    else if(choice == 2){
        bool status = IsloggedIn();

        if(status == true){
            cout<<"Successful Sign In!\n";
            system("PAUSE");
            return 0;
        }
        else{
            cout<<"Sign In failed!\n";
            system("PAUSE");
            return 1;
        }
    }
    
}

void SignUp(){
    string username, password;
    cout<<"Enter Username: "; cin>>username;
    cout<<"Enter Password: "; cin>>password;
    ofstream file;
    file.open("data\\" + username + ".txt");
    file<<username<<endl<<password;
    file.close();
    main();
}

bool IsloggedIn(){
    string username, password, un, pass;

    cout<<"Enter Username: "; cin>>username;
    cout<<"Enter Password: "; cin>>password;

    ifstream read("data\\" + username + ".txt");
    getline(read, un);
    getline(read, pass);

    if(un == username && pass == password)
        return true;
    else
        return false;
}