/**************************************************************************
 * Author	 : RebelIce 杨俊逸
 * Email	 : yangrebelice@gmail.com
 * Github	 : github.com/rebelice
 * ************************************************************************/

#include <stdlib.h>

int main()
{
	int *a = malloc(sizeof(int));
	*a = 10;
	free(a);
	/* Invalid */
	*a = 10;
	/* Invalid */
	free(a);
	return 0;
}
