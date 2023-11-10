#pragma once
#include "Enums.h"
#include <string>


public ref class Student
{
public:
	Student();
	Student(System::String^ Name,
			System::String^ Surname,
			System::String^ IdPhoto,
			System::String^ Gender,
			bool SnapshotLastState,
			int StudentId,
			int RsaId,
			int DaysAbsent,
			int DaysLate,
			int DaysEarlyLeave,
			int DaysPresent,
			int DaysNormal);

	System::Object^ GetStudentIdPhoto(void);
	void UpdateAttendance(void); // Writes to an object to set new attendance
	void SetAttendance(int StudentId, int DaysPresent, int DaysLate, int DaysEarlyLeave, int DaysAbsent, bool SnapshotLastState, int DaysNormalAttendance); // Runs on instantiation of an object to set old attendance
	void UpdateDetails(void); // Writes to an object to set new details
	void SetDetails(int StudentId, char* Name, char* Surname, int RsaId, char* IdPhoto, char* Gender); // Runs on instantiation of an object to set old details

	// Accessors
	System::String^ GetName(void) { return Name; }
	System::String^ GetSurname(void) { return Surname; }
	System::String^ GetIdPhoto(void) { return IdPhoto; }
	Gender GetGender(void) { return Gender; }
	bool GetSnapshotLastState(void) { return SnapshotLastState; }
	int GetStudentId(void) { return StudentId; }
	int GetRsaId(void) { return RsaId; }
	int GetDaysPresent(void) { return DaysPresent; }
	int GetDaysLate(void) { return DaysLate; }
	int GetDaysEarlyLeave(void) { return DaysEarlyLeave; }
	int GetDaysAbsent(void) { return DaysAbsent; }
	int GetDaysNormal(void) { return DaysNormal; }

	// Mutators
	void SetDaysPresent(int DaysPresent) {this->DaysPresent = DaysPresent;}
	void SetDaysAbsent(int DaysAbsent) { this->DaysAbsent = DaysAbsent; }
	void SetDaysLate(int DaysLate) { this->DaysLate = DaysLate; }
	void SetDaysEarlyLeave(int DaysEarlyLeave) { this->DaysEarlyLeave = DaysEarlyLeave; }
	void SetSnapshotLastState(bool SnapshotLastState) { this->SnapshotLastState = SnapshotLastState; }
	void SetDaysNormalAttendance(int DaysNormalAttendance) { this->DaysNormal = DaysNormalAttendance; }

private:
	System::String^ Name;
	System::String^ Surname;
	System::String^ IdPhoto;
	Gender Gender;
	bool SnapshotLastState;
	int StudentId;
	int RsaId;
	int DaysPresent;
	int DaysLate;
	int DaysEarlyLeave;
	int DaysAbsent;
	int DaysNormal;
};

