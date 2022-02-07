
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <stack>
#include <string>
using namespace std;
namespace sol1676
{
    class Solution
    {
    private:
    public:
        Node *lca(Node *root, vector<int> input);
    };
}
#endif