/***************************************
* Project - Compiler for IFJ21
*
* @brief Library for easier string handeling
*
* @author Josef Susík <xsusik00>
* @author Marek Putala <xputal00>
*
* @file string.h
**************************************/

#ifndef _MY_STRING_H
#define _MY_STRING_H

#include <stdio.h>
#include <string.h>


typedef struct {
    char* str;
    int length;
    int alloc_size;
} String;

int string_init(String *s);
void string_free(String *s);
void string_clear(String *s);
int string_add_char(String *s, char c);
int string_cmp(String *s, const char *keyword_string);



#endif // STRING_H
