#include <iostream>
#include <string>
#define st_num 3

bool operator >(const std::string& str1, const std::string& str2)
{
	if (str1.size() == str2.size()) {
		for (int i = 0; i < str1.size(); i++)
		{
			if (str1[i] != str2[i]) {
				return str1[i] > str2[i];
			}
		}
	}
	else {
		return str1.size() > str2.size();
	}
}
bool operator <(const std::string& str1, const std::string& str2)
{
	return !operator>(str1, str2) && !operator==(str1, str2);
}
class Tree
{

	struct Node
	{
		int value;	// кол. одинаковых работ
		bool students[st_num] = { false, false, false };
		std::string str;
		Node* left;
		Node* right;
		int height;
		Node() :value(1), left(NULL), right(NULL), height(1) {}
		~Node()
		{
			delete left; delete right;
		}
	};
	Node* root;
	Node* CreateNode(const std::string& str, bool students[])
	{
		Node* new_node = new Node;
		new_node->str = str;
		for (int i = 0; i < st_num; i++) {
			new_node->students[i] = new_node->students[i] || students[i];
		}
		return new_node;
	}

	int hight(Node* node)
	{
		return node ? node->height : 0;
	}
	//public:		////////////////////////////////////////////////////
	int balanc(Node* node)
	{
		return hight(node->right) - hight(node->left);
	}

	void fix(Node* node)
	{
		int heightl = hight(node->left);
		int heightr = hight(node->right);

		node->height = (heightl > heightr ? heightl : heightr) + 1;
	}

	Node* rotate_right(Node* node)
	{
		Node* temp = node->left;
		node->left = temp->right;
		temp->right = node;
		fix(node);
		fix(temp);
		return temp;
	}

	Node* rotate_left(Node* node)
	{
		Node* temp = node->right;
		node->right = temp->left;
		temp->left = node;
		fix(node);
		fix(temp);
		return temp;
	}

	Node* balance(Node* node)
	{
		fix(node);
		if (balanc(node) == 2)
		{
			if (balanc(node->right) < 0)
			{
				node->right = rotate_right(node->right);
			}
			return rotate_left(node);
		}
		if (balanc(node) == -2)
		{
			if (balanc(node->left) > 0)
			{
				node->left = rotate_left(node->left);
			}
			return rotate_right(node);
		}
		return node;
	}

	//int exist(Node* node, const std::string& str)
	//{
	//	if (node == NULL)
	//	{
	//		return 0;
	//	}
	//	if (str == node->str)
	//	{
	//		return 1;
	//	}
	//	if (str > node->str)
	//	{
	//		return exist(node->right, str);
	//	}
	//	else
	//		return exist(node->left, str);
	//}

	Node* RecursiveInsert(Node* node, const std::string& str, bool students[])
	{
		if (node == NULL) {
			return CreateNode(str, students);
		}
		else if (str == node->str) {

			for (int i = 0; i < st_num; i++) {
				node->students[i] = node->students[i] || students[i];
			}
			node->value++;
		}
		else if (str < node->str) {
			node->left = RecursiveInsert(node->left, str, students);
		}
		else {
			node->right = RecursiveInsert(node->right, str, students);
		}
		if (node != root) {		// !!!!!!!!!!!!!!!!!!!
			return balance(node);
		}
		return nullptr;
	}
	void RecursiveOutputGrades(Node* node, int grades[])
	{
		if (node != NULL) {
			for (int i = 0; i < st_num; i++) {
				if (node->students[i]) {
					switch (node->value)
					{
					case 1:
						grades[i] += 3;
						break;
					case 2:
						grades[i] += 1;
						break;
					case 3:
						break;
					default:
						;
					}
				}
			}
			RecursiveOutputGrades(node->left, grades);
			RecursiveOutputGrades(node->right, grades);
		}
	}
	
public:
	Tree() :root(NULL) {}
	void Insert(const std::string& str, bool students[])
	{
		if (root == NULL) {
			root = CreateNode(str, students);
		}
		else {
			RecursiveInsert(root, str, students);
			root = balance(root);
		}

	}
	void OutputGrades()
	{
		int grades[st_num] = { 0, 0, 0 };
		RecursiveOutputGrades(root, grades);
		for (int i = 0; i < st_num; i++) {
			std::cout << grades[i] << ' ';
		}
	}
};

int main()
{
	using namespace std;
	Tree tree; string str;
	int n;
	bool students[st_num];
	cin >> n;
	for (int i = 0; i < st_num; i++) {
		for (int k = 0; k < st_num; k++) {
			students[k] = false;
		}
		students[i] = true;
		for (int j = 0; j < n; j++) {
			cin >> str;
			tree.Insert(str, students);
		}
	}
	tree.OutputGrades();
}
