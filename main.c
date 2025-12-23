#include "bitmaplib.h"
#include "vectlib.h"

#define MAX(x , y) x > y ? x : y;

void swap(color *a , color *b){
    color *p = a; 
    a = b; 
    b = p;
}
void transpose(color *arr , int w , int h){
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            swap((arr + w*j + i) , (arr));
        }
    }
}

int main(){

   picture pic = read_pic("mouse.ppm");
   transpose(pic.pixels , pic.width , pic.height);
   save_pic(pic , "O.ppm");
    free(pic.pixels);
}