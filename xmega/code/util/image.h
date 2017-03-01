/*
 * image.h
 *
 * Created: 3/1/2017 2:42:06 PM
 *  Author: elmar
 */


#ifndef IMAGE_H_
#define IMAGE_H_

typedef struct {
    uint16_t width;
    uint16_t height;
    uint8_t isFlash;
    uint16_t * image;
} Image;

#define IMAGE_COLOR(img, x, y) ((img->isFlash)?img->image[y*img->width + x] : img->image[y*img->width + x])
#define IMAGE_WIDTH(img) img->width
#define IMAGE_HEIGHT(img) img->height
#define IMAGE_SIZE(img) img-> width * 2 * img->height * 2

#endif /* IMAGE_H_ */