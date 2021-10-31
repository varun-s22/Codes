#include <iostream>
#include <queue>
#define ll long long int
using namespace std;
struct node
{
    node *left;
    int data;
    node *right;
};
class binary_tree
{
    node *root;
    queue<node *> q1;

public:
    binary_tree()
    {
        root = NULL;
    }
    void create()
    {
        if (root == NULL)
        {
            //first value;
            root = new node;
            int root_value;
            cin >> root_value;
            root->data = root_value;
            root->right = NULL;
            root->left = NULL;
            q1.push(root);
        }
        else
        {
            // not first element
            while (q1.size())
            {
                node *temp_root = q1.front();
                cout << "Is there a left child of: " << temp_root->data << endl;
                char choice;
                cin >> choice;
                cout << endl;
                if (choice == 'y' or choice == 'Y')
                {
                    node *temp = new node;
                    int value;
                    cin >> value;
                    temp->data = value;
                    temp->left = NULL;
                    temp->right = NULL;
                    temp_root->left = temp;
                    q1.push(temp);
                }
                cout << "Is there a right child of: " << temp_root->data << endl;
                char choice2;
                cin >> choice2;
                cout << endl;
                if (choice2 == 'y' or choice2 == 'Y')
                {
                    int value2;
                    cin >> value2;
                    node *temp2 = new node;
                    temp2->data = value2;
                    temp2->left = NULL;
                    temp2->right = NULL;
                    temp_root->right = temp2;
                    q1.push(temp2);
                }
                q1.pop();
            }
        }
    }
    void display()
    {
        queue<node *> q2;
        q2.push(root);
        while (q2.size())
        {
            node *first = q2.front();
            if (first->left != NULL)
            {
                q2.push(first->left);
            }
            if (first->right != NULL)
            {
                q2.push(first->right);
            }
            cout << first->data << " ";
            q2.pop();
        }
        cout << endl;
    }
    void pre()
    {
        cout << endl;
        preorder(root);
    }
    void preorder(node *traverse)
    {
        if (traverse == NULL)
        {
            return;
        }
        cout << traverse->data << " ";
        preorder(traverse->left);
        preorder(traverse->right);
    }

