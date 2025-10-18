#include<unistd.h>
#include<string.h>

void main()
{

size_t len;
int msg_len = 0;
char buf[100];
strncpy(buf,"i use write function write() to use this",99);
msg_len = strlen(buf);
len = write(1,buf,msg_len);
}

