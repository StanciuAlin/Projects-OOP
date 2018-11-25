#include "Network.h"
#include <iostream>

Network::Network()
{
}

Network::~Network()
{
}

bool Network::connect_user(char rank_user)
{
	switch (rank_user)
	{
	case 'a':
	{
		Admin *admin = new Admin();
		admin->Read_data_user();
		if (!find_admin(rank_user))
		{
			admin->Set_connected_status(true);
			this->Add_user(admin);
			delete admin;
			return true;
		}
		return false;
		//break;
	}
	case 'u':
	{
		User *user = new User();
		user->Read_data_user();
		user->Set_connected_status(true);
		this->Add_user(user);
		delete user;
		return true;
		//break;
	}
	default:
		break;
	}
	return false;
}

bool Network::Add_user(User *user)
{
	if (!find_admin(user->Get_rank()))
	{
		Network::network.push_back(*user);
		return true;
	}
	else
	{
		std::cout << "Nu pot exista doi admini pentru o retea!\n";
		return false;
	}
}

bool Network::Add_user(Admin *user)
{
	if (!find_admin(user->Get_rank()))
	{
		Network::network.push_back(*user);
		return true;
	}
	else
	{
		std::cout << "Nu pot exista doi admini pentru o retea!\n";
		return false;
	}
}

bool Network::find_admin(char rank_user)
{
	for (int i = 0; i < Network::network.size(); i++)
	{
		if (rank_user == 'a')
		{
			return true;
		}
	}
	return false;
}

void Network::view_all_users()
{
	cout << "\n\n***************************Lista utilizatori retea**************************************\n";
	for (int i = 0; i < Network::network.size(); i++)
	{
		cout << "\nUser " << i << "\nName: " << Network::network[i].Get_name() << "\n" << "Password: " << Network::network[i].Get_password() << "\n" << "Status: " << Network::network[i].Get_connected_status() << "\n" << "Rank in network: " << Network::network[i].Get_rank() << "\n";
	}
}


bool Network::disconnect_user(vector<User> users)
{
	for (int i = 0; i < users.size(); i++)
	{
		for (int j = 0; j < Network::network.size(); j++)
		{
			if (users[i].Get_name() == Network::network[j].Get_name() && users[i].Get_password() == Network::network[j].Get_password() && users[i].Get_rank() == Network::network[j].Get_rank() && users[i].Get_connected_status() == Network::network[j].Get_connected_status())
			{
				Network::network[j].Set_connected_status(false);
			}
		}
	}
	return false;
}

void Network::Warning_message()
{
	cout << "S-a atins numarul maxim de utilizatori acceptati in retea (impreuna cu administratorul) sau se doreste iesirea din modul adaugare utilizatori.\n";
}

void Network::Warning_message(int type_warning)
{
	cout << "S-a atins numarul maxim de utilizatori acceptati in retea sau nu se doreste intrarea altor utilizatori!\n";
}

Admin Network::Search_admin(int& admin_found)
{
	for (int i = 0; i < network.size(); i++)
	{
		if (network[i].Get_rank() == 'a')
		{
			admin_found = 1;
			return Admin();
		}
	}
	admin_found = 0;
}

