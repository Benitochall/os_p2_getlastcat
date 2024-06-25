#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{	
	char buf[512];
  getlastcat(buf); // this will recieve a bunch of args then I can do testing on them
  
	printf (1, "XV6_TEST_OUTPUT Last catted filename: %s\n", buf);    
  // this is where we call the user program
  exit();
}
