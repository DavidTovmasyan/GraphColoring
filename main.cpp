#include "Graph.h"
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <cstddef>
//#include <algorithm>
//#include <string>
//#include <map>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//
//
//
////for coloring
//#define YELLOW 0
//#define RED 1
//#define GREEN 2
//#define BLUE 3
//#define PURPLE 4
//
////I think at this moment I need to keep only the number of the vertex, the color, the name, the neighbours
//class Country {
//public:
//	Country() :_number(0), _color(YELLOW), _name("None"), _neighbours({}) {}
//	Country(std::size_t number, std::string name) :_number(number), _name(name), _color(YELLOW), _neighbours({}) {}
//	Country(std::size_t number, std::size_t color, std::string name,const std::vector<std::size_t>& neighbours) :
//		_number(number), _color(color), _name(name), _neighbours(neighbours) {}
//	void operator=(Country rC) {
//		this->_number = rC.getNumber();
//		this->_color = rC.getColor();
//		this->_name = rC.getName();
//		this->_neighbours = rC.getNeighbours();
//	}
//	std::size_t getNumber() const {
//		return _number;
//	}
//	std::size_t getColor() const{
//		return _color;
//	}
//	std::string getName() const {
//		return _name;
//	}
//	std::vector<std::size_t> getNeighbours() const {
//		return _neighbours;
//	}
//	void setNumber(std::size_t newNumber) {
//		_number = newNumber;
//	}
//	void setColor(std::size_t newColor) {
//		_color = newColor;
//	}
//	void setName(std::string newName) {
//		_name = newName;
//	}
//	void setNeigbours(const std::vector<std::size_t>& newNeighbours) {
//		_neighbours = newNeighbours;
//	}
//	void addNeighbour(std::size_t newNeighbourInd) {
//		_neighbours.push_back(newNeighbourInd);
//	}
//private:
//	std::size_t _number;
//	std::size_t _color;
//	std::string _name;
//	std::vector<std::size_t> _neighbours;
//};
//
//
//
//std::size_t findIndex(std::vector<Country> v, std::string name) {
//	for (int i = 0; i < v.size(); ++i) {
//		if (v[i].getName() == name) {
//			return v[i].getNumber();
//		}
//	}
//	return -1;
//}
//
////For debugging
//void introduceCountry(Country c,const std::vector<Country>& ourMap) {
//	std::cout << c.getNumber() << "\t|" << c.getName() << "  \t|" << c.getColor()<<"\t|";
//	std::vector<std::size_t> n = c.getNeighbours();
//	for (auto it : n) {
//		std::cout << ourMap[it].getName() << " ";
//	}
//	std::cout << std::endl;
//}
//
//void introduceMap(std::vector<Country> m) {
//	std::cout << "NUMBER" << "\t|" << "NAME   " << "  \t|" << "COLOR" << "\t|NEIGBOURS" << std::endl;
//	std::cout << "------------------------------------------------------------------------\n";
//	for (auto it : m) {
//		introduceCountry(it, m);
//	}
//}
//
////For splitting a string
//std::vector<std::string> splitString(const std::string& str, char delimiter) {
//	std::vector<std::string> result;
//	size_t start = 0;
//	size_t end = str.find(delimiter);
//
//	while (end != std::string::npos) {
//		result.push_back(str.substr(start, end - start));
//		start = end + 1;
//		end = str.find(delimiter, start);
//	}
//
//	result.push_back(str.substr(start));
//	return result;
//}
//
////Function for checking if the neighbours dont have the same color
//bool mainCond(const std::vector<Country>& m) {
//	for (auto it1 : m) {
//		for (auto it2 : it1.getNeighbours()) {
//			if (it1.getColor() == m[it2].getColor())
//				return false;
//		}
//	}
//	return true;
//}
//
//bool ifAllIsTrue(std::vector<char> v) {
//	for (auto it : v) {
//		if (it == false) {
//			return false;
//		}
//	}
//	return true;
//}

