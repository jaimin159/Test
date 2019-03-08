#include <stdio.h>
#include <string.h>

#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main()
{
  int fd1,ret; 
  char * myfifo = "/tmp/myfifo"; 		// FIFO file path 
  mkfifo(myfifo, 0666);	// Creating the named file(FIFO), mkfifo(<pathname>,<permission>)

  fd1 = open(myfifo,O_RDONLY | O_NONBLOCK);	// Open fifo in nonblockng mode

  // Set pipe in non-blocking Mode
  int flag1 = fcntl(fd1, F_GETFL, 0);
  if(fcntl(fd1, F_SETFL, flag1 | O_NONBLOCK))
    fprintf(stderr, "Error setting non_blocking mode fifo");

  return 0;
}