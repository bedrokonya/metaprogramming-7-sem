#ifndef Reader_h
#define Reader_h

#include "TypeList.h"
#include <fstream>

/*
 * Есть файл input.txt, где построчно записаны данные. В каждой строке записано несколько элементов.
 * Их типы описываются с помощью TypeList. Типы и порядок элементов во всех строках
 * одинаковые. Необходимо разработать шаблонный класс Reader, который будет получать на вход TypeList
 * с описанием строки в файле, открывать этот файл и позволять с помощью метода void* readNextLine()
 * читать по очереди все строки в файле. Возвращаемое значение функции – указатель на область памяти,
 * где последовательно записаны считанные элементы строки.
*/


// ================= рекурсивное считывание ===================

template <typename TSubList>
void readTypesRecursively(char* currentPtr, std::ifstream &stream, int &counter) {
    
    typedef typename TSubList::head Type;
    Type value;

    stream >> value;
    *((Type*)currentPtr) = value;
    currentPtr += sizeof(Type);
    readTypesRecursively<typename TSubList::tail>(currentPtr, stream, counter);
    std::cout << "The type being read: "<< typeid(Type).name() << " ---- The value: " << value << std::endl;
}

template<>
void readTypesRecursively<EmptyList>(char* currentPtr, std::ifstream &stream, int &counter) {
    std::cout << "\n======== Finished recursion of the line #" << counter<< "! ========\n";
}
// ============================================================


template<typename TList> class Reader {
    
 private:
    std::ifstream _inputFile;
    int lineCounter = 0;
    
 public:
    Reader(std::string &inputFile) {
        _inputFile.open(inputFile);
        if (_inputFile.is_open()) {
            std::cout<< "The file: " << inputFile << " has been opened\n";
        }
        else {
            std::cout<< "ERROR: the file: " << inputFile << " could not be opened\n";
        }
        
    }
    
    ~Reader() {
        _inputFile.close();
    }
    
    /*
     * Возвращает указатель на область памяти,
     * где последовательно записаны считанные элементы строки.
     * Если считывать больше нечего -- возвращает nullptr.
     */
    void* readNextLine() {
        
        void* ptrString = nullptr;
        lineCounter++;
        
        ptrString = malloc(SizeOf<TList>::value);
        readTypesRecursively<TList>((char*)ptrString, _inputFile, lineCounter);
        if (!_inputFile.eof()) {
            return ptrString;
        } else {
            std::cout << "\nThe end of file has been reached!\n";
            return nullptr;
        }
    }
    
    void readAndPrintAllLines() {
        
        void* result = readNextLine();
        while (result != nullptr) {
            result = readNextLine();
        }
    }
};


#endif /* Reader_h */
