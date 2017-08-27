#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

std::vector<std::string> Script;

//スクリプト読込関数
void ScriptRead(int root) {

	Script.clear();

	const char* Root[] = {
		"STR/Main.txt", "STR/A.txt", 
		"STR/B.txt", "STR/C.txt", 
		"STR/D.txt", "STR/E.txt", 
		"STR/F.txt"};

	std::fstream File(Root[root - 1]);

	for (std::string s; std::getline(File, s); )
		Script.emplace_back(std::move(s));

	File.close();
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

	File1.close();
	File2.close();
}

//選択処理関数
int ScriptChoiceDraw(int root) {

	int RootChoice;

	system("cls");
	ChoiceDraw(root);
	std::cin >> RootChoice;

	if (RootChoice == 1) {
		system("cls");
		root *= 2;
		return root;
	}
	else {
		system("cls");
		root *= 2 + 1;
		return root;
	}
}

//スクリプト描画関数
int ScriptDraw(int root) {

	int RootChoice;

	for (auto&& s : Script) {

		if (s == "CHOICE") {
			return root = ScriptChoiceDraw(root);
		}
		else if (s == "END") {
			return root = 99;
		}
		else {
			std::cout << s << std::endl;
			getchar();
		}
	}
}

int main() {

	int root = 1;

	while (root != 99) {

		ScriptRead(root);

		root = ScriptDraw(root);

		if (root == 99)
			break;
	}

	return 0;
}