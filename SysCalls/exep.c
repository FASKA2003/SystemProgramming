#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int ret;
  ret = execvp("nvim", "/home/itsmeayoub/Downloads/linux.txt");
  if (ret == -1) {
    perror("execvp");
  }
  return 0;
}
