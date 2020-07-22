#include "RMS_func.h"

void RunRMS(){
    bool cancel = false;
    LoadingScreen();
    filesAddress();
    Subjects = &GRADE_12_COMMERCE_SUBS;
    struct Menu Nav = {"Choose following option to take action:", {"Add Record", "Marks Ledger", "Filter Record", "Search Record", "Delete Record", "More Options", "Exit"}, 7};

    CheckFileStatus();
    do{
        switch(DisplayMenu(Nav)){
            case 1:
                AddRecord();
                break;
            case 2:
                DisplayMarksLedger();
                PauseScreen();
                break;
            case 3:
                FilterRecord();
                break;
            case 4:
                SearchRecord();
                break;
            case 5:
                DeleteRecord();
                break;
            case 6:
                MoreMenu();
                break;
            case 7:
                cancel = true;
                break;
            default:
                break;
        }
    }while(cancel==false);
    ExitProgram();
}

void MoreMenu(){
    bool cancel = false;
    struct Menu Nav = {"SEARCH RECORDS ON DATABASE:", {"Software Information", "GPA Details", "Back"}, 3};

    do{
        switch(DisplayMenu(Nav)){
            case 1:
                SoftwareInfo();
                break;
            case 2:
                GPADetails();
                break;
            case 3:
                cancel = true;
                break;
            default:
                break;
        }
    }while(cancel == false);
}

int DisplayMenu(struct Menu Nav){
    int Select = 0;
    do{
        system("cls");
        smDottedLines;
        printf("%s\n", Nav.head);
        for(int i=0; i<Nav.total; i++){
            printf("%d. %s\n", i+1, Nav.items[i]);
        }
        smDottedLines;
        printf("\n");
        Select = ValidateNumber("Select: ", 1, Nav.total);
    }while(Select < 1 || Select > Nav.total);
    return Select;
}
