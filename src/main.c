#include "bitmaplib.h"
#include "vectlib.h"

#define MAX(x , y) x > y ? x : y;

int main(){
    picture pic = read_pic("mouse.ppm");
    int H = pic.height, W = pic.width;
    for(int i = 0 ;i < H ;i++){
        for(int j = 0; j < W;j++){
            color c = {rand()%255, rand()%255, rand()%255};
            set_pixel(pic, i,j,c);
        }
    }
    free(pic.pixels);
}