#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <exception>
#include <cstdlib>
#include <cstring>
#include <map>


PmergeMe::PmergeMe(int ac, char **av): vecComparisons(0), deqComparisons(0)
{
    if (ac < 2)
        throw std::runtime_error("Error");

    for (int i = 1; i < ac; ++i)
    {
        std::istringstream iss(av[i]);
        int num;

        iss >> num;

        if (iss.fail() || !iss.eof() || num < 0)
            throw std::runtime_error("Error");

        vec.push_back(num);
        deq.push_back(num);
    }

    run();
}

std::vector<Node> PmergeMe::fordJohnsonVec(std::vector<Node>& input)
{
    if (input.size() <= 1)
        return input;

    std::vector<Node> mainChain;
    std::vector<Node> pendingPaired;
    bool hasExtra = false;
    Node extra;

    // step 1: pair and separate
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

    // step 2: recursively sort larger elements
    mainChain = fordJohnsonVec(mainChain);

    if (mainChain.empty())
        return mainChain;

    // align smalls with the sorted order of their paired bigs
    std::vector<Node> orderedPending;
    std::map<int, Node> byPair;
    for (size_t i = 0; i < pendingPaired.size(); ++i)
        byPair[pendingPaired[i].pair] = pendingPaired[i];
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        std::map<int, Node>::iterator it = byPair.find(mainChain[i].index);
        if (it != byPair.end())
            orderedPending.push_back(it->second);
    }

    // b1 pair (a1) is inserted for free at chain start
    if (!orderedPending.empty())
        mainChain.insert(mainChain.begin(), orderedPending[0]);

    // step 3: jacobsthal-guided insertion of remaining smalls
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
        {
            if (bound->index == small.pair)
                break;
        }

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

std::deque<Node> PmergeMe::fordJohnsonDeq(std::deque<Node>& input)
{
    if (input.size() <= 1)
        return input;

    std::deque<Node> mainChain;
    std::deque<Node> pendingPaired;
    bool hasextra = false;
    Node extra;

    // step 1: pair and separate
    for (size_t i = 0; i < input.size(); i += 2)
    {
        if (i + 1 >= input.size())
        {
            hasextra = true;
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

    // step 2: recursively sort larger elements
    mainChain = fordJohnsonDeq(mainChain);

    if (mainChain.empty())
        return mainChain;

    std::deque<Node> orderedPending;
    std::map<int, Node> byPair;
    for (size_t i = 0; i < pendingPaired.size(); ++i)
        byPair[pendingPaired[i].pair] = pendingPaired[i];
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        std::map<int, Node>::iterator it = byPair.find(mainChain[i].index);
        if (it != byPair.end())
            orderedPending.push_back(it->second);
    }

    if (!orderedPending.empty())
        mainChain.insert(mainChain.begin(), orderedPending[0]);

    std::vector<int> order = jacobsthalOrder(orderedPending.size());
    bool extraInserted = false;
    size_t extraInsertStep = order.size();
    if (hasextra)
    {
        if (orderedPending.size() == 2)
            extraInsertStep = 0;
        else if (orderedPending.size() >= 4 && !order.empty())
            extraInsertStep = order.size() - 1;
    }

    for (size_t i = 0; i < order.size(); ++i)
    {
        if (hasextra && !extraInserted && i == extraInsertStep)
        {
            std::deque<Node>::iterator posStr = lowerBoundDeq(mainChain, mainChain.end(), extra);
            mainChain.insert(posStr, extra);
            extraInserted = true;
        }

        size_t idx = order[i] - 1;
        if (idx >= orderedPending.size())
            continue;

        Node small = orderedPending[idx];
        std::deque<Node>::iterator bound = mainChain.begin();
        for (; bound != mainChain.end(); ++bound)
        {
            if (bound->index == small.pair)
                break;
        }

        std::deque<Node>::iterator pos = lowerBoundDeq(mainChain, bound, small);
        mainChain.insert(pos, small);
    }

    if (hasextra && !extraInserted)
    {
        std::deque<Node>::iterator pos = lowerBoundDeq(mainChain, mainChain.end(), extra);
        mainChain.insert(pos, extra);
    }

    return mainChain;
}

bool PmergeMe::compareNodesVec(const Node &a, const Node &b)
{
    ++vecComparisons;
    return a.val < b.val;
}

bool PmergeMe::compareNodesDeq(const Node &a, const Node &b)
{
    ++deqComparisons;
    return a.val < b.val;
}

std::vector<Node>::iterator PmergeMe::lowerBoundVec(std::vector<Node> &chain,
    std::vector<Node>::iterator end, const Node &target)
{
    size_t first = 0;
    size_t count = static_cast<size_t>(end - chain.begin());
    while (count > 0)
    {
        size_t step = count / 2;
        size_t it = first + step;
        if (compareNodesVec(chain[it], target))
        {
            first = it + 1;
            count -= step + 1;
        }
        else
            count = step;
    }
    return chain.begin() + first;
}

std::deque<Node>::iterator PmergeMe::lowerBoundDeq(std::deque<Node> &chain,
    std::deque<Node>::iterator end, const Node &target)
{
    size_t first = 0;
    size_t count = static_cast<size_t>(end - chain.begin());
    while (count > 0)
    {
        size_t step = count / 2;
        size_t it = first + step;
        if (compareNodesDeq(chain[it], target))
        {
            first = it + 1;
            count -= step + 1;
        }
        else
            count = step;
    }
    return chain.begin() + first;
}
std::vector<int> PmergeMe::jacobsthalOrder(size_t n) {
    std::vector<int> order;

    if (n <= 1)
        return order;

    size_t prev = 1;
    size_t j_prev = 1;
    size_t j = 3;

    while (j <= n)
    {
        for (size_t k = j; k > prev; --k)
        {
            if (k >= 2)
                order.push_back(static_cast<int>(k));
        }
        size_t next = j + 2 * j_prev;
        j_prev = j;
        prev = j;
        j = next;
    }

    for (size_t k = n; k > prev; --k)
        if (k >= 2)
            order.push_back(static_cast<int>(k));

    return order;
}

std::vector<Node> PmergeMe::buildNodeVector(const std::vector<int>& input)
{
    std::vector<Node> nodes;

    for (std::size_t i = 0; i < input.size(); ++i)
        nodes.push_back(Node(input[i], i));

    return nodes;
}

std::deque<Node> PmergeMe::buildNodeDeque(const std::deque<int>& input)
{
    std::deque<Node> nodes;

    for (std::size_t i = 0; i < input.size(); ++i)
        nodes.push_back(Node(input[i], i));

    return nodes;
}

void PmergeMe::run() {
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << ' ';
    std::cout << std::endl;

    std::vector<Node> vecNodes = buildNodeVector(vec);
    vecNodes = fordJohnsonVec(vecNodes);

    std::deque<Node> deqNodes = buildNodeDeque(deq);
    deqNodes = fordJohnsonDeq(deqNodes);

    std::cout << "After: ";
    for (size_t i = 0; i < vecNodes.size(); i++)
        std::cout << vecNodes[i].val << ' ';
    std::cout << std::endl;

    const char *showComparisons = std::getenv("PMERGEME_SHOW_COMPARISONS");
    if (showComparisons != NULL && std::strcmp(showComparisons, "1") == 0)
    {
        std::cerr << "Comparisons (std::vector): " << vecComparisons << std::endl;
        std::cerr << "Comparisons (std::deque): " << deqComparisons << std::endl;
    }
}

size_t PmergeMe::getVecComparisons() const { return vecComparisons; }
size_t PmergeMe::getDeqComparisons() const { return deqComparisons; }

