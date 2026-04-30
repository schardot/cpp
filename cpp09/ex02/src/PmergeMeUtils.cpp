#include "PmergeMe.hpp"
#include <cmath>

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

std::vector<int> PmergeMe::jacobsthalOrder(size_t n)
{
    std::vector<int> order;
    if (n <= 1)
        return order;
    size_t j_prev = 1;
    size_t j = 3;
    while (j <= n)
    {
        for (size_t k = j; k > j_prev; --k)
            if (k >= 2)
                order.push_back(k);
        size_t next = j + 2 * j_prev;
        j_prev = j;
        j = next;
    }
    for (size_t k = n; k > j_prev; --k)
        if (k >= 2)
            order.push_back(k);
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

size_t PmergeMe::getVecComparisons() const { return vecComparisons; }
size_t PmergeMe::getDeqComparisons() const { return deqComparisons; }

size_t PmergeMe::optimalComparisons(size_t n) const
{
    size_t sum = 0;
    for (size_t k = 1; k <= n; ++k)
        sum += static_cast<size_t>(std::ceil(std::log((3.0 * static_cast<double>(k)) / 4.0) / std::log(2.0)));
    return sum;
}
