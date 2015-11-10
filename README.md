# SQL_IndexManager
IndexManager is one of 6 modules of <a title="our whole project" href="https://github.com/2015DatabaseDesign/MiniDB" target="_blank">MINISQL </a>, project of database design course. You can compile and debug IndexManager **without** other modules just use *make* command in your shell. <br/>
The structure of the program is listed below:<br/>
<img src="https://github.com/bingzhangdai/MiniSQL_IndexManager/blob/master/doc/overall.png" alt="structure" align=center /><br/>

## API
IndexManager class provides 4 interfaces for other modules<br/>

```cpp
class IndexManager {
private:
    /* some code here */
public:
    IndexManager();
    int search_one(const std::string& database, const std::string& table_name, struct index_info& inform);
    void search_many(const std::string& database, const std::string& table_name, int type, struct index_info& inform, std::vector<int>& container);
    void insert_one(const std::string& database, const std::string& table_name, struct index_info& inform);
    void delete_one(const std::string& database, const std::string& table_name, struct index_info& inform);
};
```
## Node definition
Use a 4K block as a B+ tree node. The first byte is used to identify whether it is leaf node. After that the *value number* is followed. Then the node is followed by repeating *offset* and *key* combination.<br/>
### nonleaf node
![](https://github.com/bingzhangdai/MiniSQL_IndexManager/blob/master/doc/innode.png)<br/>
### leaf node (not the last one)
![](https://github.com/bingzhangdai/MiniSQL_IndexManager/blob/master/doc/leafnode0.png)<br/>
### leaf node (the last leaf node)
![](https://github.com/bingzhangdai/MiniSQL_IndexManager/blob/master/doc/leafnode1.png)<br/>

## datatypes
some of the *struct*s are predefined:<br/>
### some *const*s
```cpp
const int Int(0), Float(1), Char_n(2);
const int Greater(1), NotLess(2), Less(3), NotGreater(4);
const int DataFile(0), IndexFile(1);
```
### node(block)
```cpp
struct blockInfo {
    int blockNum;               // the block number of the block
    bool dirtyBit;              // 0 -> flase
                                // 1 -> indicate dirty, write back
    blockInfo *next;            // the pointer point to next block 
    fileInfo *file;             // the pointer point to the file, which the block belongs to
    int charNum;                // the number of chars in the block
    char *cBlock;               // the array space for storing the records in the block in buffer
    int iTime;                  // it indicate the age of the block in use 
    int lock;                   // prevent the block from replacing
};
```
### index(key)
```cpp
struct index_info {
    std::string index_name;     //the name of the index file
    int length;                 //the length of the value
    char type;                  //the type of the value
                                //0---int,1---float,2----char(n)    
    long offset;                //the record offset in the table file
    std::string value;          //the value
    index_info(){}
};
```




