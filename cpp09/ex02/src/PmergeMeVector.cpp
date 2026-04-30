#include "PmergeMe.hpp"
#include <algorithm>

std::vector<Node> PmergeMe::fordJohnsonVec(std::vector<Node>& input)
{
    if (input.size() <= 1)
        return input;

    std::vector<Node> mainChain;
    std::vector<Node> pendingPaired;
    bool hasExtra = false;
    Node extra;
    for (size_t i = 0; i < input.size(); i += 2)
    {
        if (i + 1 >= input.size())
        {
            hasExtra = true;
            extra = input[i];
            break;
        }
        Node a = input[i];
        Node b = input[i + 1];
        ++vecComparisons;
        if (a.val > b.val)
            std::swap(a, b);
        a.pair = b.index;
        pendingPaired.push_back(a);
        mainChain.push_back(b);
    }

    mainChain = fordJohnsonVec(mainChain);
    if (mainChain.empty())
        return mainChain;

    std::vector<Node> orderedPending;
    for (size_t i = 0; i < mainChain.size(); ++i)
        for (size_t j = 0; j < pendingPaired.size(); ++j)
            if (pendingPaired[j].pair == mainChain[i].index)
            {
                orderedPending.push_back(pendingPaired[j]);
                break;
            }

    if (!orderedPending.empty())
        mainChain.insert(mainChain.begin(), orderedPending[0]);

    std::vector<int> order = jacobsthalOrder(orderedPending.size());
    bool extraInserted = false;
    size_t extraInsertStep = order.size();
    if (hasExtra)
    {
        if (orderedPending.size() == 2)
            extraInsertStep = 0;
        else if (orderedPending.size() >= 4 && !order.empty())
            extraInsertStep = order.size() - 1;
    }

    for (size_t i = 0; i < order.size(); ++i)
    {
        if (hasExtra && !extraInserted && i == extraInsertStep)
        {
            std::vector<Node>::iterator posStr = lowerBoundVec(mainChain, mainChain.end(), extra);
            mainChain.insert(posStr, extra);
            extraInserted = true;
        }
        size_t idx = order[i] - 1;
        if (idx >= orderedPending.size())
            continue;
        Node small = orderedPending[idx];
        std::vector<Node>::iterator bound = mainChain.begin();
        for (; bound != mainChain.end(); ++bound)
            if (bound->index == small.pair)
                break;
        std::vector<Node>::iterator pos = lowerBoundVec(mainChain, bound, small);
        mainChain.insert(pos, small);
    }

    if (hasExtra && !extraInserted)
    {
        std::vector<Node>::iterator pos = lowerBoundVec(mainChain, mainChain.end(), extra);
        mainChain.insert(pos, extra);
    }
    return mainChain;
}
