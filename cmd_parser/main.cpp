#include <iostream>
#include <stdint.h>
#include "string.h"
#include "cmd_line.h"

using namespace std;



int main() {
    cmd_parser((char*)"test 3 1 245 3   4fd 5fdfd");
    return 0;
}


