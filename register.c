#include <stdio.h>
#include <string.h>

int registerV(){
    FILE *file = fopen("register.csv", "a");

    if (file == NULL) {
        printf("Can't open the file.\n");
        return 1;
    }

    // ทำการลูปและบันทึกข้อมูลลงในไฟล์
    while (1==1)
    {
        char number[10];
        printf("Enter numbers (Enter END to stop.): ");// ป้อนข้อมูลจากผู้ใช้
        scanf("%s", number);
        if (strcmp("END",number)==0){
            fclose(file);// ปิดไฟล์
            break;
        }
        else{
            fprintf(file, "%s\n", number);
            printf("The information is saved in a file. register.csv\n");
    }
    }
    
    return 0;
}




int main() {
    registerV();
}