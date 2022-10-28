#include "Matrix.h"
void Matrix::printMatrix()
{
	for (const auto& row : this->mMatrix)
	{
		for (const auto& item : row)
		{
			std::cout << std::setw(10) << std::setprecision(3) << item;
		}
		std::cout << std::endl;
	}

}