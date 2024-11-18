#include <stdio.h> 

#include <stdlib.h> 

#define MAX_SIZE 101  

  

// Function to find the mode(s) 

void findModes(int data[], int size) { 

    int frequency[MAX_SIZE] = {0};  

    int maxCount = 0; 

  

    // Count the frequency of each number 

    for (int i = 0; i < size; i++) { 

        frequency[data[i]]++; 

        if (frequency[data[i]] > maxCount) { 

            maxCount = frequency[data[i]]; 

        } 

    } 

  

    // Find and print all modes 

    printf("The mode(s) of the dataset is/are: "); 

    for (int i = 0; i < MAX_SIZE; i++) { 

        if (frequency[i] == maxCount) { 

            printf("%d ", i); 

        } 

    } 

    printf("\n"); 

} 

  

int main() { 

    int data[MAX_SIZE];  

    int size = 0;        

  

    FILE *in_file = fopen("data.txt", "r"); 

    if (!in_file) { 

        printf("Error: Could not open file.\n"); 

        return -1; 

    } 

  

   
    while (fscanf(in_file, "%d", &data[size]) == 1) { 

        size++; 

        if (size > MAX_SIZE) {  

            printf("Error: Dataset exceeds maximum size of %d.\n", MAX_SIZE); 

            fclose(in_file); 

            return -1; 

        } 

    } 

    fclose(in_file);  

  

    findModes(data, size); 

  

    return 0; 

} 