#pragma once
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <opencv2/face.hpp>
#include <Windows.h>
#include <string>

public ref class SnapshotHandler
{
};

std::string name;
cv::CascadeClassifier face_cascade;

void return_name() {
    std::cout << "Add student name\n";

}

void CreateOutput() {
    std::cout << "\nEnter Your Name:  ";
    std::cin >> name;
    //string OutputFolder = "C://Users/jeanl/source/repos/ObjectDetection/ObjectDetection/Resources/" + name; //Snapshot Output folder (Change this)

    /*
    if (CreateDirectoryA(OutputFolder.c_str(), NULL)) {
    std::cout << "Folder created successfully." << std::endl;
    }
    else {
    std::cout << "Failed to create folder." << std::endl;
    }
    */
}

void Capture() {
    cv::VideoCapture cap(0);
    cv::Mat img;

    CreateOutput();


    cv::CascadeClassifier faceCascade;
    faceCascade.load("Resources/haar.xml");

    if (faceCascade.empty()) { std::cout << "XML file not loaded" << std::endl; }

    std::vector<cv::Rect> faces;


    while (true) {

        cap.read(img);

        faceCascade.detectMultiScale(img, faces, 1.1, 10);

        for (int i = 0; i < faces.size(); i++)
        {
            cv::Mat imgCrop = img(faces[i]);
            //imshow(to_string(i), imgCrop); //Shows face saving live
            for (int j = 0; j < 10; j++)
            {
                imwrite("Resources/Faces/" + name + std::to_string(j) + ".png", imgCrop); //Saves faces to folder/destination of choice
            }
            rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(0, 255, 0), 2); //Rectangle values, Scalar is for BGR colour, and the final number is for thickness of the rectangle
        }

        imshow("Image", img);
        cv::waitKey(1);
    }
}

