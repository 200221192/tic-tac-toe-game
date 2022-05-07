#include <iostream>
using namespace std;
int main()
{
    char block[3][3] =
    {
        {'#', '#', '#'},
        {'#', '#', '#'},
        {'#', '#', '#'}
    };
    char player = 'X', winner = '#';
    for(int moves = 0; moves < 9; moves++)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << block[i][j] << ' ';
            }
            cout << endl;
        }
        int row, column;

        // take the input from the user 
        cout << "Enter a row number (1 or 2 or 3): ";
        cin >> row;
        cout << "Enter a column number (1 or 2 or 3): ";
        cin >> column;
        if(block[row - 1][column - 1] == '#')
            block[row - 1][column -1] = player;
        else
        {
            cout << "Invalid move" << endl;
            continue;
        }
        bool gameEnded = false;
        for(int i = 0; i < 3; i++)
        {
            if(block[0][i] == player && block[1][i] == player && block[2][i] == player)
            {
                gameEnded = true;
                winner = player;
                break;
            }
        }
        if(gameEnded)
            break;
        for(int i = 0; i < 3; i++)
        {
            if(block[0][0] == player && block[i][1] == player && block[i][2] == player)
            {
                gameEnded = true;
                winner = player;
                break;
            }
        }
        if(gameEnded)
            break;
        if(block[0][0] == player && block[1][1] == player && block[2][2] == player)
        {
            winner = player;
            break;
        }
        if(block[0][2] == player && block[1][1] == player && block[2][0] == player)
        {
            winner = player;
            break;
        }
        if(player == 'X')
            player = 'O';
        else
            player = 'X';
    }
    if(winner == 'X')
        cout << "Player X has won!" << endl;
    else if(winner == 'O')
        cout << "Player O has won!" << endl;
    else
        cout << "It's a tie!" << endl;
    return 0;
}
