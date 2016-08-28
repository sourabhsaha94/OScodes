#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
  printf("Hello world (pid:%d)\n",(int)getpid());
  int rc=fork();

  if(rc<0){
    fprintf(stderr,"fork failed");
    exit(1);
  }else if(rc==0){
    printf("This is child (pid:%d)\n",(int)getpid());
  }else{
    int wc = wait(NULL);

    printf("This is parent of %d (wc:%d)(pid:%d)",rc,wc,(int)getpid());
  }
  return 0;
}

/*OUTPUT
Hello world (pid:4460)
This is child (pid:4461)
This is parent of 4461 (wc:4461)(pid:4460)*/
