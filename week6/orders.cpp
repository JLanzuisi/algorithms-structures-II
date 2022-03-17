#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct TreeNode {
	public:
	string value;
	TreeNode *firstChild,
			 *nextSibling;
	TreeNode (string s) {
		value = s;
		firstChild = NULL;
		nextSibling = NULL;
	}
	TreeNode (string s, TreeNode *fc, TreeNode *ns) {
		value = s;
		firstChild = fc;
		nextSibling = ns;
	}
};


void preorder(TreeNode *n) {
	if (n == NULL)
		return;
	cout << n->value << " ";
	preorder(n->firstChild);
	preorder(n->nextSibling);
}

void postorder(TreeNode *n) {
	if (n == NULL)
		return;
	postorder(n->firstChild);
	cout << n->value << " ";
	postorder(n->nextSibling);
}


int main() {

	TreeNode *T;
	
	T = new TreeNode("*",
			new TreeNode("+",
				new TreeNode("23", NULL,
					new TreeNode("5", NULL, NULL)),
				new TreeNode("/",
					new TreeNode("100",NULL,
						new TreeNode("5", NULL, NULL)),
					NULL)),
			NULL);

	preorder(T);
	cout << endl;
	postorder(T);
	cout << endl;

	return 0;
}
