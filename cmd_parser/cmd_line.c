#include <stdint.h>
#include <stdio.h>
#include "string.h"
#include "cmd_line.h"

static int test(char**);
static int test1(char**);
static int test2(char**);
static int test3(char**);
static int test5(char**);
static int cmd_item_number;
static char* list_agrs[10];



extern int cmd_parser(char*);


static cmd_line_t test_cmd_table[] = {
    {(char*)"test", test , (char*)"test"},
    {(char*)"test1", test1 , (char*)"test 1"},
    {(char*)"test2", test2 , (char*)"test 2"},
    {(char*)"test3", test3 , (char*)"test 2"},
    {(char*)"test5", test5 , (char*)"test 5"},
    {(char*)0, (pf_cmd_func)0, (char*)0}
};

static int test(char** inut) {
    printf("run test 0\n");
    return 0;
}

static int test1(char** inut) {
    printf("run test 1\n");
    return 0;
}

static int test2(char** inut) {
    printf("run test 2\n");
    return 0;
}

static int test3(char** inut) {
    printf("run test 3\n");
    return 0;
}


static int test5(char** inut) {
    printf("run test 5\n");
    return 0;
}



extern int cmd_parser(char *input_string) {
    // parser string && assign list_agrs, cmd_item_numberd
    int i = 0 , j = 0;
    int len = strlen(input_string);
    char s[len];

    //Copie chuỗi cần làm sang chuỗi đệm s
    strcpy(s,input_string);

    for(i = 0; i < len; i++)
        {
            if(s[i] == ' ')
                s[i] = '\0';
            if(s[len-1] !=0)
                s[len] = '\0';
        }


     //Tách và chép từng lệnh vào mảng lưu
    for(i = 0; i < len; i++)
        {
            if(s[0] != '\0')
                list_agrs[0] = &s[0];

            if(s[i-1] == '\0' && s[i] != '\0')
                list_agrs[j++] = &s[i];
        }


    //  In chuỗi lệnh
    for (int j = 0; j < 10; j++)
        {
            printf("agrs[%d] : %s\n", j, list_agrs[j]);
        }


/*********************************************************************************/
    // compare with command table
/*********************************************************************************/

    i = 0;
    while (test_cmd_table[i].cmd != 0)
        {
            if(strcmp(list_agrs[0],test_cmd_table[i].cmd) == 0)
                {
                    test_cmd_table[i].func(list_agrs);
                    return CMD_SUCCES;
                    break;
                }
            i++;
        }


    return CMD_NOT_FOU;
}
