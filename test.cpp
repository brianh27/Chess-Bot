#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <memory>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

const vector<double> points = {0, 5, 3, 3.5, 9, 9999999, 1};
const vector<vector<double>> adjust = {
    {}, // Placeholder for 0-index
    {-0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5, -0.4, -0.2, 0,    0,    0,
     0,    -0.2, -0.4, -0.4, 0,    0.1,  0.2,  0.2,  0.1,  0,    -0.4, -0.4, 0,
     0.2,  0.25, 0.25, 0.2,  0,    -0.4, -0.4, 0,    0.2,  0.25, 0.25, 0.2,  0,
     -0.4, -0.4, 0,    0.1,  0.2,  0.2,  0.1,  0,    -0.4, -0.4, -0.2, 0,    0,
     0,    0,    -0.2, -0.4, -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5},
    {-0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5, -0.4, -0.2, 0,    0,    0,
     0,    -0.2, -0.4, -0.4, 0,    0.1,  0.2,  0.2,  0.1,  0,    -0.4, -0.4, 0,
     0.2,  0.25, 0.25, 0.2,  0,    -0.4, -0.4, 0,    0.2,  0.25, 0.25, 0.2,  0,
     -0.4, -0.4, 0,    0.1,  0.2,  0.2,  0.1,  0,    -0.4, -0.4, -0.2, 0,    0,
     0,    0,    -0.2, -0.4, -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5},
    {-0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5, -0.4, -0.2, 0,    0,    0,
     0,    -0.2, -0.4, -0.4, 0,    0.1,  0.2,  0.2,  0.1,  0,    -0.4, -0.4, 0,
     0.2,  0.25, 0.25, 0.2,  0,    -0.4, -0.4, 0,    0.2,  0.25, 0.25, 0.2,  0,
     -0.4, -0.4, 0,    0.1,  0.2,  0.2,  0.1,  0,    -0.4, -0.4, -0.2, 0,    0,
     0,    0,    -0.2, -0.4, -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5},
    {-0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5, -0.4, -0.2, 0,    0,    0,
     0,    -0.2, -0.4, -0.4, 0,    0.1,  0.2,  0.2,  0.1,  0,    -0.4, -0.4, 0,
     0.2,  0.25, 0.25, 0.2,  0,    -0.4, -0.4, 0,    0.2,  0.25, 0.25, 0.2,  0,
     -0.4, -0.4, 0,    0.1,  0.2,  0.2,  0.1,  0,    -0.4, -0.4, -0.2, 0,    0,
     0,    0,    -0.2, -0.4, -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5},
    {-0.3, -0.4, -0.4, -0.5, -0.5, -0.4, -0.4, -0.3, -0.3, -0.4, -0.4,
     -0.5, -0.5, -0.4, -0.4, -0.3, -0.3, -0.4, -0.4, -0.5, -0.5, -0.4,
     -0.4, -0.3, -0.3, -0.4, -0.4, -0.5, -0.5, -0.4, -0.4, -0.3, -0.3,
     -0.4, -0.4, -0.5, -0.5, -0.4, -0.4, -0.3, -0.2, -0.2, -0.2, -0.2,
     -0.2, -0.2, -0.2, -0.2, 0.2,  0.2,  0,    0,    0,    0,    0.2,
     0.2,  0.2,  0.3,  0.1,  0,    0,    0.1,  0.3,  0.2},
    {-0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5, -0.4, -0.2, 0,    0,    0,
     0,    -0.2, -0.4, -0.4, 0,    0.1,  0.2,  0.2,  0.1,  0,    -0.4, -0.4, 0,
     0.2,  0.25, 0.25, 0.2,  0,    -0.4, -0.4, 0,    0.2,  0.25, 0.25, 0.2,  0,
     -0.4, -0.4, 0,    0.1,  0.2,  0.2,  0.1,  0,    -0.4, -0.4, -0.2, 0,    0,
     0,    0,    -0.2, -0.4, -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5}

};

struct State {
  vector<vector<int>> board;
  vector<tuple<int, int, int, int>> moves;
};

bool isSameSide(int a, int b) {
  if (a == 0 || b == 0)
    return false;
  return (a > 0 && b > 0) || (a < 0 && b < 0);
}

set<tuple<int, int, int, int>> check(int x, int y, int dx, int dy, int dist,
                                     const vector<vector<int>> &board) {
  set<tuple<int, int, int, int>> moves;
  for (int step = 1; step <= dist; ++step) {
    int nx = x + dx * step, ny = y + dy * step;
    if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
      break;
    if (isSameSide(board[x][y], board[nx][ny]))
      break;
    moves.insert({x, y, nx, ny});
    if (board[nx][ny] != 0)
      break;
  }
  return moves;
}

