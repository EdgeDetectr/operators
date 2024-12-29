#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include "gradient/gradient_operator.h"
#include "gradient/sobel.h"
#include "gradient/alt_sobel.h"
#include "utils/path_helper.h"
using namespace std;

void applyOperator(GradientOperator* operatorPtr, const string& inputPath, const string& outputPath) {
    cout << operatorPtr->getOperatorName() << " operator: " << endl;
    operatorPtr->getEdges(inputPath, outputPath);
    delete operatorPtr;
}

int main() {
    try {
        string projectPath = PathHelper::getProjectPath();
        string inputPath = projectPath + "/test/gradient/datasets/photo.jpg";
        string outputPath = "output.png";

//        sobel
        applyOperator(new Sobel(), inputPath, outputPath);
//        alt sobel
        applyOperator(new AltSobel(), inputPath, outputPath);
    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
        return 1;
    }

    return 0;
}
