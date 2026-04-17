

#include "bitmaplib.h"
#include "vectlib.h"

vector *read_vector_file(const char* FILE_NAME){
	vector *VECT = NULL;
	vector *tmp = NULL; 
    FILE *text; 
	text = fopen(FILE_NAME, "r");
	double x1 , y1 , x2 , y2;
	while(fscanf(text , "%lf %lf %lf %lf" , &x1 , &y1 , &x2 , &y2)==4){
		vector *new_vect = (vector*) malloc(sizeof(vector));
		new_vect->x1 = x1; 
		new_vect->y1 = y1; 
		new_vect->x2 = x2; 
		new_vect->y2 = y2; 
		new_vect->next = NULL;
		if(!VECT){
			VECT = new_vect; 
			tmp = VECT; 
		}
		else{
			tmp->next = new_vect; 
			tmp = tmp->next;
		}
	}
	fclose(text);
	return VECT; 
}

void draw_vector(vector *VECT , picture pic , color clr){
	vector *tmp = VECT; 
	while(tmp){
		draw_line(pic , tmp->x1 , tmp->y1 , tmp->x2 , tmp->y2 , clr);
		tmp = tmp->next;
	}
}

void scale_vector(vector *VECT , double scale){
	vector *tmp = VECT; 
	while(tmp){
		tmp->x1 *= scale;
		tmp->y1 *= scale;
		tmp->x2 *= scale; 
		tmp->y2 *= scale;
		tmp = tmp->next;
	}
}

void shift_vector(vector *VECT , double x , double y){
	vector *tmp = VECT; 
	while(tmp){
		tmp->x1 += x;
		tmp->y1 += y;
		tmp->x2 += x; 
		tmp->y2 += y;
		tmp = tmp->next;
	}
}

void flip_vector(vector *VECT){
	vector *tmp = VECT; 
	while(tmp){
		tmp->x1 = -tmp->x1;
		tmp->x2 = -tmp->x2; 
		tmp = tmp->next;
	}
}

void free_vector(vector *VECT) {
    vector *tmp;
    while (VECT) {
        tmp = VECT;
        VECT = VECT->next;
        free(tmp);
    }
}
