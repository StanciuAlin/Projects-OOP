#include "Network.h"
#include "Admin.h"
#include "User.h"
#include <iostream>

int main()
{
	Network *net = new Network();
	char option_user = 'y';
	while (net->Get_size_network() < 12 && option_user == 'y')
	{
		std::cout << "Tipul utilizatorului \'a\' - admin sau \'u\' - utilizator normal\n Optiunea aleasa este   ";
		std::cin >> option_user;
		switch (option_user)
		{
		case 'a':
		{
			std::cout << "Introduceti datele utilizatorului admin:\n";
			Admin *user = new Admin();
			if (!net->connect_user('a'))
			{
				cout << "Nu pot exista doi admini intr-o retea unica!\n";
				break;
			}
			char option;
			cout << "Ca admin puteti vizualiza toti utilizatorii retelei si puteti deconecta unul sau mai multi utilizatori! Daca doriti apasati \'v\' pentru vizualizare sau \'d\' pentru a deconecta.\n";
			cout << "Doriti sa efectuati una din operatii? y/n\n";
			cin >> option;
			if (option == 'n')
			{
				break;
			}
			else
			{
				cout << "Optiunea aleasa este: \n";
				cin >> option;
				switch (option)
				{
				case 'v':
				{
					net->view_all_users();
					break;
				}
				case 'd':
				{
					int no_users = 0;
					vector<User> users_for_disconnect;
					cout << "Numarul de utilizatori deconectati este: ";
					cin >> no_users;
					for (int i = 0; i < no_users; i++)
					{
						User *user = new User();
						user->Read_data_user();
						users_for_disconnect.push_back(*user);
						delete user;
					}
					net->disconnect_user(users_for_disconnect);
					//users_for_disconnect.clear();
					users_for_disconnect.resize(0);
					break;
				}
				default:
					break;
				}
			}
			delete user;
			break;
		}
		case 'u':
		{
			char option = 'y';
			while (net->Get_size_network() < 11 && option == 'y')
			{
				std::cout << "Introduceti datele utilizatorului nou? y/n\n";
				
				cin >> option;
				switch (option)
				{
				case 'y':
				{
					User *user = new User();
					if (!net->connect_user('u'))
					{
						break;
						cout << "Nu te-ai putut conecta!\n";
					}
					else
					{
						cout << "Conectare cu succes!\n";
					}
					break;
				}
				case 'n':
				{
					break;
				}
				}
			}
			net->Warning_message(net->Get_size_network());
			break;
		}
		default:
			break;
		}
		cout << "Continuati sesiunea de adaugat useri? y/n\n";
		cin >> option_user;
	}
	net->Warning_message();
	Admin admin;
	int adm_search = 0;
	net->Search_admin(adm_search);
	if (!adm_search)
	{
		cout << "Nu exista admin al retelei\n";
	}
	else
	{
		net->view_all_users();
	}
	return 0;
}