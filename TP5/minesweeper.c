#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void minimalistic_minesweeper(unsigned mapsize, unsigned mapnum)
{
    uint8_t (*map)[mapsize] = malloc(mapsize * mapsize);
    if (map == 0)
    {
        fprintf(stderr, "not enough memory\n");
        return;
    }

    // init
    srandom(mapnum);
    unsigned nmines = 1 + (random() % (mapsize / 4));

    for (unsigned i = 0; i < mapsize; i++)
    {
        for (unsigned j = 0; j < mapsize; j++)
        {
            map[i][j] = 0;
        }
    }

    for (unsigned i = 0; i < nmines; i++)
    {
        map[random() % mapsize][random() % mapsize] = 1;
    }

    // game
    unsigned lm[2][mapsize];
    unsigned x, y;
    unsigned c = 0;

    bool k = true;

    do
    {
        printf("Last checked squares: ");
        for (unsigned i = 0; i < mapsize; i++)
        {
            printf("(%u, %u) ", lm[0][(i + c) % mapsize], lm[1][(i + c) % mapsize]);
        }
        printf("\n");

        printf("What square do you want to check next?\n");
        printf("x?\n");
        if (scanf("%u", &x) != 1)
        {
            free(map);
            return;
        }
        printf("y?\n");
        if (scanf("%u", &y) != 1)
        {
            free(map);
            return;
        }

        c += 1;
        lm[0][c] = x;
        lm[1][c] = y;

        if (map[x][y]){
            k = false;
            printf("This square was mined. Game over :(\n");
        }

        if (k)
        {
            int mincount = 0;
            for (int i = -1; i < 1; i++){
                for (int j = -1; j < 1; j++){
                    if(x + i <1 || x + i > mapsize || y + 1 <0 || y + i > mapsize){
                        printf("This square is not in the grid\n");
                    }
                    else{mincount += map[x + i][y + j];}
                    
                }
            }
            printf("This square was not mined; it's surrounded by %d mines\n", mincount);
        }

    } while (k);

    free(map);

    return;
}


int main()
{
    minimalistic_minesweeper(4, 1);

    return 0;
}
