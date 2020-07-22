#include "RMS_func.h"

void DeleteRecord() {
    int op, count;
    bool close = false;

    FILE *file;
    FILE *tempfile;

    struct Student search, st, temp;
    struct Menu Nav = {"SEARCH RECORDS ON DATABASE:", {"Delete by Roll Number", "Delete by Name", "Back"}, 3};

    do{
        count = 0;
        op = DisplayMenu(Nav);
        printf("\n");

        system("cls");
        switch(op){
            case 1:
                search.rollNo = ValidateNumber("Delete by Roll Number: ", 1, 100);
                break;
            case 2:
                printf("Delete by Name: ");
                scanf(" %s", search.name);
                break;
            default:
                return;
        }

        printf("\n");
        file = fopen(file_path, "r");
        while(fscanf(file, "%hu%s%hu%hu%hu%hu%hu", &st.rollNo, st.name, &st.marks[0], &st.marks[1], &st.marks[2], &st.marks[3], &st.marks[4])!=EOF){
            strcpy(temp.name, st.name);
            if((op==1 && search.rollNo!=st.rollNo) || (op==2 && strcmp(strlwr(search.name), strlwr(temp.name))!=0)){
                tempfile = fopen(temp_file_path, "a");
                fprintf(tempfile, "%d\t%s\t\t\t%d\t%d\t%d\t%d\t%d\n", st.rollNo, st.name, st.marks[0], st.marks[1], st.marks[2], st.marks[3], st.marks[4]);
                fclose(tempfile);
            }else{
                count++;
            }
        }
        fclose(file);

        if (remove(file_path)) {
            perror("Couldn't Remove the file: ");
        }else {
            if(rename(temp_file_path, file_path)) {
                perror("Couldn't Rename the file: ");
            }else {
                if(count == 0) Message("Please try again! We could not find your record.");
                else Message("Task Successful! Your record has been deleted.");
            }
        }
        PauseScreen();
    }while(close == false);
}