set<tuple<int, int, int, int>> generateMoves(const vector<vector<int>> &board,
                                             bool nex) {
  set<tuple<int, int, int, int>> possible;
  for (int a = 0; a < 8; ++a) {
    for (int b = 0; b < 8; ++b) {
      if (board[a][b] == 0) { // Using 0 to represent `None` in Python
        continue;
      }

      if ((board[a][b] < 0) == nex) {
        int t = abs(board[a][b]);

        if (t == 1) {
          possible.merge(check(a, b, 0, 1, 99999999, board));
          possible.merge(check(a, b, 1, 0, 99999999, board));
          possible.merge(check(a, b, -1, 0, 99999999, board));
          possible.merge(check(a, b, 0, -1, 99999999, board));
        } else if (t == 3) {
          possible.merge(check(a, b, 1, 1, 99999999, board));
          possible.merge(check(a, b, -1, -1, 99999999, board));
          possible.merge(check(a, b, 1, -1, 99999999, board));
          possible.merge(check(a, b, -1, 1, 99999999, board));
        } else if (t == 4) {
          possible.merge(check(a, b, 1, 1, 99999999, board));
          possible.merge(check(a, b, -1, -1, 99999999, board));
          possible.merge(check(a, b, 1, -1, 99999999, board));
          possible.merge(check(a, b, -1, 1, 99999999, board));
          possible.merge(check(a, b, 0, 1, 99999999, board));
          possible.merge(check(a, b, 1, 0, 99999999, board));
          possible.merge(check(a, b, -1, 0, 99999999, board));
          possible.merge(check(a, b, 0, -1, 99999999, board));
        } else if (t == 2) {
          possible.merge(check(a, b, -2, -1, 1, board));
          possible.merge(check(a, b, -2, 1, 1, board));
          possible.merge(check(a, b, 2, 1, 1, board));
          possible.merge(check(a, b, 2, -1, 1, board));
          possible.merge(check(a, b, 1, -2, 1, board));
          possible.merge(check(a, b, -1, -2, 1, board));
          possible.merge(check(a, b, -1, 2, 1, board));
          possible.merge(check(a, b, 1, 2, 1, board));
        } else if (t == 5) {
          possible.merge(check(a, b, 1, 1, 1, board));
          possible.merge(check(a, b, -1, -1, 1, board));
          possible.merge(check(a, b, 1, -1, 1, board));
          possible.merge(check(a, b, -1, 1, 1, board));
          possible.merge(check(a, b, 0, 1, 1, board));
          possible.merge(check(a, b, 1, 0, 1, board));
          possible.merge(check(a, b, -1, 0, 1, board));
          possible.merge(check(a, b, 0, -1, 1, board));
        } else if (t == 6) {
          if (nex) {
            if (a == 6) {
              possible.merge(check(a, b, -1, 0, 2, board));
            } else {
              possible.merge(check(a, b, -1, 0, 1, board));
            }
          } else {
            if (a == 1) {
              possible.merge(check(a, b, -1, 0, 2, board));
            } else {
              possible.merge(check(a, b, -1, 0, 1, board));
            }
          }
        }
      }
    }
  }

  return possible;
}

double evaluate(const vector<vector<int>> &board, bool nextMoveWhite) {
  double eval = 0;
  for (int x = 0; x < 8; ++x) {
    for (int y = 0; y < 8; ++y) {
      if (board[x][y] == 0)
        continue;
      int piece = abs(board[x][y]);
      double value = points[piece];
      int posIndex = x * 8 + y;
      value += adjust[piece][posIndex];
      if (board[x][y] > 0 == nextMoveWhite)
        eval += value;
      else
        eval -= value;
    }
  }
  return eval;
}

int main() {
  vector<State> games = {{{{1, 2, 3, 4, 5, 3, 2, 1},
                           {6, 6, 6, 6, 6, 6, 6, 6},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {-6, -6, -6, -6, -6, -6, -6, -6},
                           {-1, -2, -3, -4, -5, -3, -2, -1}},
                          {}}};

  for (int turn = 0; turn < 6; ++turn) {
    cout << "Turn: " << turn << endl;
    vector<State> nextStates;
    for (const auto &game : games) {
      auto possibleMoves = generateMoves(game.board, turn % 2 == 0);
      for (const auto &move : possibleMoves) {
        State newState = game;
        auto [x1, y1, x2, y2] = move;
        newState.board[x2][y2] = newState.board[x1][y1];
        newState.board[x1][y1] = 0;
        newState.moves.push_back(move);
        nextStates.push_back(newState);
      }
    }
    games = nextStates;
  }

  double bestEval = -numeric_limits<double>::infinity();
  tuple<int, int, int, int> bestMove;
  for (const auto &game : games) {
    double eval = evaluate(game.board, true);
    if (eval > bestEval && !game.moves.empty()) {
      bestEval = eval;
      bestMove = game.moves[0];
    }
  }

  cout << "Best Move: (" << get<0>(bestMove) << ", " << get<1>(bestMove)
       << ") -> (" << get<2>(bestMove) << ", " << get<3>(bestMove) << ")\n";
  return 0;
}
