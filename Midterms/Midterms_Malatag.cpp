#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Problem 1

double Distance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

int problem1(){

int N;
    cout << "Enter number of points: ";
    cin >> N;

    vector<pair<int, int>> points(N);
    cout << "Enter points in 'x y' format:\n";
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double totalDistance = 0;
    for (int i = 0; i < N - 1; i++) {
        totalDistance += Distance(points[i], points[i + 1]);
    }

    int sumNaturalNumbers = (N * (N + 1)) / 2;

    cout << "Total distance: " << totalDistance << endl;
    cout << "Sum of first " << N << " natural numbers: " << sumNaturalNumbers << endl;

    return 0;

}


// Problem 2

void bubbleSort(vector<int>& arr) {
    int n = arr.size();                 // O(1)
    for (int i = 0; i < n - 1; i++) {   // O(n)
        for (int j = 0; j < n - i - 1; j++) {   // O(n - i)
            if (arr[j] > arr[j + 1]) {      // O(1)
                swap(arr[j], arr[j + 1]);       // O(1)
            }
        }
    }
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;   // O(1)
    int n2 = r - m;    // O(1)

    vector<int> L(n1), R(n2);    // O(n1 + n2)

    for (int i = 0; i < n1; i++)   // O(n1)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)   // O(n1)
        R[i] = arr[m + 1 + i];   

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {    // O(n1 + n2)
        if (L[i] <= R[j]) {
            arr[k] = L[i];        // O(1)
            i++;
        } else {
            arr[k] = R[j];          // O(1)
            j++;
        }
        k++;
    }

    while (i < n1) {            // O(n1)
        arr[k] = L[i];  // O(1)
        i++;
        k++;
    }

    while (j < n2) {    // O(n2)
        arr[k] = R[j];   // O(1)
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r)  // O(1)
        return;
    int m = l + (r - l) / 2;  // O(1)
    mergeSort(arr, l, m);   // O(log n)
    mergeSort(arr, m + 1, r);  // O(log n)
    merge(arr, l, m, r);   // O(n)
}


int problem2() {
    vector<int> deliverTime = {21, 9, 13, 42, 5, 57};

    vector<int> bubbleSorted = deliverTime;
    bubbleSort(bubbleSorted);
    cout << "Bubble Sorted Times: ";
    for (int t : bubbleSorted) cout << t << " ";
    cout << endl;

    vector<int> mergeSorted = deliverTime;
    mergeSort(mergeSorted, 0, deliverTime.size() - 1);
    cout << "Merge Sorted Times: ";
    for (int t : mergeSorted) cout << t << " ";
    cout << endl;

    cout << "Bubble Sort Time Complexity: O(N^2)" << endl;
    cout << "Merge Sort Time Complexity: O(N log N)" << endl;

    return 0;
}

// Problem 3

void TowerOfHanoi(int n, char source, char destination, char buffer) {
    if (n == 0) return;  // O(1)

    TowerOfHanoi(n - 1, source, buffer, destination);  // O(2^n-1)
    cout << "Move package " << n << " from " << source << " to " << destination << endl; // O(1)
    TowerOfHanoi(n - 1, buffer, destination, source); // O(2^n-1)
}



int problem3() {
    int N;
    cout << "Enter number of packages (discs): ";
    cin >> N;

    TowerOfHanoi(N, 'A', 'C', 'B');
    cout << "Total number of moves: " << (1 << N) - 1 << endl;

    return 0;
}




int main() {

    problem1();

    problem2();
    
    problem3();


    return 0;
}
