#pragma once
#include <vector>
#include "User.h"

using namespace std;

class Admin : public User
{
public:
	Admin() : User() { this->rank = 'a'; }
	~Admin();
};