#ifndef __CMD_LINE_H__
#define __CMD_LINE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define CMD_SUCCES  0
#define CMD_NOT_FOU 1

extern int cmd_parser(char*); //user
extern int cmd_get_number_line(); //user
extern char* cmd_get_item(int); //user
extern int cmd_parser(char *input_string);

typedef int (*pf_cmd_func)(char**);

typedef struct {
    char* cmd;
    pf_cmd_func func;
    char* cmd_info;
} cmd_line_t;


#ifdef __cplusplus
}
#endif


#endif //__CMD_LINE_H__
