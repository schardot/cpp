#include "PmergeMe.hpp"
#include <algorithm>

std::deque<Node> PmergeMe::fordJohnsonDeq(std::deque<Node>& input)
{
    if (input.size() <= 1)
        return input;

    std::deque<Node> mainChain;
    std::deque<Node> pendingPaired;
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
        ++deqComparisons;
        if (a.val > b.val)
            std::swap(a, b);
        a.pair = b.index;
        pendingPaired.push_back(a);
        mainChain.push_back(b);
    }

    mainChain = fordJohnsonDeq(mainChain);
    if (mainChain.empty())
        return mainChain;

    std::deque<Node> orderedPending;
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
    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i] - 1;
        if (idx >= orderedPending.size())
            continue;
        Node small = orderedPending[idx];
        std::deque<Node>::iterator bound = mainChain.begin();
        for (; bound != mainChain.end(); ++bound)
            if (bound->index == small.pair)
                break;
        std::deque<Node>::iterator pos = lowerBoundDeq(mainChain, bound, small);
        mainChain.insert(pos, small);
    }

    if (hasExtra)
    {
        std::deque<Node>::iterator pos = lowerBoundDeq(mainChain, mainChain.end(), extra);
        mainChain.insert(pos, extra);
    }
    return mainChain;
}
