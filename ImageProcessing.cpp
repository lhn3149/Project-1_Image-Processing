#include "ImageProcessing.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int** flipV( int **original, int height, int width )
{
    //Declare modified file memory
    int **modified;
    modified = new int *[height];

    for (int i = 0; i < height; i++) {
        modified[i] = new int[width];
    }

    int tempTop, tempBottom, w, h;
    for( h = 0; h < height; h++ )
    {
        for( w = 0; w < width; w++ )
        {
            tempTop = *(*(original+h)+w);
            tempBottom = *(*(original+(height-1-h))+w);

            *(*(modified+h)+w) = tempBottom;
            *(*(modified+(height-1-h))+w) = tempTop;
        }
    }
    return modified;
}

int** flipH( int **original, int height, int width )
{
    //Declare modified file memory
    int** modified;
    modified = new int*[height];
    for(int i = 0; i < height; i++)
        modified[i] = new int[width];

    int h,w;
    int tempTop, tempBottom;
    for (h = 0; h < height; h++) {
        for (w = 0; w < width; w++)
        {
            tempTop = *(*(original+h)+w);
            tempBottom = *(*(original+h)+(width-1-w));

            *(*(modified+h)+w) = tempBottom;
            *(*(modified+h)+(width-1-w)) = tempTop;
        }
    }
    return modified;
}

int** medFilter( int **original, int height, int width )
{
    cout << "in medFilter" << endl;
    cout << height << endl;
    cout << width << endl;

    int** modified;
    modified = new int*[height];
    for(int i = 0; i < height; i++)
        modified[i] = new int[width];

    vector<int> box;


    //iterate through every pixel possible (accounting for edge boundaries)
    for(int j = 0; j < (height); j++)
    {
        for(int i = 0; i < (width); i++)
        {
            if(((i > 3) && (i < (width-4))) && ((j > 3) && (j < (height-4))))
            {
                box =  {*(*(original + j-4)+i-4), *(*(original + j-3)+i-4), *(*(original + j-2)+i-4), *(*(original + j-1)+i-4), *(*(original + j)+i-4), *(*(original + j+1)+i-4), *(*(original + j+2)+i-4), *(*(original + j+3)+i-4), *(*(original + j+4)+i-4),
                        *(*(original + j-4)+i-3), *(*(original + j-3)+i-3), *(*(original + j-2)+i-3), *(*(original + j-1)+i-3), *(*(original + j)+i-3), *(*(original + j+1)+i-3), *(*(original + j+2)+i-3), *(*(original + j+3)+i-3), *(*(original + j+4)+i-3),
                        *(*(original + j-4)+i-2), *(*(original + j-3)+i-2), *(*(original + j-2)+i-2), *(*(original + j-1)+i-2), *(*(original + j)+i-2), *(*(original + j+1)+i-2), *(*(original + j+2)+i-2), *(*(original + j+3)+i-2), *(*(original + j+4)+i-2),
                        *(*(original + j-4)+i-1), *(*(original + j-3)+i-1), *(*(original + j-2)+i-1), *(*(original + j-1)+i-1), *(*(original + j)+i-1), *(*(original + j+1)+i-1), *(*(original + j+2)+i-1), *(*(original + j+3)+i-1), *(*(original + j+4)+i-1),
                        *(*(original + j-4)+i),   *(*(original + j-3)+i),   *(*(original + j-2)+i),   *(*(original + j-1)+i),   *(*(original + j)+i),   *(*(original + j+1)+i),   *(*(original + j+2)+i),   *(*(original + j+3)+i),   *(*(original + j+4)+i),
                        *(*(original + j-4)+i+1), *(*(original + j-3)+i+1), *(*(original + j-2)+i+1), *(*(original + j-1)+i+1), *(*(original + j)+i+1), *(*(original + j+1)+i+1), *(*(original + j+2)+i+1), *(*(original + j+3)+i+1), *(*(original + j+4)+i+1),
                        *(*(original + j-4)+i+2), *(*(original + j-3)+i+2), *(*(original + j-2)+i+2), *(*(original + j-1)+i+2), *(*(original + j)+i+2), *(*(original + j+1)+i+2), *(*(original + j+2)+i+2), *(*(original + j+3)+i+2), *(*(original + j+4)+i+2),
                        *(*(original + j-4)+i+3), *(*(original + j-3)+i+3), *(*(original + j-2)+i+3), *(*(original + j-1)+i+3), *(*(original + j)+i+3), *(*(original + j+1)+i+3), *(*(original + j+2)+i+3), *(*(original + j+3)+i+3), *(*(original + j+4)+i+3),
                        *(*(original + j-4)+i+4), *(*(original + j-3)+i+4), *(*(original + j-2)+i+4), *(*(original + j-1)+i+4), *(*(original + j)+i+4), *(*(original + j+1)+i+4), *(*(original + j+2)+i+4), *(*(original + j+3)+i+4), *(*(original + j+4)+i+4)};
                std::sort(box.begin(), box.end());
                *(*(modified+j)+i) = box[40];
            }
            else
            {
                *(*(modified+j)+i) = *(*(original+j)+i);
            }
        }
    }

    return modified;
}