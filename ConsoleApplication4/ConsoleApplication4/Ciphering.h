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
	unsigned key;
	Ciphering(std::wstring message, unsigned key)
	{
		this->message = message;
		this->isCiphered = false;
		this->key = key;
	}
	~Ciphering()
	{
		this->isCiphered = false;
		this->key = 0U;
	}
	std::wstring cipher(std::wstring message);
	std::wstring cipher();
	std::wstring decipher(std::wstring messageCiphered);
	std::wstring decipher();
	std::vector<std::wstring> readfile(const std::wstring & filepath);
	void writefile(const std::wstring& filepath, std::vector<std::wstring>& lines);
private:
	size_t split(const std::wstring& txt, std::vector<std::wstring>& strs, wchar_t ch);
};

