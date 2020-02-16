#include <iostream>

using namespace std;

struct movie {
    int ID;
    char name[10];
};

struct node {
    movie movieData;
    node *left;
    node *right;
};

class MovieDict {
private:
    node *root;
public:
    MovieDict();
    node *newNode(movie movieData); // Create a new node for a new movie
    node *searchMovie(node *root, movie movieData); // Search movie
    void preorder(node *root); // Search from head
    void inorder(node *root); // Search from middle
    void postorder(node *root); // Search from behind
    node *insertMovie(node *newNode, movie movieData); // Add a new movie
    node *deleteMovie(node *root, movie movieData); // Delete a movie
    void Function(); // The executing function
};

MovieDict::MovieDict() {
    root = NULL;
}

node *MovieDict::newNode(movie movieData) {
    node *newNode = new node;

    newNode->movieData = movieData;

    newNode->left = NULL;

    newNode->right = NULL;

    return newNode;
}

node *MovieDict::searchMovie(node *root, movie movieData) {
    if(root == NULL || root->movieData.ID == movieData.ID) {
        return root;
    }

    if(root->movieData.ID < movieData.ID) {
        return searchMovie(root->right, movieData);
    }

    return searchMovie(root->left, movieData);
}

void MovieDict::preorder(node *root) {
    if(root != NULL) {
        cout<<"ID: "<<root->movieData.ID<<"--"<<"Movie: "<<root->movieData.name<<endl;
        preorder(root->right);
        preorder(root->left);
    }
    else {
        cout<<"Empty Dictionary!"<<endl;
    }
}

void MovieDict::inorder(node *root) {
    if(root != NULL) {
        inorder(root->left);
        cout<<"ID: "<<root->movieData.ID<<"--"<<"Movie: "<<root->movieData.name<<endl;
        inorder(root->right);
    }
    else {
        cout<<"Empty Dictionary!"<<endl;
    }
}

void MovieDict::postorder(node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout<<"ID: "<<root->movieData.ID<<"--"<<"Movie: "<<root->movieData.name<<endl;
    }
}

node *MovieDict::insertMovie(node *newNode, movie movieData) {

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
