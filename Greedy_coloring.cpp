//#include "Graph.h"
//
////The greedy algorithm that works for delta(G) or delt(G)+1 and for O(N^2)
////Also exists the random algorithm that works for delta(G)+1 and for O(N*logN)
//void greedyColoring(std::vector<Country>& m) {
//	std::vector<std::unordered_set<std::size_t>> cls(5);
//
//
//	for (std::size_t i = 0; i < m.size(); ++i) {
//		for (std::size_t j = 0; j < cls.size(); ++j) {
//			bool contains = false;
//			std::vector < std::size_t> ng = m[i].getNeighbours();
//			for (std::size_t k = 0; k < ng.size(); ++k) {
//				if (cls[j].find(ng[k]) != cls[j].end()) {
//					contains = true;
//				}
//			}
//			if (!contains) {
//				cls[j].insert(i);
//				break;
//			}
//		}
//	}
//	for (std::size_t i = 0; i < cls.size(); ++i) {
//		for (auto it : cls[i]) {
//			m[it].setColor(i);
//		}
//	}
//}
//
//int main() {
//	//Start working with the file
//
//	// Create a text string, which is used to output the text file
//	std::string tempText;
//	std::string mainInfo;
//	// Read from the text file
//	std::ifstream MapInfo("Map.txt");
//
//	// Use a while loop together with the getline() function to read the file line by line
//	while (getline(MapInfo, tempText)) {
//		// Output the text from the file
//		mainInfo += tempText + " ";
//	}
//
//	// Close the file
//	MapInfo.close();
//
//	//End working with the file
//	//Now we have all the information we need in mainInfo
//	std::vector<std::string> splittedInfo = splitString(mainInfo, ' ');
//	std::size_t countriesNumber = atoi(&splittedInfo[0][0]);
//	std::size_t ind = 1;
//	std::vector<Country> ourMap(countriesNumber);
//	for (std::size_t i = 0; i < countriesNumber; ++i) {
//		ourMap[i].setNumber(i);
//		ourMap[i].setName(splittedInfo[ind]);
//		++ind;
//	}
//	std::size_t tempNeighboursNumber;
//	for (std::size_t i = 0; i < countriesNumber; ++i) {
//		tempNeighboursNumber = atoi(&splittedInfo[ind][0]);
//		++ind;
//		for (std::size_t j = 0; j < tempNeighboursNumber; ++j) {
//			ourMap[i].addNeighbour(findIndex(ourMap, splittedInfo[ind]));
//			++ind;
//		}
//	}
//	//At this moment we have all the information about our map
//	std::cout << "The map before coloring: \n\n";
//
//	introduceMap(ourMap);
//
//	//If our map can be colored with 1 color(already is colored)
//	if (mainCond(ourMap)) {
//		std::cout << "It's possible to color with 1 color.\n";
//		introduceMap(ourMap);
//		return 0;
//	}
//
//	////uncomment this for bruteForceAlgorithm
//	//std::size_t finColNum = finalSolution(ourMap);
//
//	////test for greedyAlgorithm
//	std::size_t finColNum = 5;
//	greedyColoring(ourMap);
//	////
//
//
//	std::cout << "\nIt's possible to color with " << finColNum << " colors." << std::endl;
//	std::cout << "\nThe map after coloring: \n\n";
//	introduceMap(ourMap);
//	std::cout << std::endl;
//	//Writing to the result file
//
//	//Getting all edges by numbers
//	std::vector<std::pair<std::size_t, std::size_t>> edges;
//	for (auto it1 : ourMap) {
//		for (auto it2 : it1.getNeighbours()) {
//			if (it1.getNumber() < it2)
//				edges.push_back({ it1.getNumber(), it2 });
//			else
//				edges.push_back({ it2, it1.getNumber() });
//
//		}
//	}
//	std::set<std::pair<std::size_t, std::size_t>> s;
//	for (auto it : edges) {
//		s.insert(it);
//	}
//
//	std::ofstream res("Results.txt"); // Create a file named "Results.txt"
//
//	if (res.is_open()) { // Check if the file was successfully opened
//		res << ourMap.size() << std::endl;
//		for (auto it : ourMap) {
//			res << it.getName() << " ";
//		}
//		res << std::endl;
//		for (auto it : ourMap) {
//			if (it.getColor() == 0)
//				res << "yellow ";
//			else if (it.getColor() == 1)
//				res << "red ";
//			else if (it.getColor() == 2)
//				res << "green ";
//			else if (it.getColor() == 3)
//				res << "blue ";
//			else
//				res << "purple ";
//		}
//		res << std::endl;
//		for (auto it : s) {
//			res << it.first << " " << it.second << std::endl;
//		}
//		res.close(); // Close the file
//		std::cout << "File created and written successfully." << std::endl;
//	}
//	else {
//		std::cout << "Unable to create or open the file." << std::endl;
//	}
//
//	return 0;
//}