#include <iostream>

using namespace std;

void printBoard(int arr[][3] , int number_of_rows) {
    for(int i = 0; i < number_of_rows; i++) {
        for(int j = 0; j< 3; j++){
            if(arr[i][j]!=0)
            {
                for(int k = 0; k < number_of_rows-arr[i][j]+1; k++){
                    cout << " ";
                }
                for(int k = 0; k < arr[i][j]; k++){
                    cout << "[]";
                }
                for(int k = 0; k < number_of_rows-arr[i][j]+1; k++){
                    cout << " ";
                }
            }
            else
            {
                cout << "        ";
                cout << "::";
                cout << "        ";
            }
        }
            cout << endl;
    }
}

int main()
{
    int disksAmount;

    cout << "Enter disks number: " << endl;
    cin >> disksAmount;


    int board[disksAmount][3];
    for(int i = 0; i < disksAmount; i++) {
        for(int j = 0; j < 3; j++) {
            if(j==0)
                board[i][j] = i+1;
            else
                board[i][j] = 0;
        }
    }

    printBoard(board, disksAmount);

    int TowerNumberRemove, TowerNumberPut;

    while(true) {
        cout << "Write expression remove/put: " << endl;
        cin >> TowerNumberRemove >> TowerNumberPut;
        TowerNumberRemove -= 1;
        TowerNumberPut -= 1;
        for(int i = 0; i < disksAmount; i++) {
            if(board[i][TowerNumberRemove]!=0){
                for(int j = disksAmount; j > -1; j--) {
                    if(board[j][TowerNumberPut]==0){
                        board[j][TowerNumberPut] = board[i][TowerNumberRemove];
                        board[i][TowerNumberRemove] = 0;
                        break;
                    } else if (board[j][TowerNumberPut]<board[i][TowerNumberRemove]){
                        cout << "You can't put. Top disk too small." << endl;
                        break;
                    }
                }
                break;
            }
        }
        printBoard(board, disksAmount);
    }

    return 0;
}
