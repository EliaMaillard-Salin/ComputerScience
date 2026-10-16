
#include "BenchMark.h"
#include <iostream>

int main()
{
	BenchMark benchmark = BenchMark();
	

	std::cout << "---------------------- SORTING ALGO ---------------------- \n";
	std::cout << "\nBEST : \n";
	benchmark.LaunchSortingAlgo(1000,BenchMark::ListState::ASCENDING_SORTED);
	std::cout << "\nWORST : \n";
	benchmark.LaunchSortingAlgo(1000,BenchMark::ListState::DESCENDING_SORTED);
	std::cout << "\nAVERAGE : \n";
	benchmark.LaunchSortingAlgo(1000,BenchMark::ListState::RANDOM);

	std::cout << "---------------------- SEARCHING ALGO ---------------------- \n";

	benchmark.LaunchSearchingAlgo(100,98);

	benchmark.LaunchHuffmanAlgo("Alors, ça compresse, ça créer le fichier et tout hein mais je sais pas si la compression est correcte, et si la conversion en binaire se passe bien");

	return 1;
}