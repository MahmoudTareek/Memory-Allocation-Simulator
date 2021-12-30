#include <iostream>
#include <stdlib.h>
using namespace std;
int* blocks(int n) {
    int* memoryblocks = new int(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the size of block " << i + 1 << " : ";
        cin >> memoryblocks[i];
    }
    return memoryblocks;
}

int* processes(int n1) {
    int* processesarray = new int(n1);
    for (int i = 0; i < n1; i++)
    {
        cout << "Enter size of processes " << i + 1 << " : ";
        cin >> processesarray[i];
    }
    return processesarray;
}

void FirstFit(int numberofblocks, int* b, int numberofprocesses, int* p) {
    cout << "First Fit" << endl;

    int* deepCopy = new int[numberofblocks];
    for (int i = 0; i < numberofblocks; i++)
        deepCopy[i] = b[i];


    for (int i = 0; i < numberofprocesses; i++)
    {
        bool allocated = false;

        for (int j = 0; j < numberofblocks; j++)
        {
            if (p[i] <= deepCopy[j])
            {
                cout << "Process of size " << p[i] << " -> block of size " << deepCopy[j] << endl;
                deepCopy[j] = 0;
                allocated = true;
                break;
            }
        }
        if (allocated == false)
        {
            cout << "Process of size " << p[i] << " -> " << "Not Allocated" << endl;
        }
    }
}

void BestFit(int numberofblocks, int* b, int numberofprocesses, int* p) {

    cout << "Best Fit" << endl;

    int* deepCopy = new int[numberofblocks];
    for (int i = 0; i < numberofblocks; i++)
        deepCopy[i] = b[i];

    for (int i = 0; i < numberofprocesses; i++)
    {
        bool allocated = false;

        int min = -1;

        for (int j = 0; j < numberofblocks; j++)
        {
            if (p[i] <= deepCopy[j])
            {
                if (min == -1)
                {
                    min = j;
                    allocated = true;
                }
                else if (deepCopy[min] >= deepCopy[j] && deepCopy[j] > 0) {
                    min = j;
                    allocated = true;
                }
            }
        }
        if (allocated == true) {
            cout << "Process of size " << p[i] << " -> block of size " << deepCopy[min] << endl;
            deepCopy[min] = 0;
        }
        else {
            cout << "Process of size " << p[i] << " -> Not Allocated" << endl;
        }

    }
}

void WorstFit(int numberofblocks, int* b, int numberofprocesses, int* p) {

    cout << "Worst Fit" << endl;

    int* deepCopy = new int[numberofblocks];
    for (int i = 0; i < numberofblocks; i++)
        deepCopy[i] = b[i];


    for (int i = 0; i < numberofprocesses; i++)
    {
        bool allocated = false;

        int max = -1;

        for (int j = 0; j < numberofblocks; j++)
        {
            if (p[i] <= deepCopy[j])
            {
                if (max == -1)
                {
                    max = j;
                    allocated = true;
                }
                else if (deepCopy[max] <= deepCopy[j] && deepCopy[j] > 0) {
                    max = j;
                    allocated = true;
                }
            }
        }
        if (allocated == true) {
            cout << "Process of size " << p[i] << " -> block of size " << deepCopy[max] << endl;
            deepCopy[max] = 0;
        }
        else {
            cout << "Process of size " << p[i] << " -> Not Allocated" << endl;
        }

    }
}

int main()
{
    int numberofblocks;
    cout << "Enter number of blocks: ";
    cin >> numberofblocks;
    int* b = blocks(numberofblocks);

    int numberofprocesses;
    cout << "Enter number of processes: ";
    cin >> numberofprocesses;
    int* p = processes(numberofprocesses);

    bool flag = true;
    while (flag) {

        int m;
        string methods[5] = { "First Fit", "Best Fit", "Worst Fit", "Enter another data" ,"Exit" };

        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << "- " << methods[i] << endl;
        }
        cout << "Choose the method: ";
        cin >> m;
        switch (m) {
        case 1:
            FirstFit(numberofblocks, b, numberofprocesses, p);
            break;
        case 2:
            BestFit(numberofblocks, b, numberofprocesses, p);
            break;
        case 3:
            WorstFit(numberofblocks, b, numberofprocesses, p);
            break;
        case 4:
            main();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid input, try again." << endl;
        }
    }
}
