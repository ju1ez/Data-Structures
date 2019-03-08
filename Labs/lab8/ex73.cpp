
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<cstddef>
using namespace std;

int main() {
//class/struct that stores students information
  FILE * fp, * ft;
  char other, choic;
  struct stu {
    char firstname[20], lastname[20], course[100], rollnumber[100];
  };
  //will read/write student information to temp file
  struct stu e;
  char xfirstname[20], xlastname[20];
  long int recsize;
  fp = fopen("example.txt", "rb+");

  if (fp == NULL) {
    fp = fopen("example.txt", "wb+");
    if (fp == NULL) {
      puts("cannot open the file");
      return 0;
    }
  }
  recsize = sizeof(e);
  //application menu
  while (1) {
    system("cls");
    cout << "Menu:" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Display Students" << endl;
    cout << "3. Edit Records" << endl;
    cout << "4. Delete Records" << endl;
    cout << "5. Exit" << endl;
    fflush(stdin);
    choic = getche();
    switch (choic) {
    	//add student
    case '1':
      fseek(fp, 0, SEEK_END);
      other = 'y';
      while (other == 'y' || other == 'y') {
        system("cls");
        cout << endl << "Enter Firstname" << endl;
        cin >> e.firstname;
        cout << "Enter Lastname" << endl;
        cin >> e.lastname;
        cout << "Enter Course Name" << endl;
        cin >> e.course;
        cout << "Enter Semester" << endl;
        cin >> e.rollnumber;
        fwrite( & e, recsize, 1, fp);
        cout << "Would you like to enter another record? (y/n)" << endl;
        fflush(stdin);
        other = getchar();
      }
      break;
	//display student information
    case '2':
      system("cls");
      rewind(fp);
      cout << endl << "Displaying Students..." << endl;
      while (fread( & e, recsize, 1, fp) == 1) {
        cout << "Name: " << e.firstname << " " << e.lastname << endl;
        cout << "Course: " << e.course << endl;
        cout << "Semester: " << e.rollnumber << endl;
      }
      cout << endl;
      system("pause");
      break;
	//edit student information
    case '3':
      system("cls");
      other = 'y';
      while (other == 'y' || other == 'y') {
        cout << "Enter the LASTNAME of the student: ";
        cin >> xlastname;
        rewind(fp);
        while (fread( & e, recsize, 1, fp) == 1) {
          if (strcmp(e.lastname, xlastname) == 0) {
            cout << "Enter NEW Firstname" << endl;
            cin >> e.firstname;
            cout << "Enter NEW Lastname" << endl;
            cin >> e.lastname;
            cout << "Enter NEW Course" << endl;
            cin >> e.course;
            cout << "Enter NEW Semester" << endl;
            cin >> e.rollnumber;
            fseek(fp, recsize, SEEK_CUR);
            fwrite( & e, recsize, 1, fp);
            break;
          } else
            cout << "Record does not exist";
        }
        cout << "Modify another record? (y/n)" << endl;
      }
      break;
	//delete student information
    case '4':
      system("cls");
      other = 'y';
      while (other == 'y' || other == 'y') {
        cout << "Enter LASTNAME of student to delete: " << endl;
        cin >> xlastname;
        ft = fopen("temp.dat", "wb");
        rewind(fp);
        while (fread( & e, recsize, 1, fp) == 1)
          if (strcmp(e.lastname, xlastname) != 0) {
            fwrite( & e, recsize, 1, ft);
          }
        fclose(fp);
        fclose(ft);
        remove("example.txt");
        rename("temp.dat", "example.txt");
        fp = fopen("example.txt", "rb+");
        cout << "Delete another record? (y/n)" << endl;
        fflush(stdin);
        other = getchar();
      }
      break;
	//exit application
    case '5':
      fclose(fp);
      cout << endl << endl << "Application is closing..." << endl;
      exit(0);
    }
  }
  system("pause");
  return 0;
}