    void in()
    {
        cout << endl;
        inorder(root);
    }
    void inorder(node *traverse)
    {
        if (traverse == NULL)
        {
            return;
        }
        inorder(traverse->left);
        cout << traverse->data << " ";
        inorder(traverse->right);
    }
    int height()
    {
        int h = height_og(root);
        return h;
    }
    int height_og(node *traverse)
    {
        // comparing left and right
        if (traverse == NULL)
        {
            return 0;
        }
        int left = height_og(traverse->left);
        int right = height_og(traverse->right);
        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
};
class binary_search_tree
{
    node *root;

public:
    binary_search_tree(int value)
    {
        root = new node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    }
    node *create_node(int value)
    {
        node *temp = new node;
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    void add(int value)
    {
        insert(root, value);
    }
    node *insert(node *link, int value)
    {
        if (link == NULL)
        {
            return create_node(value);
        }
        if (value > link->data)
        {
            // right side
            link->right = insert(link->right, value);
        }
        else
        {
            // left side
            link->left = insert(link->left, value);
        }
    }
    void display()
    {
        queue<node *> q2;
        q2.push(root);
        while (q2.size())
        {
            node *first = q2.front();
            if (first->left != NULL)
            {
                q2.push(first->left);
            }
            if (first->right != NULL)
            {
                q2.push(first->right);
            }
            cout << first->data << " ";
            q2.pop();
        }
        cout << endl;
    }
    void search(int value)
    {
        binary_search(root, value);
    }
    node *binary_search(node *link, int value)
    {
        if (link == NULL)
        {
            return NULL;
        }
        if (value == link->data)
        {
            cout << "Value found" << endl;
            return link;
        }
        else if (value < link->data)
        {
            binary_search(link->left, value);
        }
        else
        {
            binary_search(link->right, value);
        }
        return 0;
    }
    void deletethenode(int value)
    {
        // child 0,1,2
        node *deletednode = delete_node(root, value);
        cout << "value deleted" << endl;
    }
    node *inorder_succesor(node *link)
    {
        node *temp = link->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    node *delete_node(node *link, int value)
    {
        if (link == NULL)
        {
            // empty tree
            return NULL;
        }
        if (value > link->data)
        {
            link->right = delete_node(link->right, value);
        }
        else if (value < link->data)
        {
            link->left = delete_node(link->left, value);
        }
        else
        {
            if (link->left == NULL and link->right == NULL)
            {
                delete link;
                return NULL;
            }
            else if (link->left != NULL and link->right == NULL)
            {
                node *temp = link;
                link = link->left;
                delete temp;
                return link;
            }
            else if (link->left == NULL and link->right != NULL)
            {
                node *temp = link;
                link = link->right;
                delete temp;
                return link;
            }
            else
            {
                node *temp = inorder_succesor(link);
                link->data = temp->data;
                link->right = delete_node(link->right, temp->data);
                return link;
            }
        }
        return link;
    }
};
struct node_avl
{
    int data;
    node_avl *left;
    node_avl *right;
    int height;
};
class avl_trees
{
    node_avl *root;

public:
    avl_trees()
    {
        root = NULL;
    }
    avl_trees(int value)
    {
        root = new node_avl;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        root->height = 1;
    }
    node_avl *LLrotation(node_avl *link)
    {
        node_avl *temp = link->left;
        node_avl *temp2 = temp->right;
        temp->right = link;
        link->left = temp2;
        link->height = 1 + max(height(link->left), height(link->right));
        temp->height = 1 + max(height(temp->left), height(temp->right));
        return temp;
    }
    node_avl *RRrotation(node_avl *link)
    {
        node_avl *temp = link->right;
        node_avl *temp2 = temp->left;
        temp->left = link;
        link->right = temp2;
        link->height = 1 + max(height(link->left), height(link->right));
        temp->height = 1 + max(height(temp->left), height(temp->right));
        return temp;
    }
    node_avl *LRrotation(node_avl *link)
    {
        node_avl *temp = link->left;
        node_avl *temp2 = temp->right;
        node_avl *temp3 = temp2->left;
        node_avl *temp4 = temp2->right;
        temp->right = temp3;
        link->left = temp4;
        temp2->right = link;
        temp2->left = temp;
        link->height = 1 + max(height(link->left), height(link->right));
        temp->height = 1 + max(height(temp->left), height(temp->right));
        temp2->height = 1 + max(height(temp2->left), height(temp2->right));
        return temp2;
    }
    node_avl *RLrotation(node_avl *link)
    {
        node_avl *temp = link->right;
        node_avl *temp2 = temp->left;
        node_avl *temp3 = temp2->right;
        node_avl *temp4 = temp2->left;
        temp->left = temp3;
        link->right = temp4;
        temp2->left = link;
        temp2->right = temp;
        link->height = 1 + max(height(link->left), height(link->right));
        temp2->height = 1 + max(height(temp2->left), height(temp2->right));
        temp->height = 1 + max(height(temp->left), height(temp->right));
        return temp2;
    }
    int height(node_avl *link)
    {
        if (link == NULL)
        {
            return 0;
        }
        return link->height;
    }
    int balancefactor(node_avl *link)
    {
        return height(link->left) - height(link->right);
    }
    void create(int value)
    {
        root = insertTOavl(root, value);
    }
    node_avl *createnode(int value)
    {
        node_avl *link = new node_avl;
        link->data = value;
        link->left = NULL;
        link->right = NULL;
        link->height = 1;
        return link;
    }
    node_avl *fixmytreeplease(node_avl *link)
    {
        link->height = 1 + max(height(link->left), height(link->right));
        if (balancefactor(link) == 2 and balancefactor(link->left) == 1)
        {
            link = LLrotation(link);
        }
        else if (balancefactor(link) == 2 and balancefactor(link->left) == -1)
        {
            link = LRrotation(link);
        }
        else if (balancefactor(link) == -2 and balancefactor(link->right) == -1)
        {
            link = RRrotation(link);
        }
        else if (balancefactor(link) == -2 and balancefactor(link->right) == 1)
        {
            link = RLrotation(link);
        }
        return link;
    }
    node_avl *fixtreeafterdeletion(node_avl *link)
    {
        link->height = 1 + max(height(link->left), height(link->right));
        if (balancefactor(link) == 2 and balancefactor(link->left) == 1)
        {
            link = LLrotation(link);
        }
        else if (balancefactor(link) == 2 and balancefactor(link->left) == -1)
        {
            link = LRrotation(link);
        }
        else if (balancefactor(link) == 2 and balancefactor(link->left) == 0)
        {
            link = LRrotation(link);
        }
        else if (balancefactor(link) == -2 and balancefactor(link->right) == -1)
        {
            link = RRrotation(link);
        }
        else if (balancefactor(link) == -2 and balancefactor(link->right) == 1)
        {
            link = RLrotation(link);
        }
        else if (balancefactor(link) == -2 and balancefactor(link->right) == 0)
        {
            link = RLrotation(link);
        }
        return link;
    }
    node_avl *insertTOavl(node_avl *link, int value)
    {
        if (link == NULL)
        {
            return createnode(value);
        }
        if (value > link->data)
        {
            link->right = insertTOavl(link->right, value);
        }
        else if (value < link->data)
        {
            link->left = insertTOavl(link->left, value);
        }
        return fixmytreeplease(link);
    }
    node_avl *inorder_succesor(node_avl *link)
    {
        node_avl *temp = link->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    void deletenode(int value)
    {
        root = delete_node(root, value);
    }
    node_avl *delete_node(node_avl *link, int value)
    {
        if (link == NULL)
        {
            // empty tree
            return NULL;
        }
        if (value > link->data)
        {
            link->right = delete_node(link->right, value);
        }
        else if (value < link->data)
        {
            link->left = delete_node(link->left, value);
        }
        else
        {
            if (link->left == NULL and link->right == NULL)
            {
                delete link;
                // return NULL;
            }
            else if (link->left != NULL and link->right == NULL)
            {
                node_avl *temp = link;
                link = link->left;
                delete temp;
                // return link;
            }
            else if (link->left == NULL and link->right != NULL)
            {
                node_avl *temp = link;
                link = link->right;
                delete temp;
                // return link;
            }
            else
            {
                node_avl *temp = inorder_succesor(link);
                link->data = temp->data;
                link->right = delete_node(link->right, temp->data);
                // return link;
            }
        }
        return fixtreeafterdeletion(link);
    }
    void display()
    {
        queue<node_avl *> q2;
        q2.push(root);
        while (q2.size())
        {
            node_avl *first = q2.front();
            if (first->left != NULL)
            {
                q2.push(first->left);
            }
            if (first->right != NULL)
            {
                q2.push(first->right);
            }
            cout << first->data << " ";
            q2.pop();
        }
        cout << endl;
    }
};
class red_black
{
    // to be continued later
};
int main()
{
    // creating binary tree
    // binary_tree b1;
    // b1.create();
    // b1.create();
    // b1.create();
    // b1.create();
    // b1.create();
    // b1.create();
    // b1.display();
    // b1.pre();
    // b1.in();
    // cout << b1.height() << endl;

    // binary_search_tree b11(50);
    // b11.add(30);
    // b11.add(70);
    // b11.add(20);
    // b11.add(40);
    // b11.add(80);
    // b11.add(60);
    // b11.display();
    // b11.deletethenode(50);
    // b11.display();
    // b11.deletethenode(70);
    // b11.display();

    avl_trees a1(9);
    a1.create(5);
    a1.create(10);
    a1.create(0);
    a1.create(6);
    a1.create(11);
    a1.create(-1);
    a1.create(1);
    a1.create(2);
    a1.deletenode(10);
    a1.display();
    return 0;
}