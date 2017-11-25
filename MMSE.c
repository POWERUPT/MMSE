#include <stdio.h>
#include <stdlib.h>

int main () {
    int choice;

    char filename[255];
    int fsize;
    unsigned int magic;
    unsigned int a = 0x01;
    unsigned int b = 0x00;
    //unsigned int value[2];

    printf("Input save name\n");
    scanf("%s",filename);

    while(1) {

        FILE *f;
        f = fopen(filename,"r+b");

        if (f == NULL) {
            printf("Could not open save!\n");
            return(1);
        }

        fseek(f, 0x00, SEEK_SET);
        fread(&magic, sizeof(unsigned int), 1, f);

        if (magic != 541281859 ) {    // I know this is bad
            printf("Invalid header!\n");
            return(2);
        }

        fseek(f, 0x00, SEEK_END);
        fsize = ftell(f);
        fseek(f, 0x00, SEEK_SET);

        if (fsize != 0x36 ) {
            printf("Invalid size!\n");
            return(3);
        }

        printf("###########################\n");
        printf("# Meegah Meme save editor #\n");
        printf("###########################\n\n");
        printf("(1) or (11) BUMBMEM state\n");
        printf("(2) or (22) GLUTZMEM state\n");
        printf("(3) or (33) KUTMEM state\n");
        printf("(4) or (44) LECKMEM state\n");
        printf("(5) or (55) ICMEM state\n");
        printf("(6) or (66) FARMEM state\n");
        //printf("(7) Set number of ROBATMESTRZ\n");
        printf("(8) Exit\n\n");
        scanf(" %d", &choice);

        switch(choice) {
        case(1):
            fseek(f, 0x1e, SEEK_SET );
            fwrite(&a,sizeof(unsigned int),1,f);
            printf("BUMBMEM is dead\n\n");
            fclose(f);
            break;
        }

        switch(choice) {
        case(2):
            fseek(f, 0x22, SEEK_SET );
            fwrite(&a,sizeof(unsigned int),1,f);
            printf("GLUTZMEM is dead\n\n");
            fclose(f);
            break;
        }

        switch(choice) {
        case(3):
            fseek(f, 0x26, SEEK_SET );
            fwrite(&a,sizeof(unsigned int),1,f);
            printf("KUTMEM is dead\n\n");
            fclose(f);
            break;
        }

        switch(choice) {
        case(4):
            fseek(f, 0x2a, SEEK_SET );
            fwrite(&a,sizeof(unsigned int),1,f);
            printf("LECKMEM is dead\n\n");
            fclose(f);
            break;
        }

        switch(choice) {
        case(5):
            fseek(f, 0x2e, SEEK_SET );
            fwrite(&a,sizeof(unsigned int),1,f);
            printf("ICMEM is dead\n\n");
            fclose(f);
            break;
        }

        switch(choice) {
        case(6):
            fseek(f, 0x32, SEEK_SET );
            fwrite(&a,sizeof(unsigned int),1,f);
            printf("FARMEM is dead\n\n");
            fclose(f);
            break;
        }

        //switch(choice) {
        //case(7):
            //printf("Input value\n");
            //scanf("%x",value);        // Undesired effects if not hex
            //fseek(f, 0x12, SEEK_SET );
            //fwrite(&value,sizeof(unsigned int),1,f);
            //printf("Value set\n\n");
            //fclose(f);
            //break;
        //}

        switch(choice) {
        case(8):
            exit(0);
            break;
        }

        switch(choice) {
        case(11):
            fseek(f, 0x1e, SEEK_SET );
            fwrite(&b,sizeof(unsigned int),1,f);
            printf("BUMBMEM is alive\n\n");
            fclose(f);
            break;
        }

        switch(choice) {
        case(22):
            fseek(f, 0x22, SEEK_SET );
            fwrite(&b,sizeof(unsigned int),1,f);
            printf("GLUTZMEM is alive\n\n");
            fclose(f);
            break;
        }

        switch(choice) {
        case(33):
            fseek(f, 0x26, SEEK_SET );
            fwrite(&b,sizeof(unsigned int),1,f);
            printf("KUTMEM is alive\n\n");
            fclose(f);
            break;
        }

        switch(choice) {
        case(44):
            fseek(f, 0x2a, SEEK_SET );
            fwrite(&b,sizeof(unsigned int),1,f);
            printf("LECKMEM is alive\n\n");
            fclose(f);
            break;
        }

        switch(choice) {
        case(55):
            fseek(f, 0x2e, SEEK_SET );
            fwrite(&b,sizeof(unsigned int),1,f);
            printf("ICMEM is alive\n\n");
            fclose(f);
            break;
        }

        switch(choice) {
        case(66):
            fseek(f, 0x32, SEEK_SET );
            fwrite(&b,sizeof(unsigned int),1,f);
            printf("FARMEM is alive\n\n");
            fclose(f);
            break;
        }

    }
    return(0);
}
