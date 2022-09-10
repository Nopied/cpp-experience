#include <iostream>

// Congrats! This code could not be the correct answer due to timeout. (> 0.3s) Fu

struct Node
{
    char data = '\0';
    Node *left = nullptr, *right = nullptr;
};

Node *g_hCursor;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::string str; std::cin >> str;
    int len = str.length();

    Node *priviousNode = nullptr;

    for(int loop = 0; loop < len; loop++)
    {
        Node *current = new Node;
        current->left = priviousNode;
        current->data = str[loop];

        if (priviousNode != nullptr)
            priviousNode->right = current;
        priviousNode = current;
    }

    g_hCursor = new Node;

    priviousNode->right = g_hCursor;
    g_hCursor->left = priviousNode;

    int count;
    std::cin >> count;
    char command, target;

    for(int loop = 0; loop < count; loop++)
    {
        std::cin >> command;

        switch(command)
        {
            case 'L':
            {
                Node *myLeft = g_hCursor->left;
                if (myLeft != nullptr)
                {
                    Node *replace = myLeft->left;
                    
                    if (replace != nullptr)
                    {
                        g_hCursor->left = replace;
                        replace->right = g_hCursor;
                    }
                    else
                        g_hCursor->left = nullptr;

                    Node *myRight = g_hCursor->right;
                    if (myRight != nullptr)
                    {
                        myRight->left = myLeft;

                        myLeft->right = myRight;
                    }
                    else
                    {
                        myLeft->right = nullptr;
                    }

                    g_hCursor->right = myLeft;
                    myLeft->left = g_hCursor;                 
                } 

                break;
            }
            case 'D':
            {
                Node *myRight = g_hCursor->right;
                if (myRight != nullptr)
                {
                    Node *replace = myRight->right;

                    if (replace != nullptr)
                    {
                        g_hCursor->right = replace;
                        replace->left = g_hCursor;
                    }
                    else
                        g_hCursor->right = nullptr;

                    Node *myLeft = g_hCursor->left;
                    if (myLeft != nullptr)
                    {
                        myLeft->right = myRight;

                        myRight->left = myLeft;
                    }
                    else
                    {
                        myRight->right = nullptr;
                    }

                    g_hCursor->left = myRight;
                    myRight->right = g_hCursor;
                }

                break;
            }
            case 'B':
            {
                if(g_hCursor->left == nullptr)
                    break;

                Node *replace = (g_hCursor->left)->left;

                delete g_hCursor->left; // DoubleFree????? WHY???
                g_hCursor->left = nullptr;

                if (replace != nullptr)
                {
                    replace->right = g_hCursor;
                    g_hCursor->left = replace;
                }

                break;
            }
            case 'P':
            {
                std::cin >> target;

                Node *newNode = new Node;
                newNode->data = target;

                Node *replace = g_hCursor->left;

                newNode->left = replace;
                if (replace != nullptr)
                    replace->right = newNode;

                g_hCursor->left = newNode;
                newNode->right = g_hCursor;
                
                break;
            }
        }
    }

    // int loopCount = 0;
    while (1)
    {
        // std::cout << loopCount++ << " " << g_hCursor->data;

        if (g_hCursor->left == nullptr)
            break;
        
        g_hCursor = g_hCursor->left;            
    }

    while (1)
    {
        Node *killMe = g_hCursor;

        std::cout << g_hCursor->data;

        if (g_hCursor->right == nullptr)
            break;

        g_hCursor = g_hCursor->right;
        delete killMe;
    }
    return 0;
}