#include "GeomProgression.h"
void GeomProgression::printProgression()
{
	std::cout << u8"Прогрессия:" << std::endl << u8"[1] элемент прогрессии => " << 1 << std::endl;
	for (size_t i = 1; i < this->sizeProg; ++i)
	{
		std::cout << u8"[" << i + 1 << u8"] " << u8"элемент прогрессии => " << this->progression[i - 1] << u8" * " << this->stepProg << u8" = " << this->progression[i] << std::endl;
	}
}
double GeomProgression::getElem(size_t index)
{
	return this->progression[index];
}
void GeomProgression::printElem(size_t index)
{
	std::cout << u8"Элемент прогрессии с индексом " << index + 1 << u8" = " << this->getElem(index) << std::endl;
}
double GeomProgression::sumProgIndex(size_t index)
{
	double sum = 0;
	for (size_t i = 0; i < index; ++i)
		sum += this->getElem(i);
	return sum;
}
void GeomProgression::printSumProgIndex(size_t index)
{
	std::cout << u8"Сумма элементов прогрессии с начала до индекса " << index + 1 << u8" = " << this->sumProgIndex(index) << std::endl;
}