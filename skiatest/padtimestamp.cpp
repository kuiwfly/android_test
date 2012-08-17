#include <SkBitmap.h>
#include <SkPaint.h>
#include <SkCanvas.h>
#include <SkImageEncoder.h>
extern "C"
{
uint8_t get_timestamp_pad(uint8_t *src, char *str_stamp, uint32_t width, uint32_t height)
{
	if(src == NULL | str_stamp == NULL){
		return 0 ;
	}
	SkBitmap mBmp ;
	mBmp.setConfig(SkBitmap::kARGB_8888_Config,width,height) ;
	mBmp.setPixels(src,NULL) ;

	SkPaint mPaint ;
	mPaint.setColor(SK_ColorRED) ;
	mPaint.setTextSize(40) ;

	SkCanvas mCanvas(mBmp) ;
	mCanvas.drawText(str_stamp,strlen(str_stamp),5,50,mPaint) ;
	
	return 1 ;
}
void save_image(uint8_t *img, uint32_t width, uint32_t height)
{
	if(img == NULL) {
		return  ;
	}
	SkBitmap mBmp ;
	
	mBmp.setConfig(SkBitmap::kARGB_8888_Config,width,height) ;
	mBmp.setPixels(img,NULL) ;
	SkImageEncoder::EncodeFile("system/bin/snapshot.jpg",mBmp,
		SkImageEncoder::kJPEG_Type,
		100) ;
}
}
