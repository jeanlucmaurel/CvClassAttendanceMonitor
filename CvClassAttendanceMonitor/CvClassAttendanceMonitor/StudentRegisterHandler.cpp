#include "StudentRegisterHandler.h"
#include "Student.h"
#include "ObjectDetection.h"
#include "DatabaseHandler.h"
#include <array>



/* Description of Class:
* The StudentRegisterHandler class marks attendance and interacts with the database
  in order to update student information. The student registration class also utilizes
  student data container objects.

  Once Student is detected, the necessary attendance assignment is given and the Attendance Table is updated

  Once register
  give me student number and snapshot name  epoch ,

  Create an array of objects from the student table to store all table details.

*/

StudentRegisterHandler::StudentRegisterHandler()
{
	//Constructor

	DB = gcnew DatabaseHandler();
	cli::array<Student^>^ StudentObjectArray = DB->GetStudents(); //An array of objects, of students 
	cli::array<int^>^ attendanceArr = gcnew cli::array<int^>(100);

	int studentCount = DB->StudentCount; //Number of total students enrolled in course, located on Student Attendance Register

	int StudentNumber = 0;
	int DaysPresent = 0;
	int DaysLate = 0;
	int DaysEarlyLeave = 0;
	int DaysAbsent = 0;
	bool SnapshotLastState = false;
	int DaysNormalAttendance = 0;
	int studentObjectArrSize = 0;

	//Need to instantiate a List of String student numbers 
	int lengthOfList = 0;//Size of list of students detected list, changes 
	int totalSnaps, currentSnap = 0;//Get from ObjectDetection Class; totalSnaps = ObjectDetection::totalSnaps; 

	//Not needed, to be determined 
	StudentObject = gcnew Student();
	RegsiterActive = false;
	Attendance = false;
}

	/*	
	*	Student currStudentObjectArr[] = gcnew Student();	
	*	std::array<Student, 4> currStudentObjectArr = gcnew Student();
	*	Example to copy one array to another, have to use constant for size.
	*	std::array<int, 4> A = { 10, 20, 30, 40 };
	*	std::array<int, 4> B = A;
	*/

	/* Not needed Old Code , Remove when finalised
	   Student^ StudentObject = gcnew Student();
	   cli::array<Student^>^ StudentObjectArray = gcnew cli::array<Student^>(100); // Managed Array
	   int StudentCount = 0;
	   
	   studentObjectArrSize = (int) sizeof(StudentObjectArr) / sizeof(Student);
	   std::array<Student, studentObjectArrSize> currStudentObjectArr[] = StudentObjectArr[];

	   while (row = mysql_fetch_row(res)) {
				int StudentNumber = stoi(row[0]);
				int DaysPresent = stoi(row[1]);
				int DaysLate = stoi(row[2]);
				int DaysEarlyLeave = stoi(row[3]);
				int DaysAbsent = stoi(row[4]);
				bool SnapshotLastState = stoi(row[5]);
				int DaysNormalAttendance = stoi(row[6]);

				StudentObjectArray[StudentCount] = gcnew Student;
				StudentObjectArray[StudentCount++]->SetAttendance(StudentNumber,DaysPresent,DaysLate,DaysEarlyLeave,DaysAbsent,SnapshotLastState,DaysNormalAttendance);
			}
	*/

	/*	
	    std::vector<std::string> stringNumbers; if this is the list of student numbers of present faces detected, from ObjectDetection class

		Convert List of String to int (if list is given by object detection class)
		std::vector<int> convertToInt() 
		{
        std::vector<int> intNumbers;
        for (std::string number : stringNumbers) {
            std::stringstream ss(number);
            int num;
            ss >> num;
            intNumbers.push_back(num);
        }
        return intNumbers;
		}

		std::vector<int> intNumbers = convertToInt();
	*/
	
	void StudentRegisterHandler::StartRegister()
	{	
		DB = gcnew DatabaseHandler();
		cli::array<Student^>^ StudentObjectArray = DB->GetStudents();

		//totalSnaps = ObjectDetection::totalSnaps; currentSnap = ObjectDetection::currentSnap
		
		//These loops increment the attendanceArr with detected students 
		for (int i = 0; i < lengthOfList; i++)
		{
			// create an iterator to point to the first element of the list
			list<int>::iterator itr = intNumbers.begin();

			// increment itr to point to the 2nd element
			itr += i;
			//(StudentObjectArr[], i);
			//setAttendance();
			for (int j = 0; j < studentCount; j++)
			{
				if (*itr == StudentObjectArray[j]->GetStudentId())
				{
					attendanceArr[j] = attendanceArr[j] + 1;
				}
			}
		}

		
	}

void StudentRegisterHandler::StartRegister() 
{

}

void StudentRegisterHandler::StopRegister()
{

}

void StudentRegisterHandler::setAttendance()
{

}
//Need to correct below
void StudentRegisterHandler::getAttendance(int currentStudent)
{
	 StudentNumber = (StudentObjectArray[currentStudent].StudentId);
	 DaysPresent = (StudentObjectArray[currentStudent].DaysPresent);
	 DaysLate = (StudentObjectArray[currentStudent].DaysLate);
	 DaysEarlyLeave = (StudentObjectArray[currentStudent].DaysEarlyLeave);
	 DaysAbsent = (StudentObjectArray[currentStudent].DaysAbsent);
	 SnapshotLastState = (StudentObjectArray[currentStudent].SnapshotLastState);
	 DaysNormalAttendance = (StudentObjectArray[currentStudent].DaysNormal);
}
	/*void AddStudentToRegister(student Sudent)
	{
	}
	*/



//Error Handling

