#include "Texture.h"


Texture::Texture()
{
}
Texture::~Texture()
{
}

bool Texture::Load(const std::string& filename)
{
	m_PixData = OpenImageDevIL(filename, m_width, m_height, m_dis);
	if (!m_PixData)
	{
		return false;
	}
	glEnable(GL_TEXTURE_2D);
	if (m_nHandle < 0)
	{
		glGenTextures(1, &m_nHandle);
	}
	glBindTexture(GL_TEXTURE_2D, m_nHandle);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glPixelStorei(GL_PACK_ALIGNMENT, 1);

	LoadData(GL_TEXTURE_2D, m_PixData, m_width, m_height, m_dis);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//当所显示的纹理比加载进来的纹理小时，采用GL_LINEAR的方法来处理
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//当所显示的纹理比加载进来的纹理大时，采用GL_LINEAR的方法来处理

//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
/*	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);*/

	glBindTexture(GL_TEXTURE_2D, 0);

	return true;
}

bool Texture::SaveDIB(FIBITMAP *dib, char *lpszPath, int flag)
{

	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

	bool bSuccess = FALSE;

	fif = FreeImage_GetFIFFromFilename(lpszPath);

	if (fif != FIF_UNKNOWN)
	{

		bool bCanSave;

		FREE_IMAGE_TYPE image_type = FreeImage_GetImageType(dib);

		if (image_type == FIT_BITMAP)
		{

			int bpp = FreeImage_GetBPP(dib);

			bCanSave = (FreeImage_FIFSupportsWriting(fif) && FreeImage_FIFSupportsExportBPP(fif, bpp));

		}

		else
		{

			bCanSave = FreeImage_FIFSupportsExportType(fif, image_type);

		}

		if (bCanSave) bSuccess =FreeImage_Save(fif, dib, lpszPath, flag);

	}

	return bSuccess;
}

void Texture::SaveImage(char *imgpath)
{
	/*
	int img_widht,img_height;
	unsigned char *mpixels =new unsigned char[640*480*3];
	FREE_IMAGE_FORMAT fif =FIF_PNG;
	BOOL bSuccess = FALSE;

	glReadBuffer(GL_FRONT);
	glReadPixels(0, 0, 640, 480, GL_RGB, GL_UNSIGNED_BYTE, mpixels);
	glReadBuffer(GL_BACK);
	for(int i=0; i<(int)640*480*3; i+=3)
	{
	//repeated xor to swap bytes
	mpixels[i] ^= mpixels[i+2] ^= mpixels[i] ^= mpixels[i+2];
	}
	FIBITMAP* bitmap = FreeImage_ConvertFromRawBits(mpixels,640,480,1024,24,8,8,8,FALSE);
	//FIBITMAP *dibsave = FreeImage_Load(FIF_PNG,"img/default.png", 0);
	//FIBITMAP *dibsave =FreeImage_Allocate(FIF_PNG,800,800,32);
	//img_widht=FreeImage_GetWidth(dibsave);
	//img_height=FreeImage_GetHeight(dibsave);


	bSuccess = FreeImage_Save(FIF_PNG, bitmap, "gg1.png", PNG_DEFAULT);
	FreeImage_Unload(bitmap);
	delete[] mpixels;*/
	unsigned char *mpixels = new unsigned char[800 * 600 * 4];
	glReadBuffer(GL_FRONT);
	glReadPixels(0, 0, 800, 600, GL_RGBA, GL_UNSIGNED_BYTE, mpixels);
	glReadBuffer(GL_BACK);
	for (int i = 0; i<(int)800 * 600 * 4; i += 4)
	{

		mpixels[i] ^= mpixels[i + 2] ^= mpixels[i] ^= mpixels[i + 2];
	}
	FIBITMAP* bitmap = FreeImage_Allocate(800, 600, 32, 8, 8, 8);

	for (int y = 0; y<FreeImage_GetHeight(bitmap); y++)
	{
		BYTE *bits = FreeImage_GetScanLine(bitmap, y);
		for (int x = 0; x<FreeImage_GetWidth(bitmap); x++)
		{
			bits[0] = mpixels[(y * 800 + x) * 4 + 0];
			bits[1] = mpixels[(y * 800 + x) * 4 + 1];
			bits[2] = mpixels[(y * 800 + x) * 4 + 2];
			bits[3] = 255;
			bits += 4;

		}

	}
	bool bSuccess = FreeImage_Save(FIF_PNG, bitmap, imgpath, PNG_DEFAULT);
	FreeImage_Unload(bitmap);

//	return bSuccess;
}

