
typedef bool __rb_tree_color_type;
const __rb_tree_color_type __rb_tree_red = false;
const __rb_tree_color_type __rb_tree_black = true;

struct __rb_tree_node_base
{
	typedef __rb_tree_color_type color_type;
	typedef __rb_tree_node_base* base_ptr;

	color_type color;
	base_ptr parent;
	base_ptr left;
	base_ptr right;
};

using tree_node = __rb_tree_node_base;

/*******************************
        x
    y
a      (c)
*******************************/
void rotate_right(tree_node * x, tree_node *& root)
{
	auto y = x->left;
	x->left = y->right;
	if (y->right)
		y->right->parent = x;

	if (x == root)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->parent = x->parent;
	x->parent = y;
}

/*******************************
 x
    y
(c)    a
*******************************/
void rotate_left(tree_node * x, tree_node *& root)
{
	auto y = x->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->parent = x->parent;

	if (x == root)
		root = y;
	else if (x == x->parent->right)
		x->parent->right = y;
	else
		x->parent->left = y;

	y->left = x;
	x->parent = y;
}

int main()
{
	return 0;
}






