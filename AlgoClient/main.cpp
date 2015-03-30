//
//  main.cpp
//  AlgoClient
//
//  Created by Peter Martin on 3/13/15.
//  Copyright (c) 2015 Peter Martin. All rights reserved.
//

#include <iostream>
#include <algorithmia/algorithmia.h>

using namespace std;

int main(int argc, char *args[])
{
    wcout << L"Calling Algorithmia..." << endl;
    
    callalgorithmia();
    
    return 0;
}