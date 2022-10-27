#include <iostream>
#include <deque>
#include "Ciphering.h"
std::deque<size_t> eratosfenSieve(size_t n)
{
	std::deque<size_t> result{};
	std::deque<bool> prime(n + 1ull, true);
	prime[0] = prime[1] = false;
	for (size_t i = 2ull; i < n + 1ull; ++i)
		if (prime[i])
		{
			result.push_back(i);
			if (i * i < n + 1ull)
				for (size_t j = i * i; j < n + 1ull; j += i)
					prime[j] = false;
		}
	return result;
}
std::deque<size_t> opt_eratosfenSieve(size_t n)
{
	std::deque<size_t> result{2};
	std::deque<bool> prime(n / 2ull + 1ull, true);
	size_t maxFactor = sqrt(n);
	for (size_t p = 3ull; p < maxFactor + 1ull; p += 2ull)
	{
		if (prime[p / 2ull])
		{
			for (size_t i = p * p; i < n; i += 2ull * p)
			{
				prime[i / 2ull] = false;
			}
		}
	}
	for (size_t i = 1ull; i < n / 2ull; ++i)
		if (prime[i])
		{
			size_t p = i * 2ull + 1ull;
			if (n < p + 1ull)
				break;
			result.push_back(p);
		}
	return result;
}


int main() {
	system("chcp 866");
	std::wcout.imbue(std::locale::locale(".866"));
	std::wcin.imbue(std::locale::locale(".866"));
	Ciphering * ci = new Ciphering(L"Хотя  TTF.", 3333U);
	auto lines = ci->readfile(L"C:/test.txt");
	ci->writefile(L"C:/test2.txt", lines);
	//std::wcout << ci->cipher() << std::endl;
	//std::wcout << ci->decipher() << std::endl;
	//std::wstring message = L"Хотя общий потолок цен введен не будет, Еврокомиссия добивается от национальных правительств разрешения предлагать (только в крайних случаях) ценовые ограничения на сделки на хабе TTF.";//L"Practicing your comprehension of written english will both improve your vocabulary and understanding of grammar and word order.";
	//std::wstring cipheredMessage = ci->cipher(message);
	//std::wstring decipheredMessage = ci->decipher(cipheredMessage);
	//std::wcout << message << std::endl;
	//std::wcout << cipheredMessage << std::endl;
	//std::wcout << decipheredMessage << std::endl;
	//delete ci;
	//long n = 0;
	//std::wcout << L"Введите N для решета Эратосфена и нахождения всех простых чисел от 2 до N" << std::endl;
	//std::wcin >> n;
	//auto a = eratosfenSieve(n);
	//auto b = opt_eratosfenSieve(n);
	//std::wcout << L"Решето Эратосфена : " << a.size() << std::endl;
	//for (auto i : a)
	//	std::wcout << i << L"\t";
	//std::wcout << std::endl << L"Опт. Решето Эратосфена : " << b.size() << std::endl;
	//for (auto i : b)
	//	std::wcout << i << L"\t";
	return 0;
}