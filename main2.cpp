//
//  main2.cpp
//  Project3C
//
//  Created by Alexia Terry on 12/4/16.
//  Copyright © 2016 Alexia Terry. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>

const int PAGE_SIZE = 256;

using namespace std;

int main()
{
    ifstream infile;
    ifstream bifile;
    ofstream outfile;
    char page_frame[256][256];
    int pagetable[256];
    int page = 0;
    int offset = 0;
    int row = 0;
    int tlb[16][2];
    int tlbsize = 0;
    int foundpage = 0;
    bool found = false;
    char temp_page[256];
    int pagenumber = 0;
    
    infile.open("addresses.txt");
    outfile.open("compare_output.txt");
    bifile.open("BACKING_STORE.bin" , ios::binary | ios::in);
    
    string temp;
    
    int wheretostart;
    
    while(getline(infile, temp))
    {
        page = stoi(temp) / PAGE_SIZE;
        offset = stoi(temp) % PAGE_SIZE;
        
        
        for(int i = 0; i < 16; i++)
        {
            if(tlb[i][0] == page)
            {
                found = true;
                foundpage = tlb[i][1];
            }
        }
        
        if(found)
        {
            wheretostart = page * PAGE_SIZE;
            infile.seekg(wheretostart, ios::beg);
            infile.read(reinterpret_cast<char *> (temp_page), 255);
            pagetable[pagenumber] = row;
            
            for(int i = 0; i < 256; i++)
            {
                page_frame[row][i] = temp_page[i];
            }
            
        }
        
        found = false;
        
        
        if(tlbsize == 15)
        {
            tlbsize = 0;
        }
        
        tlb[tlbsize][0] = page;
        tlb[tlbsize][1] = row;
        
        tlbsize++;
        row++;
        
        outfile << "Virtual address: " << temp << "  Physical address: " << (pagetable[pagenumber] * 256) + offset << " Value: " << page_frame[pagetable[pagenumber]][offset] << endl;
        
    }
    
    infile.close();
    outfile.close();
    bifile.close();


    return 0;

    
    

    
    
}
