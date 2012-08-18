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
	int tmp_width = 1920 ;
	int tmp_height = 1080 ;

	int pad_width = 200 ;
	int pad_height = 50 ;
	
	SkBitmap mSrcBmp  ;
	mSrcBmp.setConfig(SkBitmap::kARGB_8888_Config,tmp_width ,tmp_height) ;
	mSrcBmp.allocPixels() ;
	
	SkBitmap mPadBmp ;
	mPadBmp.setConfig(SkBitmap::kARGB_8888_Config,pad_width ,pad_height) ;
	mPadBmp.allocPixels() ;
	
	SkPaint mPaint ;
	mPaint.setColor(SK_ColorRED) ;
	mPaint.setTextSize(35) ;
	
	
	SkCanvas mCanvas(mPadBmp) ;
	mCanvas.drawText(str_stamp,strlen(str_stamp),5,50,mPaint) ;

	int *p_src = (int*)mSrcBmp.getPixels() ;
	int *p_pad = (int*)mPadBmp.getPixels() ;
	int pad_horizon_x = 0 ;
	int pad_horizon_y = 0 ;
	int pad_vertical_x = 500 ;
	int pad_vertical_y = 500 ;
	int *tmp_src = p_src + pad_horizon_x + pad_horizon_y * tmp_width;
	int *tmp_pad = p_pad ;
/*no rotate*/
	for(int i=0;i<pad_height;i++) {
		for(int j=0 ;j<pad_width ;j++){
			*tmp_src++ = *tmp_pad++ ;
		}
		tmp_src += tmp_width - pad_width + pad_horizon_x;
	}
	tmp_src = p_src +  pad_vertical_y*tmp_width;
	tmp_pad = p_pad ;
/*rotate 90*/
	for(int i=0;i<pad_height;i++){
		for(int j=0;j<pad_width;j++) {
			tmp_src[j*tmp_width+i+pad_vertical_x]=*tmp_pad++ ;
		}
	}

	int pad180_x = 250 ;
	int pad180_y = 250 ;
	int pad270_x = 750 ;
	int pad270_y = 750 ;

	tmp_src = p_src + pad180_y * tmp_width;
	tmp_pad = p_pad ;
/*rotate 180*/
	for(int i=0;i<pad_height;i++){
		for(int j=0;j<pad_width;j++){
			tmp_src[i*tmp_width+pad_width-j+pad180_x] = *tmp_pad++ ;	
		}
	}

	tmp_src = p_src + pad270_y * tmp_width ;
	tmp_pad = p_pad ;
/*rotate 270*/
	for(int i=0;i<pad_height;i++){
		for(int j=0;j<pad_width;j++){
			tmp_src[(pad_width-j)*tmp_width+i+pad270_x] = *tmp_pad++ ;
		}
	}
	SkImageEncoder::EncodeFile("system/bin/snapshot.jpg",mSrcBmp,
		SkImageEncoder::kJPEG_Type,
		100) ;
/*	
	SkBitmap mBmp ;
	mBmp.setConfig(SkBitmap::kARGB_8888_Config,width,height) ;
	mBmp.setPixels(src,NULL) ;

	SkPaint mPaint ;
	mPaint.setColor(SK_ColorRED) ;
	mPaint.setTextSize(40) ;

	SkCanvas mCanvas(mBmp) ;
	mCanvas.drawText(str_stamp,strlen(str_stamp),5,50,mPaint) ;
*/	
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
