/**************************************************************************
 * Author	 : RebelIce 杨俊逸
 * Email	 : yangrebelice@gmail.com
 * Github	 : github.com/rebelice
 * ************************************************************************/

#include <stdlib.h>

typedef struct node{
	struct node* parent;
	int v;
}node;

int main()
{
	int i, len = 3;
	node *TreeNode[len];
	for (i = 0; i < len; i++)
		TreeNode[i] = (node *)malloc(sizeof(node));
	TreeNode[1]->parent = TreeNode[0];
	TreeNode[2]->parent = TreeNode[0];
	return 0;
}
