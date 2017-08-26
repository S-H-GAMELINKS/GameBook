#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

std::vector<std::string> Script;

//�X�N���v�g�Ǎ��֐�
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
}

//�I�����`��֐�
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

//�X�N���v�g�`��֐�
int ScriptDraw(int root) {

	int RootChoice;

	for (auto&& s : Script) {

		if (s == "CHOICE") {
			system("cls");
			ChoiceDraw(root);
			std::cin >> RootChoice;

			if (RootChoice == 1) {
				root *= 2;
				return root;
			} else {
				root *= 2 + 1;
				return root;
			}
		}

		if (s == "END")
			return root = 99;

		std::cout << s << std::endl;
		getchar();
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