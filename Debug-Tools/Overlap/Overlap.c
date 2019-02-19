/**************************************************************************
 * Author	 : RebelIce 杨俊逸
 * Email	 : yangrebelice@gmail.com
 * Github	 : github.com/rebelice
 * ************************************************************************/

#include <string.h>

int main()
{
	char s[50];
	/* Overlap */
	strncpy(s, s + 20, 21);
	return 0;
}
