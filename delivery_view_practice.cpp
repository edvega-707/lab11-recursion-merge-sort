/*
 * Course: COEN 2220 - Programming 2
 * Name: Eduardo D. Vega Rodriguez 
 * Lab: Lab 11 - Recursion and Merge Sort
 * Description: Practice - create a temporary delivery order view
 * Due date: 11/3/2026
 */

#include <iostream>
#include <string>
using namespace std;

// Store the information for one cafeteria order.
struct OrderPreview
{
    int orderId;       // Store the order identification number.
    string orderType;  // Store DELIVERY or DINE_IN.
    string status;     // Store the current order status.
    string building;   // Store the delivery building.
    int priority;      // Store the priority of the order.
};

int main()
{
    const int ORDER_COUNT = 4;

    // Create four orders in their original arrival order.
    OrderPreview orders[ORDER_COUNT] =
    {
        {101, "DELIVERY", "PENDING", "Engineering", 2},
        {102, "DINE_IN", "IN_PROGRESS", "Cafeteria", 1},
        {103, "DELIVERY", "IN_PROGRESS", "Library", 3},
        {104, "DELIVERY", "COMPLETED", "Science", 2}
    };

    // Create an array to store pointers to selected orders.
    OrderPreview *view[ORDER_COUNT];

    // Count how many valid orders are stored in the view.
    int viewCount = 0;

    // Display the original orders before creating the view.
    cout << "Original orders before creating the view:" << endl;

    for (int index = 0; index < ORDER_COUNT; index++)
    {
        cout << "Order ID: " << orders[index].orderId
             << " | Type: " << orders[index].orderType
             << " | Status: " << orders[index].status
             << endl;
    }

    // Check each order without removing it from the original array.
    for (int index = 0; index < ORDER_COUNT; index++)
    {
        // Select only active DELIVERY orders.
        if (orders[index].orderType == "DELIVERY" &&
            (orders[index].status == "PENDING" ||
             orders[index].status == "IN_PROGRESS"))
        {
            // Store the address of the selected order.
            view[viewCount] = &orders[index];

            // Increase the number of selected orders.
            viewCount++;
        }
    }

    // Display the selected delivery orders.
    cout << "\nTemporary delivery view:" << endl;

    for (int index = 0; index < viewCount; index++)
    {
        cout << "Order ID: " << view[index]->orderId
             << " | Building: " << view[index]->building
             << " | Priority: " << view[index]->priority
             << " | Status: " << view[index]->status
             << endl;
    }

    // Display how many orders were selected.
    cout << "\nTotal selected delivery orders: " << viewCount << endl;

    // Display the original orders again to verify their order.
    cout << "\nOriginal orders after creating the view:" << endl;

    for (int index = 0; index < ORDER_COUNT; index++)
    {
        cout << "Order ID: " << orders[index].orderId
             << " | Type: " << orders[index].orderType
             << " | Status: " << orders[index].status
             << endl;
    }

    return 0;
}