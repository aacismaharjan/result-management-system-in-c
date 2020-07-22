#include "RMS_func.h"

void SoftwareInfo(){
    char paragraph[100];

    FILE *file;
    file = fopen(info_file_path, "r");

    system("cls");
    while(fgets(paragraph, sizeof(paragraph), file)){
        printf("%s", paragraph);
    }
    printf("\n");
    PauseScreen();
    fclose(file);
}
