#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define TIMEOUT 5
#define BUF_LEN 1024

int main (void)
{
  struct timeval tv;
  fd_set readfs;
  int ret;

  //wait on stdin fir input
  FD_ZERO(&readfs);
  FD_SET(STDIN_FILENO, &readfs);

  //wait up to five seconds
  tv.tv_sec = TIMEOUT;
  tv.tv_usec = 0;

  //Non Block
  ret = select(STDIN_FILENO+1 , &readfs, NULL, NULL, &tv);
  if (ret == -1)
  {
    perror("select");
    return 1;
  } else if (!ret) {
    fprintf(stdout, "%d seconds elapsed.\n",TIMEOUT);
    return 0;
  }

  if (FD_ISSET(STDIN_FILENO, &readfs)) {
    char buf[BUF_LEN+1];
    int len;
    len = read(STDIN_FILENO, buf, BUF_LEN);
    if (len == -1) {
      perror("read");
      return 1;
    }

    if (len > 0) {
      buf[len] = '\0';
      fprintf(stdout, "read : %s\n", buf);
    }

    return 0;
  }

  fprintf(stderr, "This should not happen!\n");
  return 1;

}
