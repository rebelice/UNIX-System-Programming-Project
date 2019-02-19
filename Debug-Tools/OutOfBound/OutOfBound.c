/**************************************************************************
 * Author	 : RebelIce 杨俊逸
 * Email	 : yangrebelice@gmail.com
 * Github	 : github.com/rebelice
 * ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *A;
	int len = 5;
	A = (int *)malloc(sizeof(int) * len);
	/* Out of bound */
	A[len] = 10;
	printf("%d\n", A[len]);
	free(A);
	return 0;
}
