#include <iostream>
#include <fstream>
#include <string>



bool overwrite(std::string put, std::string str) {
	std::fstream file(put);
	if (!file) {
		return false;
	}
	else
		std::fstream file(put, std::ios::out);
		if (file.is_open()) {
			file << str << "\n";
			file.close();
			return true;
		}
		
}


int main()
{
	system("chcp 1251>null");
	std::cout << "������ 1 \n";

	std::ofstream out;
	out.open("file.txt", std::ios::app);
	if (out.is_open()) {
		std::cout << "���� ������\n";
	}
	else
		std::cout << "������ �������� �����\n";

	if (out.is_open()) {
		std::string input;
		do {
			std::cout << "������� ������: ";
			std::getline(std::cin, input);
			out << input << "\n";
		} while (input != "end");
	}
	else
		std::cout << "������ �������� �����\n";
	out.close();

	std::ifstream in;
	in.open("file.txt");
	if (in.is_open()) {
		std::cout << "���� ������\n";
	}
	else
		std::cout << "������ �������� �����\n";
	if (in.is_open()) {
		std::string str;
		while (std::getline(in, str)) {
			std::cout << str << std::endl;
		}
	}
	else
			std::cout << "������ �������� �����\n";
	in.close();
	remove("file.txt");
	

	std::cout << "������ 2 \n";
	
	std::string put;
	std::cout << "������� ���� � �����: ";
	std::getline(std::cin, put);
	std::string str;
	std::cout << "������� ������: ";
	std::getline(std::cin, str);
	std::cout << overwrite(put, str);


	return 0;
}