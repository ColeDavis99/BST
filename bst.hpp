#ifndef BST_H
#define BST_H
#include "node.hpp"

template <typename K, typename V>
class BST
{
  private:
    Node<K,V> *root = nullptr;

  public:

    /*===================
          CONSTRUCTOR
    =====================*/
    //Default Constructor
    BST<K,V>()
    {
      cout<<"DEFAULT CONSTRUCTOR"<<endl;
      root = nullptr;
    };

    //Passed in a single node or a node constructor
    BST<K,V>(Node<K,V> &node_arg)
    {
      //cout<<"Constructed TREE"<<endl;
      root = new Node<K,V>(node_arg); //Use copy constructor
      //cout<<"BST has root of "<<root<<endl;
    };



    /*===================
        FUNCTIONALITY
    =====================*/
    //Used for adding nodes
    bool emplace(Node<K,V> arg_node)
    {
      //Special case
      if(root == nullptr)
      {
        root = new Node<K,V>(arg_node);
      }


      Node<K,V>* currNode;
      currNode = root;
      K arg_key = arg_node.getKey();
      bool foundSpot = false;


       //Keep iterating to insertion point until it's found
       while(!foundSpot)
       {
         if(currNode->getKey() > arg_key) //See if I need to move left
         {
           if(currNode->left != nullptr)//If node to left exists, move there.
           {
             currNode = currNode->left;
           }
           else //If I need to move left and the left node doesn't exist, then put the new node here.
           {
             currNode->left = new Node<K,V>(arg_node);
             foundSpot = true;

                                                                                                             //cout<<"Current key: "<<currNode->getKey()<<endl;
                                                                                                             //cout<<"has left node of "<<currNode->left->getKey()<<endl<<endl<<endl;
             return foundSpot;
           }
         }
         else if(currNode->getKey() < arg_key)//See if I need to move right
         {
           if(currNode->right != nullptr) //If node to right exists, move there.
           {
             currNode = currNode->right;
           }
           else //If I need to move right and the a right node doesn't exits, then put the new node here.
           {
             currNode->right = new Node<K,V>(arg_node);
                                                                                                             //cout<<"Current key: "<<currNode->getKey()<<endl;
                                                                                                             //cout<<"has right node of "<<currNode->right->getKey()<<endl<<endl<<endl;
             foundSpot = true;
             return foundSpot;
           }
         }
         else
         {
           cout<<"Duplicate key detected";
           return foundSpot;
         }
       }

    };


    //Print out contents by recursing left, then right
    void ascend_printout(Node<K,V>* currNode)
    {
      if(currNode == nullptr)
        return;

      else
      {
        ascend_printout(currNode->left);
        cout<<currNode->getKey()<<endl;
        ascend_printout(currNode->right);
      }
    };


    //Returns pointer to root node.
    Node<K,V>* getRoot()
    {
      return root;
    }


    /*===================
        DECONSTRUCTOR
    ===================*/
    ~BST<K,V>()
    {
      //cout<<"DECONSTRUCTED BST with root of "<<root<<"."<<endl;
    };
};

#endif
