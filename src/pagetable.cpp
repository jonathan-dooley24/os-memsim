#include "pagetable.h"

PageTable::PageTable(int page_size)
{
    _page_size = page_size;
}

PageTable::~PageTable()
{
}

std::vector<std::string> PageTable::sortedKeys()
{
    std::vector<std::string> keys;

    std::map<std::string, int>::iterator it;
    for (it = _table.begin(); it != _table.end(); it++)
    {
        keys.push_back(it->first);
    }

    std::sort(keys.begin(), keys.end(), PageTableKeyComparator());

    return keys;
}

void PageTable::addEntry(uint32_t pid, int page_number)
{
    // Combination of pid and page number act as the key to look up frame number
    std::string entry = std::to_string(pid) + "|" + std::to_string(page_number);

    int frame = 0; 

    // Find free frame
    // TODO: implement this!
    if(_table.count(entry) == 0){ //if the entry is not already present in the table
        
        std::vector<std::string> keys = sortedKeys();
        bool spot_found = true;

        while(true){
            

        }

    }
 
    _table[entry] = frame;
}

int PageTable::getPhysicalAddress(uint32_t pid, uint32_t virtual_address)
{
    // Convert virtual address to page_number and page_offset
    // TODO: implement this!
    int page_number = 0;
    int page_offset = 0;

    // Combination of pid and page number act as the key to look up frame number
    std::string entry = std::to_string(pid) + "|" + std::to_string(page_number);
    
    // If entry exists, look up frame number and convert virtual to physical address
    int address = -1;
    if (_table.count(entry) > 0)
    {
        // TODO: implement this!
    }

    return address;
}

void PageTable::print()
{
    int i;

    std::cout << " PID  | Page Number | Frame Number" << std::endl;
    std::cout << "------+-------------+--------------" << std::endl;

    std::vector<std::string> keys = sortedKeys();

    for (i = 0; i < keys.size(); i++)
    {
        // TODO: print all pages.
        //the position of "|" in the key can be found using: keys[i].find("|")
        //get pid. AKA keys[i] from beginning to "|"
        std::string pid = keys[i].substr(0, keys[i].find("|"));
        //get page num. AKA keys[i] from "|" to end
        std::string page_number = keys[i].substr(keys[i].find("|") + 1);
        //get frame num
        int frame_number = _table[keys[i]];

        //print
        printf(" %4s | %11s | %12d \n", pid.c_str(), page_number.c_str(), frame_number);

    }
}
