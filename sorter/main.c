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
    FILE *original = fopen("1000Sorted.txt", "r");
    // FILE *output = fopen("output.txt", "w");

    ABP *tree = createTree();
    TreeStats stats = initCounter("ABP");

    Food food;
    while(!getFoodFromFile(&food, original))
    {
        // fprintf(output, "%s;%d\n", food.name, food.calories);
        insertABP(&tree, food, &stats);
    }

    // fPrintfTree(tree, 5, output);
    
    int numNodes = numberNodes(tree);
    int height = heightTree(tree);

    printf("Number of nodes: %d\n", numNodes);
    printf("Height: %d\n", height);

    fclose(original);
    // fclose(output);

    deletTree(&tree);

    return 0;
}