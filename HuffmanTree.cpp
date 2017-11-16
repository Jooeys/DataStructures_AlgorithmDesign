#include <iostream>
#include <cstring>
#include <vector>
struct data {
	char Char;
	int Weight;
};
struct node {
	data Data;
	node *parent;
	node *leftchild;
	node *rightchild;
};
void generateNodeList(char *s,std::vector<node> &nodelist) {
	int r = 0;
	for(int i=0; s[i]!=0; ++i) { // traverse string s
		for(r=0; r<nodelist.size(); ++r) { // traverse nodelist
			if(s[i]==nodelist[r].Data.Char) { // s[i] is in nodelist
				nodelist[r].Data.Weight++;// increase weight of char s[i]
				break;
			}
		}
		if(r>=nodelist.size()) { // s[i] is not in nodelist
			node temp = {{s[i],1},NULL,NULL,NULL};// initialize
			nodelist.push_back(temp);// add node to nodelist
		}
	}
	for(r=0; r<nodelist.size(); ++r) {
		printf("node[%d].data:{%c,%d}\n",r,nodelist[r].Data.Char,nodelist[r].Data.Weight);
	}
}
node* getMinWeightNode(std::vector<node> &nodelist) {
	node * minWeightNode = NULL;// initialize
	for(int i=0; i<nodelist.size()-1; ++i) {
		if(nodelist[i].parent==NULL) { //node is not appended
			if(minWeightNode == NULL
			        ||nodelist[i].Data.Weight < minWeightNode->Data.Weight) { // find the node whose data.weight is lowest
				minWeightNode = &nodelist[i];// record that node's address
			}
		}
	}
	return minWeightNode;
}
void generateHuffmanTree(std::vector<node> &nodelist) {
	while(true) {
		// add ParentNode
		nodelist.push_back({{'0',0},NULL,NULL,NULL});
		node *newnode = &nodelist[nodelist.size()-1];
		// set ParentNode.leftchild
		newnode->leftchild = getMinWeightNode(nodelist);
		if(newnode->leftchild!=NULL) {
			newnode->Data.Weight += newnode->leftchild->Data.Weight;
			newnode->leftchild->parent = newnode;
		} else break;
		// set ParentNode.rightchild
		newnode->rightchild = getMinWeightNode(nodelist);
		if(newnode->rightchild!=NULL) {
			newnode->Data.Weight += newnode->rightchild->Data.Weight;
			newnode->rightchild->parent = newnode;
		} else break;
		// print ParentNode
		printf("parent:{%c,%d} leftchild:{%c,%d} rightchild:{%c,%d}\n",
		       newnode->Data.Char, newnode->Data.Weight,
		       newnode->leftchild->Data.Char, newnode->leftchild->Data.Weight,
		       newnode->rightchild->Data.Char, newnode->rightchild->Data.Weight);
	}
}
void printNode(node *Node,std::string code) {
	if(Node->Data.Char=='0'||Node->Data.Weight==0) { // node is parent node
		if(Node->leftchild!=NULL) printNode(Node->leftchild,code+"0");// node has leftchild
		if(Node->rightchild!=NULL) printNode(Node->rightchild,code+"1");// node has rightchild
	} else { // node is leaf node
		printf("node data:{%c,%d} encoding:'%s'\n",Node->Data.Char,Node->Data.Weight,code.c_str());
	}
}
void printHuffmanTree(std::vector<node> &nodelist) {
	node *Root = &nodelist[nodelist.size()-1];
	// find root node
	if(Root->rightchild==NULL && Root->leftchild->Data.Char=='0') Root = Root->leftchild;
	// print root node
	printf("root node:{%c,%d} ",Root->Data.Char, Root->Data.Weight);
	if(Root->leftchild)
		printf("leftchild:{%c,%d} ",Root->leftchild->Data.Char, Root->leftchild->Data.Weight);
	if(Root->rightchild)
		printf("rightchild{%c,%d}",Root->rightchild->Data.Char, Root->rightchild->Data.Weight);
	printf("\n");
	// print all nodes
	printNode(Root,"");
}
int main() {
	char s[1024];
	std::vector<node> nodelist;
	puts("please input a string (without '0' and less than 1024 characters)");
	gets(s);
	puts("\ngenerating node list...");
	generateNodeList(s,nodelist);
	puts("\ngenerating Huffman tree...");
	generateHuffmanTree(nodelist);
	puts("\nprinting Huffman tree...");
	printHuffmanTree(nodelist);
	system("pause");
}
