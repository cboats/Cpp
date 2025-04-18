//Aleksandra Prodziewicz
template<typename KEY_TYPE, typename DATA_TYPE>
class BST {
public:
    struct Node {
        KEY_TYPE key;
        DATA_TYPE data;
        struct Node *left;
        struct Node *right;
    };
    struct Node *root;

    DATA_TYPE *Search(KEY_TYPE thisKey) {
        Node *currNode = root;
        while (currNode != NULL) {
            if (thisKey < currNode->key) {
                currNode = currNode->left;
            } else if (currNode->key < thisKey) {
                currNode = currNode->right;
            } else {
                return &(currNode->data);
            }
        }
        return NULL;
    }

    bool Delete(KEY_TYPE thisKey) {
        if (Search(thisKey) != NULL) {
            Node *currNode = root;
            Node *prevNode = NULL;
            while (currNode != NULL) {
                if (thisKey < currNode->key) {
                    prevNode = currNode;
                    currNode = currNode->left;
                } else if (currNode->key < thisKey) {
                    prevNode = currNode;
                    currNode = currNode->right;
                } else {//found!!
                     if (currNode->left == NULL && currNode->right == NULL) {//no kids
                         if(currNode == root){
                            root = NULL;
                         }
                        else {
                             if (prevNode->left == currNode) {
                                 prevNode->left = NULL;
                             } else {
                                 prevNode->right = NULL;
                             }
                        }
                        if (currNode != NULL) {
                            delete currNode;
                            currNode = NULL;
                        }
                    } else if (currNode->left != NULL && currNode->right == NULL) {//one kid left
                         if(currNode == root){
                             root = currNode->left;
                         }else {
                             if (prevNode->left == currNode) { //currNode is left child of prevNode
                                 prevNode->left = currNode->left;
                             } else {//currNode is right child of prevNode
                                 prevNode->right = currNode->left;
                             }
                         }
                         if (currNode != NULL) {
                             delete currNode;
                             currNode = NULL;
                         }
                    }else if (currNode->left == NULL && currNode->right != NULL) {//one kid right
                         if(currNode == root){
                             root = currNode->right;
                         }else {
                             if (prevNode->left == currNode) { //currNode is left child of prevNode
                                 prevNode->left = currNode->right;
                             } else {//currNode is right child of prevNode
                                 prevNode->right = currNode->right;
                             }
                         }
                        if (currNode != NULL) {
                            delete currNode;
                            currNode = NULL;
                        }
                    } else {//two kids
                        Node* tempNode = currNode->right;
                        Node* parentNode = NULL;
                        while(tempNode->left != NULL){
                            parentNode = tempNode;
                            tempNode = tempNode->left;
                        }
                        if(parentNode == NULL){
                            currNode->right = tempNode->right;
                        }
                        else{
                            parentNode->left = tempNode->right;
                        }
                        currNode->key = tempNode->key;
                        currNode->data = tempNode->data;
                        if(tempNode != NULL){
                            delete tempNode;
                            tempNode = NULL;
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool Insert(KEY_TYPE thisKey, DATA_TYPE thisData) {
        if (Search(thisKey) == NULL) {
            Node *thisNode = new Node();
            thisNode->key = thisKey;
            thisNode->data = thisData;
            thisNode->left = NULL;
            thisNode->right = NULL;
            if (root == NULL) {
                root = thisNode;
            } else {
                Node *currNode = root;
                Node *prevNode = NULL;
                while (currNode != NULL) {
                    prevNode = currNode;
                    if (thisKey < currNode->key) {
                        currNode = currNode->left;
                    } else {
                        currNode = currNode->right;
                    }
                }
                if (thisKey < prevNode->key) {
                    prevNode->left = thisNode;
                } else {
                    prevNode->right = thisNode;
                }
            }
            return true;
        } else {
            return false;
        }
    }
    void preorder(Node* currNode){
        if(currNode != NULL){
            cout << currNode->key << currNode->data;
            preorder(currNode->left);
            preorder(currNode->right);
        }
    }
    void PreOrder(){
        Node* currNode = root;
        if(currNode != NULL){
            preorder(currNode);
        }
    }
    void inorder(Node* currNode){
        if (currNode != NULL) {
            inorder(currNode->left);
            cout << currNode->key << currNode->data;
            inorder(currNode->right);
        }
    }
    void InOrder(){
        Node* currNode = root;
        if(currNode != NULL){
            inorder(currNode);
        }
    }
    void postorder(Node* currNode){
        if (currNode != NULL) {
            postorder(currNode->left);
            postorder(currNode->right);
            cout << currNode->key << currNode->data;
        }
    }
    void PostOrder(){
        Node* currNode = root;
        if(currNode != NULL){
            postorder(currNode);
        }
    }
    void currLevel(Node* currNode, int level){
        if (currNode == NULL) return;
        if (level == 0) {
            cout << currNode->key << currNode->data;
        }
        else if (level > 0){
            currLevel(currNode->left, level-1);
            currLevel(currNode->right, level-1);
        }
    }
    void LevelOrder(){
        int height = Height();
        for (int i = 0; i <= height; i++) {
            currLevel(root, i);
        }
    }
    int cHeight(Node* currNode){
        if(currNode == NULL){
            return -1;
        }else{
            int leftTree = cHeight(currNode->left);
            int rightTree = cHeight(currNode->right);
            if(leftTree > rightTree){
                return 1 + leftTree;
            }else{
                return 1 +rightTree;
            }
        }
    }
    int Height() {
       return cHeight(root);
    }

    BST() {
        root = NULL;
    }

    ~BST() {
        while (root != NULL) {
            Delete(root->key);
        }
    }
};