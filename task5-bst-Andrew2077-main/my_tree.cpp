#ifndef MY_TREE_H
#define MY_TREE_H
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

template <class T>
class MyTree{

    private:


	struct Node
		{
    	int data;
    	Node* left = nullptr, *right = nullptr;
 
    	Node() {}
    	Node(int data): data(data) {}
		};

	Node* root;

	Node* insert(Node *root, int key)
		{
    	if (root == nullptr) {
        	return new Node(key);
    	}	
 
    	if (key < root->data) {
        	root->left = insert(root->left, key);
    	}
    	else {
        	root->right = insert(root->right, key);
    	}
    	return root;
		}
 

 	Node* constructBST(const vector<T>& elements,int start, int end ) {
        if (start > end)
            return nullptr;

        size_t midIndex = start + (end - start) / 2;
        Node* root = new Node(elements[midIndex]);

        root->left = constructBST(elements, start, midIndex - 1);
        root->right = constructBST(elements, midIndex + 1, end);

        return root;
    }

 void inorder(Node* root){
    	if (root == nullptr) {
       		return;
    	}
 
    	inorder(root->left);
    	cout << root->data << " ";
    	inorder(root->right);
	}	

	void preOrder(Node* root){
  		if (root != NULL) {
    		cout << root->data << " ";
    		preOrder(root->left);
    		preOrder(root->right);  
		}
	}

	void postOrder(Node* root){
  		if (root != NULL) {
    		postOrder(root->left);
    		postOrder(root->right);
    		cout << root->data << " ";
  		}
	}

	void IterativeInorder(struct Node *root){
            stack<Node *> s;
    		Node *curr = root;
 
    		while (curr != NULL || s.empty() == false)
    		{
        		while (curr !=  NULL)
        		{
            		s.push(curr);
            		curr = curr->left;
        		}

        	curr = s.top();
        	s.pop();
 
	        cout << curr->data << " ";
    	    curr = curr->right;
 
    		} 
    }

    void IterativePreorder(Node* root){
    	if (root == NULL)
        	return;

    	stack<Node*> nodeStack;
    	nodeStack.push(root);
 
 	    while (nodeStack.empty() == false) {

        	struct Node* node = nodeStack.top();
	        printf("%d ", node->data);
    	    nodeStack.pop();
 
    	    if (node->right)
        	    nodeStack.push(node->right);
        	if (node->left)
            	nodeStack.push(node->left);
    	}
	}

	void IterativepostOrder(Node* root){
    	if (root == NULL)
        return;
 
    	stack<Node *> s1, s2;
 
	    s1.push(root);
    	Node* node;
 
	    while (!s1.empty()) {
    	    node = s1.top();
        	s1.pop();
        	s2.push(node);
 
	        if (node->left)
        	    s1.push(node->left);
    	    if (node->right)
            	s1.push(node->right);
    	}
 
   		while (!s2.empty()) {
        	node = s2.top();
        	s2.pop();
        	cout << node->data << " ";
    	}
	}
    
    void levelOrder(Node* root){
  		if (root != NULL) {
    		queue< Node* >q;
		    q.push(root);

    		while(!q.empty()) {
      			Node* current = q.front();
      			cout<<current->data<<" ";
     			if (current->left)
       				q.push(current->left);
     			if (current->right)
      		  		q.push(current->right);
    			q.pop(); 
    		}
  		}
	}

	int sizeOfTree(Node* root){
   		if (root == NULL)
        	return 0;
    	else
        	return(sizeOfTree(root->left) + 1 + sizeOfTree(root->right));
	}

	bool ifNodeExists(struct Node* root, int key){
    	if (root == NULL)
        	return false;
 
    	if (root->data == key)
        	return true;
 
    /* then recur on left subtree */
    	bool res1 = ifNodeExists(root->left, key);
    // node found, no need to look further
   		if(res1) return true;
 
    /* node is not found in left,
    so recur on right subtree */
    	bool res2 = ifNodeExists(root->right, key);
 
    	return res2;
	}


	bool isLeafNode(Node* root){
  		if (root != NULL && root->left == NULL && root->right == NULL)
    	return true;
  	else return false;
	}


	Node* findMin(Node* root){
  		if (root == NULL)
    		return root;
  		else if (root->left == NULL)
    		return root;
  		else return findMin(root->left);
	}	


	Node* findMax(Node* root){
  		if (root == NULL)
    		return root;
  		else if (root->right == NULL)
    		return root;
  		else return findMax(root->right);
	}


