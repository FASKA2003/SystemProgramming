#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int ret;
  ret = execl("/bin/vi", "/home/itsmeayoub/Downloads/linux.txt", NULL);
  if (ret == -1) {
    perror("execl");
  }
  return 0;
}
