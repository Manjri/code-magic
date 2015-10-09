#include <stdio.h>
/*
shallow vs deep copying

shallow copy:   copies all the member values from one object to another
deep copy:      Does the above and also deep copies any pointer objects

struct Test
{
    char * ptr;
};

void shallow_copy(Test& src, Test& dest)
{
    dest.ptr = src.ptr;
}

void deep_copy(Test& src, Test& dest)
{
    dest.ptr = (char*)malloc(strlen(src.ptr) + 1);
    strcpy(dest.ptr, src.ptr);
}
*/