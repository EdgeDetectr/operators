#ifndef SOBEL_H
#define SOBEL_H

#include "gradient_operator.h"

#include <opencv2/opencv.hpp>

/**
 * @file Sobel.h
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

    cv::Mat getEdges(const std::string& inputPath, const std::string& outputName) override;
    std::string getOperatorName() const override;

private:

    /**
     * @brief Reads an image from the specified file.
     * @param inputPath The path to the input image.
     * @return The image.
     */
    static cv::Mat getImage(const std::string &inputPath);

    /**
     * @brief Converts the input image to RGB.
     * @param input The input image.
     * @return The image in RGB format.
     */
    static cv::Mat convertToRGB(const cv::Mat& input);

    /**
     * @brief Converts the input image to grayscale.
     * @param input The input image.
     * @return The image in grayscale format.
     */
    static cv::Mat convertToGrayscale(const cv::Mat& input);

    /**
     * @brief Writes an image to the specified file.
     * @param image The image to write.
     * @param filename The name of the output file.
     */
    static void writeImage(const cv::Mat& image, const std::string& outputName);

    /**
     * @brief Computes the gradient in the x-direction.
     * @param input The input image.
     * @return The gradient in the x-direction.
     */
    cv::Mat computeGradientX(const cv::Mat& input) const;

    /**
     * @brief Computes the gradient in the y-direction.
     * @param input The input image.
     * @return The gradient in the y-direction.
     */
    cv::Mat computeGradientY(const cv::Mat& input) const;

    /**
     * @brief Combines the gradients in the x and y directions.
     * @param gradX The gradient in the x-direction.
     * @param gradY The gradient in the y-direction.
     * @return The combined gradients.
     */
    static cv::Mat combineGradients(const cv::Mat& gradX, const cv::Mat& gradY);
};

#endif //SOBEL_H
