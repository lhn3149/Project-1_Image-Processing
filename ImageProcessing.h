
//
// Created by rmb35 on 2/21/2021.
//

#ifndef PROJECT_1_IMAGEPROCESSING_H
#define PROJECT_1_IMAGEPROCESSING_H

#include <iostream>

#include <fstream>
#include <cstdio>
#include <string>

void **flipHorizontal(int **original, int** processed, int height, int width);

void **flipVertical(int **original, int** processed, int height, int width);

void **copyImage(int **original, int** processed, int height, int width);

void **medianFilter(int **original, int** processed, int height, int width);


#endif //PROJECT_1_IMAGEPROCESSING_H