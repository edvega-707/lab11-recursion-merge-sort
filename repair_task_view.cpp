/*
 * Course: COEN 2220 - Programming 2
 * Name: Eduardo D. Vega Rodriguez 
 * Lab: Lab 11 - Recursion and Merge Sort
 * Description: Practice - sort a temporary view without changing original tasks
 * Due date: 11/3/2026
 */

#include <iostream>
#include <string>
using namespace std;

struct RepairTask
{
    string taskId;     // Preserve the identity of the original task.
    int daysUntilDue;  // Smaller values must appear first in the report.
    int minutesNeeded; // Break equal-deadline ties with smaller durations first.
};

bool comesBeforeOrEqual(const RepairTask *left, const RepairTask *right);
void mergeTaskView(RepairTask *view[], RepairTask *temporary[],
                   int first, int middle, int last);
void mergeSortView(RepairTask *view[], RepairTask *temporary[], int first, int last);
void displayOriginal(const RepairTask tasks[], int count);
void displayView(RepairTask *view[], int count);

int main()
{
    const int TASK_COUNT = 8;
    RepairTask tasks[TASK_COUNT] =
    {
        {"RT-101", 3, 30}, {"RT-102", 1, 20},
        {"RT-103", 2, 15}, {"RT-104", 1, 10},
        {"RT-105", 2, 15}, {"RT-106", 3, 10},
        {"RT-107", 1, 20}, {"RT-108", 2, 5}
    };

    RepairTask *view[TASK_COUNT];      // Borrow addresses of existing tasks.
    RepairTask *temporary[TASK_COUNT]; // Hold addresses while merging the view.

    for (int index = 0; index < TASK_COUNT; index++)
    {
        view[index] = &tasks[index]; // Preserve arrival order in the initial view.
    }

    cout << boolalpha;
    cout << "Original arrival order:" << endl;
    displayOriginal(tasks, TASK_COUNT);

    // ===== Resolve these TODOs now (Part C) =====
    // TODO (Part C): Activate the C test block after completing the comparator.

    cout << "Earlier deadline first: "
         << comesBeforeOrEqual(&tasks[1], &tasks[0]) << endl;

    cout << "Shorter duration within same deadline: "
         << comesBeforeOrEqual(&tasks[3], &tasks[1]) << endl;

    cout << "Exact tie keeps left: "
         << comesBeforeOrEqual(&tasks[2], &tasks[4]) << endl;

    cout << "Later deadline first: "
         << comesBeforeOrEqual(&tasks[0], &tasks[1]) << endl;

    // ===== Resolve these TODOs later (Part D) =====
    // TODO (Part D): Call mergeSortView for the complete logical range.

    mergeSortView(view, temporary, 0, TASK_COUNT - 1);

    // TODO (Part D): Display the sorted view with a descriptive heading.

    cout << "Sorted task view:" << endl;
    displayView(view, TASK_COUNT);

    // TODO (Part D): Display tasks again to prove that arrival order did not change.

    cout << "Original arrival order after sorting:" << endl;
    displayOriginal(tasks, TASK_COUNT);

    // Test an empty logical range.
    mergeSortView(view, temporary, 0, -1);

    // Test a range with only one element.
    mergeSortView(view, temporary, 0, 0);

    // Sort the complete view again to verify the result stays the same.
    mergeSortView(view, temporary, 0, TASK_COUNT - 1);

    cout << "Sorted task view after sorting again:" << endl;
    displayView(view, TASK_COUNT);

    return 0;
}

bool comesBeforeOrEqual(const RepairTask *left, const RepairTask *right)
{
    // ===== Resolve this TODO now (Part C) =====
    // TODO (Part C): Implement the specified two-field order, including exact ties.

    // Check which task has fewer days remaining.
    if (left->daysUntilDue < right->daysUntilDue)
    {
        return true;
    }

    // Check if the left task has more days remaining.
    if (left->daysUntilDue > right->daysUntilDue)
    {
        return false;
    }

    // If the days are equal, compare the minutes needed.
    if (left->minutesNeeded < right->minutesNeeded)
    {
        return true;
    }

    // Check if the left task needs more minutes.
    if (left->minutesNeeded > right->minutesNeeded)
    {
        return false;
    }

    // If both values are equal, keep the left task first.
    return true;
}

