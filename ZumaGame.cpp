// code for Zuma Game
// https://leetcode.com/problems/zuma-game/
#include <iostream>
#include <vector>
using namespace std;

const int kMaxNeed = 6;
struct Node{
    char ch;
    int count;
    Node(char c, int i) : ch(c), count(i){}
};
void CleanBoard(vector<Node> &board) {
    vector<Node> stack;
    stack.reserve(board.size()); // avoid dynamic resize
    for (auto &node : board) {
        // before compare stack.back with current node, stack must
        // contain at lest 1 node
        if (stack.size() == 0) {
            stack.push_back(node);
        } else {
            if (node.ch == stack.back().ch) {
                stack.back().count += node.count;
            } else {
                stack.push_back(node);
            }
        }
        if (stack.back().count >= 3)  stack.pop_back();
    }
    board.swap(stack);
}
int DFS(vector<Node> board, vector<int> &hand, int remain_in_hand) {
    CleanBoard(board);
    if (board.size() == 0)  return 0;
    //cannot remove all the balls
    if (remain_in_hand <= 0)  return kMaxNeed;
    int min_need = kMaxNeed;
    for (auto &node : board) {
        int need = 3 - node.count;
        if (hand[node.ch] >= need) {
            hand[node.ch] -= need;
            node.count += need;
            //board is passed by value, a copy is made implicitly.
            int ret = DFS(board, hand, remain_in_hand - need);
            min_need = min(min_need, ret + need);
            node.count -= need;
            hand[node.ch] += need;
        }
    }
    return min_need;
}
int findMinStep(string board, string hand) {
    vector<Node> board_list;
    vector<int> hand_count(CHAR_MAX, 0);
    int remain_in_hand = hand.size();
    for (int i = 0; i < board.length(); ++i) {
        board_list.push_back(Node(board[i], 1));
        if (i != board.length() - 1 && board[i] == board[i + 1]) {
            board_list.back().count++;
            i++;
        }
    }
    for (char ch : hand)  hand_count[ch]++;
    int ret = DFS(board_list, hand_count, remain_in_hand);
    return ret == kMaxNeed ? -1 : ret;
}

int main() {
    cout << findMinStep("WRRBBW", "RB") << endl; // -1
    cout << findMinStep("WWRRBBWW", "WRBRW") << endl; // 2
    cout << findMinStep("G", "GGGGG") << endl; // 2
    cout << findMinStep("RBYYBBRRB", "YRBGB") << endl; // 3
}

