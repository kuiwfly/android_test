#include <stdio.h>
#include <SkBitmap.h>
#include <SkDevice.h>
#include <SkPaint.h>
#include <SkRect.h>
#include <SkImageEncoder.h>
#include <SkCanvas.h>
int main()
{
	printf("hello world!i\n") ;
        SkBitmap bitmap;
        bitmap.setConfig(SkBitmap::kARGB_8888_Config, 200, 200);
        bitmap.allocPixels();
	SkCanvas canvas(bitmap);
	SkPaint paint;
        SkRect r;
/*
        paint.setARGB(255, 255, 0, 0);
        r.set(25, 25, 145, 145);
        canvas.drawRect(r, paint);

 
        paint.setARGB(255, 0, 255, 0);
        r.offset(20, 20);
        canvas.drawRect(r, paint);
        paint.setARGB(255, 0, 0, 255);
        r.offset(20, 20);
        canvas.drawRect(r, paint);
*/
//	paint.setARGB(0,255,0,0) ;
	paint.setColor(SK_ColorRED) ;
	canvas.drawText("hello world!",10,25,25,paint) ;
        SkImageEncoder::EncodeFile("/system/bin/snapshot.png", bitmap,
               SkImageEncoder::kPNG_Type,
               100);
	return 0 ;
}
