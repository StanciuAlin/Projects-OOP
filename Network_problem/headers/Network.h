#pragma once
#include "Admin.h"
#include "User.h"
#include <vector>
using namespace std;

class Network
{
	friend class Admin;
	vector<User> network;
public:
	Network();
	~Network();
	bool connect_user(char rank_user);
	void view_all_users();
	bool disconnect_user(vector<User> users);
	int Get_size_network() { return network.size(); }
	void Warning_message();
	void Warning_message(int type_warning);
	Admin Search_admin(int& admin_found);
private:
	bool find_admin(char rank_user); //search if exist another admin
	bool Add_user(User *user);
	bool Add_user(Admin *user);
};