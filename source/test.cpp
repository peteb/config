#include <iostream>
#include <sstream>
#include "propertynode.h"
#include "propertytreeprinter.h"
#include "propertytreeparser.h"

int main(int argc, const char ** argv) {
	/*PropertyNode root("root");
	
	
	PropertyNode myNode("cool");
	myNode.addAttribute("attrib1");
	myNode.addProperty(Property("key", "value katt"));
	
	myNode.addNode(myNode);
	
	root.addNode(myNode);
	root.addNode(myNode);
	*/
	
	PropertyTreePrinter printer(std::cout);
	//printer.print(root);
	
	
	
	
	
	
	PropertyNode base("root");
	PropertyNode myNode("node1");
	myNode.addProperty(Property("ett", "tva"));

	PropertyNode subsub("tjabam");
	subsub.addProperty(Property("size", "45"));
	myNode.addNode(subsub);
	
	base.addNode(myNode);
	
	
	PropertyNode sub("root");
	myNode.addProperty(Property("tja", "buh-bye"));

	
	myNode.getNode("tjabam").addProperty(Property("width", "88"));
	myNode.getNode("tjabam").addProperty(Property("size", "666 och 333"));

	sub.addNode(myNode);
	
	
	printer.print(base);
	printer.print(sub);
	
	PropertyNode newRoot = PropertyNode::MergeTrees(base, sub);
	
	printer.print(newRoot);
	
	
	
	std::stringstream ss;
	PropertyTreePrinter newPrinter(ss);
	//newPrinter.print(newRoot, false);
	
	ss << "abc {";
	ss << "   key value\n";
	ss << "}tja {key value\n}";
	
	std::cout << "SS: " << std::endl << ss.str() << std::endl;
	
	
	PropertyTreeParser parser;
	PropertyNode createdTree = parser.parse(ss.str());
	
	std::cout << "parsed:" << std::endl;
	printer.print(createdTree);
	
	return EXIT_SUCCESS;
}
