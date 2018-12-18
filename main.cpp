#include "header.h"
#include "bst.hpp"
#include "node.hpp"


int main()
{
  //Default BST constuctor
  BST<int, string> bst;
  bst.emplace(Node<int, string>(173, "grubber"));

  Node<int, string> wub(17, "Grizzer"); //Make Node on stack , then there is a heap version created in the BST's constructor.
  bst.emplace(wub);

  bst.emplace(Node<int, string>(957, "grubber"));
  bst.emplace(Node<int, string>(9597, "grubber"));
  bst.emplace(Node<int, string>(6957, "grubber"));

  Node<int, string> wub2(7, "Grizzer"); //Make Node on stack , then there is a heap version created in the BST's constructor.
  bst.emplace(wub2);

  //TRYING TO GET AN ARRAY OF NODES, BUT IT CAN WAIT 
  // Node<int, string>* nodeArray = new Node<int,string>[3];
  // ++nodeArray = new Node<int,string>(245,"AHHHH");
  // cout<<"nodeArray: "<<*nodeArray<<endl;
  //
  // ++nodeArray = new Node<int,string>(994,"WHOA");
  // cout<<"nodeArray: "<<*nodeArray<<endl;
  //
  // ++nodeArray = new Node<int,string>(94494,"WHOA");
  // cout<<"nodeArray: "<<*nodeArray<<endl;
  //
  // for(int i=0; i<3; i++)
  // {
  //   cout<<"nodeArray values: "<<*nodeArray<<endl;
  // }




  bst.ascend_printout(bst.getRoot());

  //Default Node Constructor
  //Node<int, string> node1;
  //Node<string, float> node2;

  //Paramater Node Constructor



  // new Node<int, string>(81375, "fdsa");
  // new Node<int, string>(2173, "asdf");
  // new Node<int, string>(7617, "wert");
  // new Node<int, string>(5174, "uytr");
  // new Node<int, string>(13734, "cvbn");
  // new Node<int, string>(7675, "hgdf");
  // new Node<int, string>(14723, "ghjk");


  //Node<int, string> wub(172, "Grizzer"); //Make Node on stack , then there is a heap version created in the BST's constructor.




  // BST<int, float> bst3(Node<int, float>(8, 36.2308));  //Method 1 of construction
  //BST<int, string> bst4(wub); //Method 2 of construction


  // bst2.emplace(Node<int, string>(8, "Grub"));
  // bst2.emplace(Node<int, string>(3, "Chub"));
  // bst2.emplace(Node<int, string>(1, "Scrub"));
  // bst2.emplace(Node<int, string>(2, "Wack"));
  // bst2.emplace(Node<int, string>(56, "Grub"));
  // bst2.emplace(Node<int, string>(34, "Chub"));
  // bst2.emplace(Node<int, string>(25, "Scrub"));
  // bst2.emplace(Node<int, string>(13, "Wack"));
  // bst2.emplace(Node<int, string>(36736, "sbub"));
  // bst2.emplace(Node<int, string>(17456, "pulp"));
  // bst2.emplace(Node<int, string>(8543, "bumb"));
  // bst2.emplace(Node<int, string>(993, "scab"));
  // bst2.emplace(Node<int, string>(7217, "pler"));
  // bst2.emplace(Node<int, string>(3433, "acst"));
  // bst2.emplace(Node<int, string>(1453, "doot"));
  // bst2.emplace(Node<int, string>(1563, "scoor"));
  // bst2.emplace(Node<int, string>(93, "scra"));





  //bst2.ascend_printout(bst2.getRoot());

  return 0;
}
