#include "DatabaseHandler.h"

using namespace msclr::interop;
using namespace std;

DatabaseHandler::DatabaseHandler(){
	DatabaseServer = gcnew System::String("localhost:3306");
	DatabaseUsername = gcnew System::String("root");
	DatabasePassword = gcnew System::String("1234");
	StudentCount = 0;
}

DatabaseHandler::DatabaseHandler(std::string DatabaseServer, std::string DatabaseUsername, std::string DatabasePassword) {
	this->DatabaseServer = marshal_as<System::String^>(DatabaseServer);
	this->DatabaseUsername = marshal_as<System::String^>(DatabaseUsername);
	this->DatabasePassword = marshal_as<System::String^>(DatabasePassword);
	StudentCount = 0;
}

cli::array<Student^>^ DatabaseHandler::GetStudents(void) {
	cli::array<Student^>^ StudentObjectArray = gcnew cli::array<Student^>(100); // Managed Array

	MYSQL* con;
	MYSQL_ROW row;
	MYSQL_RES* res;

	con = mysql_init(0);
	con = mysql_real_connect(con, "localhost", "root", "1234", "mydb", 3306, NULL, 0);

	if (con) {
		puts("Successful Connection to Database!");

		string query = "SELECT * FROM mydb.studentattendance";
		const char* q = query.c_str();
		int qstate = mysql_query(con, q);

		if (!qstate) {
			res = mysql_store_result(con);
			while (row = mysql_fetch_row(res)) {
				int StudentNumber = atoi(row[0]);  // Use atoi for integer conversion
				int DaysPresent = atoi(row[1]);
				int DaysLate = atoi(row[2]);
				int DaysEarlyLeave = atoi(row[3]);
				int DaysAbsent = atoi(row[4]);
				bool SnapshotLastState = bool(atoi(row[5]));
				int DaysNormalAttendance = atoi(row[6]);

				StudentObjectArray[StudentCount] = gcnew Student;
				StudentObjectArray[StudentCount++]->SetAttendance(StudentNumber, DaysPresent, DaysLate, DaysEarlyLeave, DaysAbsent, SnapshotLastState, DaysNormalAttendance);
			}
		}
		else {
			cout << "Query Failed:" << mysql_error(con) << endl;
		}

		query = "SELECT * FROM mydb.studentdetails";
		const char* q1 = query.c_str();
		qstate = mysql_query(con, q1);

		if (!qstate) {
			res = mysql_store_result(con);
			int i = 0;

			while (row = mysql_fetch_row(res)) {
				if (i <= StudentCount) {
					int StudentNumber = atoi(row[0]);
					char* Name = row[1];
					char* Surname = row[2];
					int RsaId = atoi(row[3]);
					char* IdPhoto = row[4];
					char* Gender = row[5];

					StudentObjectArray[i++]->SetDetails(StudentNumber, Name, Surname, RsaId, IdPhoto, Gender);
				}
			}
		}
		else {
			cout << "Query Failed:" << mysql_error(con) << endl;
		}
	}
	return StudentObjectArray;
}

void DatabaseHandler::SetStudents(cli::array<Student^>^ StudentObjectArray) {
	MYSQL* con;

	con = mysql_init(0);
	con = mysql_real_connect(con, "localhost", "root", "1234", "mydb", 3306, NULL, 0);

	if (con) {
		puts("Successful Connection to Database!");

		for (int i = 0; i < StudentCount; i++) {
			// Retrieve data from StudentObjectArray
			int StudentId = StudentObjectArray[i]->GetStudentId();
			int DaysPresent = StudentObjectArray[i]->GetDaysPresent();
			int DaysLate = StudentObjectArray[i]->GetDaysLate();
			int DaysEarlyLeave = StudentObjectArray[i]->GetDaysEarlyLeave();
			int DaysAbsent = StudentObjectArray[i]->GetDaysAbsent();
			bool SnapshotLastState = StudentObjectArray[i]->GetSnapshotLastState();
			int DaysNormalAttendance = StudentObjectArray[i]->GetDaysNormal();

			// Construct an SQL update query for the attendance table
			string query = "UPDATE studentattendance SET DaysPresent = " + to_string(DaysPresent) +
				", DaysLate = " + to_string(DaysLate) +
				", DaysEarlyLeave = " + to_string(DaysEarlyLeave) +
				", DaysAbsent = " + to_string(DaysAbsent) +
				", SnapshotLastState = " + (SnapshotLastState ? "1" : "0") +
				", DaysNormalAttendance = " + to_string(DaysNormalAttendance) +
				" WHERE StudentId = " + to_string(StudentId);

			const char* q = query.c_str();
			int qstate = mysql_query(con, q);

			if (qstate) {
				cout << "Query Failed:" << mysql_error(con) << endl;
			}
		}
	}
	mysql_close(con);
}


void DatabaseHandler::AddObject(Object Object) {
	// To be implemented


}

void DatabaseHandler::UpdateObject(Object Object) {
	// To be implemented


}

void DatabaseHandler::DeleteObject(Object Object) {
	// To be implemented


}