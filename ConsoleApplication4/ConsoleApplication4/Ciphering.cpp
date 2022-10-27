#include "Ciphering.h"
#include <fstream>

size_t Ciphering::split(const std::wstring& txt, std::vector<std::wstring>& strs, wchar_t ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::wstring::npos) {
		if (txt.substr(initialPos, pos - initialPos).length() != 0)
			strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	// Add the last one
	if (txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1).length() != 0)
		strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

	return strs.size();
}


std::wstring Ciphering::cipher(std::wstring message)
{
	std::wstring ciphered = L"";
	for (wchar_t message : message)
	{
		std::wstring messageString = std::to_wstring(unsigned(message) + this->key);
		for (wchar_t number : messageString)
		{
			number = (7 + number) % 10;
		}
		//std::swap(messageString[0], messageString[2]);
		std::swap(messageString[1], messageString[3]);
		unsigned cipheredNumber = 0;
		std::wistringstream(messageString) >> cipheredNumber;
		ciphered += std::to_wstring(cipheredNumber) + L" ";
	}
	return ciphered;
}

std::wstring Ciphering::cipher()
{
	if (!this->isCiphered)
	{
		std::wstring ciphered = L"";
		for (wchar_t message : this->message)
		{
			std::wstring messageString = std::to_wstring(unsigned(message) + this->key);
			for (wchar_t number : messageString)
			{
				number = (7 + number) % 10;
			}
			//std::swap(messageString[0], messageString[2]);
			std::swap(messageString[1], messageString[3]);
			unsigned cipheredNumber = 0;
			std::wistringstream(messageString) >> cipheredNumber;
			ciphered += std::to_wstring(cipheredNumber) + L" ";
		}
		this->isCiphered = !this->isCiphered;
		this->message = ciphered;
		return ciphered;
	}
	else
	{
		std::wcout << L"Сообщение уже зашифровано!" << std::endl;
		return L"Сообщение уже зашифровано!";
	}
}

std::wstring Ciphering::decipher(std::wstring messageCiphered)
{
	std::wstring ciphered = L"";
	std::vector <std::wstring> splitted{};
	split(messageCiphered, splitted, L' ');
	for (std::wstring messageCiphered : splitted)
	{
		std::swap(messageCiphered[1], messageCiphered[3]);
		for (wchar_t number : messageCiphered)
		{
			number = std::to_wstring(7.0 + number - 10.0 * floor((7.0 - number) / 10.0))[0];
		}
		unsigned cipheredNumber = 0;
		std::wistringstream(messageCiphered) >> cipheredNumber;
		ciphered += static_cast<wchar_t>(cipheredNumber - this->key);
	}
	return ciphered;
}
std::wstring Ciphering::decipher()
{
	if (this->isCiphered)
	{
		std::wstring ciphered = L"";
		std::vector <std::wstring> splitted{};
		split(this->message, splitted, L' ');
		for (std::wstring messageCiphered : splitted)
		{
			//std::swap(messageCiphered[0], messageCiphered[2]);
			std::swap(messageCiphered[1], messageCiphered[3]);
			for (wchar_t number : messageCiphered)
			{
				number = std::to_wstring(7.0 + number - 10.0 * floor((7.0 - number) / 10.0))[0];
			}
			unsigned cipheredNumber = 0;
			std::wistringstream(messageCiphered) >> cipheredNumber;
			ciphered += static_cast<wchar_t>(cipheredNumber - this->key);
		}
		this->message = ciphered;
		this->isCiphered = !this->isCiphered;
		return ciphered;
	}
	else
	{
		std::wcout << L"Сообщение уже расшифрорвано!" << std::endl;
		return L"Сообщение уже расшифрорвано!";
	}
}

std::vector<std::wstring> Ciphering::readfile(const std::wstring& filepath)
{
	std::vector<std::wstring> lines{};
	std::wifstream file(filepath);
	file.imbue(std::locale::locale(".65001"));
	if (!file.is_open())
	{
		std::wcout << L"Файл не открыт." << std::endl;
	}
	else
	{
		std::wstring line = L"";
		while (getline(file, line))
			lines.push_back(line);
	}
	return lines;
}
void Ciphering::writefile(const std::wstring& filepath, std::vector<std::wstring>& lines)
{
	std::wofstream file(filepath);
	file.imbue(std::locale::locale(".65001"));
	for (const auto& item : lines)
		file << item << std::endl;
	file.close();
}
