#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
void main()
{
char buffer;
int fd, fd_new;
fd = open("cse2G2.txt", O_RDONLY);
if (fd == -1)
{
printf("Error opening first_file\n");
close(fd);
return;
}
fd_new = open("newfile.txt", O_WRONLY | O_CREAT);
while(read(fd, &buffer, 1))
{
write(fd_new, &buffer, 1);
}
printf("Successfully Copied\n");
close(fd);
close(fd_new);
}