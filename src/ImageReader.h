//
//  ImageReader.h
//  OnlineCalibration
//
//  Created by Paul on 16.11.17.
//  Copyright (c) 2017 Paul Bergmann. All rights reserved.
//
//  Commented
//

#ifndef __OnlineCalibration__ImageReader__
#define __OnlineCalibration__ImageReader__

#include <stdio.h>
#include <iostream>
#include <dirent.h>

#include "StandardIncludes.h"

/**
 * Read input images from image files
 * Resizes the images if requested
 */

class ImageReader
{
public:
    
    /** 
     * Initialize the image reader
     * @param image_folder Image folder
     * @param new_size Resize input images to new_size
     */
    ImageReader(std::string image_folder,
                cv::Size new_size);

    /**
     * Read a new input image from the hard drive and return it
     *
     * @param Input image index to read
     * @return Read input image
     */
    cv::Mat readImage(int image_index);

    int getNumImages() { return (int)m_files.size(); }

    int getDir(std::string dir, std::vector<std::string> &files);
    
private:
    
    /**
     * Resize images to this size
     */
    cv::Size m_img_new_size;

    std::vector<std::string> m_files;
};

#endif /* defined(__OnlineCalibration__ImageReader__) */