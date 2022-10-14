#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
class Ciphering
{
public:
	std::wstring message;
	bool isCiphered;
	Ciphering(std::wstring message)
	{
		this->message = message;
		this->isCiphered = false;
	}
	~Ciphering()
	{
		this->isCiphered = false;
	}
	std::wstring cipher(std::wstring message);
	std::wstring cipher();
	std::wstring decipher(std::wstring messageCiphered);
	std::wstring decipher();
private:
	size_t split(const std::wstring& txt, std::vector<std::wstring>& strs, wchar_t ch);
};

