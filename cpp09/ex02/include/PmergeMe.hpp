#pragma once

#include <deque>
#include <vector>

struct Node
{
    int val;
    int index;
    int pair;

    Node() : val(0), index(0), pair(-1) {}
    Node(int v, int i) : val(v), index(i), pair(-1) {}
};

class PmergeMe
{
private:
    std::deque<int> deq;
    std::vector<int> vec;
    size_t vecComparisons;
    size_t deqComparisons;

    std::vector<Node> fordJohnsonVec(std::vector<Node> &input);
    std::deque<Node> fordJohnsonDeq(std::deque<Node> &input);
    std::vector<int> jacobsthalOrder(size_t n);
    bool compareNodesVec(const Node &a, const Node &b);
    bool compareNodesDeq(const Node &a, const Node &b);
    std::vector<Node>::iterator lowerBoundVec(std::vector<Node> &chain, std::vector<Node>::iterator end, const Node &target);
    std::deque<Node>::iterator lowerBoundDeq(std::deque<Node> &chain, std::deque<Node>::iterator end, const Node &target);

    std::vector<Node> buildNodeVector(const std::vector<int> &input);
    std::deque<Node> buildNodeDeque(const std::deque<int> &input);

public:
    PmergeMe() {};
    PmergeMe(int ac, char **av);
    //PmergeMe(const PmergeMe &obj) {};
    //PmergeMe &operator=(const PmergeMe &obj) {};
    ~PmergeMe(){};

    void run();
    size_t getVecComparisons() const;
    size_t getDeqComparisons() const;
};

