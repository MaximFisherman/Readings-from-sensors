// Reading from sensors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MongoDB.h"
int main()
{
	MongoDB mongodb("mongodb://localhost:27017");
	mongodb.addCollection("{\"name\": {\"second\":\"Grace1\", \"third\":\"Hopper1\"}}");

	system("pause");
    return 0;
}

