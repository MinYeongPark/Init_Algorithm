#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

typedef struct node* TreeNode;
typedef struct node {
	char data;
	TreeNode left, right;
} node;

// 전위순회
void preorder(TreeNode tree) {
	if (tree != NULL) {
		printf("%c", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

// 중위순회
void inorder(TreeNode tree) {
	if (tree != NULL) {
		inorder(tree->left);
		printf("%c", tree->data);
		inorder(tree->right);
	}
}

// 후위순회
void postorder(TreeNode tree) {
	if (tree != NULL) {
		postorder(tree->left);
		postorder(tree->right);
		printf("%c", tree->data);
	}
}

int main() {
	int N;
	scanf("%d", &N);

	node *nodes = (node*)malloc(sizeof(node) * N);
	int num;        // 현재 입력받는 노드의 인덱스

	for (int i = 0; i < N; i++) {
		getchar();
		char x, y, z;
		scanf("%c %c %c", &x, &y, &z);
		
		num = (int) x - 'A';
		nodes[num].data = x;

		if (y == '.') {
			nodes[num].left = NULL;
		}
		else {
			nodes[num].left = &nodes[y - 'A'];
		}
		
		if (z == '.') {
			nodes[num].right = NULL;
		}
		else {
			nodes[num].right = &nodes[z - 'A'];
		}
	}

	preorder(&nodes[0]);
	cout << "\n";
	inorder(&nodes[0]);
	cout << "\n";
	postorder(&nodes[0]);
	
	return 0;
}
