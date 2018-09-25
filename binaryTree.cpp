#include <iostream>

using namespace std;

template<class ItemType>
struct TreeNode{
	ItemType info;
	TreeNode<ItemType>* left;
	TreeNode<ItemType>* right;
};

enum OrderType{
	PRE_ORDER, 
	IN_ORDER, 
	POST_ORDER
};

template<class ItemType>
class TreeType{
	public:
		TreeType();
		~TreeType();
		TreeType(const TreeType<ItemType>&);
		void operator=(const TreeType<ItemType>&);
		void MakeEmpty();
		bool IsEmpty() const;
		bool IsFull() const;
		int NumberOfNodes() const;
		void RetriveItem(ItemType&, bool& found);
		void InsertItem(ItemType);
		void DeleteItem(ItemType);
		void ResetTree(OrderType);
		void GetNextItem(ItemType&, OrderType, bool&);
		void PrintTree(ofstream&) const;
	private:
		TreeNode<ItemType>* root;
};

template<class ItemType>
int TreeType<ItemType>::NumberOfNodes() const{
	return CountNodes(root);
}

template<class ItemType>
int CountNodes(TreeNode<ItemType>* tree){
	if(tree == NULL){
		return 0;
	}else{
		// this is run time O(N)
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;
	}
}

template<class ItemType>
void Retrive(TreeNode<ItemType>* tree, ItemType& item, bool& found){
	if(tree == NULL){
		found = false;
	}else if(item < tree->info){
		Retrieve(tree->left, item, found);
	}else if(item > tree->info){
		Retrieve(tree->right, item, found);
	}else{
		item = tree->info;
		found = true;
	}
}

template<class ItemType>
void TreeType<ItemType>::RetriveItem(ItemType& item, bool& found){
	Retrive(root, item, found);
}

template<class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item){
	Insert(root, item);
}

template<class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item){
	if(tree == NULL){
		tree = new TreeNode<ItemType>;
		tree->right = NULL;
		tree->left = NULL;
		tree->info = item;
	}else if(item < tree->info){
		Insert(tree->left, item);
	}else{
		Insert(tree->right, item);
	}
}

template<class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item){
	Delete(root, item);
}

template<class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item){
	if(item < tree->info){
		Delete(tree->left, item);
	}else if(item > tree->info){
		Delete(tree->right, item);
	}else{
		DeleteNode(tree);
	}
}

template<class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree){
	ItemType item;
	TreeNode<ItemType>* tempPtr;
	tempPtr = tree;
	if(tree->left == NULL){
		tree = tree->right;
		delete tempPtr;
	}else if(tree->right == NULL){
		tree = tree->left;
		delete tempPtr;
	}else{
		GetPredecessor(tree->left, item);
		tree->info = item;
		Delete(tree->left, item);
	}
}

template<class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& item){
	while(tree->right != NULL){
		tree = tree->right;
	}
	item = tree->info;
}

int main(){

return 0;
}
