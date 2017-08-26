#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> Script;

//スクリプト読込関数
void ScriptRead(int root) {

	const char* Root[] = {"Main.txt", "A.txt", "B.txt", "C.txt", "D.txt", "E.txt", "F.txt"};

	std::fstream File(Root[root - 1]);

	for (std::string s; std::getline(File, s); )
		Script.emplace_back(std::move(s));
}

//スクリプト描画関数
void ScriptDraw() {
	for (auto&& s : Script) {
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