#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include "src/gradient/gradient_operator.h"
#include "gradient/sobel.h"
#include "gradient/alt_sobel.h"
#include <filesystem>
using namespace std;

std::string getProjectPath() {
    std::filesystem::path currentPath = std::filesystem::current_path();
    while (currentPath.has_parent_path()) {
        if (currentPath.filename() == "operators") {
            return currentPath.string();
        }
        currentPath = currentPath.parent_path();
    }
    throw std::runtime_error("Could not find the 'operators' folder.");
}

int main() {
    try {
        std::string projectPath = getProjectPath();
        std::string inputPath = projectPath + "/test/gradient/datasets/photo.jpg";
        std::string outputPath = "output.png";

        // Instantiate the Sobel operator
        GradientOperator* operatorPtr = nullptr;

        // Example: Use Sobel Operator
        operatorPtr = new AltSobel();

        // Apply the Sobel operator
        cv::Mat edgeDetectedImage = operatorPtr->getEdges(inputPath, outputPath);
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
