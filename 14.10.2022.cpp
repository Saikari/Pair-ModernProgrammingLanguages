#include <iostream>
#include "Ciphering.h"

int main() {
	system("chcp 866");
	std::wcout.imbue(std::locale::locale(".866"));
	std::wcin.imbue(std::locale::locale(".866"));
	Ciphering * ci = new Ciphering(L"asd");
	std::wstring message = L"Practicing your comprehension of written english will both improve your vocabulary and understanding of grammar and word order.";
	std::wstring cipheredMessage = ci->cipher(message);
	std::wstring decipheredMessage = ci->decipher(cipheredMessage);
	std::wcout << message << std::endl;
	std::wcout << cipheredMessage << std::endl;
	std::wcout << decipheredMessage << std::endl;
	delete ci;
	return 0;
}
