#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <sstream>
std::vector<int> cipher(std::vector<int>* messages)
{
	std::vector<int> ciphered{};
	for (int message : *messages)
	{
		std::string messageString = std::to_string(message);
		for (char number : messageString)
		{
			number = (7 + number) % 10;
		}
		std::swap(messageString[0], messageString[2]);
		std::swap(messageString[1], messageString[3]);
		int cipheredNumber = 0;
		std::istringstream(messageString) >> cipheredNumber;
		ciphered.push_back(cipheredNumber);
	}
	return ciphered;
}

std::vector<int> decipher(std::vector<int>* messagesCiphered)
{
	std::vector<int> ciphered{};
	for (int messageCiphered : *messagesCiphered)
	{
		std::string messageString = std::to_string(messageCiphered);
		std::swap(messageString[0], messageString[2]);
		std::swap(messageString[1], messageString[3]);
		for (char number : messageString)
		{
			number = std::to_string(7.0 + number - 10.0 * 
				floor((7.0 - number) / 10.0))[0];
		}

		int cipheredNumber = 0;
		std::istringstream(messageString) >> cipheredNumber;
		ciphered.push_back(cipheredNumber);
	}
	return ciphered;
}


int f(int, int);

int l(int k, int n, int i) {
	return i ? f(k, n - i) + l(k, n, i - 1) : n <= k;
}

int f(int k, int n) {
	if (n <= 0)
		return 0;
	else
		return l(k, n, k);
}



void print(std::vector<std::vector<int>> output) {
	for (int i = 0; i < output.size(); i++) {
		do {
			for (int j = 0; j < output[i].size(); j++) {
				std::wcout << output[i][j] << (j != output[i].size() - 1 ? L" -> " : L"");
			}
			std::wcout << std::endl;
		} while (std::next_permutation(output[i].begin(), output[i].end()));
	}
}

void print_all_sum_rec(
	int target,
	int current_sum,
	int start, std::vector<std::vector<int>>& output,
	std::vector<int>& result,
	int k) {

	if (target == current_sum) {
		output.push_back(result);
	}

	for (int i = start; i < k + 1; ++i) {
		int temp_sum = current_sum + i;
		if (temp_sum <= target) {
			result.push_back(i);
			print_all_sum_rec(target, temp_sum, i, output, result, k);
			result.pop_back();

		}
		else {
			return;
		}
	}
}

std::vector<std::vector<int>> print_all_sum(int target, int k) {
	std::vector<std::vector<int>> output;
	std::vector<int> result;
	print_all_sum_rec(target, 0, 1, output, result, k);
	return output;
}

int main() {
	system("chcp 866");
	std::wcout.imbue(std::locale::locale(".866"));
	std::wcin.imbue(std::locale::locale(".866"));
	std::vector<int> messages{};
	unsigned size = 10;
	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(1000, 9999);
	for (unsigned i = 0; i < size; ++i)
	{
		int val = distribution(generator);
		while (val / 10 % 10 == 0)
			val = distribution(generator);
		messages.push_back(val);
	}
	std::wcout << L"Исходное сообщение " << std::endl;
	for (auto message : messages)
		std::wcout << message << "\t";
	std::wcout << std::endl << L"Зашифрованное сообщение " << std::endl;
	auto cipheredMessages = cipher(&messages);
	for (auto cipheredMessage : cipheredMessages)
		std::wcout << cipheredMessage << "\t";
	std::wcout << std::endl << L"Расшифрованное сообщение " << std::endl;
	auto decipheredMessages = decipher(&cipheredMessages);
	for (auto decipheredMessage : decipheredMessages)
		std::wcout << decipheredMessage << "\t";
	int k, n;
	std::wcout << std::endl << L"Введите k " << std::endl;
	std::wcin >> k;
	std::wcout << std::endl << L"Введите n " << std::endl;
	std::wcin >> n;
	std::wcout << std::endl << L"k = " << k << L"\tn = " << n;
	std::wcout << std::endl << L"Количество путей = " << f(k, n) << std::endl;
	std::vector<std::vector<int>> result = print_all_sum(n, k);
	print(result);
	return 0;
}
