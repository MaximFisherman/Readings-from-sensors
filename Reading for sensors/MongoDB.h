#pragma once
#include "stdafx.h"
using namespace std;

class MongoDB
{
public:
	MongoDB(const char* _uri_str);
	void addCollection(const char* nameCollection, const char* nameSensor, const char* valueSensor);
	void deleteCollection(const char* nameCollection);
	~MongoDB();

private:
	const char *uri_str;
	mongoc_client_t *client;
	mongoc_database_t *database;
	mongoc_collection_t *collection;

	char *str;
	bool retval;
};

