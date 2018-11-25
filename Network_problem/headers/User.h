#pragma once
#include <string>
using namespace std;
class User
{
protected:
	string name; //user name
	string password; //user password
	bool connected_status; //true if user is connected and false if user is disconnected
	char rank = 'u'; //'a' allias for admin and 'u' allias for common user
public:
	User() : password(""), name(""), connected_status(false) {};
	~User();

	//getter
	char Get_rank() { return rank; }
	bool Get_connected_status() { return connected_status; }
	string Get_name() { return name; }
	string Get_password() { return password; }
	//setter 
	void Set_rank(char new_rank) { this->rank = new_rank; }
	void Set_connected_status(bool new_connected_status) { this->connected_status = new_connected_status; }
	void Set_name(string new_name) { this->name = new_name; }
	void Set_password(string new_password) { this->password = new_password; }
	
	void Read_data_user();
};