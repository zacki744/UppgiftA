#include "Sorting.h"
#include <string>
#include <chrono> // kör dester för tidkomplexiteten
#include <crtdbg.h>
#include <fstream>
using namespace chrono;

//
//int banana()
//{
//    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//
//    int* arr1 = new int[1000];
//    int* arr2 = new int[1000];
//    int* arr3 = new int[1000];
//
//
//    int c = 0;
//    if (std::ifstream in{ "../../../Testdata/1000(0,1000).txt" })
//    {
//        std::string word;
//        while (in >> word)
//        {
//            arr1[c] = stoi(word);
//            arr2[c] = stoi(word);
//            arr3[c] = stoi(word);
//            c++;
//        }
//    }
//    else
//    {
//        cout << "couldn't open file" << endl;
//    }
// 
//    heapsort(arr1, c, 10);
//    quicksortPivotLast(arr2, c);
//    quicksortPivotMedian(arr3, c);
//
//    /*for (int i = 0; i < c; i++) {
//        if (arr2[i] != arr3[i])
//        {
//            cout << "hmmmmmm not good" << endl;
//        }
//        if (arr1[i] != arr3[i])
//        {
//            cout << "hmmmmmm not good" << endl;
//        }
//        cout << arr2[i] << "\t" << arr3[i] << "\t" << arr1[i] << endl;
//
//    }*/
//
//    delete[] arr1;
//    delete[] arr2;
//    delete[] arr3;
//    return 0;
//}
int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    int* arr1 = new int[50000];
    int* arr2 = new int[50000];
    int* arr3 = new int[50000];


    int c = 0;
    if (std::ifstream in{ "../../../Testdata/50000(0,10000000).txt" })
    {
        std::string word;
        while (in >> word)
        {
            arr1[c] = stoi(word);
            arr2[c] = stoi(word);
            arr3[c] = stoi(word);
            c++;
        }
        in.close();
    }
    else
    {
        cout << "couldn't open file" << endl;
    }

    auto qlt1 = std::chrono::high_resolution_clock::now();
    // sortera
    heapsort(arr1, c, 4);
    auto qlt2 = std::chrono::high_resolution_clock::now();
    auto qmt1 = std::chrono::high_resolution_clock::now();
    // sortera
    quicksortPivotLast(arr2, c);
    auto qmt2 = std::chrono::high_resolution_clock::now();
    auto hst1 = std::chrono::high_resolution_clock::now();
    // sortera
    quicksortPivotMedian(arr3, c);//somthing is wrong with this one
    auto hst2 = std::chrono::high_resolution_clock::now();

    duration<double, std::ratio<1, 1000>> qs_time_diff_milli_secs = duration_cast<duration<double, std::ratio<1, 1000>>>(qlt2 - qlt1);
    double qs_milli_seconds = qs_time_diff_milli_secs.count();

    duration<double, std::ratio<1, 1000>> qm_time_diff_milli_secs = duration_cast<duration<double, std::ratio<1, 1000>>>(qmt2 - qmt1);
    double qm_milli_seconds = qm_time_diff_milli_secs.count();

    duration<double, std::ratio<1, 1000>> hs_time_diff_milli_secs = duration_cast<duration<double, std::ratio<1, 1000>>>(hst2 - hst1);
    double hs_milli_seconds = hs_time_diff_milli_secs.count();

    cout << qs_milli_seconds << "\t" << qm_milli_seconds << "\t" << hs_milli_seconds << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    return 0;
}