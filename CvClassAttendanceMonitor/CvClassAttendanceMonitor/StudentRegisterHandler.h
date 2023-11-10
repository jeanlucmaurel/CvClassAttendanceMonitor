#pragma once
#include "Student.h"
#include "Enums.h"

ref class StudentRegisterHandler
{
public:
	StudentRegisterHandler();
	Student^ StudentObject;
	DatabaseHandler^ DB;

	void getAttendance(int currentStudent);

private:
	cli::array<Student^>^ attendanceArr;
	
	bool RegsiterActive;
	bool Attendance;

	Punctuality Punctuality;
	void StartRegister();
	void StopRegister();
	void setAttendance();
};