#include <iostream>
#include "PGM.h"
using namespace std;

int main()
{
    // Path to the file
    // If image is in the same directory as executable
    //string fileName = "lena.pgm";

    // Clion paths if cloned from repo
    string fileName = "..\\test_images\\balloons.pgm";
    string outputName = "..\\processed_images\\lena_copy.pgm";

    //Open File set information
    if( openPGM(fileName) )
    {
        // Get Image Size Information
        int width = getPGMWidth();
        int height = getPGMHeight();

        // Declare and allocate memory for data
        int** original; 	        
        original = new int*[ height];          
        
        for(int i = 0; i < height; i++){
            original[i] = new int[width];  		             
        }
        
        // Get the data
        getPGMData(original);	

        // Write back out the same image
        if( !writePGM(outputName, original) ){
            cout << "Failed to write out file\n";
        }

        // Clean up memory
        for(int i = 0; i < height; i++){
            delete[] original[i];  	            
        }	         
        delete original;
    }else{
        cout << "Cannot open file " << fileName << endl;
    }
}


/*
 *
 *
 * #include <iostream>
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
    string fileName = "originals/";
    string outputName = "processed/";

    char response;

    do {
        string name;

        //Prompt User to enter file name
        cout << "Enter File name: " << endl;
        cin >> name;
        fileName = fileName + name; //Concatenate name to fileName

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
            int operationVar;
            cout << "Select Operation: " << "\n(0) Copy Image" << "\n(1) Flip Vertical"
                 << "\n(2) Flip Horizontal" << "\n(3) Median Filter" << endl;
            cin >> operationVar;


            //Prompt User for Output Name
            cout << "Enter Output file name: " << endl;
            cin >> name;
            outputName = outputName + name;







            //Perform operation specified by user
            cout << "Performing Operation..." << endl;
            int **newFile = nullptr;
            switch (operationVar) {
                case 0:
                    newFile = original;
                    break;
                case 1:
                    newFile = flipV(original, height, width);
                    break;
                case 2:
                    newFile = flipH(original, height, width);
                    break;
                case 3:
                    newFile = medFilter(original, height, width);
                    break;
                default:
                    cout << "Invalid Operation, Sorry." << endl;
            }

            // Write back out the same image
            cout << "Writing out the File..." << endl;
            if (!writePGM(outputName, newFile)) {
                cout << "Failed to write out file\n";
            }

            // Clean up memory
            for (int i = 0; i < height; i++) {
                delete[] original[i];
            }
            delete original;

        }
        else {
            cout << "Cannot open file " << fileName << endl;
        }

        fileName = "..\\test_images\\";
        outputName = "..\\processed_images\\";

        //Perform another operation?
        cout << "Perform another operation [y/n]? ";
        char c;
        cin >> c;
        response = c;

    }while(response=='y');
}
 */