#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

int main(int argc,char ** argv) {
  int i;
  char buf[4096];
  int fd = open("/dev/mem", O_RDWR | O_SYNC);
  uint8_t * mem =
    (uint8_t *) mmap
    ( 0,
      1,
      PROT_WRITE, MAP_SHARED,
      fd,
      0xE0001000
    );
  int len = 0;
  if(argc != 2) {
    fprintf(stderr, "%s takes exactly one string.\n",argv[0]);
    return 1;
  }
  len = strlen(argv[1]);
  if(len >= 4096) { 
    len = 4095;
  }
  memcpy(buf,argv[1],len);
  buf[len] = 0;
  for(i = 0; i <=len ; i++) {
    mem[i] = buf[i];
  }
  mem = 
    (uint8_t *) mmap (0, 1, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0xE0000000);
  mem[0] = 1;
}
