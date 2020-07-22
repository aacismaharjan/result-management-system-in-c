#include "RMS_func.h"

// Subject Settings
char** Subjects;
char* DEFAULT_SUBJECTS[] = {"English", "Faculty Compulsory", "College Compulsory", "Optional First", "Optional Second"};
char* GRADE_12_COMMERCE_SUBS[] = {"English", "Accountancy", "Economics", "Computer", "B.Maths"};
char* GRADE_12_SCIENCE_SUBS[] = {"English", "Physics", "Chemistry", "Maths", "Computer"};
int NUM_OF_SUBS = 5;


// Grade Settings
char GradeInDetail[][25] = {"Very Insufficient", "Very Insufficient", "Very Insufficient", "Insufficient", "Partially Acceptable", "Acceptable", "Satisfactory", "Good", "Very Good", "Excellent", "Outstanding"};
float GradeInPoint[] = {0.0, 0.4, 0.8, 1.2, 1.6, 2.0, 2.4, 2.8, 3.2, 3.6, 4.0};
char GradeInGPA[][3] = {"F+", "E", "E+", "D", "D+", "C", "C+", "B", "B+", "A", "A+"};
int GradeInScore[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int nGrades = sizeof(GradeInScore)/sizeof(GradeInScore[0]);


// Folder Settings
char* FOLDER_NAME = "Program Files";
char file_path[50], temp_file_path[50], info_file_path[50];


// Files Settings
void filesAddress() {
    snprintf(temp_file_path, sizeof(temp_file_path), "%s/TempGrade12Result.txt", FOLDER_NAME);
    snprintf(info_file_path, sizeof(temp_file_path), "%s/Software Info.txt", FOLDER_NAME);
    snprintf(file_path, sizeof(file_path), "%s/Grade12Result.txt", FOLDER_NAME);
}

// Fires the Result Management System
int main(){
    srand(time(NULL)); // Seeding Random numbers
    RunRMS();
    return 0;
}
