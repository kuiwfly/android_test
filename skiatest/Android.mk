###############################
# Build Shared library
###############################
LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS :=optional
LOCAL_SRC_FILES := \
	padtimestamp.cpp
LOCAL_C_INCLUDES :=\
        external/skia/include/core \
        external/skia/include/effects \
        external/skia/include/images \
        external/skia/include/ports \
        external/skia/include/utils \
        external/skia/src/core

LOCAL_SHARED_LIBRARIES :=\
   libskia libcutils
 
#LOCAL_STATIC_LIBARIES :=\
    libskiagpu

LOCAL_PRELINK_MODULE :=false 
LOCAL_MODULE:= libpadtimestamp
include $(BUILD_SHARED_LIBRARY)

################################
# Build Application
###############################
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULES_TAGS :=optional

LOCAL_SRC_FILES := \
	main.c

LOCAL_SHARED_LIBRARIES :=\
	libpadtimestamp	

LOCAL_PRELINK_MODULE :=false 
LOCAL_MODULE:= testskia
include $(BUILD_EXECUTABLE)


