#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

/*
 * Compile com
 *   g++ main.cpp -o output `pkg-config --cflags --libs opencv`
 */

using namespace cv;
using namespace std;

#define THRESHOLD_VALUE 170
#define THRESHOLD_MAX 255
#define THRESHOLD_TYPE 0

Mat frame, gray_frame, thresholded;

Mat splitImageVertically(int half)
{
    Mat croppedImage;

    if (half == 0)
    { // left
        croppedImage = frame(Rect(0, 0, frame.cols / 2, frame.rows));
    }
    else if (half == 1)
    { // right
        croppedImage = frame(Rect(frame.cols / 2, 0, frame.cols / 2, frame.rows));
    }
    else
    { // unknown
        cout << "Please inform either ";
        cout << "0 to return the left side of the image or ";
        cout << "1 to return the right side of the imgae" << endl;

        croppedImage = -1;
    }

    return croppedImage;
}

Mat splitImageHorizontally(int half)
{
    Mat croppedImage;

    if (half == 0)
    { // top
        croppedImage = frame(Rect(0, 0, frame.cols, frame.rows / 2));
    }
    else if (half == 1)
    { // bottom
        croppedImage = frame(Rect(0, frame.rows / 2, frame.cols, frame.rows / 2));
    }
    else
    { // unknown
        cout << "Please inform either ";
        cout << "0 to return the top side of the image or ";
        cout << "1 to return the bottom side of the imgae" << endl;

        croppedImage = -1;
    }

    return croppedImage;
}

int main(int argc, char **argv)
{

    VideoCapture cap;

    if (!cap.open(0))
    {
        cout << "Camera open failed!" << endl;
        return -1;
    }

    while (1)
    {
        cap >> frame;

        if (frame.empty())
        {
            break;
        }

        cvtColor(frame, gray_frame, COLOR_BGR2GRAY);
        threshold(gray_frame, thresholded, THRESHOLD_VALUE, THRESHOLD_MAX, THRESHOLD_TYPE);

        imshow("Video capture", thresholded);

        if (waitKey(10) == 27)
        {
            cout << "Esc pressed, shuting down..." << endl;
            break;
        }
    }

    return 0;
}