// ===== Resolve these TODOs later (Part D) =====
void mergeSortView(RepairTask *view[], RepairTask *temporary[], int first, int last)
{
    // TODO (Part D): Implement recursive merge sort using inclusive indices.

    // Stop if the range has zero or one element.
    if (first >= last)
    {
        return;
    }

    // Find the middle position of the range.
    int middle = first + (last - first) / 2;

    // Sort the left half of the view.
    mergeSortView(view, temporary, first, middle);

    // Sort the right half of the view.
    mergeSortView(view, temporary, middle + 1, last);

    // Combine both sorted halves.
    mergeTaskView(view, temporary, first, middle, last);
}

void mergeTaskView(RepairTask *view[], RepairTask *temporary[],
                   int first, int middle, int last)
{
    // TODO (Part D): Merge two sorted segments using comesBeforeOrEqual.
    // TODO (Part D): Preserve pending pointers and copy the merged segment back.

    // Start at the beginning of each half.
    int leftIndex = first;
    int rightIndex = middle + 1;
    int tempIndex = first;

    // Compare tasks while both halves still have elements.
    while (leftIndex <= middle && rightIndex <= last)
    {
        // Select the task that should appear first.
        if (comesBeforeOrEqual(view[leftIndex], view[rightIndex]))
        {
            temporary[tempIndex] = view[leftIndex];
            leftIndex++;
        }
        else
        {
            temporary[tempIndex] = view[rightIndex];
            rightIndex++;
        }

        tempIndex++;
    }

    // Copy the remaining addresses from the left half.
    while (leftIndex <= middle)
    {
        temporary[tempIndex] = view[leftIndex];
        leftIndex++;
        tempIndex++;
    }

    // Copy the remaining addresses from the right half.
    while (rightIndex <= last)
    {
        temporary[tempIndex] = view[rightIndex];
        rightIndex++;
        tempIndex++;
    }

    // Copy the sorted addresses back into the view.
    for (int index = first; index <= last; index++)
    {
        view[index] = temporary[index];
    }
}

void displayOriginal(const RepairTask tasks[], int count)
{
    for (int index = 0; index < count; index++)
    {
        cout << "Task: " << tasks[index].taskId
             << " | Days until due: " << tasks[index].daysUntilDue
             << " | Minutes: " << tasks[index].minutesNeeded << endl;
    }
}

void displayView(RepairTask *view[], int count)
{
    for (int index = 0; index < count; index++)
    {
        cout << "Task: " << view[index]->taskId
             << " | Days until due: " << view[index]->daysUntilDue
             << " | Minutes: " << view[index]->minutesNeeded << endl;
    }
}

/*
 * Analysis Answers
 *
 * C5 - Two-field decision
 * Explain the result for RT-103 compared with RT-108. Which field decides it?
 * Answer:
 * RT-103 and RT-108 both have 2 days remaining, so the program
 * compares their minutes. RT-103 needs 15 minutes and RT-108
 * needs 5 minutes. The function returns false because RT-108
 * should come first. The minutesNeeded field decides the order.
 *
 * D1 - Recursive ranges
 * Show first, last, middle, and the base-case evaluations along the first branch
 * starting at 0..7. Identify where execution resumes after the call for 0..0.
 * Answer:
 * The program starts with first = 0 and last = 7, so middle = 3.
 * It then goes to the left half, first = 0 and last = 3,
 * where middle = 1. Next, it goes to first = 0 and last = 1,
 * where middle = 0. The next call is first = 0 and last = 0.
 * Since first >= last, the function returns.
 * Execution goes back to the call for 0..1 and continues
 * with the right half, 1..1. After both halves return,
 * the program merges them.
 *
 * D2 - Stable ties
 * Identify both pairs of tasks that tie in the two sort fields. Explain how the
 * comparator and the merge preserve their arrival order.
 * Answer:
 * RT-102 and RT-107 both have 1 day remaining and need
 * 20 minutes. RT-103 and RT-105 both have 2 days remaining
 * and need 15 minutes. When both values are equal, the
 * comparator returns true. This makes the merge choose
 * the left task first, keeping their original arrival order.
 *
 * D3 - Time, space, and original data
 * Give the sorting time and auxiliary-space order of this pointer-array version.
 * Compare with the linked-list sort in Part B and explain why the original task
 * storage order is preserved here but the node order changes in Part B.
 * Answer:
 * In this program, n is the number of tasks being sorted.
 * The sorting time is O(n log n) because the program divides
 * the view into smaller parts and merges them back together.
 * The auxiliary space is O(n) because the temporary array
 * stores pointers, and the recursive calls use O(log n) space.
 * In Part B, the linked-list sort also takes O(n log n) time,
 * but uses O(log n) auxiliary space for recursive calls.
 * In Part D, only the pointers inside view are moved, so
 * the original tasks stay in the same order. In Part B,
 * the links between nodes are changed to sort the list.
 *
 */