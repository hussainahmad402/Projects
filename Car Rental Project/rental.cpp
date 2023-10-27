
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// To check the car list first we enter the car name, car model and the car price/km in the "car_detail" file than it can show the list of the availaable car otherwise the list can't show


#include <iostream>
#include <string>
#include <fstream>  //this library is used for the file handling
#include <stdlib.h> //this library is added to use the "system" function in the code
using namespace std;
void menu();
void check_login();
void car_list();
void book_car();
void show_data();

int main()
{
    check_login();
    menu();
    return 0;
}
void check_login() // function for the login
{
    string username;
    int password;
    string checkusername;
    int checkpassword;
    cout << "Enter Username: ";
    cin >> checkusername;
    cout << "Enter Password: ";
    cin >> checkpassword;
    bool found = false;
    ifstream checklogin;
    checklogin.open("username.txt");
    ofstream Username;
    Username.open("username.txt", ios::app);
    while (checklogin >> username >> password)
    {
        if (checkusername == username && checkpassword == password)
        {
            found = true;
            checklogin.close();
            system("CLS"); // this is the function on "stdlib" library to clear the previous content on the console
        }
    }

    checklogin.close();
    if (found == false)
    {
        Username << checkusername;
        Username << "\t\t" << checkpassword << endl;

        Username.close();
        system("CLS"); // this is the function on "stdlib" library to clear the previous content on the console
    }
}
void menu()
{
    cout << "\t\t\t\t\tWELCOME TO THE CAR RENTAL SERVICE" << endl
         << endl;
    cout << "press 1 to show the all available car list" << endl;
    cout << "press 2 for the booking of car" << endl;
    cout << "press 3 to see the data of the user" << endl;
    cout << "press 4 for the exit menu" << endl;
    int menu;
    cin >> menu;
    switch (menu)
    {
    case 1:
        car_list();
        break;
    case 2:
        book_car();
        break;
    case 3:
        show_data();
    case 4:
        exit(0);
        break;
    }
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// To check the car list first we enter the car name, car model and the car price/km than it can show the list of the availaable car


void car_list() // function for checking the car list
{
    system("CLS");
    string name;
    int model;
    int price;
    cout << "\t\tName"
         << "\t\tModel"
         << "\t\tPrice/KM" << endl;
    ifstream cardetail;
    cardetail.open("car_detail.txt");
    while (cardetail >> name >> model >> price)
    {
        cout << "\t\t" << name << "\t\t" << model << "\t\t" << price << endl;
    }

    cardetail.close();
    char get;
    cout << endl
         << "Do You Want To Exit (y/n): ";
    cin >> get;
    if (get == 'y')
    {
        exit(0);
    }
    else if (get == 'n')
    {
        system("CLS");
        menu();
    }
}
void book_car() // function for the booking the cara
{
    system("CLS");
    string carname;
    string checkname;
    int carmodel;
    int checkmodel;
    int price;
    int km;
    string name;
    string phone;
    string cnic;
    string date;
    string address;
    char get;
    ofstream data;
    ifstream cardetail;
    bool found = false;
    data.open("detail.txt", ios::app);
    cardetail.open("car_detail.txt");
    cout << "Car Name: ";
    cin >> checkname;
    cout << "Car Model: ";
    cin >> checkmodel;
    while (cardetail >> carname >> carmodel >> price)
    {
        if (checkname == carname && checkmodel == carmodel)
        {
            found = true;
            cout << "CNIC: ";
            cin >> cnic;
            data << cnic << "\t\t";
            cout << "Name: ";
            cin >> name;
            data << name << "\t\t";
            cout << "Contect: ";
            cin >> phone;
            data << phone << "\t\t";
            cout << "Address: ";
            cin >> address;
            data << address << "\t\t";
            cout << "Date: ";
            cin >> date;
            data << date << "\t\t";
            data << carname << "\t\t";
            data << carmodel << "\t\t";
            cout << "How many kilometers are you asking for? ";
            cin >> km;
            price = price * km;
            data << price << endl;
            // cout << endl;
            cout << "According to your car name & model and the Kilometer you entered your price will be: " << price << endl;
        }
    }
    if (found == false)
    {
        cout << "Car or Model is not available" << endl;
    }
    cardetail.close();

    cout << endl
         << "Do You Want To Exit (y/n): ";
    cin >> get;
    if (get == 'y')
    {
        exit(0);
    }
    else if (get == 'n')
    {
        system("CLS");
        menu();
    }
}
void show_data() // function for seeing the data of the booking person
{
    system("CLS");
    string checkcnic;
    string carname;
    int carmodel;
    int price;
    int km;
    string name;
    string phone;
    string cnic;
    string date;
    string address;
    ifstream data;
    data.open("detail.txt");
    bool found = false;
    cout << "Enter CNIC: ";
    cin >> checkcnic;
    while (data >> cnic >> name >> phone >> address >> date >> carname >> carmodel >> price)
    {
        if (checkcnic == cnic)
        {
            found = true;
            cout << "\t\t\t\t\tCNIC:\t\t" << cnic << endl;
            cout << "\t\t\t\t\tName:\t\t" << name << endl;
            cout << "\t\t\t\t\tContect:\t" << phone << endl;
            cout << "\t\t\t\t\tAddress: \t" << address << endl;
            cout << "\t\t\t\t\tBooking Date:\t" << date << endl;
            cout << "\t\t\t\t\tCar Name:\t" << carname << endl;
            cout << "\t\t\t\t\tCar Model:\t" << carmodel << endl;
            cout << "\t\t\t\t\tBooking Price:\t" << price << endl;
        }
    }
    if (found == false)
    {
        cout << "\t\t\t\t\tUser Not Found!!!" << endl;
    }
    char get;
    cout << endl
         << "Do You Want To Exit (y/n): ";
    cin >> get;
    if (get == 'y')
    {
        exit(0);
    }
    else if (get == 'n')
    {
        system("CLS");
        menu();
    }
}
