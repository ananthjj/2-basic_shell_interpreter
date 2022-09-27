Grade: 101/100

-2 Did not print "Fork failed" when return value of fork() is < 0

-2 The approach for the extra credit was correct but two crucial aspects led to the shell working incorrectly. First, was after setting the SIGALRM to be delivered after 1 second using alarm(1) but never removing it if the child exited sucessfully - this should have been done using alarm(0). Second, you use getpid() in the SIGALRM handler killChild - getpid() returns the pid of the calling process and calling it from the parent process will return the parent's pid. This means you kill the parent parent itself if the child hasn't exited after one second and this happens each time a command is executed. Consequently, after running one command (even a valid command), the shell exits.

+5 Checks WIFEXITED before WEXITSTATUS to see if the child was terminated by a signal. Uses alarm(1) and sets a SIGALARM handler killChild in the parent process. Partial credit for the bonus 

Good job!
