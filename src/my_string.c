/***************************************
* Project - Compiler for IFJ21
* 
* @brief Library for easier string handeling 
* 
* @author Josef Susík <xsusik00>
* @author Marek Putala <xputal00>
* 
* @file string.c 
**************************************/
#include <stdlib.h>


#include "my_string.h"
#include "error.h"


#define STRING_LEN_INC 8

int string_init(String *s) {
    
    s->str = (char*) malloc(sizeof(STRING_LEN_INC));
    
    if (s->str == NULL) {
        return INTERNAL_ERR;
    }
    
    s->str[0] = '\0';
    s->length = 0;
    s->alloc_size = STRING_LEN_INC;
    
    return OK;
}

void string_free(String *s) {
    free(s->str);
}

void string_clear(String *s) {
    s->str[0] = '\0';
    s->length = 0;
}

int string_add_char(String *s, char c) {
    
    // Not enough memory, need to reallocate
    if ((s->length + 1) >= s->alloc_size) {
        s->str = (char*) realloc(s->str, s->length + STRING_LEN_INC);
        
        if (s->str == NULL) {
               return INTERNAL_ERR;
        }
        
        s->alloc_size = s->length + STRING_LEN_INC; // New allocated size
    
    } // end if
    
    s->str[s->length] = c;  // Add the new char
    s->length++;    // Increase the length by 1
    s->str[s->length] = '\0';   // Insert '\0' to the end of the string
    
    return OK;
}

int string_cmp(String *s, const char *keyword_string){
    
    return strcmp(s->str, keyword_string);
}