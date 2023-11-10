//#include "stdafx.h"
#include "Student.h"
#include "DatabaseHandler.h"
#include <stdlib.h>
#include <iostream>
#include <mysql.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

using namespace std;

int main()
{
	DatabaseHandler^ DB = gcnew DatabaseHandler();
	cli::array<Student^>^ StudentObjectArray = DB->GetStudents();

	cout << DB->StudentCount << endl;
	
	std::system("pause");

	for (int i = 0; i < DB->StudentCount; i++) {
		System::Console::WriteLine("=======================================================");
		System::Console::WriteLine("i = " + i);
		System::Console::WriteLine("=======================================================");

		System::Console::WriteLine("Student ID: " + StudentObjectArray[i]->GetStudentId());
		System::Console::WriteLine("Name: " + StudentObjectArray[i]->GetName());
		System::Console::WriteLine("Surname: " + StudentObjectArray[i]->GetSurname());
		System::Console::WriteLine("ID Photo: " + StudentObjectArray[i]->GetIdPhoto());

		// For GetGender, you should cast it to an int to display it as an integer value
		//System::Console::WriteLine("Gender: " + int(StudentObjectArray[i]->GetGender()));

		System::Console::WriteLine("Snapshot Last State: " + StudentObjectArray[i]->GetSnapshotLastState());
		System::Console::WriteLine("RSA ID: " + StudentObjectArray[i]->GetRsaId());
		System::Console::WriteLine("Days Present: " + StudentObjectArray[i]->GetDaysPresent());
		System::Console::WriteLine("Days Late: " + StudentObjectArray[i]->GetDaysLate());
		System::Console::WriteLine("Days Early Leave: " + StudentObjectArray[i]->GetDaysEarlyLeave());
		System::Console::WriteLine("Days Absent: " + StudentObjectArray[i]->GetDaysAbsent());
		System::Console::WriteLine("Days Normal: " + StudentObjectArray[i]->GetDaysNormal());
		System::Console::WriteLine("=======================================================");

		System::Console::WriteLine("");
	}
	std::system("pause");


	// Modify Attendance Example
	StudentObjectArray[3]->SetAttendance(221064909, 75, 2, 1, 0, 0, 72);


	for (int i = 3; i<4; i++) {
		System::Console::WriteLine("=======================================================");
		System::Console::WriteLine("i = " + i);
		System::Console::WriteLine("=======================================================");

		System::Console::WriteLine("Student ID: " + StudentObjectArray[i]->GetStudentId());
		System::Console::WriteLine("Name: " + StudentObjectArray[i]->GetName());
		System::Console::WriteLine("Surname: " + StudentObjectArray[i]->GetSurname());
		System::Console::WriteLine("ID Photo: " + StudentObjectArray[i]->GetIdPhoto());

		// For GetGender, you should cast it to an int to display it as an integer value
		//System::Console::WriteLine("Gender: " + int(StudentObjectArray[i]->GetGender()));

		System::Console::WriteLine("Snapshot Last State: " + StudentObjectArray[i]->GetSnapshotLastState());
		System::Console::WriteLine("RSA ID: " + StudentObjectArray[i]->GetRsaId());
		System::Console::WriteLine("Days Present: " + StudentObjectArray[i]->GetDaysPresent());
		System::Console::WriteLine("Days Late: " + StudentObjectArray[i]->GetDaysLate());
		System::Console::WriteLine("Days Early Leave: " + StudentObjectArray[i]->GetDaysEarlyLeave());
		System::Console::WriteLine("Days Absent: " + StudentObjectArray[i]->GetDaysAbsent());
		System::Console::WriteLine("Days Normal: " + StudentObjectArray[i]->GetDaysNormal());
		System::Console::WriteLine("=======================================================");

		System::Console::WriteLine("");
	}

	std::system("pause");

	// Upload Changes to Database Example
	DB->SetStudents(StudentObjectArray);

	std::system("pause");

	return 0;
}