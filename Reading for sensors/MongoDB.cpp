#include "stdafx.h"
#include "MongoDB.h"


MongoDB::MongoDB(const char* _uri_str) : uri_str(_uri_str)
{
}

void MongoDB::deleteCollection(const char* nameCollection)
{
	mongoc_client_t *client;
	mongoc_collection_t *collection;
	bson_error_t error;
	bson_oid_t oid;
	bson_t *doc;

	mongoc_init();
	bson_oid_init(&oid, NULL);

	client = mongoc_client_new("mongodb://localhost:27017/?appname=insert-example");
	collection = mongoc_client_get_collection(client, "SensorsDB", nameCollection);

	doc = bson_new();
	BSON_APPEND_OID(doc, "_id", &oid);

	if (!mongoc_collection_remove(
		collection, MONGOC_REMOVE_SINGLE_REMOVE, doc, NULL, &error)) {
		fprintf(stderr, "Delete failed: %s\n", error.message);
	}

	bson_destroy(doc);
	mongoc_collection_destroy(collection);
	mongoc_client_destroy(client);
	mongoc_cleanup();

	/*bson_error_t error;
	bson_oid_t oid;
	bson_t *doc;

	mongoc_init();

	client = mongoc_client_new("mongodb://localhost:27017/?appname=delete-example");
	collection = mongoc_client_get_collection(client, "mydb", "{\"name\": {\"second\":\"Grace1\", \"third\":\"Hopper1\"}}");

	doc = bson_new();
	BSON_APPEND_OID(doc, "_id", &oid);

	if (!mongoc_collection_remove(
		collection, MONGOC_REMOVE_SINGLE_REMOVE, doc, NULL, &error)) {
		fprintf(stderr, "Delete failed: %s\n", error.message);
	}

	bson_destroy(doc);
	mongoc_collection_destroy(collection);
	mongoc_client_destroy(client);
	mongoc_cleanup();*/
}

void MongoDB::addCollection(const char* nameCollection, const char* nameSensor, const char* valueSensor)
{
	bson_error_t error;
	bson_oid_t oid;
	bson_t *doc;
	mongoc_init();

	client = mongoc_client_new("mongodb://localhost:27017/?appname=insert-example");
	collection = mongoc_client_get_collection(client, "SensorsDB", nameCollection);

	doc = bson_new();
	bson_oid_init(&oid, NULL);
	BSON_APPEND_OID(doc, "_id", &oid);
	BSON_APPEND_UTF8(doc, nameSensor, valueSensor);

	if (!mongoc_collection_insert(collection, MONGOC_INSERT_NONE, doc, NULL, &error)) {
		fprintf(stderr, "%s\n", error.message);
	}

	bson_destroy(doc);
	mongoc_collection_destroy(collection);
	mongoc_client_destroy(client);
	mongoc_cleanup();

		

		//mongoc_init();

		//client = mongoc_client_new("mongodb://localhost:27017/?appname=insert-example");
		//collection = mongoc_client_get_collection(client, "mydb", strCollection);

		//doc = bson_new();
		//bson_oid_init(&oid, NULL);
		//BSON_APPEND_OID(doc, "_id", &oid);
		//BSON_APPEND_UTF8(doc, "hello", "world");

		//if (!mongoc_collection_insert(collection, MONGOC_INSERT_NONE, doc, NULL, &error)) {
		//	fprintf(stderr, "%s\n", error.message);
		//	
		//	ofstream outLogError("Log.txt");
		//	char str[32]{};
		//	time_t a = time(nullptr);
		//	struct tm time_info;

		//	// localtime_s, Microsoft version (returns zero on success, an error code on failure)
		//	if (localtime_s(&time_info, &a) == 0) 
		//		strftime(str, sizeof(str), "%H:%M:%S", &time_info);

		//	outLogError << str << "> " << error.message <<"\n";
		//	outLogError.close();
		//}

		//bson_destroy(doc);
		//mongoc_collection_destroy(collection);
		//mongoc_client_destroy(client);
		//mongoc_cleanup();
}


MongoDB::~MongoDB()
{
}
