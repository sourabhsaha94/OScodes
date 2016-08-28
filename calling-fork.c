#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
  printf("Hello world (pid:%d)",(int)getpid());
  int rc = fork();
  if(rc<0) {
    fprintf(stderr,"fork failed\n");
    exit(1);
  }else if(rc==0){//child(new process)
    printf("This is child (pid:%d)\n",(int)getpid());
  }else{//parent
    printf("This is parent of %d (pid:%d)\n",rc,(int)getpid());
  }
  return 0;
}

/*OUTPUT

Hello world (pid:3559)This is parent of 3560 (pid:3559)
Hello world (pid:3559)This is child (pid:3560)
*/
