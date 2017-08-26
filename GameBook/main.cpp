#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> Script;

//�X�N���v�g�Ǎ��֐�
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

//�X�N���v�g�`��֐�
void ScriptDraw() {
	for (auto&& s : Script) {

		if (s == "END")
			break;

		std::cout << s << std::endl;
		getchar();
	}
}

int main() {

	int root = 1;

	ScriptRead(root);

	ScriptDraw();

	return 0;
}