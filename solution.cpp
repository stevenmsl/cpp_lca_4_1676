#include "solution.h"

#include <unordered_set>
#include <functional>

using namespace sol1676;
using namespace std;

/*takeaways
  - core concept to find the lca in a tree given a target set
    - for a node, reports itself back if
      it's in the target set and don't visit
      its children
      - this might be confusing at first
        but it really doesn't matter if
        there are any targets in its
        subtrees
      - if there are, the node will be
        their representative anyway
      - if there isn't, it just represents itself

    - for a parent, the responsibilities are
      - report itself as a representative
        if both of its subtrees can find nodes
        in the target set
      - or relay whichever child who can find
        the nodes in the target set
      - or report nothing to see here

  - in a nutshell, we are moving the target nodes
    or their lca(s) up the tree (not modifying the tree)
    until it converges into one node

*/

Node *Solution::lca(Node *root, vector<int> input)
{
  unordered_set target(input.begin(), input.end());

  function<Node *(Node *)> visit = [&target, &visit](Node *node)
  {
    if (node == nullptr)
      /* c++ note
         - this is just to make the compiler happy
           or it will report it as an error:
           onversion from 'sol1676::Node*' to non-scalar type 'std::nullptr_t' requested
      */
      return static_cast<Node *>(nullptr);
    /*
      - don't bother to look at this node's children as
        the result will be the same
        - if any of the target is in this node's subtree
          then this node will be their lca; report it
          back as a representative
        - if there is none, just reports back to the
          parent to inform the parent that you have
          found one in this subtree. Let the parent
          decide what to do next
    */
    if (target.count(node->val))
      return node;

    auto left = visit(node->left);
    auto right = visit(node->right);

    /*
       - this node is a representative of
         the targets found in the left and
         right subtrees
    */
    if (left != nullptr && right != nullptr)
      return node;

    /*
      - ignore this node but relay the message
        to its parent
    */
    if (left != nullptr)
      return left;
    if (right != nullptr)
      return right;

    /* nothing to look here */
    return static_cast<Node *>(nullptr);
  };

  return visit(root);
}
