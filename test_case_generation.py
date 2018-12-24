import random

#File 1 generates a C++ program to test BST values
#File 2 generates a listing of numbers I can put into visualgo.com and
    #See what the BST I just made looks like
file1 = open("test1.txt","w")
file2 = open("test2.txt","w")

file1.write("#include \"header.h\"\n")
file1.write("#include \"bst.hpp\"\n")
file1.write("#include \"node.hpp\"\n\n")
file1.write("int main()\n")
file1.write("{\n")

'''
L1 stores listing of 1000 random numbers from 1-1000 inclusive in the order they were gen.
L2 stores either "None" or 1. The index number represents y/n the number is found in L1
L3 stores the final listing of AT MOST 1000 unique elements numbered 1-1000 inclusive.
'''
MAX_NUM_NODES = 1000
L1 = [None] * int(MAX_NUM_NODES+1)
L2 = [None] * int(MAX_NUM_NODES+1)
L3 = [None] * int(MAX_NUM_NODES+1)

#Genereate 100 numbers 1-100 inclusive
for i in range(MAX_NUM_NODES):
    randomNum = random.randint(1,MAX_NUM_NODES)
    L1[i] = randomNum
#print(L1)
#print("\n\n")


#Store whether or not a number was generated in L2, index # is the # generated
for q in range(MAX_NUM_NODES):
    L2[L1[q]] = 1
#print(L2)
#print("\n\n")


#Create a unique listing of all numbers generated (Every element in list is unique)
ctr = 0;
for z in range(MAX_NUM_NODES):
    if(L2[L1[z]] == 1):
        L2[L1[z]] = None
        L3[ctr] = L1[z]
        ctr += 1

#Chop off the extra "Nones"
L3 = L3[:ctr]
#print(L3)


length = len(L3)
for k in range(length):
    #Generate the code that creates the BST with the first # that was generated
    if(k == 0):
        file1.write("\tBST<int,string> bst2(Node<int, string> ("+str(L3[k])+", \"RootVal\"));\n")
    else:
        file1.write("\tbst2.emplace(Node<int, string>("+str(L3[k])+", \"value\"));\n");

    #Remove last comma in the number listing
    if(k == length-1):
        file2.write(str(L3[k]))
    else:
        file2.write(str(L3[k]) + ",")

file1.write("\n\tbst2.ascend_printout(bst2.getRoot());\n")
file1.write("\treturn 0;\n}")
file1.close()
file2.close()
