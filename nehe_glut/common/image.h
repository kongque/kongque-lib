/*************************************************************/
/*                          IMAGE.H                          */
/*                                                           */
/* Purpose: Definitions for the CImage class, image loading  */
/*          saving, and manipulation routines.               */
/*      Evan Pipho (evan@codershq.com)                       */
/*                                                           */
/*************************************************************/
#ifndef IMAGE_H
#define IMAGE_H

//-------------------------------------------------------------
//                          CImage                            -
// author: Evan Pipho (evan@codershq.com)                     -
// date  : Jul 10, 2002                                       -
//-------------------------------------------------------------
class CImage
{
public:

	//Load the image
	bool Load(char * szFilename, bool bMipmap = true);
	//Flip image
	void VFlip(unsigned char * ucpData, unsigned int uiHeight, unsigned int uiWidth, unsigned int uiBpp); //Vertically

	//Get image data
	unsigned char* getImageData() const;

	unsigned int getImageWidth() const;
	unsigned int getImageHeight() const;

	//Constructors
	CImage()
	{
		m_szFilename = 0;
		m_ucpBuffer = 0;
	}
	
	CImage(char * szFile, bool bMipMap = true)
	{
		m_ucpBuffer = 0;
		m_szFilename = 0;
		Load(szFile, bMipMap);
	}

	~CImage()
	{
	}

private:


	//Load various image formats
	bool LoadTGA(bool bCompressed);
	bool LoadBMP();
	bool LoadPCX();

	//dimentions
	unsigned int m_uiWidth;
	unsigned int m_uiHeight;
	unsigned int m_uiFileLen; //needed for PCX
	//Image ID
	unsigned int m_uiImage;
	//file buffer
	unsigned char * m_ucpBuffer;
	//mipmap?
	bool m_bMipMap;
	//filename
	char * m_szFilename;
};

#endif //IMAGE_H
