#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t pid;

	pid = fork();		// fork()를 호출하는 동시에 실행중인 프로세스와
						// 동일한 프로세스가 pid=0으로 생성되고, 실행된다.

	if(pid < 0)
	{
		fprintf(stderr, "Fork Failed\n");
		exit(-1);
	}
	else if(pid == 0){
		// 생성된 자식 프로세스에 의해서 ls 명령이 실행된다.
		execlp("/bin/ls","ls", NULL);
	}
	else {
		wait(NULL);
		// 자식 프로세스가 완료된 후 아래의 printf가 실행된다.
		printf("Child Complete\n");
		exit(0);
	}
	
	return 0;
}

