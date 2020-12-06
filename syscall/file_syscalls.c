#include <types.h>
#include <lib.h>
#include <kern/unistd.h>
#include <syscall.h>
int sys_write(int fd, const void *buf,size_t size)
{
	if(fd!= STDOUT_FILENO && fd != STDERR_FILENO)
    {
        kprintf("sys_write only accepts stdout!");
        return -1;
    }
	size_t i;
    char *p= (char *) buf;
	for(i=0; i < size; i++)
	{
		putch(p[i]);
	}
	return (int)size;
}

int sys_read(int  fd, void *buf, size_t size)
{	
	if(fd!= STDIN_FILENO)
    {
        kprintf("sys_read only accepts stdin!");
        return -1;
    }
	size_t i;
	char *p= (char *) buf;
	size_t count = 0;
	for(i=0; i < size; i++)
	{	
		p[i] = getch();
		if(p[i] == '\n' || p[i]=='\r')
		{
            return count+1;
		}
		else if(p[i]<0)
        {
            return count;
        }
        count++;    
	}
    
    return (int)size;
}
