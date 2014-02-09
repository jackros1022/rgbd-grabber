/**
 * @file DepthCamera.h
 * @author Yutaka Kondo <yutaka.kondo@kawadarobot.co.jp>
 * @date Jul 9, 2013
 */
#ifndef DEPTHCAMERA_H_
#define DEPTHCAMERA_H_

#include <vector>
#include <stdexcept>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <pcl/point_types.h>
#include "util/Error.h"

namespace krc {

typedef std::vector<pcl::PointXYZRGB, Eigen::aligned_allocator<pcl::PointXYZRGB>>
        PointXYZRGBVector;

class DepthCamera {
public:
    DepthCamera();

    virtual ~DepthCamera();

  /**
   * Return the size of depth image.
   *
   * @return Size of depth image
   */
    virtual cv::Size depthSize() const;

  /**
   * Return the size of color image.
   *
   * @return Size of color image
   */
    virtual cv::Size colorSize() const;

  /**
   * Start the device updating.
   */
    virtual void start() = 0;

  /**
   * Copy the latest depth data to the buffer.
   * Note that the buffer must be allocated in advance.
   *
   * @param buffer Returned matrix of CV_32F
   */
    virtual void captureDepth(cv::Mat& buffer);

  /**
   * Copy the latest amplitude data to the buffer.
   * Note that the buffer must be allocated in advance.
   *
   * @param buffer Returned matrix of CV_32F
   */
    virtual void captureAmplitude(cv::Mat& buffer);

  /**
   * Copy the latest color data to the buffer.
   * Note that the buffer must be allocated in advance.
   *
   * @param buffer Returned matrix of CV_8UC3
   */
    virtual void captureColor(cv::Mat& buffer);

  /**
   * Copy the latest 3D point cloud data to the buffer.
   * Note that the buffer must be allocated in advance.
   *
   * @param buffer Returned vector of PointXYZRGB
   */
    virtual void captureVertex(PointXYZRGBVector& buffer);

  /**
   * Copy the latest 3D point cloud data to the buffer.
   * The data is moving averaged one.
   * Note that the buffer must be allocated in advance.
   *
   * @param buffer Returned vector of PointXYZRGB
   */
    virtual void captureMovingAveragedVertex(PointXYZRGBVector& buffer);

  /**
   * Copy the latest audio data to the buffer.
   * Note that the buffer must be allocated in advance.
   *
   * @param buffer Returned value of uchar
   */
    virtual void captureAudio(std::vector<uchar>& buffer);

  /**
   * Copy the latest acceleration data to the buffer.
   *
   * @param buffer Returned 3D data of Point3f
   */
    virtual void captureAcceleration(cv::Point3f& acc);
};

}
#endif /* DEPTHCAMERA_H_ */
