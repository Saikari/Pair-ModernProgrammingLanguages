#include "Ciphering.h"

size_t Ciphering::split(const std::wstring& txt, std::vector<std::wstring>& strs, wchar_t ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::wstring::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	// Add the last one
	strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

	return strs.size();
}


std::wstring Ciphering::cipher(std::wstring message)
{
	std::wstring ciphered = L"";
	for (wchar_t message : message)
	{
		std::wstring messageString = std::to_wstring(long(message) + 3333L);
		for (char number : messageString)
		{
			number = (7 + number) % 10;
		}
		std::swap(messageString[0], messageString[2]);
		std::swap(messageString[1], messageString[3]);
		long cipheredNumber = 0;
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
		for (char message : this->message)
		{
			std::wstring messageString = std::to_wstring(long(message) + 3333L);
			for (char number : messageString)
			{
				number = (7 + number) % 10;
			}
			std::swap(messageString[0], messageString[2]);
			std::swap(messageString[1], messageString[3]);
			int cipheredNumber = 0;
			std::wistringstream(messageString) >> cipheredNumber;
			ciphered += std::to_wstring(cipheredNumber) + L" ";
		}
		this->isCiphered = !this->isCiphered;
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
		if (messageCiphered == L"")
			return ciphered;
		std::swap(messageCiphered[0], messageCiphered[2]);
		std::swap(messageCiphered[1], messageCiphered[3]);
		for (wchar_t number : messageCiphered)
		{
			number = std::to_wstring(7.0 + number - 10.0 * floor((7.0 - number) / 10.0))[0];
		}
		long cipheredNumber = 0;
		std::wistringstream(messageCiphered) >> cipheredNumber;
		ciphered += static_cast<wchar_t>(cipheredNumber - 3333L);
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
			std::swap(messageCiphered[0], messageCiphered[2]);
			std::swap(messageCiphered[1], messageCiphered[3]);
			for (char number : messageCiphered)
			{
				number = std::to_wstring(7.0 + number - 10.0 * floor((7.0 - number) / 10.0))[0];
			}
			long cipheredNumber = 0;
			std::wistringstream(messageCiphered) >> cipheredNumber;
			ciphered += static_cast<wchar_t>(cipheredNumber - 3333L);
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
