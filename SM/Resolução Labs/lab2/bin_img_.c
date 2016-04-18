void bin_img(unsigned char *ptr, int w, int h, unsigned char limiar)
{
	int size=w*h, c=0;
	
	while (c++<size)
	{
		if (*ptr<limiar) *ptr=0; else *ptr=255;
		++ptr;
	}
}

