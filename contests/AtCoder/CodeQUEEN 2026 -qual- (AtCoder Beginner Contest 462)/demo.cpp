// C++ program to demonstrate lower_bound()
// and upper_bound() in Vectors of Pairs

#include <bits/stdc++.h>
using namespace std;

// Function to implement lower_bound()
void findLowerBound(vector<pair<int, int> >& arr,
                    pair<int, int>& p)
{
    // Given iterator points to the
    // lower_bound() of given pair
    auto low = lower_bound(arr.begin(), arr.end(), p);

    cout << "lower_bound() for {2, 5}"
         << " is at index: " << low - arr.begin() << endl;
}

// Function to implement upper_bound()
void findUpperBound(vector<pair<int, int> >& arr,
                    pair<int, int>& p)
{
    // Given iterator points to the
    // upper_bound() of given pair
    auto up = upper_bound(arr.begin(), arr.end(), p);

    cout << "upper_bound() for {2, 5}"
         << " is at index: " << up - arr.begin() << endl;
}

// Driver Code
int main()
{
    // Given sorted vector of Pairs
    vector<pair<int, int> > arr;
    arr = { { 1, 3 }, { 1, 7 }, { 2, 4 },
            { 3, 4 }, { 3, 8 }, { 8, 6 } };

    // Given pair {2, 5}
    pair<int, int> p = { 2, 5 };

    // Function Call to find lower_bound
    // of pair p in arr
    findLowerBound(arr, p);

    // Function Call to find upper_bound
    // of pair p in arr
    findUpperBound(arr, p);

    return 0;
}