#include <iostream>
#include <string>
#include <stdlib.h>
#include "datatype.h"
#include "mystr.h"
#include "IndexManager.h"
using namespace std;

blockInfo *block[50];
IndexManager Im;

blockInfo *readBlock(const std::string& table_name, int blockNum, int fileType) {
    for (int i = 0; i < 50; i++)
        if (block[i] == NULL)
            return NULL;
        else if (block[i]->blockNum == blockNum)
            return block[i];
}

blockInfo *get_new_block(const std::string& table_name, int fileType, int blockNum) {
    int i;
    for (i = 0; i < 50; i++)
        if (block[i] == NULL)
            break;
    block[i] = (blockInfo *)malloc(sizeof(blockInfo));
    block[i]->blockNum = blockNum;
    block[i]->cBlock = (char *)malloc(sizeof(char)*4096);
    return block[i];
}

int i;
int main(void) {
    index_info inform;
    inform.type = Char_n;

    //for (i = 0; i < 8000; i++) {
        inform.value = "3.3";
        inform.length = 10;
        inform.offset = i;
        Im.insert_one("", "", inform);
        inform.value = "004";
        Im.insert_one("", "", inform);
        inform.value = "4.0";
        Im.insert_one("", "", inform);
        inform.value = "3.30";
        cout << Im.search_one("","",inform) << endl;
//    }
//    for (i = 790; i > 1; i--) {
//        inform.value = IToStr(i, 3);
//        Im.delete_one("", "", inform);
//    }


    /*cout << string(block[0]->cBlock) << endl << endl;
    cout << string(block[1]->cBlock) << endl << endl;
    cout << string(block[3]->cBlock) << endl;*/
    
    
    return 0;
}

