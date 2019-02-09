/**************************************************************************
 * Author	 : RebelIce 杨俊逸
 * Email	 : yangrebelice@gmail.com
 * Github	 : github.com/rebelice
 * ************************************************************************/

#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[])
{
	int i;
	
	for (i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);

	/* Another way */
/*	for (i = 0; argv[i] != NULL; i++)
		printf("argv[%d]: %s\n", i, argv[i]);
*/

	/* Here exit(0); is same as retuen 0; */
//	exit(0);
	return 0;
}
