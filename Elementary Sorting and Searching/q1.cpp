// 1. A list of students’ exam score is given. First, arrange the scores in ascending order using Insertion Sort. Then,
// allow the teacher to search for a particular student’s score using Binary Search. If the score exists, display the
// student’s rank. Otherwise, show "Score not found".
#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int n;
    cout << "Enter number of studnets: ";
    cin >> n;
    
    int scores[n];
    
    cout << "Enter exam scors:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << (i + 1) << " scor: ";
        cin >> scores[i];
    }
    
    insertionSort(scores, n);
    
    cout << "Scores aranged in asending order: ";
    for (int i = 0; i < n; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
    
    int searchScore;
    cout << "Enter scor to serch for: ";
    cin >> searchScore;
    
    int position = binarySearch(scores, n, searchScore);
    
    if (position == -1) {
        cout << "Scor not found" << endl;
    } else {
        cout << "Scor found! Studnet's rank: " << (position + 1) << endl;
    }
    
    return 0;
}