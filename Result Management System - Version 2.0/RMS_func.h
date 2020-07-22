#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "common.h"

#ifndef RMS_FUNC_H_INCLUDED
#define RMS_FUNC_H_INCLUDED

#define msgDottedLines dottedLines(90, '-')
#define xlDottedLines dottedLines(110, '=')
#define smDottedLines dottedLines(70, '-')

struct Student{
    char name[15];
    unsigned short int rollNo, marks[5];
};

struct Menu{
    char head[50];
    char* items[10];
    int total;
};

void RunRMS();
void AddRecord();
void SearchRecord();
int FilterRecord();
void DeleteRecord();
void MoreMenu();
void SoftwareInfo();
void DisplaySheet(struct Student);
void DisplayMarksLedger();
void MarksLedger(struct Student s[100]);
int ValidateNumber(char*, int, int);
int DisplayMenu(struct Menu);
void SortBy(char* sortType, struct Student s[100], int count);
void SearchRecordBy(char* searchType);
void CheckFileStatus();
void ExitProgram();

char *GPA(int);
char *CheckResult(int);
float GradePoint(int);
float StGradePoint(struct Student st);
char *Result(struct Student);
int TotalMarks();
float Percentage();
void Message(char msg[100]);
void LoadingScreen();
void GPADetails();void PauseScreen();
bool ContinueAgain();
void dottedLines(int, char);
void dottedLines(int lines, char c);
#endif // RMS_FUNC_H_INCLUDED
