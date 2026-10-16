
#include "BenchMark.h"

int main()
{
	BenchMark benchmark = BenchMark();
	

	benchmark.LaunchSortingAlgo(100,BenchMark::ListState::ASCENDING_SORTED);
	benchmark.LaunchSortingAlgo(100,BenchMark::ListState::DESCENDING_SORTED);
	benchmark.LaunchSortingAlgo(100,BenchMark::ListState::RANDOM);

	benchmark.LaunchSearchingAlgo(100,98);
	benchmark.LaunchSearchingAlgo(100,98);
	benchmark.LaunchSearchingAlgo(100,98);

	benchmark.LaunchHuffmanAlgo("Alors, ça compresse, ça créer le fichier et tout hein mais je sais pas si la compression est correcte, et si la conversion en binaire se passe bien");

	return 1;
}