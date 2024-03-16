#include "RMS_func.h""

// Passes Students data to Marksledger
void DisplayMarksLedger(){
    struct Student s[100];
    int i=0;

    FILE *file;
    file = fopen(file_path, "r");

    while(fscanf(file, "%hu%s%hu%hu%hu%hu%hu", &s[i].rollNo, s[i].name, &s[i].marks[0], &s[i].marks[1], &s[i].marks[2], &s[i].marks[3], &s[i].marks[4])!=EOF) i++;
    MarksLedger(s);
    fclose(file);
}

// Displays Marksledger
void MarksLedger(struct Student s[100]){
    int count=0, failNo=0, i=0;
    struct Student st;
    struct Student highest ={"student", 0, {0, 0, 0, 0, 0}};
    struct Student total ={"student", 0, {0, 0, 0, 0, 0}};

    FILE *file;
    file = fopen(file_path, "r");

    system("cls");
    printf("Grade XII [B]\n");
    printf("Management[Computer Science] Result\n\n");

    xlDottedLines;
    printf("ROLL NO\tNAME\t\t%.3s\t%.3s\t%.3s\t%.3s\t%.3s\tTOTAL\tPERCENT\tGPA\tRESULT\n", Subjects[0], Subjects[1], Subjects[2], Subjects[3], Subjects[4]);
    while(fscanf(file, "%hu%s%hu%hu%hu%hu%hu", &st.rollNo, st.name, &st.marks[0], &st.marks[1], &st.marks[2], &st.marks[3], &st.marks[4])!=EOF) i++;
    count = i;

    for(i=0; i<count; i++){
        printf("%hu\t%s\t\t%hu\t%hu\t%hu\t%hu\t%hu\t", s[i].rollNo, strupr(s[i].name), s[i].marks[0], s[i].marks[1], s[i].marks[2], s[i].marks[3], s[i].marks[4]);
        printf("%hu\t%.2f%%\t%.2f\t%s\n", TotalMarks(s[i]),  Percentage(s[i]), StGradePoint(s[i]), Result(s[i]));

        for(int j=0; j<5; j++){
            if(s[i].marks[j] > highest.marks[j]) highest.marks[j] = s[i].marks[j];
            total.marks[j] += s[i].marks[j];
        }

        if(strcmp(strlwr(Result(s[i])), "failed") == 0){
            failNo++;
        }
    }
    xlDottedLines;

    printf("\n\n\tFULL MARKS\t%d\t%d\t%d\t%d\t%d\n", 100, 100, 100, 100, 100);
    printf("\tPASS MARKS\t%d\t%d\t%d\t%d\t%d\t\tPASSED\t%d\n", 40, 40, 40, 40, 40, count - failNo);
    printf("\tHIGHEST MARKS\t%d\t%d\t%d\t%d\t%d\t\tFAILED\t%d\n", highest.marks[0], highest.marks[1], highest.marks[2], highest.marks[3], highest.marks[4], failNo);
    printf("\tAVERAGE MARKS\t%d\t%d\t%d\t%d\t%d\n", total.marks[0]/count, total.marks[1]/count, total.marks[2]/count, total.marks[3]/count, total.marks[4]/count);
    printf("\n\n");

    Message("Notice: Copyright 2019, All Rights Reserved. Gyanodaya College, Bafal.");
    fclose(file);
}
