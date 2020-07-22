#include "RMS_func.h"

int FilterRecord(){
    int op, i=0, count=0;
    struct Menu Nav = {"Choose Action:",
                        {"Sort by Name",
                        "Sort by Percentage",
                        "Sort by Grade Points",
                        "Sort by Roll Number",
                        "Sort by Marks in English",
                        "Sort by Marks in Accounts",
                        "Sort by Marks in Economics",
                        "Sort by Marks in Computer",
                        "Sort by Marks in Maths",
                        "Back"},
                        10};
    struct Student st[100];

    sortAgain:
    count = 0, i=0, op=0;
    FILE *file;
    file = fopen(file_path, "r");

    op = DisplayMenu(Nav);

    while(fscanf(file, "%hu%s%hu%hu%hu%hu%hu", &st[i].rollNo, st[i].name, &st[i].marks[0], &st[i].marks[1], &st[i].marks[2], &st[i].marks[3], &st[i].marks[4])!=EOF) i++;
    count = i;

    system("cls");
    switch(op){
        case 1:
            SortBy("name", st, count);
            break;
        case 2:
            SortBy("percentage", st, count);
            break;
        case 3:
            SortBy("gradepoints", st, count);
            break;
        case 4:
            SortBy("rollno", st, count);
            break;
        case 5:
            SortBy("english", st, count);
            break;
        case 6:
            SortBy("account", st, count);
            break;
        case 7:
            SortBy("economis", st, count);
            break;
        case 8:
            SortBy("computer", st, count);
            break;
        case 9:
            SortBy("maths", st, count);
            break;
        case 10:
            fclose(file);
            return 0;
            break;
        default:
            break;
    }
    fclose(file);
    PauseScreen();
    goto sortAgain;
}

void SortBy(char* sortType, struct Student s[100], int count){
    int i, j;

    for(i=0; i<count; i++){
        for(j=i+1; j<count; j++){
            if(strcmp(sortType, "percentage")==0){
                if(TotalMarks(s[i]) < TotalMarks(s[j])){
                    swapStruct(&s[i], &s[j]);
                }
            }else if(strcmp(sortType, "gradepoints")==0){
                if(StGradePoint(s[i]) < StGradePoint(s[j])){
                    swapStruct(&s[i], &s[j]);
                }
            }else if(strcmp(sortType, "name")==0){
                if(strcmp(s[i].name, s[j].name)>0){
                    swapStruct(&s[i], &s[j]);
                }
            }else if(strcmp(sortType, "rollno")==0){
                if(s[i].rollNo > s[j].rollNo){
                    swapStruct(&s[i], &s[j]);
                }
            }else if(strcmp(sortType, "english")==0){
                if(s[i].marks[0] < s[j].marks[0]){
                    swapStruct(&s[i], &s[j]);
                }
            }else if(strcmp(sortType, "account")==0){
                if(s[i].marks[1] < s[j].marks[1]){
                    swapStruct(&s[i], &s[j]);
                }
            }else if(strcmp(sortType, "economics")==0){
                if(s[i].marks[2] < s[j].marks[2]){
                    swapStruct(&s[i], &s[j]);
                }
            }else if(strcmp(sortType, "computer")==0){
                if(s[i].marks[3] < s[j].marks[3]){
                    swapStruct(&s[i], &s[j]);
                }
            }else if(strcmp(sortType, "maths")==0){
                if(s[i].marks[4] < s[j].marks[4]){
                    swapStruct(&s[i], &s[j]);
                }
            }
        }
    }
    MarksLedger(s);
}
