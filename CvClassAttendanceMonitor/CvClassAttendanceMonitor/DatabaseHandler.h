#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include "Student.h"
#include <stdlib.h>
#include <iostream>
#include <mysql.h>
#include "mysql_connection.h"

ref class DatabaseHandler
{
public:
	DatabaseHandler();
	DatabaseHandler(std::string, std::string, std::string);
	cli::array<Student^>^ GetStudents(void);
	void SetStudents(cli::array<Student^>^);
	int StudentCount;
	

private:
	const System::String^ DatabaseServer;
	const System::String^ DatabaseUsername;
	const System::String^ DatabasePassword;

	void AddObject(Object);
	void UpdateObject(Object);
	void DeleteObject(Object);

};