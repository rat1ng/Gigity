#include <stdlib.h>
#define defaultSize 256

typedef struct {
    char* ch;
    int maxSize;
    int curLength;
} SeqString;

void initString(SeqString s) {
    s.ch = new char[defaultSize];
    if (s.ch == NULL) {
        exit(1);
    }
    s.ch[0] = '\0';
    s.maxSize = defaultSize;
    s.curLength = 0;
}

void overflowProcess() {
    char* newAddress = new char[2 * maxSize]
}



