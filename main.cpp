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

int main() {
    try {
        string projectPath = PathHelper::getProjectPath();
        string inputPath = projectPath + "/test/gradient/datasets/photo.jpg";
        string outputPath = "output.png";

//        opencv sobel
        applyOperator(new OcvSobel(), inputPath, outputPath);
//        alt sobel
        applyOperator(new AltSobel(), inputPath, outputPath);

//        openmp sobel - 50% of alt sobel
        omp_set_num_threads(1);
        applyOperator(new OmpSobel(), inputPath, outputPath);

    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
        return 1;
    }

    return 0;
}
