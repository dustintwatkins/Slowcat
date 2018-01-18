HW 2 - slowcat
 
In this mini-lab homework assignment, you will learn and practice:
 
- Coding and compilation in C, including basic Input/Output
- Accessing environment variables
- Process ID
- Pipelining
- Suspending, backgrounding, and resuming processes
 
For this lab you will implement a basic cat-like program.
 
The usage is as follows:
 
slowcat filename
 
which means that it will take a single filename as input on the command line.
It will determine the value sleep_time by getting the SLOWCAT_SLEEP_TIME environment variable from the environment (see the getenv() function).  If not specified, the sleep time is 1.
Open the file (see the fopen() function); if the filename is "-", then use standard input (stdin).
Print the process ID of the current process to stderr (see the getpid() function).
For each line in the file: a) read the line (see the fgets() function); b) print the line (see the fprintf() function); and c) sleep for sleep_time seconds (see the sleep() function).
Save your file as slowcat.c, and use the command 'gcc -o slowcat slowcat.c' to compile your program.  Here is the file to use for your testing:
 
test.txt  Download
 
Once written, you should do the following from a shell, and save the command and its output to a file:
Execute slowcat such that test.txt is opened by the slowcat program.
Execute slowcat such that test.txt is opened by the shell, which sends it to slowcat's stdin, and slowcat reads it.
Execute slowcat as in #1 above, but specify a sleep time of 5.
Execute a pipeline of 3 slowcats, the first being executed as #1 above
 
Execute slowcat as in #1 above; suspend the process after two lines are read.
Execute slowcat again as in #1 above; suspend the newest process after two lines are read.
List the current jobs.
Background the first suspended instance of slowcat.
Foreground the second suspended instance of slowcat.
Execute slowcat as in #1 above, but in the background.
Submission
Please include 1) your source code, slowcat.c, and 2) your console output from tests 1 - 6 above.  Use the following command to tar/gzip your files:
 
tar -zcvf slowcat.tar.gz slowcat.c slowcat-output.txt
