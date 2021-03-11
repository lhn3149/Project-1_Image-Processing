
//
// Created by rmb35 on 2/21/2021.
//

#include "ImageProcessing.h"
#include "SelectionSort.h"
#include <iostream>
#include <string>
using namespace std;

void **copyImage(int **original, int** processed, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(*(processed+i)+j) = *(*(original+i)+j);
        }
    }
}


void **flipVertical(int **original, int** processed, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(*(processed+i)+j) = *(*(original+i)+width-j-1);  // +i) width-j-1
        }
    }
}

void **flipHorizontal(int **original, int** processed, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(*(processed+i)+j) = *(*(original+height-i+1)+j);
        }
    }
}

void** medianFilter( int **original, int** processed, int height, int width )
{
    int filterparam = 9 ;

    int filterSize = filterparam * filterparam;

    int* medianWindow = new int[filterSize];


    //iterate through every pixel possible (accounting for edge boundaries)
    for(int i = 0; i < (height); i++)
    {
        for(int j = 0; j < (width); j++)
        {
            if(((i > 3) && (i < (height-4))) && ((j > 3) && (j < (width-4))))
            {
                int p = 0; //position in medianwidow
                for (int m = 0; m < filterparam; m++){
                    for (int n = 0; n < filterparam; n++){
                        medianWindow [p] = *(*(original+i-4+n)+j-4+m);
                        p = p + 1;
                    }
                }
                selectionSort(medianWindow,filterSize,ascending);
                *(*(processed+i)+j) = medianWindow[40];
            }
            else
            {
                *(*(processed+i)+j) = *(*(original+i)+j);
            }
        }
    }
}