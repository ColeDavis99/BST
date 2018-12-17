#ifndef NODE_H
#define NODE_H

template <typename K, typename V>
struct Node{

//Each node has a key and a value. The key is what's going to be used in all of the  BST operations
public:
  K key;
  V value;
  Node<K,V>* left;
  Node<K,V>* right;


  /*====================
        CONSTRUCTORS
  ======================*/
  //Default constuctor
  Node<K,V>()
  {
    cout<<"CREATED NODE"<<endl;
    left = nullptr;
    right = nullptr;
  };

  //Copy constructor
  Node<K,V>(const Node<K,V>& source)
  {
    left = nullptr;
    right = nullptr;
    value = source.value;
    key = source.key;
  };

  //Templated constructor
  Node<K,V>(K key_arg,V value_arg)
  {
    key = key_arg;
    value = value_arg;
    left = nullptr;
    right = nullptr;
    //cout<<endl<<endl<<"Paramaterized node created with "<<endl<<"address of "<<this<<endl<<"key of "<<this->key<<endl<<"value of "<<this->value<<endl<<endl;
    //cout<<endl<<endl<<"Node created "<<this<<endl<<endl;
  };



  /*===================
      FUNCTIONALITY
  =====================*/
  //Getters
  K getKey()
  {
    return this->key;
  };

  V getValue()
  {
    return this->value;
  };

  bool isLeaf()
  {
    if(this->left == nullptr && this->right == nullptr)
      return true;
    return false;
  };





  /*===================
      DECONSTRUCTOR
  =====================*/
  ~Node<K,V>()
  {
    //cout<<endl<<endl<<"DECONSTRUCTED NODE WITH "<<endl<<"address of "<<this<<endl<<"key of "<<this->key<<endl<<"value of "<<this->value<<endl<<endl;
    //cout<<endl<<endl<<"Node deconstructed "<<this<<endl;
    //cout<<"Left: "<<this->left<<" Right: "<<this->right<<endl;
  };

};//End of class Node

#endif
