#include "bitmaplib.h"

#ifndef VECTLIB
#define VECTLIB

typedef struct vector{
	double x1 , y1 , x2 , y2; 
	struct vector *next;
}vector; 

vector *read_vector_file(const char* FILE_NAME);

void draw_vector(vector *VECT , picture pic , color clr);

void scale_vector(vector *VECT , double scale);

void shift_vector(vector *VECT , double x , double y);

void flip_vector(vector *VECT);

void free_vector(vector *VECT);


#endif

