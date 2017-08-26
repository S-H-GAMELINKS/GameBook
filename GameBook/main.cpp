#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> Script;

void ScriptDraw() {
	for (auto&& s : Script) {
		std::cout << s << std::endl;
		getchar();
	}
}

int main() {

	std::fstream File("test.txt");

	for (std::string s; std::getline(File, s); )
		Script.emplace_back(std::move(s));

	ScriptDraw();

	return 0;
}