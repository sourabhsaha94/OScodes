#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
  printf("Hello world (pid:%d)\n",(int)getpid());
  int rc=fork();

  if(rc<0){
    fprintf(stderr,"fork failed");
    exit(1);
  }else if(rc==0){//child: redirect standard output to a different file
    close(STDOUT_FILENO);
    open("fwe-redirect.output",O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

    char *myargs[3];
    myargs[0]=strdup("wc"); //wc is command for wordcount
    myargs[1]=strdup("fwe-redirect.c");
    myargs[2]=NULL;

    execvp(myargs[0],myargs);
    
  }else{
    int wc = wait(NULL);

    printf("This is parent of %d (wc:%d)(pid:%d)",rc,wc,(int)getpid());
  }
  return 0;
}
/*OUTPUT
>cat fwe-redirect.output 
 33  58 743 fwe-redirect.c
*/
