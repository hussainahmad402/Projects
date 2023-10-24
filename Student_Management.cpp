#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void input_user();
void input_record();
void show_data();
int main()
{
	int chose;
	cout << "Press 1 to input for username & password:" << endl;
	cout << "Press 2 to input the record of the student" << endl;
	cout << "Press 3 to show the record of the student" << endl;
	cout << "Press 4 to Exit" << endl;
	cin >> chose;
	switch (chose)
	{
	case 1:
		input_user();
		break;
	case 2:
		input_record();
		break;
	case 3:
		show_data();
		break;
	case 4:
		exit(0);
	}
	return 0;
}
void input_user()
{
	string username;
	string password;
	ofstream input_username;
	input_username.open("username.txt"); // file for storing the username and password
	for (int i = 0; i < 2; i++)			 // Taking input of username , password
	{
		cout << "Enter Username: ";
		cin >> username;
		input_username << username << "\t";
		cout << "Enter Password: ";
		cin >> password;
		input_username << password << "\t" << endl
					   << endl;
	}
	input_username.close();
	main();
}
void input_record()
{
	string username;
	string password;
	string name;
	int roll;
	int semester;
	int age;
	float cgpa;
	ofstream input_data;
	input_data.open("data.txt"); // file for storing the student record
	for (int i = 0; i < 2; i++)	 // Taking input of student Record
	{
		cout << "Enter Username: ";
		cin >> username;
		input_data << username << "\t";
		cout << "Enter Name: ";
		cin >> name;
		input_data << name << "\t";
		cout << "Enter Roll Number: ";
		cin >> roll;
		input_data << roll << "\t";
		cout << "Enter Semester: ";
		cin >> semester;
		input_data << semester << "\t";
		cout << "Enter Age: ";
		cin >> age;
		input_data << age << "\t";
		cout << "Enter CGPA: ";
		cin >> cgpa;
		input_data << cgpa << "\t" << endl;
	}
	input_data.close();
	main(); // Returning to the main function
}
void show_data() // Show the student record
{
	string username;
	string password;
	string name;
	int roll;
	int semester;
	int age;
	float cgpa;
	ifstream out_username;
	ifstream out_data;
	out_username.open("username.txt");
	out_data.open("data.txt");
	string checkuser;
	string checkpasword;
	cout << "Enter the username: ";
	cin >> checkuser;
	cout << "Enter the password: ";
	cin >> checkpasword;
	bool found=false;

	while (out_username >> username >> password)
	{
		if (username == checkuser && password == checkpasword) // check the username & password are match or not
		{
			found=true;
			cout << "\t\t\t\t\tUser Found" << endl;
			cout << "\t\t\t\t_____________________________" << endl;

			while (out_data >> username >> name >> roll >> semester >> age >> cgpa)
			{
				if (username == checkuser) // Read the student data from the record file
				{
					cout << "\t\t\t\t\tName: " << name << endl;
					cout << "\t\t\t\t\tRoll Number: " << roll << endl;
					cout << "\t\t\t\t\tSemester: " << semester << endl;
					cout << "\t\t\t\t\tAge: " << age << endl;
					cout << "\t\t\t\t\tCGPA: " << cgpa << endl;
					cout << endl;
				}
			}

			break;
		}
	}
	out_data.close();
	if(found==false)
	{
		cout<<endl<<"\t\t\t\t\tInvalid Username or Password"<<endl<<endl;
	main();
}
