#include "BellmanFord.h"

BellmanFord::BellmanFord(Reader read, int src_)
{
	std::vector<Point> list = read.getList();
    src = src_;
    if (src <0 || src>SIZE)
    {
        std::cout << "No such point\n";
        return;
    }
	SIZE = list.size();
	for (size_t i = 0; i < SIZE; ++i)
		this->finalCosts.push_back(i == src ? 0 : INT_MAX);
    for (int k = 1; k < SIZE; ++k)
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                if (list.at(j).getRoads().at(i)!= INT_MAX&& finalCosts[j]!= INT_MAX)
                    if (finalCosts[j] + list.at(j).getRoads().at(i) < finalCosts[i])
                        finalCosts[i] = finalCosts[j] + list.at(j).getRoads().at(i);

}

void BellmanFord::outPrint(int end)
{
    if (end < SIZE)
        std::cout << "Way from " << src << " to " << end << " cost " << finalCosts.at(end) << std::endl;
    else
        std::cout << "No such point\n";
}
