#ifndef OPERATORS_SOBEL_H
#define OPERATORS_SOBEL_H

#include "gradient_operator.h"
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

/**
 * @file sobel.h
 * @brief This file contains the declaration of the Sobel class.
 */
class Sobel : public GradientOperator {
private:
    int ksize;  // kernel size for the Sobel operator
    double scale; // scaling factor for the gradient values
    double delta; // offset added to the gradient values

public:
    /**
     * @brief Constructs a Sobel object.
     * @param kernelSize The size of the kernel for the Sobel operator. Default is 3.
     */
    explicit Sobel(int kernelSize = 3);

    Mat getEdges(const string& inputPath, const string& outputName) override;
    [[nodiscard]] string getOperatorName() const override;

private:

    /**
     * @brief Converts the input image to RGB.
     * @param input The input image.
     * @return The image in RGB format.
     */
    static Mat convertToRGB(const Mat& input);

    /**
     * @brief Converts the input image to grayscale.
     * @param input The input image.
     * @return The image in grayscale format.
     */
    static Mat convertToGrayscale(const Mat& input);

    /**
     * @brief Computes the gradient in the x-direction.
     * @param input The input image.
     * @return The gradient in the x-direction.
     */
    [[nodiscard]] Mat computeGradientX(const Mat& input) const;

    /**
     * @brief Computes the gradient in the y-direction.
     * @param input The input image.
     * @return The gradient in the y-direction.
     */
    [[nodiscard]] Mat computeGradientY(const Mat& image) const;

    /**
     * @brief Combines the gradients in the x and y directions.
     * @param gradX The gradient in the x-direction.
     * @param gradY The gradient in the y-direction.
     * @return The combined gradients.
     */
    static Mat combineGradients(const Mat& gradX, const Mat& gradY);
};

#endif //OPERATORS_SOBEL_H
