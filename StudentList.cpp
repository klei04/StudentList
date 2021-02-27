/*
This is a program that creates a list of students and their information from the user's input.
The program can add students, print the list, and delete entries.
Author: Kevin Lei
Print: 2/26/2021
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

//Function prototypes
struct Student;
void ADD(vector<Student*>* &studentList);
void PRINT(vector<Student*>* studentList);
void DELETE(vector<Student*>* &studentList);

//Creating the struct 'Student'
struct Student {
  int ID;
  char lastName[20];
  char firstName[10];
  float GPA;
};

//Main method
int main() {

  vector<Student*>* studentList = new vector<Student*>;
  //Student* testStudent = new Student();
  //testStudent->ID = 123456;
  //testStudent->GPA = 1.23;
  //studentList->push_back(testStudent);
  //cout << studentList->at(0)->GPA << endl;
  char userResponse[7];
  
  //Program will continue to run as long as the user doesn't input 'QUIT'
  while (strcmp(userResponse, "QUIT") != 0) {
    
    cout << "Type 'ADD' to add a student." << endl
	 << "Type 'PRINT' to see all students." << endl
	 << "Type 'DELETE' to delete a student." << endl
	 << "Type 'QUIT' to exit." << endl;
    cin >> userResponse;

    //Depending on the user's input, the ADD, PRINT, or DELETE method will run.
    //Or, if the user inputs something different,
    //the system will notify the user that it is not a valid response.
    if (strcmp(userResponse, "ADD") == 0) {
      ADD(studentList);
      cout << studentList->at(0)->firstName << endl;
    } else if (strcmp(userResponse, "PRINT") == 0) {
      PRINT(studentList);
    } else if (strcmp(userResponse, "DELETE") == 0) {
      DELETE(studentList);
    } else if (strcmp(userResponse, "QUIT") != 0) {
      cout << "Please type a valid response." << endl;
    }
  }
  
  cout << "Goodbye." << endl;
}

//Method to add a student to the list
void ADD(vector<Student*>* &studentList) {

  Student* tempStudent = new Student();

  cout << "Please enter an ID." << endl;
  cin >> tempStudent->ID;
  cout << "Please enter a last name." << endl;
  cin >> tempStudent->lastName;
  cout << "Please enter a first name." << endl;
  cin >> tempStudent->firstName;
  cout << "Please enter a GPA." << endl;
  cin >> tempStudent->GPA;

  studentList->push_back(tempStudent);
}


//Method to print out all the students in the list
void PRINT(vector<Student*>* studentList) {
  for (int a = 0; a < studentList->size(); a++) {
    cout << studentList->at(a)->ID << ": "
	 << studentList->at(a)->firstName << " "
	 << studentList->at(a)->lastName << ", "
	 << fixed << setprecision(2) << studentList->at(a)->GPA << endl;
  }
}

//Method to delete a student from the list
void DELETE(vector<Student*>* &studentList) {
  
  int chosenStudent;
  cout << "Please type the ID of the student to be deleted." << endl;
  cin >> chosenStudent;

  //Runs through the vector looking for the chosen student and then deletes the student
  for (int a = 0; a < studentList->size(); a++) {
    if (studentList->at(a)->ID == chosenStudent) {
      studentList->erase(studentList->begin() + a);
      return;
    }
  }

  //If no student is found the system will notify the user
  cout << "Student not found." << endl;
}
