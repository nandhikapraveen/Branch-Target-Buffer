#include <stdio.h>
#include <stdlib.h>
// Define a structure to represent an entry in the BTB
typedef struct {
 int pc; // Program Counter (PC) value
 int target; // Target address
} BTB_Entry;
// Define a structure to represent the BTB itself
typedef struct {
 int size; // Size of the BTB
 BTB_Entry *entries; // Array of BTB entries
} BranchTargetBuffer;
// Function to initialize the BTB
BranchTargetBuffer *initialize_BTB(int size) {
 // Allocate memory for the BTB structure
 BranchTargetBuffer *btb = (BranchTargetBuffer 
*)malloc(sizeof(BranchTargetBuffer));
 // Set the size of the BTB
 btb->size = size;
 // Allocate memory for the array of BTB entries
 btb->entries = (BTB_Entry *)malloc(size * sizeof(BTB_Entry));
 // Initialize all PC values to -1 to indicate empty entries
 for (int i = 0; i < size; i++) {
 btb->entries[i].pc = -1;
 }
 return btb;
}
// Function to insert an entry into the BTB
void insert_entry(BranchTargetBuffer *btb, int pc, int target) {
 // Iterate through the BTB entries to find an empty slot
 for (int i = 0; i < btb->size; i++) {
 // If the PC value is -1, it indicates an empty entry
 if (btb->entries[i].pc == -1) {
 // Insert the PC and target values into the empty entry
 btb->entries[i].pc = pc;
 btb->entries[i].target = target;
 return;
 }
 }
 // If no empty slot is found, print a message indicating that the BTB is 
full
 printf("BTB is full. Entry not inserted.\n");
}
// Function to lookup the target for a given PC
int lookup_target(BranchTargetBuffer *btb, int pc) {
 // Iterate through the BTB entries to find the entry with the matching 
PC value
 for (int i = 0; i < btb->size; i++) {
 // If the PC value matches, return the corresponding target value
 if (btb->entries[i].pc == pc) {
 return btb->entries[i].target;
 }
 }
 // If the PC value is not found, print a message indicating that it was not 
found
 printf("PC not found in BTB.\n");
 return -1;
}
// Main function to demonstrate BTB usage
int main() {
 // Initialize a BTB with a size of 8
 BranchTargetBuffer *btb = initialize_BTB(8);
 // Insert entry for PC 100 with target 200
 insert_entry(btb, 100, 200);
 // Insert entry for PC 150 with target 250
 insert_entry(btb, 150, 250);
 // Lookup targets for some PCs and print the results
 printf("Target for PC 100: %d\n", lookup_target(btb, 100)); // Output: 200
 printf("Target for PC 150: %d\n", lookup_target(btb, 150)); // Output: 250
 printf("Target for PC 200: %d\n", lookup_target(btb, 200)); // Output: PC 
not found
 // Free memory allocated for the BTB entries and the BTB structure 
itself
 free(btb->entries);
 free(btb);
 return 0;
}
