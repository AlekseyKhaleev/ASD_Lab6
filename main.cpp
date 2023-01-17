
#include <ctime>
#include <iostream>

#include "ClassList.h"
#include "Utils.h"


int main(int argc, char* argv[])
{
    NextRand(time(nullptr)); // инициализируем генератор случайных числел

    std::string input;
    std::cout<<"\nEnter array size (For exit enter 'q'):\n";
    std::cin>>input;
    while(input != "q") {
        int arraySize;
        try {
            arraySize = std::stoi(input); // попытка привести к целому типу полученного аргумента

            List<int> myArr;
            for(int i=0; i< arraySize; i++) myArr.PushBack(NextRand()%100);

            std::cout<<"\nRandom generated array:\n";
            for(int i=0; i< myArr.GetSize();i++) std::cout<<myArr.Ind(i)<<" ";

            QSort(myArr, 0, myArr.GetSize()-1);
            std::cout<<"\n\nSorted array:\n";
            for(int i=0; i< myArr.GetSize();i++) std::cout<<myArr.Ind(i)<<" ";
        } catch (std::exception &stoi_err) {
            std::cout << "Array size must be an integer\n";
        }


        std::cout<<"\nEnter array size (For exit enter 'q'):\n";
        std::cin>>input;
    }
    return 0;
}
