#include <iostream>
#include "gradient/gradient_operator.h"
#include "gradient/ocv_sobel.h"
#include "gradient/alt_sobel.h"
#include "gradient/omp_sobel.h"
#include "utils/path_helper.h"
using namespace std;

void applyOperator(GradientOperator* operatorPtr, const string& inputPath, const string& outputPath) {
    cout << operatorPtr->getOperatorName() << " operator: " << endl;
    operatorPtr->getEdges(inputPath, outputPath);
    delete operatorPtr;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Usage: operators <operator> <input_path> <output_path>" << endl;
        return 1;
    }

    string operatorType = argv[1];
    string inputPath = argv[2];
    string outputPath = argv[3];

    string projectPath = PathHelper::getProjectPath();
    try {
        if (operatorType == "opencv%20sobel") {
            OcvSobel sobelOperator;
            sobelOperator.getEdges(inputPath, outputPath);
        } else if (operatorType == "alternative%20sobel") {
            AltSobel altSobelOperator;
            altSobelOperator.getEdges(inputPath, outputPath);
        } else if (operatorType == "openmp%20sobel") {
            OmpSobel ompSobelOperator;
            ompSobelOperator.getEdges(inputPath, outputPath);
        } else {
            std::cerr << "Unknown operator: " << operatorType << std::endl;
            return 1;
        }
        std::cout << "Processing completed successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
