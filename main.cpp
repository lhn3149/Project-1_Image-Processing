#include <iostream>
#include <string>
#include "PGM.h"
#include "ImageProcessing.h"
using namespace std;

int main()
{
    // Path to the file
    // If image is in the same directory as executable
    //string fileName = "lena.pgm";

    // Clion paths if cloned from repo

    string fileName_folder = "..\\test_images\\";
    string outputName_folder = "..\\processed_images\\";
    string fileName;
    string outputName;
    string operationName;
    char response;
    int operation;
    do {
        string name;

        //Prompt User to enter file name
        cout << "Enter File name to be processed without .pgm (ie. lena, balloons, noisy):  " << endl;
        cin >> name;
        fileName = fileName_folder + name+ ".pgm"; //Concatenate name to fileName

        //Open File set information
        if (openPGM(fileName)) {

            cout << "Reading in File" << endl;

            //Get Image Size Information
            int width = getPGMWidth();
            int height = getPGMHeight();

            // Declare and allocate memory for data
            int **original;
            original = new int *[height];

            for (int i = 0; i < height; i++) {
                original[i] = new int[width];
            }

            // Get the data
            getPGMData(original);
            cout << "Done Reading in File" << endl;

            // Read in operation from user
            cout << "Select Operation: \n" << "(0) Copy Image \n" << "(1) Flip Vertical\n"
                 << "(2) Flip Horizontal\n" << "(3) Median Filter\n" << endl;
            cin >> operation;

            //Perform operation specified by user
            cout << "Performing Operation..." << endl;

            int **processed;
            processed = new int *[height];

            for (int i = 0; i < height; i++) {
                processed[i] = new int[width];
            }

            switch (operation) {
                case 0:
                    operationName = "_copy";
                    copyImage(original, processed, height, width);
                    cout << "Performing Copy..." << endl;
                    break;
                case 1:
                    operationName = "_flipV";
                    flipVertical(original, processed, height, width);
                    cout << "Performing Vertical Flip..." << endl;
                    break;
                case 2:
                    operationName = "_flipH";
                    flipHorizontal(original, processed, height, width);
                    cout << "Performing Horizontal Flip..." << endl;
                    break;
                case 3:
                    operationName = "_medianF";
                    medianFilter(original, processed, height, width);
                    cout << "Performing Median Filter..." << endl;
                    break;
                default:
                    cout << "Invalid Operation, Try again." << endl;
            }
            outputName = outputName_folder + name +operationName + ".pgm";
            // Write back out the same image
            cout << "Writing out the File..." << endl;
            if (!writePGM(outputName, processed)) {
                cout << "Failed to write out file\n";
            }

            // Clean up memory
            for (int i = 0; i < height; i++) {
                delete[] original[i];
            }
            delete original;


            for (int i = 0; i < height; i++) {
                delete[] processed[i];
            }
            delete processed;


        }
        else {
            cout << "Cannot open file " << fileName << endl;
        }

        //Perform another operation?
        cout << "Perform another operation [y/n]?";
        cin >> response;

    }while(response=='y');
}