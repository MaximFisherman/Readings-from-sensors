#pragma once
#include "stdafx.h"
class MongoDB
{
public:
	MongoDB(const char* _uri_str);
	bool addCollection(const char* strCollection);
	~MongoDB();

private:
	const char *uri_str;
	mongoc_client_t *client;
	mongoc_database_t *database;

	char *str;
	bool retval;
};

