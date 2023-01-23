#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int
main(int argc, char *argv[])
{
	int pipefd[2];
	int pipefd2[2];
	pid_t cpid;
	char buf1[5];
	char buf2[5];
	int i;
	struct timeval t0;
	struct timeval t1;

	if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
               exit(EXIT_FAILURE);
           }

           if (pipe(pipefd) == -1) {
               perror("pipe");
               exit(EXIT_FAILURE);
           }

		   if (pipe(pipefd2) == -1){
				perror("pipe");
				exit(EXIT_FAILURE);
		   }
			gettimeofday(&t0,0);
           cpid = fork();
           if (cpid == -1) {
               perror("fork");
               exit(EXIT_FAILURE);
           }

           if (cpid == 0) {    /* Child reads from pipe */
               close(pipefd[1]);          /* Close unused write end */
				close(pipefd2[0]); // close read end, only use write
               while (read(pipefd[0], &buf1, 5) >0){
				   write(pipefd2[1], "pong\n", 5);
			   }
               close(pipefd[0]);
               _exit(EXIT_SUCCESS);

           } else {            /* Parent writes argv[1] to pipe */
               close(pipefd[0]);          /* Close unused read end */
			   close(pipefd2[1]);
				for (i = 0; i< 100000; i++)  {
					write(pipefd[1], "ping\n", 5);
					if (read(pipefd2[0], &buf2, 5) > 0 ){
//						write(STDOUT_FILENO, &buf2, 5);
						//write(STDOUT_FILENO, "\n", 1);
					}
				}
               //write(pipefd[1], argv[1], strlen(argv[1]));
               close(pipefd[1]);          /* Reader will see EOF */
               wait(NULL);/* Wait for child */
			   gettimeofday(&t1, 0);
			   printf("elapsed: %f\n", timedifference_msec(t0, t1));
               exit(EXIT_SUCCESS);

           }
       }

