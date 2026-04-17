
#include "bitmaplib.h"

picture new_pic(int width , int height){
    picture pic; 
    pic.width = width; 
    pic.height = height; 
    pic.pixels = (color*)malloc(width * height * sizeof(color));
    return pic; 
} 

FILE *save_pic(picture pic , char *nom_pic){

    char w[12] , h[12];
    snprintf(w, sizeof(w), "%d", pic.width);
    snprintf(h, sizeof(h), "%d", pic.height);

    FILE *image; 
    image = fopen(nom_pic, "w");

    if(image == NULL){
        fclose(image);
        return NULL;
    }
    fprintf(image ,"P6"); 
    fprintf(image , "\n");
    fprintf(image , w); 
    fprintf(image , " "); 
    fprintf(image , h); 
    fprintf(image , "\n"); 
    fprintf(image , "255"); 
    fprintf(image , "\n");
    
    for(int i = 0 ; i < pic.height ; i++){
        for(int j = 0 ; j < pic.width ; j++){
            color clr = pic.pixels[i*(pic.width) + j]; 
            fputc(clr.red , image); 
            fputc(clr.green , image); 
            fputc(clr.blue , image);
        }
    }   

    fclose(image);  
    return 0;  
}

void set_pixel(picture pic , int x , int y , color clr){
    if((x < pic.width) && (y>=0 && y < pic.height))
        pic.pixels[(y*pic.width + x)] = clr;
}

void draw_line(picture pic , int x1 , int y1 , int x2 , int y2 , color clr){
    int n = abs(x1 - x2) > abs(y1 - y2) ? abs(x1 - x2) + 1 : abs(y1 - y2) + 1; 
    int x = x1 , y = y1; 
    for(int i = 0 ; i <= n-1 ;i++){
        x = (x1 + (i * (float)(x2 - x1) / (n-1))); 
        y = (y1 + (i * (float)(y2 - y1) / (n-1)));
        set_pixel(pic , x , y , clr); 
    }
}

picture read_pic(const char* NAME_FILE){
    int h , w , A255; 
    FILE *image = fopen(NAME_FILE , "rb"); 
    char P6[3]; 
    if(!image){
        fclose(image);
        exit(1); 
    }
    if(!fgets(P6,sizeof(P6),image)){
        fclose(image);
        exit(1);
    }
    int c;
    while ((c=fgetc(image))=='#'){
        while(fgetc(image)!='\n');
    }
    ungetc(c, image);
    if(fscanf(image, "%d %d %d", &w, &h, &A255) != 3){
        fclose(image);
        exit(1);
    }
    if (A255!=255){
        fclose(image);
        exit(1); 
    }
    picture pic = new_pic(w , h);

    while (fgetc(image) != '\n');

    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            unsigned char rgb[3];
            if(fread(rgb,sizeof(unsigned char),3,image)!=3){
                fclose(image);
                exit(1); 
            }
            color c = {rgb[0],rgb[1],rgb[2]};
            set_pixel(pic, j, i, c);
        }
    }
    fclose(image);
    return pic;
}