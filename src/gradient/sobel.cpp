#include "../include/gradient/sobel.h"
#include "../include/utils/image_utils.h"

Sobel::Sobel(int kernelSize) : ksize(kernelSize), scale(1), delta(0) {}

std::string Sobel::getOperatorName() const {
    return "Sobel";
}

cv::Mat Sobel::getEdges(const std::string& inputPath, const std::string& outputName) {
    clock_t t = clock();

    cv::Mat image = ImageUtils::getImage(inputPath);
    cv::Mat rgbImage = convertToRGB(image);
    cv::Mat grayImage = convertToGrayscale(rgbImage);
    cv::Mat gradX = computeGradientX(grayImage);
    cv::Mat gradY = computeGradientY(grayImage);
    cv::Mat edges = combineGradients(gradX, gradY);
    ImageUtils::writeImage(edges, outputName);

    printf("Time taken: %.4fs\n", (float)(clock() - t)/CLOCKS_PER_SEC);

    return edges;
}

cv::Mat Sobel::convertToRGB(const cv::Mat& image) {
    cv::Mat rgbImage;
    cv::cvtColor(image, rgbImage, cv::COLOR_BGR2RGB);
    return rgbImage;
}

cv::Mat Sobel::convertToGrayscale(const cv::Mat &image) {
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_RGB2GRAY);
    return grayImage;
}

cv::Mat Sobel::computeGradientX(const cv::Mat &image) const {
    cv::Mat gradX;
    cv::Sobel(image, gradX, CV_32F, 1, 0, ksize, scale, delta, cv::BORDER_DEFAULT);
    return gradX;
}

cv::Mat Sobel::computeGradientY(const cv::Mat &image) const {
    cv::Mat gradY;
    cv::Sobel(image, gradY, CV_32F, 0, 1, ksize, scale, delta, cv::BORDER_DEFAULT);
    return gradY;
}

cv::Mat Sobel::combineGradients(const cv::Mat &gradX, const cv::Mat &gradY) {
    cv::Mat edges;
    cv::magnitude(gradX, gradY, edges);
    cv::normalize(edges, edges, 0, 255, cv::NORM_MINMAX, CV_8U);
    return edges;
}