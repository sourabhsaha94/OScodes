#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    char *myargs[3];
    myargs[0]=strdup("wc"); //wc is command for wordcount
    myargs[1]=strdup("fork-wait-exec.c");
    myargs[2]=NULL;

    execvp(myargs[0],myargs);
    
  }else{
    int wc = wait(NULL);

    printf("This is parent of %d (wc:%d)(pid:%d)",rc,wc,(int)getpid());
  }
  return 0;
}
/*OUTPUT
Hello world (pid:5384)
This is child (pid:5385)
 30  51 627 fork-wait-exec.c
 This is parent of 5385 (wc:5385)(pid:5384)*/
