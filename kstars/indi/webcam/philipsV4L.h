/*
    Phlips webcam driver
    Copyright (C) 2004 by Jasem Mutlaq

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#ifndef PHILIPS_V4L_H
#define PHILIPS_V4L_H

#include <stdio.h>
#include <stdlib.h>
#include <linux/videodev.h>

/*int device_;
unsigned long options_;
struct video_capability capability_;
struct video_window window_;
struct video_picture picture_;
/// mmap stuf
struct video_mbuf mmap_mbuf_;
unsigned char * mmap_buffer_;
unsigned char * tmpBuffer_;
long mmap_last_sync_buff_;
long mmap_last_capture_buff_;  
bool grey_;
int frameRate_;
bool usingTimer;
bool streamActive;
unsigned char * YBuf,*UBuf,*VBuf, *colorBuffer;*/
 
//static QCam * openBestDevice(const char * devpath = "/dev/video0");
int connectPhilips(const char * devpath="/dev/video0", int preferedPalette = 0);

/* Philips related, from QAstrocam */
int    saveSettings(char *errmsg);
void   restoreSettings();
void   restoreFactorySettings();
int    setGain(int value, char *errmsg);
int    getGain();
int    setExposure(int val, char *errmsg);
void   setCompression(int value);
int    getCompression();
int    setNoiseRemoval(int value, char *errmsg);
int    getNoiseRemoval();
int    setSharpness(int value, char *errmsg);
int    getSharpness();
int    setBackLight(bool val, char *errmsg);
bool   getBackLight();
int    setFlicker(bool val, char *errmsg);
bool   getFlicker();
void   setGama(int value);
int    getGama();
int    setFrameRate(int value, char *errmsg);
int    getFrameRate();
int    setWhiteBalance(char *errmsg);
int    getWhiteBalance();
int    setWhiteBalanceMode(int val, char *errmsg);
int    setWhiteBalanceRed(int val, char *errmsg);
int    setWhiteBalanceBlue(int val, char *errmsg);

/* TODO consider the SC modded cam after this
void setLongExposureTime(const QString& str);
void setFrameRateMultiplicateur(int value);*/


/* Updates */
void updatePhilipsFrame(int d, void *p);
void callPhilipsFrame(void *p);

/* Image Size */
void checkPhlipsSize(int & x, int & y);
bool setPhilipsSize(int x, int y);

#endif
