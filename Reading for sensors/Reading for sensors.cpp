// Reading from sensors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MongoDB.h"
using namespace std;

int main()
{
	MongoDB mongodb("mongodb://localhost:27017");
	//mongodb.addCollection("SensorColl","Sensor_1","0");
	mongodb.deleteCollection("SensorColl");
	system("pause");
    return 0;
}

