#include <stdio.h>
#include <dlfcn.h>
uint8_t (*get_timestamp_pad)(uint8_t *src, char *str_stamp,
	uint32_t width, uint32_t height) ;
void (*save_image)(uint8_t *img, uint32_t width, uint32_t height) ;
int main()
{
	int width = 300 ;
	int height = 50 ;
	uint8_t *ptr_src = (uint8_t*)malloc(width*height*3) ;
	memset(ptr_src,255,width*height*3) ;
	
	void *dp = dlopen("libpadtimestamp") ;
	if(dp == NULL) {
		printf("Get shared library failed!\n") ;
		return -1 ;
	}
	get_timestamp_pad = dlsym(dp,"get_timestamp_pad") ;
	save_image = dlsym(dp, "save_image") ;

	if(get_timestamp_pad(ptr_src,"hello world",width,height)==0) {
		printf("get pad failed!\n") ;
		return -1 ;	
	}
	save_image(ptr_src,width,height) ;
	return 0 ;
}
