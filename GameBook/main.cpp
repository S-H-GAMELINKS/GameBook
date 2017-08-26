#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

std::vector<std::string> Script;

//スクリプト読込関数
void ScriptRead(int root) {

	const char* Root[] = {
		"STR/Main.txt", "STR/A.txt", 
		"STR/B.txt", "STR/C.txt", 
		"STR/D.txt", "STR/E.txt", 
		"STR/F.txt"};

	std::fstream File(Root[root - 1]);

	for (std::string s; std::getline(File, s); )
		Script.emplace_back(std::move(s));
}

//選択肢描画関数
void ChoiceDraw(int root) {

	std::string choice1, choice2;

	const char* Choice[][2] = { {"CHOICE/A.txt", "CHOICE/B.txt"},
								{"CHOICE/C.txt", "CHOICE/D.txt" },
								{"CHOICE/E.txt","CHOICE/F.txt"} };

	std::fstream File1(Choice[root - 1][0]);
	std::fstream File2(Choice[root - 1][1]);

	std::getline(File1, choice1);
	std::getline(File2, choice2);

	std::cout << "1 : " << choice1 << std::endl;
	std::cout << "2 : " << choice2 << std::endl;
}

//スクリプト描画関数
void ScriptDraw(int root) {

	int RootChoice;

	for (auto&& s : Script) {

		if (s == "CHOICE") {
			system("cls");
			ChoiceDraw(root);
			std::cin >> RootChoice;
		}

		if (s == "END")
			break;

		std::cout << s << std::endl;
		getchar();
	}
}

int main() {

	int root = 1;

	ScriptRead(root);

	ScriptDraw(root);

	return 0;
}