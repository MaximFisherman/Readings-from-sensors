// Reading from sensors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MongoDB.h"
#include "PostgressSQL.h"
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus"); 

	PostgressSQL postgressSQL;

	//MongoDB mongodb("mongodb://localhost:27017");
	//mongodb.addCollection("SensorColl","Sensor_1","0");
	system("pause");
    return 0;
}

