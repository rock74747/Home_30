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
	std::cout << "Задача 1 \n";

	std::ofstream out;
	out.open("file.txt", std::ios::app);
	if (out.is_open()) {
		std::cout << "Файл открыт\n";
	}
	else
		std::cout << "Ошибка открытия файла\n";

	if (out.is_open()) {
		std::string input;
		do {
			std::cout << "Введите строку: ";
			std::getline(std::cin, input);
			out << input << "\n";
		} while (input != "end");
	}
	else
		std::cout << "Ошибка открытия файла\n";
	out.close();

	std::ifstream in;
	in.open("file.txt");
	if (in.is_open()) {
		std::cout << "Файл открыт\n";
	}
	else
		std::cout << "Ошибка открытия файла\n";
	if (in.is_open()) {
		std::string str;
		while (std::getline(in, str)) {
			std::cout << str << std::endl;
		}
	}
	else
			std::cout << "Ошибка открытия файла\n";
	in.close();
	remove("file.txt");
	

	std::cout << "Задача 2 \n";
	
	std::string put;
	std::cout << "Введите путь к файлу: ";
	std::getline(std::cin, put);
	std::string str;
	std::cout << "Введите строку: ";
	std::getline(std::cin, str);
	std::cout << overwrite(put, str);


	return 0;
}