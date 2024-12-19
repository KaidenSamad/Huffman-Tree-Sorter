#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;

    Node(int value){ // Remove Node:: constructors should not have the class name prefixed to them
        info = value;
        left = nullptr;
        right = nullptr;
    }
};

class Decoder{
    
    private:
    vector<Node*> nodes; // Vector named nodes that stores pointers to node objects

    Node* BuildTree(const vector<int> &inOrder, const vector<int> &levelOrder){

        if (inOrder.empty() || levelOrder.empty()){
            return nullptr;
        }

        //cout << "3" << endl;
        int rootVal = levelOrder[0];
        size_t rootIndex;
        for (rootIndex = 0; rootIndex < inOrder.size(); ++ rootIndex){
            if (inOrder[rootIndex] == rootVal){
                break; // Root value is found in the inOrder traversal
            }
        }

        // Creates the root node
        Node* root = new Node(rootVal); // Creates a new node object with value rootVal and stores its memory addressin the root pointer var

        // Split inOrder in to left and right trees
        vector<int> leftInOrder(inOrder.begin(), inOrder.begin() + rootIndex); // Left tree
        vector<int> rightInOrder(inOrder.begin() + rootIndex + 1, inOrder.end()); // Right Tree -> 1st part gets element directly after root

        // Split levelOrder into left and right trees
        vector<int> leftLevelOrder;
        vector<int> rightLevelOrder;
        for (size_t i = 1; i < levelOrder.size(); i++){
            if (find(leftInOrder.begin(), leftInOrder.end(), levelOrder[i]) != leftInOrder.end()){ //checks if current element of level order is in the left sub tree leftLevelOrder.push_back(levelOrder[i]);
                leftLevelOrder.push_back(levelOrder[i]);
            }
            else{
                rightLevelOrder.push_back(levelOrder[i]);
            }
        }

        root->left = BuildTree(leftInOrder, leftLevelOrder);
        root->right = BuildTree(rightInOrder, rightLevelOrder);

        return root;
    }

    public:
    Node* HuffmanTree(const vector<int> &inOrder, const vector<int> &levelOrder){
        return BuildTree(inOrder, levelOrder);
    }
};

void Decode(Node* root, const string &encodedText){
        
        if (!root){
            cout << "Huffman tree not valid" << endl;
            return;
        }
        
        Node* current = root;
        for (char bit : encodedText){ // Range based for loop (for each bit in string encodedText do something)
            if (bit == '0'){
                if (current->left){    
                    current = current->left;
                }
            }
            else{
                if (current->right){    
                    current = current->right;
                }
            }
            if (!current->left && !current->right){
                cout << static_cast<char>(current->info); // static tells compiler to treat int val as a char (print decoded character)
                current = root; // Reset to root for next character
            }
        }
    }

int main(int argc, char* argv[]){

    if (argc != 4){
        cout << "Wrong number of files entered" << endl;
        return 1;
    }

    string inOrderFile = argv[1];
    string levelOrderFile = argv[2];
    string encodedFile = argv[3];

    vector<int> inOrder;
    vector<int> levelOrder;
    string line;

    ifstream inOrderStream(inOrderFile);
    while (getline(inOrderStream, line)){
        istringstream iss(line); // istringstream allows you to read data from a string using stream extraction operators
        int val;
        while (iss >> val){
            inOrder.push_back(val);
        }
    }
    inOrderStream.close();

    ifstream levelOrderStream(levelOrderFile);
    while (getline(levelOrderStream, line)){
        istringstream iss(line); // istringstream allows you to read data from a string using stream extraction operators
        int val;
        while (iss >> val){
            levelOrder.push_back(val);
        }
    }
    levelOrderStream.close();

    ifstream encodedStream(encodedFile);
    string encodedText; // Store encoded text

    while(getline(encodedStream, line)){
        encodedText += line; // add each line to encodedText
    }
    encodedStream.close();

    // cout << "Encoded text: " << line << endl;

    Decoder decoder;
    Node *root = decoder.HuffmanTree(inOrder, levelOrder);
    Decode(root, encodedText);

    return 0;
}