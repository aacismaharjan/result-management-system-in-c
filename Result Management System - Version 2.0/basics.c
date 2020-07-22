#include "RMS_func.h"

// Loading Screen
void LoadingScreen(){
    int i, j, n= rand() % 5;
    char csarry[5] = {'*', '@', '%', '$', '#'}, cs = csarry[n];

    system("cls");
    smDottedLines;
    printf("                   GYANODAYA MANAGEMENT RESULT\n");
    printf("                        Bafal, Kathmandu\n");
    printf("\n\n");

    n = 7; // Size of Flag

    for(i=n; i>0; i--){printf("\t\t\t  ");for(j=i; j>0; j--) printf("%c  ", cs);printf("\n");} // Upper Triangle
    for(i=1; i<=n; i++){printf("\t\t\t  ");for(j=1; j<=i; j++){printf("%c  ", cs);}printf("\n");} // Lower Triangle
    for(i=0; i<(n/2); i++){printf("\t\t\t  ");printf("%c  \n", cs);} // Tails

    printf("\n\n");
    printf("               Copyright 2019, All Rights Reserved.\n");
    printf("            Designed and Developed by Aashish Maharjan\n");
    smDottedLines;

    PauseScreen();
}

// File Check
void CheckFileStatus(){
    FILE *file;
    FILE *info;
    file = fopen(file_path, "r");
    info = fopen(info_file_path, "r");

    system("cls");

    // Checks whether or not folder exist or not
    if(!mkdir(FOLDER_NAME, 0777)) {
        msgDottedLines;
        printf("Warning: We didn't find the required folder. \n");
        printf("Note: Our Program has successfully created the required folder(%s).\n", FOLDER_NAME);
        msgDottedLines;

        PauseScreen();
        printf("\n\n");
    }

    // Checking Software Info File
    if(info == NULL) {
        msgDottedLines;
        printf("Warning: We didn't find \"%s\" file. \n", info_file_path);
        info = fopen(info_file_path, "w");
        fprintf(info, "Comming Soon...");
        printf("Note: Our Program has successfully created the required file(%s).\n", info_file_path);
        fclose(info);
        msgDottedLines;
        PauseScreen();
    }
    fclose(info);


    // Checking main file
    if(file == NULL){
        system("cls");
        Message("Warning: No Records exists! Please add student's records.");
        PauseScreen();

        AddRecord();
    }

    fclose(file);
}

// Prevents Unwanted Values
int ValidateNumber(char* inputDialogue, int minValue, int maxValue){
    int maxDigits = floor(log(maxValue));

    char userInput[maxDigits+3];
    int validNumber = 0;
    bool isValidated = false;

    do{
        fflush(stdin);
        printf("%s", inputDialogue);
        fgets(userInput, maxDigits+2, stdin);
        fflush(stdin);

        if(sscanf(userInput, "%d", &validNumber)!=1){
            Message("Invalid Sscanf() :\(");
            continue;
        }

        if(validNumber < minValue || validNumber > maxValue){
            Message("Invalid Range :\(");
            continue;
        }

        isValidated = true;
    }while(isValidated == false);

    return validNumber;
}

// Checks Division of Marks
char *Result(struct Student st){
    static char result[30] = "Passed";
    unsigned int percent = Percentage(st);
    int pm = 40; // Pass Marks
    if(st.marks[0] >= pm && st.marks[1] >=pm && st.marks[2] >=pm && st.marks[3] >=pm && st.marks[4] >=pm){
        if(percent >= 80){
            strcpy(result, "Distinction");
        }else if(percent >= 70){
            strcpy(result, "First Division");
        }else if(percent >= 60){
            strcpy(result, "Second Division");
        }else if(percent >= 50){
            strcpy(result, "Third Division");
        }else{
            strcpy(result, "Passed");
        }
    }else {
        strcpy(result, "Failed");
    }
    return strupr(result);
}

// Returns total marks
int TotalMarks(struct Student st){
    return st.marks[0] + st.marks[1] + st.marks[2] + st.marks[3] + st.marks[4];
}

// Returns Percentage
float Percentage(struct Student st){
    return TotalMarks(st)/ 5.0;
}

// Marks into GPA
char *GPA (int marks){
    static char grade[3]="A";

    for(int i=nGrades; i>0; i--){
        if(marks >= GradeInScore[i-1] && marks <= GradeInScore[i]){
            strcpy(grade, GradeInGPA[i]);
        }
    }
    return grade;
}

// Marks into Grade Points
float GradePoint(int marks){
    float grade = 0.0;
    for(int i=nGrades; i>0; i--){
        if(marks >= GradeInScore[i-1] && marks <= GradeInScore[i]){
            grade = GradeInPoint[i];
        }
    }
    return grade;
}

// Final Grade Point
float StGradePoint(struct Student st) {
    float grade_point = 0;

    for(int i=0; i<5; i++) {
        grade_point += GradePoint(st.marks[i]);
    }

    grade_point /= 5.0;
    return grade_point;
}

// Checks pass or fail
char *CheckResult(int marks_obt){
    static char passOrFail[5];
    strcpy(passOrFail, " ");

    if(marks_obt >= 0 && marks_obt < 40){
        strcpy(passOrFail, "F");
    }
    return passOrFail;
}

// Swap two structures
void swapStruct(struct Student *s1, struct Student *s2){
    struct Student temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

// Pause Function
void PauseScreen(){
    printf("\nContinue...");
    getch();
}

// Dotted Lines
void dottedLines(int lines, char c){
    for(int i=0; i<lines; i++){
        printf("%c", c);
    }
    printf("\n");
}

// Message Layout
void Message(char msg[100]){
    msgDottedLines;
    printf("%s\n", msg);
    msgDottedLines;
}

// Prompts
bool ContinueAgain(){
    char ch;
    printf("Do you want to continue(Y/N): ");
    scanf(" %c", &ch);

    return tolower(ch) == 'y';
}

// Exit
void ExitProgram(){
    system("taskkill/IM cb_console_runner.exe");
}
