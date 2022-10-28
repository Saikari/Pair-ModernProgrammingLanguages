#pragma once
#include <vector>
#include <iostream>
class GeomProgression
{
public:
	size_t sizeProg;
	double stepProg;
	GeomProgression(size_t sizeProg, double stepProg)
	{
		this->sizeProg = sizeProg;
		this->stepProg = stepProg;
		progression.push_back(1.0);
		for (size_t i = 1; i < sizeProg; ++i)
		{
			progression.push_back(progression.back() * this->stepProg);
		}
	}
	~GeomProgression()
	{
		progression = {};
		sizeProg = 0;
		stepProg = 0.0;
	}
	void printProgression();
	double getElem(size_t index);
	void printElem(size_t index);
	double sumProgIndex(size_t index);
	void printSumProgIndex(size_t index);
private:
	std::vector<double> progression;
};

