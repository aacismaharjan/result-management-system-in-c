#include "RMS_func.h"

void DisplaySheet(struct Student st){
    system("cls");
    printf("Grade XII [B]\n");
    printf("Management[Computer Science] Result\n\n");

    smDottedLines;
    printf("Name: %s\t\t\t\t\tRoll Number: %d\n\n", strupr(st.name), st.rollNo);
    printf("SUBJECTS\t\tMarks\t\tGrade\tRemarks\n");

    for(int i=0; i<NUM_OF_SUBS; i++){
        printf("%d. %-20.20s\t%d\t\t%s\t%s\n", i+1, Subjects[i], st.marks[i], GPA(st.marks[i]), CheckResult(st.marks[i]));
    }

    printf("\nPercentage: %.2f%%\t\t\t\tResult: %s", Percentage(st), Result(st));
    printf("\nTotal Marks: %-4d\t\t\t\tGPA: %s (%.2f)\n", TotalMarks(st), GPA(StGradePoint(st)*25), StGradePoint(st));
    smDottedLines;

    printf("\n");
    Message("Notice: Copyright 2019, All Rights Reserved. Gyanodaya College, Bafal.");
}
