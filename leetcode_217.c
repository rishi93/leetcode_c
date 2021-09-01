/*
Solution to Leetcode problem 217
Contains duplicate

Approach:
Implement a custom hashmap for integers in C
with collisions resolved by linked list at an array slot
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

bool isPresent(struct Node** head, int key) {
    if(*head == NULL) {
        return false;
    }
    struct Node* curr = *head;
    while(curr != NULL) {
        if(curr->val == key) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void insert(struct Node** head, int key) {
    if (*head == NULL) {
        *head = (struct Node*)malloc(sizeof(struct Node));
        (*head)->val = key;
        (*head)->next = NULL;
    }
    else {
        struct Node* curr = *head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = (struct Node*)malloc(sizeof(struct Node));
        curr->next->val = key;
        curr->next->next = NULL;
    }
}

void printList(struct Node* head) {
    if(head == NULL) {
        printf("\n");
    }
    struct Node* curr = head;
    while(curr != NULL) {
        printf("%d ->", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

bool containsDuplicate(int *nums, int numsSize) {
    struct Node* hashMap[1000000] = {0};

    for(int i = 0; i < numsSize; i++) {
        /* Get all values down to 0 to 2 * 10^9
        and then down to 0 to 1000000
        */
        int hash_value = (nums[i] + 1000000000) % 1000000;
        /* If curr_num exists in hashMap */
        if(isPresent(&hashMap[hash_value], nums[i])) {
            // printf("Value of %d seen before at hash value of %d\n", nums[i], hash_value);
            return true;
        }
        /* If curr_num seen for first time */
        else {
            /* Add to hashMap */
            // printf("Value of %d not seen before at hash value of %d\n", nums[i], hash_value);
            insert(&hashMap[hash_value], nums[i]);
        }
    }

    return false;
}

int main() {
    int nums[] = {1, 5, -2, -4, -2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    bool result = containsDuplicate(nums, numsSize);
    printf("Value of result is %d\n", result);
}