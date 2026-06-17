#include <iostream>
#include <vector>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    // Create our grid and our DP memory cache
    vector<vector<int>> grid(R, vector<int>(C));
    vector<vector<int>> dp(R, vector<int>(C));

    // ---------------------------------------------------------
    // STEP 1: Read the grid and set up the starting line
    // ---------------------------------------------------------
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> grid[row][col];

            // The first row has no rules above it, so its max score 
            // is just its own starting numbers.
            if (row == 0) {
                dp[row][col] = grid[row][col]; 
            }
        }
    }

    // ---------------------------------------------------------
    // STEP 2: The Main DP Loop (Moving row by row)
    // ---------------------------------------------------------
    for (int row = 1; row < R; row++) {

        // Before we do anything, let's look at the row directly ABOVE us
        // and find out exactly what the best and second best scores are.
        int best_score = -1;
        int best_col = -1; // We remember the exact column of the best score!
        int second_best_score = -1;

        for (int col = 0; col < C; col++) {
            int score_above = dp[row - 1][col];

            if (score_above > best_score) {
                // Demote the old best to second place
                second_best_score = best_score; 

                // Crown the new best score and remember its column
                best_score = score_above;       
                best_col = col;                 
            } 
            else if (score_above > second_best_score) {
                // We found a new second place
                second_best_score = score_above;
            }
        }

        // Now that we know the best scores from above, let's calculate our current row
        for (int col = 0; col < C; col++) {

            // THE BANNED COLUMN CHECK:
            if (col == best_col) {
                // Oh no, we are standing directly under the best score. We are banned!
                // We have to settle for the backup plan (second best).
                dp[row][col] = grid[row][col] + second_best_score;
            } else {
                // We are safe! Add the absolute best score.
                dp[row][col] = grid[row][col] + best_score;
            }
        }
    }

    // ---------------------------------------------------------
    // STEP 3: Find the biggest winner in the very last row
    // ---------------------------------------------------------
    int final_answer = -1;
    for (int col = 0; col < C; col++) {
        if (dp[R - 1][col] > final_answer) {
            final_answer = dp[R - 1][col];
        }
    }

    cout << final_answer << endl;

    return 0;
}