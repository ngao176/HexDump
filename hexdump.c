#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv) {

    if(argc > 2){
        printf("Please input only 1 file\n");
        return 0;
    }

    if(argc < 2){
        printf("Please input a file\n");
    }

    int file = open(argv[1], O_RDONLY);
    char buf[1000];
    int c;
    



    int buffer = read(file, buf,1000);


    int line=0;
    int i=0;
    int y = 7;
    while(i < buffer){

        if(i%16 == 0 && line > 0){
            printf("\n%08x  ",line*16);
            line++;
        }

        if(line ==0){
            printf("%08x  ",line);
            line++;
        }
        

        printf("%02X ",buf[i]);

        if(i == y){
            printf(" ");
            y=y+16;
        }

        i++;
        

    }

    return 0;

}
