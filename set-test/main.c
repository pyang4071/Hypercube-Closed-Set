#include <stdio.h>

int hamming_distance(int a, int b);
void printBinary(int number, int length);

int main(){
    printf("How many numbers?\n");
    int amount;
    scanf("%d",&amount);
    
    int numbers[amount];
    printf("Type numbers\n");
    for (int i = 0; i < amount; i++){
        scanf("%d",&numbers[i]);
    }
    for (int i = 0; i < amount; i++){
        printf("%d\n", numbers[i]);
    }
    numbers[amount] = '\0';
    int max;
    printf("Max possible distance\n");
    scanf("%d",&max);
    
    int test = 1;
    int k;
    for(int i = 0; i < amount; i++){
        printf("Vertex %d:", numbers[i]);
        if(numbers[i] < 9){
            printf("        ");
        } else if (numbers[i] < 99){
            printf("       ");
        } else if (numbers[i] < 999){
            printf("      ");
        } else {
            printf("     ");
        }
        printBinary(numbers[i], max);
        for(int j = 1; j <= max; j++){
            k = 0;
            while(k < amount){
                if(hamming_distance(numbers[i], numbers[k]) == j){
                    printf("Distance %d: %d", j, numbers[k]);
                    if(numbers[k] > 999){
                        printf(" ");
                        printBinary(numbers[k], max);
                        break;
                    }
                    if(numbers[k] > 99){
                        printf("  ");
                        printBinary(numbers[k], max);
                        break;
                    }
                    if(numbers[k] > 9){
                        printf("   ");
                        printBinary(numbers[k], max);
                        break;
                    }
                    printf("    ");
                    printBinary(numbers[k], max);
                    break;
                } else{
                    k++;
                }
                if (k == amount)
                {
                    test = 0;
                }
            }
        }
        printf("\n");
    }
    if(test == 0){
        printf("Not a closed set\n");
    } else {
        printf("Closed set\n");
    }
    return 0;
}

int hamming_distance(int a, int b){
    int count = 0;
    int xor_result = a ^ b;
    while (xor_result > 0) {
        count += xor_result & 1;
        xor_result >>= 1;
    }
    return count;
}

void printBinary(int number, int length) {
    for (int i = length - 1; i >= 0; i--) {
        // Shift the number i bits to the right, then bitwise AND with 1
        // to get the value of the i-th bit (0 or 1)
        int bit = (number >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}