	Node* remove(Node* root, int key){
 		Node* temp;

  		if (root == NULL)
    		return NULL;

  		if (key < root->data) {
    		root->left = remove(root->left, key); 
  		}
   		else if (key > root->data) {
    		root->right = remove(root->right, key); 
  		} 
  		else {
  			if (isLeafNode(root)){
    			delete root;
    			root = NULL;
  			} 
  			else if (root->right && root->left) {
    			Node* temp = findMin(root->right);
    			root->data = temp->data;
    			root->right = remove(root->right, root->data);
  			} 
 	 		else {
    			temp = root;
    			if (root->right == NULL)
      				root = root->left;
    			else if (root->left == NULL)
      				root = root->right;
      			delete temp;
    		}
  		}
  	return root;
}
public:
    MyTree(){
        root = NULL;
        }

        void search(T key){
        	if (ifNodeExists(root,key))
    			cout << 1 << " "<< endl;
    		else 
    			cout << 0 << endl ;
       		}

        
        void insert(T key){
            root = insert(root , key);
        	}
        
        void inorder_rec(){
            inorder(root);
            cout << endl;
        }
        
      	void preorder_rec(){
      		preOrder(root);
            cout << endl;
      	}

        
        void postorder_rec(){
            postOrder(root);
            cout << endl;
        }
        
        void inorder_it(){
        	IterativeInorder(root);
        	cout << endl;
        }
        
       	void preorder_it(){
       		IterativePreorder(root);
		    cout << endl;

       	}
        
   	    void postorder_it(){
   	    	IterativepostOrder(root);
   	    	cout <<  endl ;
   	    }

        void breadth_traversal(){
        	levelOrder(root);
        	cout << endl ;
  			
		}

 	    void size(){
 	    	sizeOfTree(root);
 	   		cout <<sizeOfTree(root) << endl ;

 	    }

 	    void remove(T key){
 	    	root = remove (root , key);
	    }

	    void VecTOTree(vector<int> key){
	    	root = constructBST(key, 0, key.size()-1);
	    }
	    

};

#endif

int main() {
    MyTree<int> tree;

	vector<int> Vtree;
    int operation_num;
    int operation_case;
    int tree_size;
	int element;
    
    //cout<< "enter the initial tree size ";
    cin>> tree_size;
    
    //cout<< "enter the number of opeartions";
	cin>> operation_num ;
    
    for (int i = 1 ; i <= tree_size; i++){
        cin	>> element;
		Vtree.push_back(element);
        }
    sort(Vtree.begin(), Vtree.end());
	tree.VecTOTree(Vtree); 
	
	for (int i = 1 ; i <= operation_num ; i ++ ){ 
    //    cout << "choose the opeartion case" ;
		cin >> operation_case ;



		switch (operation_case){
	    	case 1 :
	    		cin	>> element;
	           	tree.insert(element);
	        //   	cout << " Element inserted " << endl ;

	        	break;
	    	case 2 :
            //    cout <<" enter elment to be searched" << endl;
	        	cin>> element;
	       		tree.search(element);
	       		break ;

	       	case 3 :
	       		int inorder_case;
	       	//	cout<< "choose inorder method " << endl;
	       		cin>>inorder_case;


	       		if ( inorder_case == 1){
                //        cout<< "inorder_recursion " << endl;
	       				tree.inorder_rec();
				   }
	       		if ( inorder_case == 2){
                //        cout<< "inorder_itratice " << endl;
	       				tree.inorder_it();
				   }
	       		break;

	        case 4 :
	       		int preorder_case;
	       		cin>>preorder_case;
                //cout<< "choose preorder method " << endl;

	       		if (preorder_case == 1 ){
                //        cout<< "preorder_recursion " << endl;
	       			tree.preorder_rec();
				}
	       		if (preorder_case == 2){
                //        cout<< "preorder_itreative " << endl;
	       				tree.preorder_it();
				   }
	       		break;

	        case 5 :
	       		int postorder_case;
	       		cin>> postorder_case;
                //cout<< "choose postorder method " << endl;

	       		if (postorder_case == 1 ){
                //        cout<< "postorder_recursion " << endl;
	       				tree.postorder_rec();
				   }

	       		if (postorder_case == 2 ){
                //        cout<< "postorder_itreative " << endl;
	       				tree.postorder_it();
				   }
	       		break;

	       	case 6 :
                //cout<< "breadth_traversal " << endl;
	       		tree.breadth_traversal();
	       		break;

	       	case 7 :
                //cout<< "the tree size " << endl;
	       		tree.size();
				cout<<" " ;
	       		break;
	}

};


    return 0; 
}

