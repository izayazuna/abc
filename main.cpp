#include <iostream>
using namespace std;
class Node
        {
public:
            string value;
            Node* left = NULL;
            Node* right = NULL;
            Node(string value)
            {
                this->value = value;
            }
            Node(string value, Node* l, Node* r)
            {
                this->value = value;
                left = l;
                right = r;
            }
        };
class ExpTree
        {
public:
    Node* root;
    bool isLEaf(Node* pn)
    {
        if(pn == NULL)
            return false;
        if(pn->left == nullptr && pn->right == nullptr)
            return true;
        return false;
    }
    bool isOperator(string c)
    {
        if (c == "+" || c == "-" || c == "*" || c == "/" )
            return true;
        return false;
    }

    void checkType(Node* rot, bool& la, bool& ra, bool& invalid, bool& undefined)
    {
        if(rot == NULL)
        {
            if(!la && !ra && !invalid)
            {
                undefined = true;
                return;
            }
            else
                return;
        }
        if(isOperator(rot->value))
        {
            if(rot->left->value == rot->value)
            {
                la = true;
            }
            if(rot->right->value == rot->value)
            {
                if(la == true) invalid = true;
                else ra = true;
            }
        }
        checkType(rot->left, la, ra, invalid,undefined);
        checkType(rot->right, la, ra, invalid,undefined);


    }
    void printAssoct()
    {
        bool la = false, ra = false, invalid = false, undefined = false;
        checkType(root, la, ra, invalid, undefined);
    }
        };
int main() {
    std::cout << "Hello, World!" << std::endl;
        std::cout<<1;
    return 0;
}
