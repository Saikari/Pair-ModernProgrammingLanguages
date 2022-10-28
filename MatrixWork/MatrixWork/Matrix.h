#pragma once
#include <vector>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <iomanip>
class Matrix
{
public:
	size_t rows;
	size_t cols;
	std::vector<std::vector<double>> mMatrix;
	Matrix(size_t rows, size_t cols)
	{
		this->rows = rows;
		this->cols = cols;
		this->mMatrix.resize(this->cols, std::vector<double>(this->rows));

		std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
		std::uniform_real_distribution<double> distribution(-49.9, 49.9);

		for (auto& row : this->mMatrix)
			for (auto& item : row)
				item = distribution(generator);
	}
	~Matrix()
	{
		this->rows = this->cols = 0;
		mMatrix = {};
	}
	void printMatrix();
	Matrix& operator++()
	{
		std::vector<std::vector<double>> tmp(this->rows, std::vector<double>());
		for (int i = 0; i < this->cols; ++i)
		{
			for (int j = 0; j < this->rows; ++j)
			{
				tmp[j].push_back(this->mMatrix[i][j]);
			}
		}
		this->mMatrix = tmp;
		std::swap(this->rows, this->cols);
		return *this;
	}


	Matrix operator++(int)
	{
		Matrix old = *this; 
		operator++(); 
		return old;    
	}

	Matrix& operator+=(const Matrix& rhs) 
	{                         
		for (auto rowInd = 0; rowInd < this->cols; ++rowInd)
		{
			for (auto colInd = 0; colInd < this->rows; ++colInd)
			{
				this->mMatrix[rowInd][colInd] += rhs.mMatrix[rowInd][colInd];
			}
		}
		return *this;
	}
	friend Matrix operator+(Matrix lhs,       
		const Matrix& rhs) 
	{

		lhs += rhs; 
		return lhs; 
	}

	Matrix& operator-=(const Matrix& rhs)
	{
		for (auto rowInd = 0; rowInd < this->cols; ++rowInd)
		{
			for (auto colInd = 0; colInd < this->rows; ++colInd)
			{
				this->mMatrix[rowInd][colInd] -= rhs.mMatrix[rowInd][colInd];
			}
		}
		return *this;
	}
	friend Matrix operator-(Matrix lhs,
		const Matrix& rhs)
	{

		lhs -= rhs;
		return lhs;
	}

};

