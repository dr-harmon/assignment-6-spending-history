# Assignment 6: Spending History

You have been hired by a technology company that sells personal finance software, and your manager has asked you to write a new reporting feature. Given a list of receipts, the report should show the total amounts spent at each company with the largest amounts first. For example, if the receipts are:

    RECEIPTS
    ====================
    Regal Cinema  $16.00
    Target        $14.00
    Olive Garden  $20.00
    Target         $8.00

Then the feature should generate the following report:

    TOTAL SPENT
    ====================
    Target        $22.00
    Olive Garden  $20.00
    Regal Cinema  $16.00

Note that the same company may appear on more than one receipt (such as Target above). If so, the report should add the amounts together and list the company only once. (When comparing companies for uniqueness, you may ignore the city and consider the name alone.)

To help you get started, your manager has provided several C++ classes:

* `SpendingHistory`: This is the main class for the reporting feature. It includes an `addReceipt` method for storing receipt information (company name and amount spent). It also includes a `getTotals` method that generates the report from the previously stored receipts.
* `Company`: A simple container class holding a company name and its home city. (Your manager says to ignore the city field for now.)
* `Money`: Represents a dollar amount. It includes functions for comparing one amount with another and for adding one amount to another.
* `TotalSpent`: This is a simple container class for the `getTotals` report. It stores the company and the total amount spent at that company.

Your manager is very concerned with the software's performance and has asked that your `addReceipt` function run in constant time and your `getTotals` method run in O(n log n) time or better.

## Hints

In `main` you can find an example of how the `SpendingHistory` might be used. It loads a CSV file containing 1000 receipts, passes them to `SpendingHistory`, then prints the report to standard output. You can use this code to debug your implementation.

A simple test case is provided in `spending_history_test.cpp`. Make sure it passes without modification.

When using a custom class with STL containers that require a hash code (e.g., `unordered_map`, `unordered_set`), you can define your own `std:hash` function (see Lab 37) for the class. For example, if the custom class to be stored in the container is `Foo`:

    namespace std {
        template <> struct hash<Foo>
        {
            size_t operator()(const Foo& f) const
            {
                // Your code here, e.g., return hash<int>()(f.value);
            }
        };
    }
