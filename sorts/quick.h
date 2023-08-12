
#pragma once

/* ---------------------------------------
Time Complexity:	 
    Best      O(n log n)
    Worst     O(n^2)
    Average   O(n log n)
    
Space Complexity:  O(log n)
Stability     No
--------------------------------------- */

int partition(int arr[], int low, int high);

void quick(int arr[], int low, int high);
