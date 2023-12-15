#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syscall.h>
#include <unistd.h>

int main() {
  int fd;
  char buffer[] = "/home/itsmeayoub/Documents/Coding/System_Programming/file\n";
  char text[] = "This file is used by the user itsmeayoub:AYOUB EL MAHFOUDI to "
                "store some useful stuff.\n";
  fd = open(buffer, O_RDWR | O_APPEND);
  if (fd >= 0) {
    fprintf(stdout,
            "The file is opened successfully, The file descriptor is %d.\n",
            fd);
  } else {
    fprintf(stdout,
            "An error has happened while trying to open the file, the error "
            "code is %d.\n",
            errno);
    exit(errno);
  }
  int bytes = write(fd, text, sizeof(text));
  if (bytes > 0) {
    fprintf(stdout, "The number of bytes written is %d.\n", bytes);
  } else {
    fprintf(stdout, "The write operation didnot successed.\n");
  }
  close(fd);
}
