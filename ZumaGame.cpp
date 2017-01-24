// code for Zuma Game
// https://leetcode.com/problems/zuma-game/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

const int kMaxNeed = 6;
struct Node{
    char ch;
    int count;
    Node(char c, int i) : ch(c), count(i){}
};
void CleanBoard(list<Node> &board){
    auto it = board.begin();
    while (it != board.end()) {
        if (it->count >= 3) {
            it = board.erase(it);
            // Ensure iterator != end(), before you use the it
            // Ensure iterator != begin(), before invoking prev(it)
            if (it != board.begin() &&
                it != board.end() &&
                it->ch == prev(it)->ch)
            {
                it->count += prev(it)->count;
                board.erase(prev(it));
            }
        } else {
            it++;
        }
    }
}
int DFS(list<Node> board, vector<int> &hand, int remain_in_hand) {
    CleanBoard(board);
    if (board.size() == 0)  return 0;
    //cannot remove all the balls
    if (remain_in_hand <= 0)  return kMaxNeed;
    int min_need = kMaxNeed;
    for (auto it = board.begin(); it != board.end(); ++it) {
        int need = 3 - it->count;
        if (hand[it->ch] >= need) {
            hand[it->ch] -= need;
            it->count += need;
            list<Node> next_board = board;
            int ret = DFS(next_board, hand, remain_in_hand - need);
            min_need = min(min_need, ret + need);
            it->count -= need;
            hand[it->ch] += need;
        }
    }
    return min_need;
}
int findMinStep(string board, string hand) {
    list<Node> board_list;
    vector<int> hand_count(CHAR_MAX, 0);
    int remain_in_hand = 0;
    for (int i = 0; i < board.length(); ++i) {
        board_list.push_back(Node(board[i], 1));
        if (i != board.length() - 1 && board[i] == board[i + 1]) {
            board_list.back().count++;
            i++;
        }
    }

    for (char ch : hand) {
        hand_count[ch]++;
        remain_in_hand ++;
    }

    int ret = DFS(board_list, hand_count, remain_in_hand);
    return ret == kMaxNeed ? -1 : ret;
}

int main() {
    cout << findMinStep("WRRBBW", "RB") << endl; // -1
    cout << findMinStep("WWRRBBWW", "WRBRW") << endl; // 2
    cout << findMinStep("G", "GGGGG") << endl; // 2
    cout << findMinStep("RBYYBBRRB", "YRBGB") << endl; // 3
}


