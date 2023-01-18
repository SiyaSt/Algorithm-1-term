#include <iostream>
#include <string>


bool operator >( std::string& str1, std::string& str2)
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
bool operator <( std::string& str1,  std::string& str2)
{
	return !operator>(str1, str2) && !operator==(str1, str2);
}

	struct Node
	{
		int value;	// кол. одинаковых работ
		std::string str;
		Node* left;
		Node* right;
		int height;
		Node() :value(0), left(NULL), right(NULL), height(1) {}
		~Node()
		{
			delete left; delete right;
		}
	};

	Node* CreateNode( std::string& str)
	{
		Node* new_node = new Node;
		new_node->str = str;
		return new_node;
	}

	int hight(Node* node)
	{
		return node ? node->height : 0;
	}

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
	int sumator = 0;
	Node* RecursiveInsert(Node* node, std::string& str) // !!!
	{
		if (node == NULL) {
			return CreateNode(str);
		}
		else if (str == node->str) {
			int i;
			int j;
			std::string str2 = "";
			i = 0;
			while (str[i] != '\0') {
				j = 0;
				while (str2[j] != '\0') 
				{
					if (str[i] == str2[j]) 
					{
						break;
					}
					j++;
				}
				if (str2[j] == '\0') 
				{
					str2.push_back(str[i]);
				}
				i++;
			}
			sumator += str2.size();
		}
		else if (str < node->str) {
			node->left = RecursiveInsert(node->left, str);
		}
		else {
			node->right = RecursiveInsert(node->right, str);
		}
		
		return balance(node);
	}


int main()
{
	using namespace std;
	int number;
	int* value = new int;
	cin >> number;

	Node* tree = new Node; 
	string str;
	tree = NULL;
	for (int i = 0; i < number; i++)
	{
		cin >> str;
		tree = RecursiveInsert(tree, str);
	}
	cout << sumator;

}
