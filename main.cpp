#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1676;

Node *buildTree()
{
  auto tree = new Node(3);
  tree->left = new Node(5);
  tree->left->left = new Node(6);
  tree->left->right = new Node(2);
  tree->left->right->left = new Node(7);
  tree->left->right->right = new Node(4);

  tree->right = new Node(1);
  tree->right->left = new Node(0);
  tree->right->right = new Node(8);
  return tree;
}

tuple<Node *, vector<int>, string> testFixture1()
{
  return make_tuple(buildTree(), vector{4, 7}, "2");
}
tuple<Node *, vector<int>, string> testFixture2()
{
  return make_tuple(buildTree(), vector{1}, "1");
}
tuple<Node *, vector<int>, string> testFixture3()
{
  return make_tuple(buildTree(), vector{7, 6, 2, 4}, "5");
}
tuple<Node *, vector<int>, string> testFixture4()
{
  return make_tuple(buildTree(), vector{0, 1, 2, 3, 4, 5, 6, 7, 8}, "3");
}

void test1()
{
  auto fixture = testFixture1();

  auto tree = get<0>(fixture);
  auto input = get<1>(fixture);
  auto target = get<2>(fixture);

  cout << "Test 1 - expect to see " << get<2>(fixture) << endl;
  Solution sol;

  auto lca = sol.lca(tree, input);

  string result = lca != nullptr ? to_string(lca->val) : "null";

  cout << "result: " << result << endl;
}

void test2()
{
  auto fixture = testFixture2();

  auto tree = get<0>(fixture);
  auto input = get<1>(fixture);
  auto target = get<2>(fixture);

  cout << "Test 2 - expect to see " << get<2>(fixture) << endl;
  Solution sol;

  auto lca = sol.lca(tree, input);

  string result = lca != nullptr ? to_string(lca->val) : "null";

  cout << "result: " << result << endl;
}

void test3()
{
  auto fixture = testFixture3();

  auto tree = get<0>(fixture);
  auto input = get<1>(fixture);
  auto target = get<2>(fixture);

  cout << "Test 3 - expect to see " << get<2>(fixture) << endl;
  Solution sol;

  auto lca = sol.lca(tree, input);

  string result = lca != nullptr ? to_string(lca->val) : "null";

  cout << "result: " << result << endl;
}

void test4()
{
  auto fixture = testFixture4();

  auto tree = get<0>(fixture);
  auto input = get<1>(fixture);
  auto target = get<2>(fixture);

  cout << "Test 4 - expect to see " << get<2>(fixture) << endl;
  Solution sol;

  auto lca = sol.lca(tree, input);

  string result = lca != nullptr ? to_string(lca->val) : "null";

  cout << "result: " << result << endl;
}

main()
{
  test1();
  test2();
  test3();
  test4();
  return 0;
}