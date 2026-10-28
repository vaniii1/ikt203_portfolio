
#include "helper/TDataLoader.h"
#include "helper/TDataStructureConverter.h"
#include "helper/TPersonComparators.h"
#include "helper/TSearchPersons.h"
#include "helper/TSortPersons.h"


void PrintFirst10InArrayOfPersons(TPerson** array) {
	for (int i = 0; i < 10; i++) {
		std::cout << array[i]->ToString() << std::endl;
	}
}

int RunApp(int argc, char* argv[]) {
	TDataLoader dataLoader;
	dataLoader.dataInit();
	auto guests = dataLoader.getGuests();
	auto employees = dataLoader.getEmployees();

	TSortPersons::MergeSort(*guests, compareByName);
	TSortPersons::MergeSort(*employees, compareByName);

    std::cout << "-------Print 10 geusts sorted by name-----------" << std::endl;
	guests->PrintFirst10();
	std::cout << "-------------------------------------------" << std::endl;

	std::cout << "-------Print 10 employees sorted by name----------" << std::endl;
	employees->PrintFirst10();
	std::cout << "-------------------------------------------" << std::endl;

	int size = guests->GetSize();
	TPerson** cabinArray
		= TDataStructureConverter<TPerson>::FromLinkedListToArray(*guests);

	TSortPersons::QuickSortArray(cabinArray, size, compareByCabinAndLastName);

	std::cout << "-------Print 10 guests sorted by cabin and name----------" << std::endl;
	PrintFirst10InArrayOfPersons(cabinArray);
	std::cout << "-------------------------------------------" << std::endl;

	TPerson** alphabeticallyArray
		= TDataStructureConverter<TPerson>::FromLinkedListToArray(*guests);
	TPerson target;
	target.firstName = "Keren";
	target.lastName = "Agee";

	TPerson* result = TSearchPersons::BinarySearch(
		alphabeticallyArray,
		size,
		target,
		compareByName
	);

	if (result != nullptr) {
		std::cout << "Found: " << result->ToString() << '\n';
	} else {
		std::cout << "Guest not found.\n";
	}

	delete[] cabinArray;
	delete[] alphabeticallyArray;
	return 0;
}
