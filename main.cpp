#include <iostream>
#include <random>
#include <list>
using std::list;



class BinarySearchTree {
protected:
    // Class to represent a node of a binary tree
    class BTNode
    {
    public:
        int data;
        BTNode *right;
        BTNode *left;

        BTNode(int d, BTNode *l=nullptr, BTNode *r=nullptr)
        {
            data = d;
            right = r;
            left = l;

        }
    };

    BTNode *root;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    void insert(int data)
    {
        BTNode *node = new BTNode(data);

        if (root == nullptr)
        {
            root = node;
        }
        else
        {
            BTNode * tmp = root;
            while (tmp != nullptr)
            {
                if (data < tmp->data)
                {
                    // data must be on left side
                    if (tmp->left == nullptr)
                    {
                        tmp->left = node; //
                        return;
                    }
                    else
                        tmp = tmp->left;
                }
                else
                {
                    // data must be on right side
                    if (tmp->right == nullptr)
                    {
                        tmp->right = node;
                        return;
                    }
                    else
                        tmp = tmp->right;
                }
            }
        }

    }

    bool search(int data) {
        BTNode * tmp = root;
        while (tmp != nullptr)
        {
            if (data == tmp->data)
                return true;

            if (data < tmp->data)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        return false;
    }

    void addInOrder(list<int> &ref, BTNode *node) {
        if (node == nullptr) return;
        addInOrder(ref, node->left);
        ref.push_back(node->data);
        addInOrder(ref, node->right);
    }

    list<int> getOrderedList()
    {
        // IMPLEMENT THIS!
        list<int> ret;
        addInOrder(ret, root);
        return ret;
    }

    friend std::ostream& operator<< (std::ostream& out, BTNode *bt);
    friend std::ostream& operator<< (std::ostream& out, BinarySearchTree &bst);
};

std::ostream& operator<< (std::ostream& out, BinarySearchTree::BTNode *bt)
{
    if (bt == nullptr)
        return out;

    if (bt->left != nullptr)
        out << bt->left;

    out << bt->data << " ";

    if (bt->right != nullptr)
        out << bt->right;

    return out;
}

std::ostream& operator<< (std::ostream& out, BinarySearchTree &bst)
{
    out << bst.root;
    return out;
}


int main()
{
    //std::random_device generator;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> dist(0,1000);

    BinarySearchTree b2;
    for(int i=0; i<20; i++)
    {
        b2.insert(dist(generator));
    }

    list<int> l2 = b2.getOrderedList();

    std::cout << "Print tree:" << std::endl;
    std::cout << b2 << std::endl;

    std::cout << "Print size of list: " << l2.size() << std::endl;

    std::cout << "Print out list: " << std::endl;
    for(auto i = l2.begin(); i != l2.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}
