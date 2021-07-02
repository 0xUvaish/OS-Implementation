#include <stdio.h>
#include <sys/types.h>       
#include <sys/stat.h>         
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

     int main()
     {
        int fd;
        fd = creat("cse2G2.txt", S_IREAD | S_IWRITE);
        if (fd == -1)
           printf("Error in opening file\n");
        else
           {
           printf("Created file opened for read/write access\n");
           printf("cse2G2.txt is currently empty\n");
           }
        close(fd);
        exit (0);
     }