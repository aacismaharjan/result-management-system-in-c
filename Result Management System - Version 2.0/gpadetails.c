#include "RMS_func.h"

void GPADetails(){
    system("cls");
    printf("Grade XII [B]\n");
    printf("Management[Computer Science] Result\n\n");

    smDottedLines;
    printf("S.N\tObtained Marks\tGPA\tExplanation\t\tGrade Point\n");
    smDottedLines;
    for(int i=10; i>0; i--){
        printf("%d\t%d-%d\t\t%s\t%-25s%.2f-%.2f\n", 10-(i-1), GradeInScore[i-1], GradeInScore[i], GradeInGPA[i], GradeInDetail[i],GradeInPoint[i-1], GradeInPoint[i]);
        smDottedLines;
    }
    PauseScreen();
}
