
#include <iostream>
#include <map>
#include <string>
int vis[10];
int n = 4; 
int totalSuccess = 0;
int puzzleTotal = 0;

int convertToNumber(std::string tmp, std::map<char, unsigned>& puzzle)
{
	int number = 0;
	for(int i = 0; i < tmp.size(); i++)
	{
		number += puzzle[tmp[i]];

//		std::cout << puzzle[tmp[i]];
//		std::cout << tmp[i];
		number *= 10;
	}
	return number;
}
bool compareAnswer(std::map<char, unsigned>& puzzle, std::string A, std::string B, std::string C)
{
	int number1 = 0, number2 = 0, number3 = 1,result = 0;
	number1 = convertToNumber(A, puzzle);
	number2 = convertToNumber(B, puzzle);
	number3 =convertToNumber(C,  puzzle );
	result = number1 + number2;
	if (result == number3) return true;
	return false;
}
void engine(int d , std::map<char, unsigned>& puzzle, std::string A, std::string B, std::string C)
{
	if (d == puzzleTotal)
	{
//		std::map<char, unsigned>::iterator it = puzzle.begin();
//		while (it != puzzle.end())
//		{
//			std::cout << it->first << " :: " << it->second << std::endl;
//			std::cout << it->second;
//			it++;
//		}
//		std::cout << "\n";

		/*if you want , you can see result.*/
 		if (compareAnswer(puzzle, A, B, C) == true) {
//			std::map<char, unsigned>::iterator it = puzzle.begin();
//			while (it != puzzle.end())
//			{
//				std::cout << it->first << " :: " << it->second << std::endl;//if you want , you can see result.
//				std::cout << it->second;
//				it++;
//			}		
//			std::cout << "\n";
			totalSuccess++;

		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (vis[i] == 0)
		{
			vis[i] = 1;
			std::map<char, unsigned>::iterator it = puzzle.begin();
			int inc = 0;
			while (it != puzzle.end())
			{
//				std::cout << it->first << " :: " << it->second << std::endl;
				if (inc == d)
				{
					puzzle[it->first] = i + 1;
					break;
				}
				it++;

				inc++;
			}
			 engine(d + 1,puzzle,A,B,C);
			vis[i] = 0;
		}
	}
}
void insertPuzzle(std::string tmp, std::map<char, unsigned>& puzzle) {
	for (int i = 0; i < tmp.size(); i++)
	{
		if (puzzle.insert(std::make_pair(tmp[i], 10)).second == true)
		{
			puzzle.insert(std::make_pair(tmp[i], 10));
//			puzzle[tmp[i]] = 1;
		}
	}
}
void outPut(std::map<char, unsigned>& puzzle)
{
	std::map<char, unsigned>::iterator it = puzzle.begin();
	while (it != puzzle.end())
	{
		std::cout << it->first << " :: " << it->second << std::endl;
		it++;
	}
}
bool puzzleSolver(std::string A, std::string B , std::string C, std::map<char, unsigned>& puzzle)
{
	insertPuzzle(A, puzzle);
	insertPuzzle(B, puzzle);
	insertPuzzle(C, puzzle);
	puzzleTotal = int(puzzle.size());
//	std::cout << "puzzleTotal   :" << engine(0, puzzle, A, B, C);
	//	outPut(puzzle);
	engine(0, puzzle,A,B,C);
	if (totalSuccess > 0) return true;
	return false;

}

int main()
{
	std::map<char, unsigned> puzzle;
//	bool p1 = puzzleSolver("POT", "PAN", "BIB", puzzle);
//	bool p1 = puzzleSolver("LARRY", "CAREER", "LEGEND", puzzle);
	bool p1 = puzzleSolver("UCI", "ALEX", "MIKE", puzzle);
	std::cout << (p1 == 1 ? "true" : "false");
//	std::cout << "Hello \n";
}
