#ifndef _BELLMANFORD_H_
#define _BELLMANFORD_H_
#include <vector>
#include <iostream>
#include "Point.h"
#include "Reader.h"

class BellmanFord
{
private:
	std::vector<int> finalCosts;
	int src;
	int SIZE;
public:
	BellmanFord(Reader read, int scr_);
	void outPrint(int end);
};
#endif // _BELLMANFORD_H_
