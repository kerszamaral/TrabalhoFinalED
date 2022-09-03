#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "trees.h"
#include "ABP.h"
#include "types.h"
#include "files.h"

int main(void)
{
    FILE *file = fopen("1000SortedOR.txt", "r");
    FILE *output = fopen("output.txt", "w");

    ABP *tree = createTree();
    TreeStats stats = initCounter("ABP");

    Food food;
    while(!getFoodFromFile(&food, file))
    {
        fprintf(output, "%s;%d\n", food.name, food.calories);
        insertABP(&tree, food, &stats);
    }

    // fPrintfTree(tree, 5, output);

    fclose(file);
    fclose(output);

    deletTree(&tree);

    return 0;
}