bool Texture::SaveImage(const unsigned char* ptr, std::string& filename, int flag, int w /*= 640*/, int h /*= 480*/, int dpp /*= 24*/)
{
	FreeImage_Initialise(true);
	FIBITMAP* dib = FreeImage_ConvertFromRawBits((BYTE*)ptr, w, h, w * (dpp / 8), dpp, 0x0000FF, 0xFF0000, 0x00FF00, FALSE);
	
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

	bool bSuccess = FALSE;

	fif = FreeImage_GetFIFFromFilename(filename.c_str());

	if (fif != FIF_UNKNOWN)
	{

		bool bCanSave;

		FREE_IMAGE_TYPE image_type = FreeImage_GetImageType(dib);

		if (image_type == FIT_BITMAP)
		{

			int bpp = FreeImage_GetBPP(dib);

			bCanSave = (FreeImage_FIFSupportsWriting(fif) && FreeImage_FIFSupportsExportBPP(fif, bpp));

		}

		else
		{

			bCanSave = FreeImage_FIFSupportsExportType(fif, image_type);

		}

		if (bCanSave) bSuccess = FreeImage_Save(fif, dib, filename.c_str(), flag);

	}
	FreeImage_Unload(dib);
	return bSuccess;
	
	
	/*bool bSuccess = FreeImage_Save(FIF_JPEG, bitmap, filename.c_str, JPEG_DEFAULT);*/
	

}

void Texture::LoadData(GLenum target, GLubyte* ptr, unsigned int w, unsigned int h, unsigned int d)
{
	glTexImage2D(target, 0, d == 3 ? GL_RGB : GL_RGBA, w, h, 0, d == 3 ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, ptr);
}

void Texture::Bind(GLuint slot)  {
	glActiveTexture(GL_TEXTURE0 + slot);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_nHandle);
}


void Texture::Bind()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_nHandle);
}
void Texture::UnBind()  {
	glBindTexture(GL_TEXTURE_2D, 0);
}
void Texture::UnBind(GLuint slot)  {
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLubyte* Texture::OpenImageDevIL(const std::string& filename, unsigned int& w, unsigned int& h, unsigned int& d)
{
#if 0
#ifdef FREEIMAGE_LIB
	FreeImage_Initialise();
#endif // FREEIMAGE_LIB


	FIBITMAP* bitmap;
	FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(filename, 0);

	if (fif == FIF_UNKNOWN)
	{
		fif = FreeImage_GetFIFFromFilename(filename);
	}
	if (fif != FIF_UNKNOWN && FreeImage_FIFSupportsReading(fif))
	{
		bitmap = FreeImage_Load(fif, filename);
	}
	else{
		bitmap = nullptr;
	}

	if (bitmap)
	{
		w = FreeImage_GetWidth(bitmap);
		h = FreeImage_GetHeight(bitmap);
		unsigned short pixel_size = FreeImage_GetBPP(bitmap);
		unsigned char* data = (unsigned char*)FreeImage_GetBits(bitmap);
		if (pixel_size == 24)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGR, GL_UNSIGNED_BYTE, (GLvoid*)data);
		}else if (pixel_size == 32)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, (GLvoid*)data);

		}
		else{
			std::cerr << "pixel size = " << pixel_size << " don't know how to process this case. I'm out!" << std::endl;
			exit(-1);
		}
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	else{
		std::cerr << "Unable to load the image file " << fname << " I'm out!" << std::endl;
		exit(-1);
	}
	FreeImage_Unload(bitmap);
#ifdef FREEIMAGE_LIB
	FreeImage_DeInitialise();
#endif	

#endif

	FreeImage_Initialise(TRUE);
	// active only for static linking
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	const char* lpszPathName = filename.c_str();
	fif = FreeImage_GetFileType(lpszPathName);

	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(lpszPathName);
	if ((fif != FIF_UNKNOWN) && FreeImage_FIFSupportsReading(fif)){
		FIBITMAP *bitmap = FreeImage_Load(fif, lpszPathName);
		FIBITMAP * bitmap_temp = 0;
		unsigned char * data = 0;
		w = FreeImage_GetWidth(bitmap);
		h = FreeImage_GetHeight(bitmap);
		// 计算每个像素的字节数
		/************************************************************************/
		/* 已经测试有JPEG格式：每像素字节数3                                      */
		/* 已经测试有JPEG格式：每像素字节数4                                      */
		/************************************************************************/
		d = FreeImage_GetLine(bitmap) / w;
		unsigned short channels = 1;
		unsigned short depth = FreeImage_GetBPP(bitmap);
		printf("Width:%d\t Height:%d\t 每像素字节数:%d\n", w, h, d);
		if (bitmap) printf("Image Load successfully!\n");

		if (depth < 8) {
			//只能创建 8 位的图像
			depth = 8;
			if (NULL != (bitmap_temp = FreeImage_ConvertToGreyscale(bitmap))) {
				data = FreeImage_GetBits(bitmap_temp);
			}
		}
		else {
			assert(depth % 8 == 0);
			channels = depth / 8;
			depth = 8;
			data = FreeImage_GetBits(bitmap);
		}
		GLubyte* img = new GLubyte[(size_t)(w)* (size_t)(h)* (size_t)(d)];
		memcpy(img, data, (size_t)(w)* (size_t)(h)* (size_t)(d));

		FreeImage_DeInitialise();
		return (GLubyte*)img;
	}
	return nullptr;

}


