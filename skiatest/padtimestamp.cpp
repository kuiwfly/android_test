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
	mPaint.setColor(SK_ColorBLACK) ;
	
	SkCanvas mCanvas(mBmp) ;
	mCanvas.drawText(str_stamp,10,5,5,mPaint) ;
	
	return 1 ;
}
void save_image(uint8_t *img, uint32_t width, uint32_t height)
{
	if(src == NULL) {
		return  ;
	}
	SkBitmap mBmp ;
	
	mBmp.setConfig(SkBitmap::kARGB_8888_Config,width,height) ;
	mBmp.setPixels(src,NULL) ;
	SkImageEncoder::EncodeFile("system/bin/snapshot.png",mBmp,
		SkImageEncoder::kPNG_Type,
		100) ;
}
}
