# 🖼️ Bitmap & Vector Graphics Library in C

A lightweight C project demonstrating **bitmap image manipulation** and **vector-based drawing**, built from scratch for educational purposes.  
Ideal for learning low-level graphics, memory management, and basic computer graphics concepts.

---

## 🚀 Features

### Bitmap Library (`bitmaplib`)
- Image creation with custom dimensions
- Pixel-level color manipulation
- Line drawing using a Bresenham-like algorithm
- Read/write support for PPM (P6) images
- Proper memory allocation and cleanup

### Vector Library (`vectlib`)
- Read vector coordinates from text files
- Draw vectors onto bitmap images
- Vector transformations: scale, shift, flip
- Linked-list based vector storage
- Safe memory deallocation

---

## 📁 Project Structure

├── bitmaplib.h  
├── bitmaplib.c  
├── vectlib.h  
├── vectlib.c  
├── main.c  
└── README.md  

---

## 🔧 Usage Examples

### Bitmap Example

```c
picture img = new_pic(800, 600);
color red = {255, 0, 0};
set_pixel(img, 100, 100, red);
draw_line(img, 0, 0, 799, 599, red);
save_pic(img, "output.ppm");
free(img.pixels);
```

### Vector Example

```c
vector *v = read_vector_file("shapes.txt");
draw_vector(v, img, green);
scale_vector(v, 2.0);
shift_vector(v, 50, 30);
flip_vector(v);
free_vector(v);
```

---

## 📊 Supported Formats

### Image
- PPM (P6)
- 24-bit RGB

### Vector File
Plain text format:
```
x1 y1 x2 y2
```

---

## 🛠️ Build

```bash
gcc -o graphics_program main.c bitmaplib.c vectlib.c -lm
./graphics_program
```

---

## ⚠️ Known Issues
- transpose() function is buggy
- Limited error handling
- Not optimized for large images

---

## 🔮 Future Improvements
- More image formats (PNG, JPEG)
- Additional drawing primitives
- Anti-aliasing
- Image transformations
- Transparency support

---

## 📚 Dependencies
- Standard C library
- GCC / C99 compiler

---

## 📄 License
Educational use only. Free to modify and extend.
