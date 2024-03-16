#include "RMS_func.h"

void AddRecord(){
    char msg[30];
    struct Student st;

    FILE *file;
    file = fopen(file_path, "a");

    do{
        system("cls");
        printf("Grade XII [B]\n");
        printf("Management[Computer Science] Result\n\n");

        Message("Add Student's Record:");
        printf("\nEnter Name: ");
        scanf(" %s", st.name);

        st.rollNo = ValidateNumber("Enter Roll No: ", 0, 100);

        printf("\nEnter marks in 5 subjects: \n");
        for(int i=0; i<5; i++){
            snprintf(msg, sizeof(msg), "%s: ", Subjects[i]);
            st.marks[i] = ValidateNumber(msg, 0, 100);
        }

        fprintf(file, "%hu\t%.7s\t\t%hu\t%hu\t%hu\t%hu\t%hu\n", st.rollNo, st.name, st.marks[0], st.marks[1], st.marks[2], st.marks[3], st.marks[4]);
        printf("\n");
        Message("Record has been added!");
    }while(ContinueAgain());

    fclose(file);
}
