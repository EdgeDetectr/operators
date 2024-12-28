#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include "src/gradient/gradient_operator.h"
#include "gradient/sobel.h"
#include "gradient/alt_sobel.h"
#include "utils/path_helper.h"
using namespace std;

int main() {
    try {
        std::string projectPath = PathHelper::getProjectPath();
        std::string inputPath = projectPath + "/test/gradient/datasets/photo.jpg";
        std::string outputPath = "output.png";

        GradientOperator* operatorPtr = nullptr;

        operatorPtr = new AltSobel();

        cv::Mat edgeDetectedImage = operatorPtr->getEdges(inputPath, outputPath);
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
