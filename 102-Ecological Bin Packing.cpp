// created by author Minh Nguyen Binh at 20201001 16:17.
// 
#include <stdio.h>
#include <stdlib.h>

int getSumOfBottles(int bottles[3][3]){
    int i, j, sum;

    for(i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            sum += bottles[i][j];
        }
    }

    return sum;
}


void showBGC(int inputNum){
    switch (inputNum){
        case 0:
            printf("B");
            break;
        case 1:
            printf("G");
            break;  
        case 2:
            printf("C");
            break;  
    }
}
int main(int argc, char *argv[]) {
    int i, j;   
    char bcgText[3] = {'B', 'G', 'C'};    
    int posibleIndex[6][3] = {{0, 2, 1}, {0, 1, 2}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    int bottles[3][3];
    int sumBottles;
    int sumMove;
    int minMove;
    int minMoveIndex = 0;
    while(scanf("%d%d%d%d%d%d%d%d%d", &bottles[0][0], &bottles[0][1], &bottles[0][2], 
                                      &bottles[1][0], &bottles[1][1], &bottles[1][2],
                                      &bottles[2][0], &bottles[2][1], &bottles[2][2]) != EOF){

        sumBottles = getSumOfBottles(bottles);
        minMove = sumBottles;

        
        for (i = 0; i < 6; i++){
            sumMove = sumBottles - (bottles[0][posibleIndex[i][0]] + bottles[1][posibleIndex[i][1]] + bottles[2][posibleIndex[i][2]]);

            if (sumMove < minMove){
                minMove = sumMove;
                minMoveIndex = i;
            }
        }      
        printf("%c%c%c %d\n", bcgText[posibleIndex[minMoveIndex][0]], 
                              bcgText[posibleIndex[minMoveIndex][1]],
                              bcgText[posibleIndex[minMoveIndex][2]],  minMove);        
    }
    return 0;
}