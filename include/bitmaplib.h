

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#ifndef BITMAPLIB
#define BITMAPLIB

typedef struct{
    unsigned char red; 
    unsigned char green; 
    unsigned char blue; 
}color; 

typedef struct{
    int width ,height; 
    color *pixels; 

}picture;


picture new_pic(int width , int height);

FILE *save_pic(picture pic , char *nom_pic);

void set_pixel(picture pic , int x , int y , color clr);

void draw_line(picture pic , int x1 , int y1 , int x2 , int y2 , color clr);

picture read_pic(const char* FILE_NAME);

#endif