# Lab 11 - Project Application

## E1 - Original collection and borrowed pointers

The `orders` array stores the four original cafeteria orders and their information. The `view` array only stores pointers to selected orders. This means the view uses the addresses of existing orders instead of creating new ones. The original orders stay in the same positions.

## E2 - Implemented view and test

I created four dummy orders to test the program. Orders 101 and 103 are active DELIVERY orders. Order 102 is an active DINE_IN order, and order 104 is a completed DELIVERY order.

The expected selected IDs were 101 and 103. After running the program, the view showed both IDs correctly.

I also displayed the original orders before and after creating the view. Their IDs, statuses, and positions stayed the same. This shows that the program did not change the original collection.

## E3 - Sorting criterion and next integration step

The delivery report will follow three sorting rules:

1. Sort by building name in alphabetical order.
2. If the building is the same, sort by priority from highest to lowest.
3. If both values are equal, sort by order ID from lowest to highest.

For example, suppose the report contains these orders:

* Order 105: Engineering, priority 2
* Order 106: Library, priority 3
* Order 107: Engineering, priority 3
* Order 108: Engineering, priority 3

The expected order would be 107, 108, 105, and 106.

The next step is to connect Merge Sort to the temporary view. This will sort the pointers without changing the original orders or their FIFO order.

## E4 - Lab evidence

Source file: `delivery_view_practice.cpp`

Test output: `delivery_view_output.txt`

This practice helps prepare the temporary delivery report for the cafeteria project. It shows how to select active delivery orders using pointers while keeping the original collection unchanged.

When this is added to the main project, the system will be able to display a sorted delivery report without changing the order in which cafeteria orders are processed.
