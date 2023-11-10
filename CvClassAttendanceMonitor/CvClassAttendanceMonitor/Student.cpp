#include "Student.h"
#include <string>

Student::Student() {
	Name = nullptr;
	Surname = nullptr;
	IdPhoto = nullptr;
	SnapshotLastState = false;

	Gender = Gender::Undefined;

	StudentId = 0;
	RsaId = 0;

	DaysPresent = 0;
	DaysLate = 0;
	DaysEarlyLeave = 0;
	DaysAbsent = 0;
	DaysNormal = 0;
}

Student::Student(System::String^ Name,
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
	int DaysNormal
) {

	this->Name = Name;
	this->Surname = Surname;
	this->IdPhoto = IdPhoto;
	this->SnapshotLastState = SnapshotLastState;
	this->StudentId = StudentId;
	this->RsaId = RsaId;
	this->DaysAbsent = DaysAbsent;
	this->DaysLate = DaysLate;
	this->DaysEarlyLeave = DaysEarlyLeave;
	this->DaysPresent = DaysPresent;
	this->DaysNormal = DaysNormal;

	if (Gender == "Male") {
		this->Gender = Gender::Male;
	}
	else if (Gender == "Female") {
		this->Gender = Gender::Female;
	}
	else {
		this->Gender = Gender::Other;
	}
}

System::Object^ Student::GetStudentIdPhoto() {

	return nullptr;
}

void Student::UpdateAttendance(void) {

}

void Student::UpdateDetails(void) {

}

void Student::SetDetails(int StudentId, char* Name, char* Surname, int RsaId, char* IdPhoto, char* Gender) {
	this->StudentId = StudentId;
	this->Name = gcnew System::String(Name);
	this->Surname = gcnew System::String(Surname);
	this->IdPhoto = gcnew System::String(IdPhoto);
	
	if (strcmp(Gender, "Male") == 0) {
		this->Gender = Gender::Male;
	}
	else if (strcmp(Gender, "Female") == 0) {
		this->Gender = Gender::Female;
	}
	else if (strcmp(Gender, "Other") == 0) {
		this->Gender = Gender::Other;
	}
	else {
		this->Gender = Gender::Undefined;
	}
}

void Student::SetAttendance(int StudentId, int DaysPresent, int DaysLate, int DaysEarlyLeave, int DaysAbsent, bool SnapshotLastState, int DaysNormalAttendance) {
	this->StudentId = StudentId;
	this->DaysPresent = DaysPresent;
	this->DaysLate = DaysLate;
	this->DaysEarlyLeave = DaysEarlyLeave;
	this->DaysAbsent = DaysAbsent;
	this->SnapshotLastState = SnapshotLastState;
	this->DaysNormal = DaysNormalAttendance;
}