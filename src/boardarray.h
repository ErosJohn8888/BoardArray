#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT
            //
            if (index == SIZE && !entry->compare(&array[SIZE - 1])) {
        cout << entry->name << "'s score is too low to be added!" << endl;
        return;
        }

        int i = (index < SIZE ? index : SIZE - 1) - 1;
        while (i >= 0 && entry->compare(&array[i])) {
        array[i + 1] = array[i];
        i--;
        }
        array[i + 1] = *entry;

    if (index < SIZE) index++;
}

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};