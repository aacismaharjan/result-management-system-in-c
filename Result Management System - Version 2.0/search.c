#include "RMS_func.h"
void SearchRecord(){
    int op;
    bool close = false;

    struct Menu Nav = {"SEARCH RECORDS ON DATABASE:", {"Search by Roll Number", "Search by Name", "Back"}, 3};

    do{
        system("cls");
        op = DisplayMenu(Nav);

        switch(op){
            case 1:
                SearchRecordBy("rollno");
                break;
            case 2:
                SearchRecordBy("name");
                break;
            case 3:
                close = true;
                break;
            default:
                close = true;
                break;
        }
    }while(close == false);
}

void SearchRecordBy(char* searchType){
    struct Student st;
    struct Student temp;
    struct Student search;

    int count = 0;

    FILE *file;
    file = fopen(file_path, "r");

    system("cls");
    if(strcmp(strlwr(searchType), strlwr("rollno"))==0){
        search.rollNo = ValidateNumber("Enter roll number: ", 0, 100);
        while(fscanf(file, "%hu%s%hu%hu%hu%hu%hu", &st.rollNo, st.name, &st.marks[0], &st.marks[1], &st.marks[2], &st.marks[3], &st.marks[4])!=EOF){
            temp = st;
            if((search.rollNo == temp.rollNo)){
                DisplaySheet(st);
                count++;
            }
        }
        if(count==0){
            msgDottedLines;
            printf("We couldn't find student with Roll number \"%d\". Please Try Again!\n", search.rollNo);
            msgDottedLines;
        }
    }else if(strcmp(strlwr(searchType), strlwr("name"))==0){
        printf("Enter name: ");
        scanf(" %s", search.name);
        while(fscanf(file, "%hu%s%hu%hu%hu%hu%hu", &st.rollNo, st.name, &st.marks[0], &st.marks[1], &st.marks[2], &st.marks[3], &st.marks[4])!=EOF){
            temp = st;
            if(strcmp(strlwr(search.name), strlwr(temp.name))==0){
                DisplaySheet(st);
                count++;
            }
        }
        if(count==0){
            msgDottedLines;
            printf("We couldn't find student with Name \"%s\". Please Try Again!\n", search.name);
            msgDottedLines;
        }
    }
    fclose(file);
    PauseScreen();
}
