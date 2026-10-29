#include "app.h"

#include <iostream>
#include "DataStructures/TLinkedList.hpp"
#include "Utils/TEmployeeLoader.h"
#include "Models/TEmployee.h"
#include "TreeDataStructures/TAVLTree.h"
#include "TreeDataStructures/TBinarySearchTree.h"

int RunApp(int argc, char* argv[]) {
	TEmployeeLoader loader;
	loader.DataInit();

	TBinarySearchTree<TEmployee> bst;
	TAVLTree<TEmployee> avl;

	TLinkedList<TEmployee>& employees = loader.GetEmployees();

	for (int i = 0; i < employees.GetSize(); i++) {
		TEmployee* employee = employees.GetAtIndex(i);

		if (employee != nullptr) {
			bst.Insert(employee->employeeID, *employee);
			avl.Insert(employee->employeeID, *employee);
		}
	}

	TEmployee* bstResult = bst.Search(employees.GetAtIndex(199)->employeeID);
	TEmployee* avlResult = avl.Search(employees.GetAtIndex(199)->employeeID);

	std::cout << "BST result : " << bstResult->ToString() << std::endl;
	std::cout << "AVL result : " << avlResult->ToString() << std::endl;
	return 0;
}
