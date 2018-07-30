/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                        Intel License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000, Intel Corporation, all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of Intel Corporation may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#include "precomp.hpp"

#include "videoio_registry.hpp"

namespace cv {

template<> void DefaultDeleter<CvCapture>::operator ()(CvCapture* obj) const
{ cvReleaseCapture(&obj); }

template<> void DefaultDeleter<CvVideoWriter>::operator ()(CvVideoWriter* obj) const
{ cvReleaseVideoWriter(&obj); }



VideoCapture::VideoCapture()
{}

VideoCapture::VideoCapture(const String& filename, int apiPreference)
{
    CV_TRACE_FUNCTION();
    open(filename, apiPreference);
}

VideoCapture::VideoCapture(const String& filename)
{
    CV_TRACE_FUNCTION();
    open(filename, CAP_ANY);
}

VideoCapture::VideoCapture(int index)
{
    CV_TRACE_FUNCTION();
    open(index);
}

VideoCapture::~VideoCapture()
{
    CV_TRACE_FUNCTION();

    icap.release();
    cap.release();
}

bool VideoCapture::open(const String& filename, int apiPreference)
{
    CV_TRACE_FUNCTION();

    if (isOpened()) release();

/**
 * Camera dispatching method: index is the camera number.
 * If given an index from 0 to 99, it tries to find the first
 * API that can access a given camera index.
 * Add multiples of 100 to select an API.
 */
CV_IMPL CvCapture * cvCreateCameraCapture (int index)
{
    int  domains[] =
    {
#ifndef WINRT_8_0
        CV_CAP_WINRT,
#else
        // not supported
#endif
#ifdef HAVE_MSMF
        CV_CAP_MSMF,
#endif
#if 1
        CV_CAP_IEEE1394,   // identical to CV_CAP_DC1394
#endif
#ifdef HAVE_TYZX
        CV_CAP_STEREO,
#endif
#ifdef HAVE_PVAPI
        CV_CAP_PVAPI,
#endif
#if 1
        CV_CAP_VFW,        // identical to CV_CAP_V4L
#endif
#ifdef HAVE_MIL
        CV_CAP_MIL,
#endif
#if defined(HAVE_QUICKTIME) || defined(HAVE_QTKIT)
        CV_CAP_QT,
#endif
#ifdef HAVE_UNICAP
        CV_CAP_UNICAP,
#endif
#ifdef HAVE_OPENNI
        CV_CAP_OPENNI,
#endif
#ifdef HAVE_OPENNI2
        CV_CAP_OPENNI2,
#endif
#ifdef HAVE_XIMEA
        CV_CAP_XIAPI,
#endif
#ifdef HAVE_AVFOUNDATION
        CV_CAP_AVFOUNDATION,
#endif
#ifdef HAVE_GIGE_API
        CV_CAP_GIGANETIX,
#endif
#ifdef HAVE_INTELPERC
        CV_CAP_INTELPERC,
#endif
        -1
    };

    // interpret preferred interface (0 = autodetect)
    int pref = (index / 100) * 100;
    if (pref)
    {
        domains[0]=pref;
        index %= 100;
        domains[1]=-1;
    }

    // try every possibly installed camera API
    for (int i = 0; domains[i] >= 0; i++)
    {
#if defined(WINRT_8_1)         || \
    defined(HAVE_MSMF)         || \
    defined(HAVE_TYZX)         || \
    defined(HAVE_VFW)          || \
    defined(HAVE_LIBV4L)       || \
    defined(HAVE_CAMV4L)       || \
    defined(HAVE_CAMV4L2)      || \
    defined(HAVE_VIDEOIO)      || \
    defined(HAVE_GSTREAMER)    || \
    defined(HAVE_DC1394_2)     || \
    defined(HAVE_DC1394)       || \
    defined(HAVE_CMU1394)      || \
    defined(HAVE_MIL)          || \
    defined(HAVE_QUICKTIME)    || \
    defined(HAVE_QTKIT)        || \
    defined(HAVE_UNICAP)       || \
    defined(HAVE_PVAPI)        || \
    defined(HAVE_OPENNI)       || \
    defined(HAVE_OPENNI2)      || \
    defined(HAVE_XIMEA)        || \
    defined(HAVE_AVFOUNDATION) || \
    defined(HAVE_GIGE_API) || \
    defined(HAVE_INTELPERC)    || \
    (0)
        // local variable to memorize the captured device
        CvCapture *capture;
#endif

        switch (domains[i])
        {
#ifdef WINRT_8_1
        case CV_CAP_WINRT:
            capture = cvCreateCameraCapture_WinRT (index);
            if (capture)
                return capture;
            break;
#endif
#ifdef HAVE_MSMF
        case CV_CAP_MSMF:
             capture = cvCreateCameraCapture_MSMF (index);
             if (capture)
                 return capture;
            break;
#endif
#ifdef HAVE_TYZX
        case CV_CAP_STEREO:
            capture = cvCreateCameraCapture_TYZX (index);
            if (capture)
                return capture;
            break;
#endif
        case CV_CAP_VFW:
#ifdef HAVE_VFW
            capture = cvCreateCameraCapture_VFW (index);
            if (capture)
                return capture;
#endif
#if defined HAVE_LIBV4L || defined HAVE_CAMV4L || defined HAVE_CAMV4L2 || defined HAVE_VIDEOIO
            capture = cvCreateCameraCapture_V4L (index);
            if (capture)
                return capture;
#endif

#ifdef HAVE_GSTREAMER
            capture = cvCreateCapture_GStreamer(CV_CAP_GSTREAMER_V4L2, 0);
            if (capture)
            {
                cap.reset(capture);
                // assume it is opened
                return true;
            }
        }
    }
    return false;
}

bool VideoCapture::open(const String& filename)
{
    CV_TRACE_FUNCTION();

    return open(filename, CAP_ANY);
}

bool  VideoCapture::open(int cameraNum, int apiPreference)
{
    CV_TRACE_FUNCTION();

    if (isOpened()) release();

    const std::vector<VideoBackendInfo> backends = cv::videoio_registry::getAvailableBackends_CaptureByIndex();
    for (size_t i = 0; i < backends.size(); i++)
    {
        const VideoBackendInfo& info = backends[i];
        if (apiPreference == CAP_ANY || apiPreference == info.id)
        {
            CvCapture* capture = NULL;
            VideoCapture_create(capture, icap, info.id, cameraNum);
            if (!icap.empty())
            {
                if (icap->isOpened())
                    return true;
                icap.release();
            }
            if (capture)
            {
                cap.reset(capture);
                // assume it is opened
                return true;
            }
        }
    }
    return false;
}

bool VideoCapture::open(int index)
{
    CV_TRACE_FUNCTION();

    // interpret preferred interface (0 = autodetect)
    int backendID = (index / 100) * 100;
    if (backendID)
    {
        index %= 100;
    }

    return open(index, backendID);
}

bool VideoCapture::isOpened() const
{
    if (!icap.empty())
        return icap->isOpened();
    return !cap.empty();  // legacy interface doesn't support closed files
}

void VideoCapture::release()
{
    CV_TRACE_FUNCTION();
    icap.release();
    cap.release();
}

bool VideoCapture::grab()
{
    CV_INSTRUMENT_REGION()

    if (!icap.empty())
        return icap->grabFrame();
    return cvGrabFrame(cap) != 0;
}

bool VideoCapture::retrieve(OutputArray image, int channel)
{
    CV_INSTRUMENT_REGION()

    if (!icap.empty())
        return icap->retrieveFrame(channel, image);

    IplImage* _img = cvRetrieveFrame(cap, channel);
    if( !_img )
    {
        image.release();
        return false;
    }
    if(_img->origin == IPL_ORIGIN_TL)
        cv::cvarrToMat(_img).copyTo(image);
    else
    {
        Mat temp = cv::cvarrToMat(_img);
        flip(temp, image, 0);
    }
    return true;
}

bool VideoCapture::read(OutputArray image)
{
    CV_INSTRUMENT_REGION()

    if(grab())
        retrieve(image);
    else
        image.release();
    return !image.empty();
}

VideoCapture& VideoCapture::operator >> (Mat& image)
{
#ifdef WINRT_VIDEO
    // FIXIT grab/retrieve methods() should work too
    if (grab())
    {
        if (retrieve(image))
        {
            std::lock_guard<std::mutex> lock(VideoioBridge::getInstance().inputBufferMutex);
            VideoioBridge& bridge = VideoioBridge::getInstance();

            // double buffering
            bridge.swapInputBuffers();
            auto p = bridge.frontInputPtr;

            bridge.bIsFrameNew = false;

            // needed here because setting Mat 'image' is not allowed by OutputArray in read()
            Mat m(bridge.getHeight(), bridge.getWidth(), CV_8UC3, p);
            image = m;
        }
    }
#else
    read(image);
#endif
    return *this;
}

VideoCapture& VideoCapture::operator >> (UMat& image)
{
    CV_INSTRUMENT_REGION()

    read(image);
    return *this;
}

bool VideoCapture::set(int propId, double value)
{
    if (!icap.empty())
        return icap->setProperty(propId, value);
    return cvSetCaptureProperty(cap, propId, value) != 0;
}

double VideoCapture::get(int propId) const
{
    if (!icap.empty())
        return icap->getProperty(propId);
    return cap ? cap->getProperty(propId) : 0;
}


//=================================================================================================



VideoWriter::VideoWriter()
{}

VideoWriter::VideoWriter(const String& filename, int _fourcc, double fps, Size frameSize, bool isColor)
{
    open(filename, _fourcc, fps, frameSize, isColor);
}


VideoWriter::VideoWriter(const String& filename, int apiPreference, int _fourcc, double fps, Size frameSize, bool isColor)
{
    open(filename, apiPreference, _fourcc, fps, frameSize, isColor);
}

void VideoWriter::release()
{
    iwriter.release();
    writer.release();
}

VideoWriter::~VideoWriter()
{
    release();
}

bool VideoWriter::open(const String& filename, int _fourcc, double fps, Size frameSize, bool isColor)
{
    return open(filename, CAP_ANY, _fourcc, fps, frameSize, isColor);
}

bool VideoWriter::open(const String& filename, int apiPreference, int _fourcc, double fps, Size frameSize, bool isColor)
{
    CV_INSTRUMENT_REGION()

    if (isOpened()) release();

    const std::vector<VideoBackendInfo> backends = cv::videoio_registry::getAvailableBackends_Writer();
    for (size_t i = 0; i < backends.size(); i++)
    {
        const VideoBackendInfo& info = backends[i];
        if (apiPreference == CAP_ANY || apiPreference == info.id)
        {
            CvVideoWriter* writer_ = NULL;
            VideoWriter_create(writer_, iwriter, info.id, filename, _fourcc, fps, frameSize, isColor);
            if (!iwriter.empty())
            {
                if (iwriter->isOpened())
                    return true;
                iwriter.release();
            }
            if (writer_)
            {
                // assume it is opened
                writer.reset(writer_);
                return true;
            }
        }
    }
    return false;
}

bool VideoWriter::isOpened() const
{
    return !iwriter.empty() || !writer.empty();
}


bool VideoWriter::set(int propId, double value)
{
    if (!iwriter.empty())
        return iwriter->setProperty(propId, value);
    return false;
}

double VideoWriter::get(int propId) const
{
    if (!iwriter.empty())
        return iwriter->getProperty(propId);
    return 0.;
}

void VideoWriter::write(const Mat& image)
{
    CV_INSTRUMENT_REGION()

    if( iwriter )
        iwriter->write(image);
    else
    {
        IplImage _img = image;
        cvWriteFrame(writer, &_img);
    }
}

VideoWriter& VideoWriter::operator << (const Mat& image)
{
    CV_INSTRUMENT_REGION()

    write(image);
    return *this;
}

// FIXIT OpenCV 4.0: make inline
int VideoWriter::fourcc(char c1, char c2, char c3, char c4)
{
    return (c1 & 255) + ((c2 & 255) << 8) + ((c3 & 255) << 16) + ((c4 & 255) << 24);
}

} // namespace
