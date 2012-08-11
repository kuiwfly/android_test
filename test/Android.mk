LOCAL_PATH :=$(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE_TAGS :=optional

LOCAL_SRC_FILES :=$(call all-subdir-c-files)
LOCAL_MODULE :=main
include $(BUILD_EXECUTABLE)
