#include <asm-generic/errno-base.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <syscall.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>

int main()
{
  int ret;
  char file_to_read[] = "/home/itsmeayoub/Documents/Coding/System_Programming/filecr";
  char buffer[1024];
  //int len = sizeof(file_to_read);
  int fd;
  fd = open(file_to_read, O_RDWR | O_APPEND);
  if (fd >= 0)
  {
    fprintf(stdout,"The file is opened successfully, The file descriptor is %d.\n",fd);
  } else {
    fprintf(stdout,"An error has happened while trying to open the file, the error code is %d.\n",errno);
    exit(errno);
  }
  ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
  if (bytes_read == -1)
  {
    perror("read");
  }
  if (bytes_read > 0)
  {
    fprintf(stdout,"The number of bytes read is %d.\n",(int)bytes_read);
    fprintf(stdout,"%s", buffer);
  }
  //we will try to get the current offset of the fd ;
  ret = lseek (fd, 0,SEEK_CUR);
  if (ret == (off_t) -1)
  {
    fprintf(stderr, "An error has occured this the value errno %d.\n",errno);
  }
  else {
    fprintf(stdout, "The current offset of the fd :%d is %d.\n",fd,ret);
  }
  close(fd);
}
