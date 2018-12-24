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

    //BST Constr. w/ Paramater of node that already exists
    BST<K,V>(const Node<K,V> &node_arg)
    {
      root = new Node<K,V>(node_arg); //Use copy constructor
      cout<<"Constructed TREE root: "<<root<<endl;
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
        cout<<"Special case of emplace w/ empty BST: "<<root<<endl;
      }

      else
      {
        Node<K,V>* currNode;
        currNode = root;
        K arg_key = arg_node.getKey();
        bool foundSpot = false;


         //Keep iterating to insertion point until it's found (iterative, not recursive)
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
             cout<<"Duplicate key detected"<<endl;
             return foundSpot;
           }
         }
       }
    };

    //Returns a memory address (pointer) to a node with a specified key
    Node<K,V>* at(K key_arg)
    {

      Node<K,V>* currNode;
      currNode = root;

       //Keep iterating to insertion point until it's found (iterative, not recursive)
       while(true)
       {
         if(currNode->getKey() > key_arg) //See if I need to move left
         {
           if(currNode->left != nullptr)//If node to left exists, move there.
           {
             currNode = currNode->left;
           }
           else //If I need to move left and the left node doesn't exist, then put the new node here.
           {
             cout<<"Key doesn't exist"<<endl;
             return nullptr;
           }
         }
         else if(currNode->getKey() < key_arg)//See if I need to move right
         {
           if(currNode->right != nullptr) //If node to right exists, move there.
           {
             currNode = currNode->right;
           }
           else //If I need to move right and the a right node doesn't exits, then put the new node here.
           {
             cout<<"Key doesn't exist"<<endl;
             return nullptr;
           }
         }
         else if(currNode->getKey() == key_arg)
         {
           cout<<"Found it."<<endl;
           return currNode;
         }
       }
    };


    //Delete the node with a particular key
    bool deleteNode(K key_arg)
    {
      bool found_node = false;


      //Keep track of parent and child nodes for our search.
      //Child will be deleted, parent will get its left or right pointer assigned
      Node<K,V>* parent;
      parent = nullptr;
      Node<K,V>* child;
      child = root;

      //Keeps track of child pointer's relation to the parent pointer
      bool child_is_left = false;




      //Special case of deleting an empty BST
      if(root == nullptr)
      {
        cout<<"This BST is empty, nothing do delete."<<endl;
        found_node = true;
        return found_node;
      }





      /*
      Three steps for deletion:
            1. Locate node to deleted
            2. See if node to delte has one, two, or no children and assign parent pointer accordingly
                2a: node has two children
                2b: node has one child
                2c: node has no children
      */

      // Step 1 of 2: Locate node to delete
      while(child != nullptr)
      {
        if(child->getKey() == key_arg) // We've found the node to delete
        {
          found_node = true;
          if(parent != nullptr)
            cout<<"Delete node with parent of "<<parent->getKey()<<" and the node itself is "<<child->getKey()<<endl;
          else
            cout<<"Deleting root (no parent), the node itself is "<<child->getKey()<<endl;

          if(child_is_left && parent != nullptr)
            cout<<"to the left of parent"<<endl;
          else if(parent != nullptr)
            cout<<"To the right of parent"<<endl;
          break;
        }

        else if(child->getKey() > key_arg) //Move left
        {
          parent = child;
          child = child->left;
          child_is_left = true;
        }

        else if (child->getKey() < key_arg) //Move right;
        {
          parent = child;
          child = child->right;
          child_is_left = false;
        }
      }

      //key doesn't exist in the BST
      if(child == nullptr)
      {
        cout<<"No key of "<<key_arg<<" in the BST"<<endl;
        return found_node;
      }



      // Step 2 of 2: See if Node to delete has one, two, or no children and assign parent pointer accordingly.

      //Step 2a: node hads two children
      if(child->left != nullptr && child->right != nullptr)
      {
        cout<<"TWO CHILDREN"<<endl;

        if(parent == nullptr)//If we're deleting root node
        {
          root = leftmost_child(child->right);

          if(root->getKey() != child->right->getKey()) //Make sure to remove right subtree of child if there's only one node in it
            root->right = child->right;
          root->left = child->left;

          child->left = nullptr;
          child->right = nullptr;
          delete child;
        }

        else if(child_is_left) //Child is left child of parent
        {
          parent->left = leftmost_child(child->right);
          parent->left->left = child->left;
          if(child->right->getKey() != parent->left->getKey()) //Make sure to remove right subtree of child if there's only one node in it.
            parent->left->right = child->right;

          child->left = nullptr;
          child->right = nullptr;
          delete child;
        }
        else //Child is right child of parent
        {
          parent->right = leftmost_child(child->right);
          parent->right->left = child->left;
          if(child->right->getKey() != parent->right->getKey()) //Make sure to remove right subtree of child if there's only one node in it.
            parent->right->right = child->right;

          child->left = nullptr;
          child->right = nullptr;
          delete child;
        }
      }


      //Step 2b: Node has one child
      else if( (child->left == nullptr && child->right != nullptr)  ||  (child->right == nullptr && child->left != nullptr) )
      {
        cout<<"One child"<<endl;
        if(parent == nullptr) //If we're deleting the root
        {
          if(child->right != nullptr) //Root has subtree to the right, and left is completly empty
          {
            root = leftmost_child(child->right);

            if(root->right->getKey() != child->right->getKey()) //Make sure to remove right subtree of child if there's only one node in it
              root->right = child->right;
            root->left = child->left;

            child->left = nullptr;
            child->right = nullptr;
            delete child;
          }

          else //Child has subtree to the left, and right is completly empty
          {
            root = child->left;
            child->left = nullptr;
            delete child;
          }
        }//End of root deletion cases

        else if(child_is_left) //Child is left child of parent
        {
          //Assign parent's left pointer equal to child's only child
          if(child->right != nullptr)
          {
            parent->left = child->right;
            child->right = nullptr;
          }
          else
          {
            parent->left = child->left;
            child->left = nullptr;
          }
          delete child;
        }
        else //Child is right child of parent
        {
          //Assign parent's right pointer equal to child's only child
          if(child->right != nullptr)
          {
            parent->right = child->right;
            child->right = nullptr;
          }
          else
          {
            parent->right = child->left;
            child->left = nullptr;
          }
          delete child;
        }
      }

      //Step 2c: Node has no children
      else if(child->left == nullptr && child->right == nullptr)
      {
        cout<<"No children"<<endl;

        if(parent != nullptr)
        {
          if(child_is_left)
            parent->left = nullptr;
          else
            parent->right = nullptr;
        }
        else
        {
          root = nullptr;
        }

        delete child;
      }
      return found_node; //Returns true if this point is reached
    };

    //Print out contents by recursing left, then right
    void ascend_printout(Node<K,V>* currNode)
    {
      //Keep track of the tab spaces (wow, recursion)
      static string spaces = "";

      if(currNode == nullptr)
        return;

      else
      {
        spaces += "     ";
        ascend_printout(currNode->right);
        cout<<spaces<<currNode->getKey()<<endl;
        ascend_printout(currNode->left);
        spaces.pop_back();
        spaces.pop_back();
        spaces.pop_back();
        spaces.pop_back();
        spaces.pop_back();



        //cout<<currNode->getKey()<<"\t\t";
        //cout<<currNode->getKey()<<"\t"<<currNode->getValue()<<"\t"<<currNode<<"\t";
        // if(currNode->left != nullptr)
        //   cout<<currNode->left->getKey()<<"\t";
        // else
        //   cout<<"0"<<"\t";
        // if(currNode->right != nullptr)
        //   cout<<currNode->right->getKey()<<endl;
        // else
        //   cout<<"0"<<endl;
      }
    };





    //Returns pointer to root node.
    Node<K,V>* getRoot()
    {
      return root;
    }


    //Return pointer to leftmost child of paramater node, also fixes leftmost node's right subtree
    Node<K,V>* leftmost_child(Node<K,V>* arg_node)
    {
      Node<K,V>* parent;
      parent = nullptr;
      Node<K,V>* child;
      child = arg_node;


      //Special case of only one node in the subtree
      if(arg_node->left == nullptr && arg_node->right == nullptr)
      {
        cout<<"Leftmost's parent is itself (subtree is only one node)"<<endl;
        return child;
      }


      while(child->left != nullptr)
      {
        cout<<"Leftmost: "<<child->getKey()<<endl;
        parent = child;
        child = child->left;
      }

      //Fix the right subtree of the leftmost node (make sure it isn't dropped)
      cout<<"Leftmost LAST: "<<child->getKey()<<endl;
      if(parent != nullptr)
      {
        cout<<"Leftmost's parent: "<<parent->getKey()<<endl;
        parent->left = child->right;
      }

      return child;
    }


    //Used for deconstructing the nodes in the BST (avoid memory leaks)
    void deconstructNodes(Node<K,V>* currNode)
    {
      if(currNode == nullptr)
        return;

      else
      {
        deconstructNodes(currNode->left);
        delete currNode;
        deconstructNodes(currNode->right);
      }
    }

    /*===================
        DECONSTRUCTOR
    ===================*/
    ~BST<K,V>()
    {
      if(root != nullptr)
        cout<<"DECONSTRUCTED BST with root of "<<root<<" and key of "<<root->getKey()<<"."<<endl;
      else
        cout<<"Deconstructed BST with empty root."<<endl;
      deconstructNodes(root);
    };
};

#endif
