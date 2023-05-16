#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

// Function to detect faces in an image
void detectAndDisplay(Mat frame);

// Pre-trained face detection model
String face_cascade_name = "C:/Users/Raviteja/Desktop/FaceDetection/haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;

int main(int argc, const char** argv)
{
    // Load the cascade classifier
    if (!face_cascade.load(face_cascade_name)) {
        printf("--(!)Error loading face cascade\n");
        return -1;
    };

    // Open the default video camera
    VideoCapture capture(0);
    if (!capture.isOpened()) {
        printf("--(!)Error opening video capture\n");
        return -1;
    }

    Mat frame;
    while (capture.read(frame)) {
        if (frame.empty()) {
            printf(" --(!) No captured frame -- Break!");
            break;
        }

        // Apply the classifier to the frame
        detectAndDisplay(frame);

        if (waitKey(10) == 27) {
            break; // escape
        }
    }
    return 0;
}

void detectAndDisplay(Mat frame)
{
    std::vector<Rect> faces;
    Mat frame_gray;

    // Convert to gray scale
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    // Detect faces
    face_cascade.detectMultiScale(frame_gray, faces);

    for (size_t i = 0; i < faces.size(); i++) {
        Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
        ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4);

        Mat faceROI = frame_gray(faces[i]);
    }

    // Show the result
    imshow("Capture - Face detection", frame);
}
