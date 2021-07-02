#include <fcntl.h>         
#include <sys/types.h>     
#include <sys/stat.h>      
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
     int main()
     {
        int fd;
        long position;

        fd = open("cse2G2.txt", O_RDONLY);
        if ( fd != -1)
           {
           position = lseek(fd, 0, 2);  /* seek 0 bytes from end-of-file */
           if (position != -1)
              printf("The length of cse2G2.txt is %ld bytes.\n", position);
           else
              perror("lseek error");
           }
        else
           printf("can't open cse2G2.txt\n");         
        close(fd);
     }