////Functions for coloring the map with n colors
//
//bool colorTheMapRecDFS(std::vector<Country>& m, std::vector<char>& used,std::size_t cur_ind,std::vector<std::size_t> colors) {
//	used[cur_ind] = true;
//	std::vector<std::size_t> neighbours = m[cur_ind].getNeighbours();
//	m[cur_ind].setColor(colors[cur_ind]);
//	for (auto neig : neighbours) {
//		if (!used[neig]) {
//			colorTheMapRecDFS(m, used, neig, colors);
//		}
//	}
//	return false;
//}
//
//void colorTheMapDFS(std::vector<Country>& m, std::vector<std::size_t> colors){
//	std::vector<char> used(m.size(), false);
//	colorTheMapRecDFS(m, used, 0,colors);
//	//fix if we have islands
//}
//
//bool colorCombsRec(std::vector<Country> m,std::vector<std::size_t>& colors, std::size_t col_num, std::size_t ind) {
//	if (ind == colors.size()) {
//		colorTheMapDFS(m, colors);
//			if (mainCond(m))
//				return true;
//			return false;
//	}
//	for (std::size_t i = 0; i < col_num; ++i) {
//		colors[ind] = i;
//		if (colorCombsRec(m, colors, col_num, ind + 1))
//			return true;
//	}
//	return false;
//
//}
//
//std::vector<std::size_t> colorCombs(std::vector<Country> m, std::size_t col_num) {
//	std::vector<std::size_t> colors(m.size());
//	if(colorCombsRec(m,colors, col_num, 0))
//		return colors;
//	return {};
//}
//
//std::size_t finalSolution(std::vector<Country>& m) {
//	std::vector<std::size_t> fin_col = colorCombs(m, 2);
//	if (!fin_col.empty()) {
//		for (auto& it : m) {
//			it.setColor(fin_col[it.getNumber()]);
//		}
//		return 2;
//	}
//	fin_col = colorCombs(m, 3);
//	if (!fin_col.empty()) {
//		for (auto& it : m) {
//			it.setColor(fin_col[it.getNumber()]);
//		}
//		return 3;
//	}
//	fin_col = colorCombs(m, 4);
//	if (!fin_col.empty()) {
//		for (auto& it : m) {
//			it.setColor(fin_col[it.getNumber()]);
//		}
//		return 4;
//	}
//}
//
////The greedy algorithm that works for delta(G) or delt(G)+1 and for O(N^2)
////Also exists the random algorithm that works for delta(G)+1 and for O(N*logN)
//void greedyColoring(std::vector<Country>& m) {
//	std::vector<std::unordered_set<std::size_t>> cls (5);
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

int main() {
	//Start working with the file
	
	// Create a text string, which is used to output the text file
	std::string tempText;
	std::string mainInfo;
	// Read from the text file
	std::ifstream MapInfo("Map.txt");

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MapInfo, tempText)) {
		// Output the text from the file
		mainInfo += tempText +" ";
	}

	// Close the file
	MapInfo.close();
	
	//End working with the file
	//Now we have all the information we need in mainInfo
	std::vector<std::string> splittedInfo = splitString(mainInfo, ' ');
	std::size_t countriesNumber = atoi(&splittedInfo[0][0]);
	std::size_t ind = 1;
	std::vector<Country> ourMap(countriesNumber);
	for (std::size_t i = 0; i < countriesNumber; ++i) {
		ourMap[i].setNumber(i);
		ourMap[i].setName(splittedInfo[ind]);
		++ind;
	}
	std::size_t tempNeighboursNumber;
	for (std::size_t i = 0; i < countriesNumber; ++i) {
		tempNeighboursNumber = atoi(&splittedInfo[ind][0]);
		++ind;
		for (std::size_t j = 0; j < tempNeighboursNumber; ++j) {
			ourMap[i].addNeighbour(findIndex(ourMap,splittedInfo[ind]));
			++ind;
		}
	}
	//At this moment we have all the information about our map
	std::cout << "The map before coloring: \n\n";

	introduceMap(ourMap);

	//If our map can be colored with 1 color(already is colored)
	if (mainCond(ourMap)) {
		std::cout << "It's possible to color with 1 color.\n";
		introduceMap(ourMap);
	}
	else {
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		//test for bruteForceAlgorithm
		//std::size_t finColNum = finalSolution(ourMap);

		////test for greedyAlgorithm
		
		std::size_t finColNum = greedyColoring(ourMap);
		
		///////////////////////////////////////////////////////////////////////////////////////////////////////


		std::cout << "\nIt's possible to color with " << finColNum << " colors." << std::endl;
		std::cout << "\nThe map after coloring: \n\n";
		introduceMap(ourMap);
		std::cout << std::endl;
	}
	//Writing to the result file

	//Getting all edges by numbers
	std::vector<std::pair<std::size_t, std::size_t>> edges;
	for (auto it1 : ourMap) {
		for (auto it2 : it1.getNeighbours()) {
			if(it1.getNumber() < it2)
				edges.push_back({ it1.getNumber(), it2 });
			else
				edges.push_back({ it2, it1.getNumber() });

		}
	}
	std::set<std::pair<std::size_t, std::size_t>> s;
	for (auto it : edges) {
		s.insert(it);
	}

	std::ofstream res("Results.txt"); // Create a file named "Results.txt"

	if (res.is_open()) { // Check if the file was successfully opened
		res << ourMap.size() << std::endl;
		for (auto it : ourMap) {
			res << it.getName() << " ";
		}
		res << std::endl;
		for (auto it : ourMap) {
			if (it.getColor() == 0)
				res << "yellow ";
			else if (it.getColor() == 1)
				res << "red ";
			else if (it.getColor() == 2)
				res << "green ";
			else if (it.getColor() == 3)
				res << "blue ";
			else
				res << "purple ";
		}
		res<<std::endl;
		for (auto it : s) {
			res << it.first<<" "<<it.second << std::endl;
		}
		res.close(); // Close the file
		std::cout << "File created and written successfully." << std::endl;
	}
	else {
		std::cout << "Unable to create or open the file." << std::endl;
	}

	return 0;
}