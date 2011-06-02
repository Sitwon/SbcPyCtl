/**
 * @file	dfvifc_c.h
 * @brief	SBC C Interface
 *
 * @author	Antenna House, Inc.
 *
 * Copyright (C) 2002-2009 Antenna House, Inc. All rights reserved.
 */

#ifndef DFVIFC_C_H__
#define DFVIFC_C_H__

#include <stddef.h>

#if !defined(_DOXYGEN) && defined(_MSC_VER) && defined(_WIN32)
	#ifdef DFVINTERFACE_EXPORTS
		#define DFVINTERFACE_API	__declspec( dllexport )
	#else
		#define DFVINTERFACE_API	__declspec( dllimport )
	#endif
#else
	#define DFVINTERFACE_API
#endif

/**
 * Error Code
 */
typedef long DfvIfErrorCode;	/* 0 means no error */

/**
 * Error Level
 */
typedef enum {
	ELVL_NORMAL			= 0,	/* no error */
	ELVL_INFORMATION	= 1,
	ELVL_WARNING		= 2,
	ELVL_RECOVERABLE	= 3,
	ELVL_FATAL			= 4
} DfvIfErrorLevel;

/**
 * Error Stream Type for MessageListener
 */
typedef enum {
	EST_NONE,				/* no output */
	EST_STDOUT,				/* output to stdout */
	EST_STDERR				/* output to stderr */
} DfvErrorStreamType;

/**
 * PDF version
 */
typedef enum  {
	PDF_13,					/* PDF 1.3 */
	PDF_14,					/* PDF 1.4 */
	PDF_15,					/* PDF 1.5 */
	PDF_16,					/* PDF 1.6 */
	PDF_17,					/* PDF 1.7 */
	PDFX_1a_2001= 101,		/* ISO 15930-1:2001 PDF/X-1a-2001 (based on PDF1.3) */
	PDFX_3_2002	= 103,		/* ISO 15930-3:2002 PDF/X-3-2002  (based on PDF1.3) */
	PDFX_1a_2003= 104,		/* ISO 15930-4:2003 PDF/X-1a-2003 (based on PDF1.4) */
	PDFX_2_2003	= 105,		/* ISO 15930-5:2003 PDF/X-2-2003  (based on PDF1.4) */
	PDFX_3_2003	= 106,		/* ISO 15930-6:2003 PDF/X-3-2003  (based on PDF1.4) */
	PDFA_1a_2005= 200,		/* ISO 19005-1:2005 (based on PDF1.4) */
	PDFA_1b_2005= 400		/* ISO 19005-1:2005 (based on PDF1.4) */
} DfvPDFVERSION;

/**
 * PDF encrypt level
 */
typedef enum  {
	ENCLEVEL_40,			/* 40-bit RC4 */
	ENCLEVEL_128			/* 128-bit RC4 */
} DfvPDFENCRYPTLEVEL;

/**
 * PDF print allow
 */
typedef enum {
	PRALLOW_NONE,			/* not allowed */
	PRALLOW_LOW,			/* low resolution printing */
	PRALLOW_HIGH			/* high resolution printing */
} DfvPDFPRINTALLOW;

/**
 * PDF image compression
 */
typedef enum {
	IMGCMPR_AUTO,			/* auto */
	IMGCMPR_JPEG,			/* JPEG */
	IMGCMPR_ZLIB,			/* ZLIB */
	IMGCMPR_JPEG2K			/* JPEG2000 */
} DfvPDFIMAGECOMPRESSION;

/**
 * PDF RGB conversion
 */
typedef enum {
	RGBCONV_NONE,			/* no conversion */
	RGBCONV_BLACK,			/* black to devicegray */
	RGBCONV_GRAY,			/* gray to devicegray */
	RGBCONV_ALL				/* all rgb to devicegray */
} DfvPDFRGBCONVERSION;

/**
 * Embed font
 */
typedef	enum {
	EMBALLFONT_PART,		/* specified fonts */
	EMBALLFONT_ALL,			/* all fonts except Base14 fonts */
	EMBALLFONT_BASE14		/* all fonts */
} DfvEMBEDALLFONT;

/**
 * Image downsampling
 */
typedef	enum {
	IMGDOWNSAMPLING_NONE,		/* no downsampling */
	IMGDOWNSAMPLING_AVERAGE,	/* average downsampling */
	IMGDOWNSAMPLING_BICUBIC,	/* bicubic downsampling */
	IMGDOWNSAMPLING_SUBSAMPLING	/* subsampling */
} DfvIMAGEDOWNSAMPLING;

/**
 * Monochrome compression
 */
typedef	enum {
	MONOCMPR_CCITT4,		/* CCITTFaxDecode group 4 filter,default value */
	MONOCMPR_CCITT3,		/* CCITTFaxDecode group 3 filter */
	MONOCMPR_RUNLENGTH,		/* RunLengthDecode filter */
	MONOCMPR_ZLIB,			/* FlateDecode filter */
	MONOCMPR_OFF			/* no filter */
} DfvMONOCHROMECOMPRESSION;

/**
 * SVG version
 */
typedef	enum {
	SVG_11,					/* SVG 1.1 */
	SVG_Basic,				/* SVG Basic */
	SVG_Tiny				/* SVG Tiny */
} DfvSVGVERSION;

/**
 * Image processing
 */
typedef	enum {
	IMGPT_EMBED_ALL,		/* embed all */
	IMGPT_COPY_ALL,			/* copy all */
	IMGPT_LINK,				/* link */
	IMGPT_COPY				/* copy */
} DfvIMAGEPROCTYPE;

/**
 * Image conversion
 */
typedef enum {
	IMGCNV_AUTO,			/* auto */
	IMGCNV_JPEG,			/* jpeg conversion except png */
	IMGCNV_PNG,				/* png conversion except jpeg */
	IMGCNV_JPEGALL			/* jpeg-all conversion */
} DfvIMAGECONVERSION;

/**
 * INX output mode
 */
typedef	enum  {
	INXOM_TEXT,				/* text area output mode */
	INXOM_LINE,				/* line area output */
	INXOM_BLOCK				/* block area output */
} DfvINXOUTPUTMODE;

/**
 * MIF output mode
 */
typedef	enum  {
	MIFOM_TEXT,				/* text area output mode */
	MIFOM_LINE,				/* line area output */
	MIFOM_BLOCK				/* block area output */
} DfvMIFOUTPUTMODE;

/***************************************************************
 * format information
 */

#ifdef __cplusplus
extern "C" {
#endif

/** Pointer to DfvObj instance. */
typedef void*	CDfvObjPtr;

/**
 * Error callback handler
 */
typedef void (DfvOnMessageProc)(DfvIfErrorLevel errLevel, DfvIfErrorCode errCode, const char* errMessage);
typedef void (DfvOnMessageProcW)(DfvIfErrorLevel errLevel, DfvIfErrorCode errCode, const wchar_t* errMessage);
typedef void (DfvOnFormatPageProc)(long pageNo);

typedef void (DfvOnMessageProcEx)(void* pAnyObj, DfvIfErrorLevel errLevel, DfvIfErrorCode errCode, const char* errMessage);
typedef void (DfvOnMessageProcExW)(void* pAnyObj, DfvIfErrorLevel errLevel, DfvIfErrorCode errCode, const wchar_t* errMessage);
typedef void (DfvOnFormatPageProcEx)(void* pAnyObj, long pageNo);

/**
 * Create instance of DfvObj
 *
 * @return	Pointer to DfvObj instance.
 */
DFVINTERFACE_API CDfvObjPtr dfv_createDfvObject();

/**
 * Release instance of DfvObj
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 */
DFVINTERFACE_API void dfv_releaseDfvObject(CDfvObjPtr pDfvObj);

/**
 * Get the URL of XML document you will format.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getDocumentURI(CDfvObjPtr pDfvObj, char* pVal, int size);
/**
 * Get the URL of XML document you will format.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getDocumentURIW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Specifies the URL of XML document you will format.
 * If it is omitted or "\@STDIN" is specified, XML document is loaded from stdin.
 * The document loaded from stdin are supposed to be FO files.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the URL of XSL document.
 */
DFVINTERFACE_API void dfv_setDocumentURI(CDfvObjPtr pDfvObj, const char* newVal);
/**
 * Specifies the URL of XML document you will format.
 * If it is omitted or "\@STDIN" is specified, XML document is loaded from stdin.
 * The document loaded from stdin are supposed to be FO files.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the URL of XSL document.
 */
DFVINTERFACE_API void dfv_setDocumentURIW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Get the path name of the output file.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getOutputFilePath(CDfvObjPtr pDfvObj, char* pVal, int size);
/**
 * Get the path name of the output file.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getOutputFilePathW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Specifies the path name of the output file. When "\@STDOUT" is specified, it is considered as stdout.
 * If both the printer name and  this property are specified, the formatted result will be stored in
 * the file by the printer driver.
 * When "\@PDF" is specified as output, the PDF is stored in the file specified by this property.
 * If the property is not specified, it is considered as stdout.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of the output file.
 */
DFVINTERFACE_API void dfv_setOutputFilePath(CDfvObjPtr pDfvObj, const char* newVal);
/**
 * Specifies the path name of the output file. When "\@STDOUT" is specified, it is considered as stdout.
 * If both the printer name and  this property are specified, the formatted result will be stored in
 * the file by the printer driver.
 * When "\@PDF" is specified as output, the PDF is stored in the file specified by this property.
 * If the property is not specified, it is considered as stdout.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of the output file.
 */
DFVINTERFACE_API void dfv_setOutputFilePathW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Get the path name of XML-format Option setting file which describes Server Based Converter options.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @param	n		Specifies to get n-th URI. 0 means first URI.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getOptionFileURI(CDfvObjPtr pDfvObj, char* pVal, int size, int n);
/**
 * Get the path name of XML-format Option setting file which describes Server Based Converter options.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @param	n		Specifies to get n-th URI. 0 means first URI.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getOptionFileURIW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size, int n);

/**
 * Specifies the path name of XML-format Option setting file which describes Server Based Converter options.
 * The set of former URIs is thrown away.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of XML-format Option setting file.
 */
DFVINTERFACE_API void dfv_setOptionFileURI(CDfvObjPtr pDfvObj, const char* newVal);
/**
 * Specifies the path name of XML-format Option setting file which describes Server Based Converter options.
 * The set of former URIs is thrown away.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of XML-format Option setting file.
 */
DFVINTERFACE_API void dfv_setOptionFileURIW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Append the path name of XML-format Option setting file which describes Server Based Converter options.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of XML-format Option setting file.
 */
DFVINTERFACE_API void dfv_addOptionFileURI(CDfvObjPtr pDfvObj, const char* newVal);
/**
 * Append the path name of XML-format Option setting file which describes Server Based Converter options.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of XML-format Option setting file.
 */
DFVINTERFACE_API void dfv_addOptionFileURIW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Get the number of URIs of XML-format Option setting file which describes Server Based Converter options.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	Returns the number of URIs.
 */
DFVINTERFACE_API int dfv_getOptionFileCount(CDfvObjPtr pDfvObj);

/**
 * Get the start page number of document to output.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	start page number of output.
 */
DFVINTERFACE_API long dfv_getStartPage(CDfvObjPtr pDfvObj);

/**
 * Specifies the start page number of document to output.
 * If the start page is omitted or the specified value is 0 or less, the start page is
 * considered from the first page.
 * If the setting is inconsistent, (for example, StartPage=5 EndPage=3) an error occurs.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	start page number of output.
 */
DFVINTERFACE_API void dfv_setStartPage(CDfvObjPtr pDfvObj, long newVal);

/**
 * Get the end page number of document to output.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	end page number of output.
 */
DFVINTERFACE_API long dfv_getEndPage(CDfvObjPtr pDfvObj);

/**
 * Specifies the end page number of document to output.
 * If the end page is omitted or the specified value exceeds the actual page number, the end page
 * is considered as the last page.
 * If the setting is inconsistent, (for example, StartPage=5 EndPage=3) an error occurs.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	end page number of output.
 */
DFVINTERFACE_API void dfv_setEndPage(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Specifies the owner password for PDF. The password must be within 32 bytes.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the owner password.
 */
DFVINTERFACE_API void dfv_setPdfOwnerPassword(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Specifies the owner password for PDF. The password must be within 32 bytes.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the owner password.
 */
DFVINTERFACE_API void dfv_setPdfOwnerPasswordW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Effective when outputting to PDF.
 * Specifies the user password for PDF. The password must be within 32 bytes.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the user password.
 */
DFVINTERFACE_API void dfv_setPdfUserPassword(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Specifies the user password for PDF. The password must be within 32 bytes.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the user password.
 */
DFVINTERFACE_API void dfv_setPdfUserPasswordW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Effective when outputting to PDF.
 * Disables printing the PDF file.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If nonezero is specified, Disables printing the PDF file.
 */
DFVINTERFACE_API void dfv_setPdfNoPrinting(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables printing the PDF file.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	If zero is returned, Enables printing the PDF file.
 * 			If nonezero is returned, Disables printing the PDF file.
 */
DFVINTERFACE_API long dfv_getPdfNoPrinting(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Disables making changes of the PDF file.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If nonezero is specified, Disables making changes of the PDF file.
 */
DFVINTERFACE_API void dfv_setPdfNoChanging(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables making changes of the PDF file.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	If zero is returned, Enables making changes of the PDF file.
 * 			If nonezero is returned, Disables making changes of the PDF file.
 */
DFVINTERFACE_API long dfv_getPdfNoChanging(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Disables copying the content of the PDF file.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If nonezero is specified, Disables copying the content of the PDF file.
 */
DFVINTERFACE_API void dfv_setPdfNoContentCopying(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables copying the content of the PDF file.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	If zero is returned, Enables copying the content of the PDF file.
 * 			If nonezero is returned, Disables copying the content of the PDF file.
 */
DFVINTERFACE_API long dfv_getPdfNoContentCopying(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Disables adding comments and form fields to the PDF file.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If nonezero is specified, Disables adding comments and form fields to the PDF file.
 */
DFVINTERFACE_API void dfv_setPdfNoAddingOrChangingCommnets(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables adding comments and form fields to the PDF file.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	If zero is returned, Enables adding comments and form fields to the PDF file.
 * 			If nonezero is returned, Disables adding comments and form fields to the PDF file.
 */
DFVINTERFACE_API long dfv_getPdfNoAddingOrChangingCommnets(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Disables adding comments and form fields to the PDF file.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If nonezero is specified, Disables adding comments and form fields to the PDF file.
 */
DFVINTERFACE_API void dfv_setPdfNoAddingOrChangingComments(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables adding comments and form fields to the PDF file.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	If zero is returned, Enables adding comments and form fields to the PDF file.
 * 			If nonezero is returned, Disables adding comments and form fields to the PDF file.
 */
DFVINTERFACE_API long dfv_getPdfNoAddingOrChangingComments(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Enables specifying whether the version of PDF is 1.3, 1.4 or 1.5.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Specifies the version of PDF.
 */
DFVINTERFACE_API void dfv_setPdfVersion(CDfvObjPtr pDfvObj, DfvPDFVERSION newVal);

/**
 * Effective when outputting to PDF.
 * Get the version of PDF.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the version of PDF.
 */
DFVINTERFACE_API DfvPDFVERSION	dfv_getPdfVersion(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Disables filling in of form fields and signing of the PDF file.
 * This parameter is effective only when you specify PDF1.4 or later to PDF version.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If nonezero is specified, Disables filling in of form fields and signing of the PDF file.
 */
DFVINTERFACE_API void dfv_setPdfNoFillForm(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables filling in of form fields and signing of the PDF file.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	If zero is returned, Enables filling in of form fields and signing of the PDF file.
 * 			If nonezero is returned, Disables filling in of form fields and signing of the PDF file.
 */
DFVINTERFACE_API long dfv_getPdfNoFillForm(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Disables text access for screen reader devices of the PDF file.
 * This parameter is effective only when you specify 1.4 or later with PDF version.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If nonezero is specified, Disables text access for screen reader devices of the PDF file.
 */
DFVINTERFACE_API void dfv_setPdfNoAccessibility(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables text access for screen reader devices of the PDF file.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	If zero is returned, Enables text access for screen reader devices of the PDF file.
 * 			If nonezero is returned, Disables text access for screen reader devices of the PDF file.
 */
DFVINTERFACE_API long dfv_getPdfNoAccessibility(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Disables inserting, deleting and rotating the PDF pages.
 * This parameter is effective only when you specify 1.4 or later with PDF version
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If nonezero is specified, Disables inserting, deleting and rotating the PDF pages.
 */
DFVINTERFACE_API void dfv_setPdfNoAssembleDoc(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables inserting, deleting and rotating the PDF pages.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	If zero is returned, Enables inserting, deleting and rotating the PDF pages.
 * 			If nonezero is returned, Disables inserting, deleting and rotating the PDF pages.
 */
DFVINTERFACE_API long dfv_getPdfNoAssembleDoc(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Specifies the key length when encrypting the PDF file during outputting.
 * The key length can be specified as either 40 or 128 (bit).
 * This parameter is effective only when you specify PDF1.4 or later with PDF version
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Specifies the key length.
 */
DFVINTERFACE_API void dfv_setPdfEncryptLevel(CDfvObjPtr pDfvObj, DfvPDFENCRYPTLEVEL newVal);

/**
 * Effective when outputting to PDF.
 * Get the key length when encrypting the PDF file during outputting.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the key length.
 */
DFVINTERFACE_API DfvPDFENCRYPTLEVEL dfv_getPdfEncryptLevel(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to embed all embeddable fonts in PDF.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of whether to embed all embeddable fonts
 */
DFVINTERFACE_API long dfv_getPdfEmbedAllFonts(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Embeds all embeddable fonts in PDF to create.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If the value is 'true' is specified, Embeds all embeddable fonts
 */
DFVINTERFACE_API void dfv_setPdfEmbedAllFonts(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the font specified to be embedded in PDF.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the fontnames. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getPdfEmbedFonts(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Gets the font specified to be embedded in PDF.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the fontnames. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getPdfEmbedFontsW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Embeds the specified font in PDF to create. If you want to specify plural fonts, put commas between fonts.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	fonts specified to embed
 */
DFVINTERFACE_API void dfv_setPdfEmbedFonts(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Embeds the specified font in PDF to create. If you want to specify plural fonts, put commas between fonts.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	fonts specified to embed
 */
DFVINTERFACE_API void dfv_setPdfEmbedFontsW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to issues the error when failing to embed fonts.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of whether to issues the error
 */
DFVINTERFACE_API long dfv_getPdfErrorOnEmbedFault(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * An error is issued in case of failing to embed fonts.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If the value is 'true' is specified, an error is issued.
 */
DFVINTERFACE_API void dfv_setPdfErrorOnEmbedFault(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to issues the error when missing glyph.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of whether to issues the error
 */
DFVINTERFACE_API long dfv_getPdfErrorOnMissingGlyph(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * An error is issued in case of missing glyph.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If the value is 'true' is specified, an error is issued.
 */
DFVINTERFACE_API void dfv_setPdfErrorOnMissingGlyph(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to print the resulting PDF file or not.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>PRALLOW_NONE	</td><td>= 0 Not Allowed</td></tr>
 *	<tr><td>PRALLOW_LOW		</td><td>= 1 Low Resolution Printing</td></tr>
 *	<tr><td>PRALLOW_HIGH	</td><td>= 2 High Resolution Printing</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of printing allowed
 */
DFVINTERFACE_API DfvPDFPRINTALLOW dfv_getPdfPrintingAllowed(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Spesifies whether to permit printing PDF to create with one of the following values.
 * This parameter is effective only when you specify PDF1.4 or later to PDF version (setPdfVersion).
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>PRALLOW_NONE	</td><td>= 0 Not Allowed</td></tr>
 *	<tr><td>PRALLOW_LOW		</td><td>= 1 Low Resolution Printing</td></tr>
 *	<tr><td>PRALLOW_HIGH	</td><td>= 2 High Resolution Printing</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of printing allowed
 */
DFVINTERFACE_API void dfv_setPdfPrintingAllowed(CDfvObjPtr pDfvObj, DfvPDFPRINTALLOW newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of how to compress the color images embedded in PDF.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGCMPR_AUTO	</td><td>= 0 Auto</td></tr>
 *	<tr><td>IMGCMPR_JPEG	</td><td>= 1 JPEG compression</td></tr>
 *	<tr><td>IMGCMPR_ZLIB	</td><td>= 2 ZLIB compression</td></tr>
 *	<tr><td>IMGCMPR_JPEG2K	</td><td>= 3 JPEG2000 compression</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of how raster graphics are compressed and stored
 */
DFVINTERFACE_API DfvPDFIMAGECOMPRESSION dfv_getPdfImageCompression(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * When the color image format cannot be stored directly in PDF, the image is stored after being transformed into the bit map format which is compatible with PDF. The compression method of the data stored in a PDF file is then specified by one of the following values.<BR>
 * When IMGCMPR_AUTO is selected, the process is automatically done and creates the image data according to the setting of dfv_setPdfJPEGQuality and dfv_setPdfRasterizeResolution. Whichever has the smaller compressed size, JPEG or ZLIB, is selected. <BR>
This is the setting for the color image. Spesify dfv_setPdfGrayscaleImageCompression for the grayscale image, and dfv_setPdfMonochromeImageCompression for the monochrome image.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGCMPR_AUTO	</td><td>= 0 Auto</td></tr>
 *	<tr><td>IMGCMPR_JPEG	</td><td>= 1 JPEG compression</td></tr>
 *	<tr><td>IMGCMPR_ZLIB	</td><td>= 2 ZLIB compression</td></tr>
 *	<tr><td>IMGCMPR_JPEG2K	</td><td>= 3 JPEG2000 compression</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of how raster graphics are compressed and stored
 */
DFVINTERFACE_API void dfv_setPdfImageCompression(CDfvObjPtr pDfvObj, DfvPDFIMAGECOMPRESSION newVal);

/**
 * Gets the value of the quality of JPEG format that is specified by dfv_setPdfImageCompression() stored in PDF.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of the quality of JPEG format
 */
DFVINTERFACE_API int	 dfv_getPdfJPEGQuality(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * For the color image format that can not be stored directly in PDF, specifies the image quality by the numerical value within the range of 1-100 when IMGCMPR_JPEG is specified by setPdfImageCompression. The quality becomes higher in proportion to the increase in the number; however the file size also becomes larger.<BR>
 * CAUTION: 	It is not for changing the quality of a JPEG format image.<BR>
 * This is the setting for the color image. Spesify setPdfGrayscaleJPEGQuality for the grayscale image.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of the quality of JPEG format
 */
DFVINTERFACE_API void dfv_setPdfJPEGQuality(CDfvObjPtr pDfvObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of whether the text and the line art in PDF are compressed in order to make the size of PDF smaller or not.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of whether make the size of PDF smaller or not
 */
DFVINTERFACE_API long dfv_getPdfCompressContentStream(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Specifies whether the text and the line art in PDF are compressed in order to make the size of PDF smaller or not.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If the value is 'true' is specified, make the PDF compress
 */
DFVINTERFACE_API void dfv_setPdfCompressContentStream(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of how to transform external link specified by the relative address in the PDF link.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of how to transform external link
 */
DFVINTERFACE_API long dfv_getPdfUseLaunchForRelativeURI(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Specifies whether the external link specified by the relative address is transformed into 'Open the file' or into 'World Wide Web link' in the PDF link properties.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If nonezero is specified, it is transformed to 'Open the file'. If zero is specified, it is transformed to 'World Wide Web link'
 */
DFVINTERFACE_API void dfv_setPdfUseLaunchForRelativeURI(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of how to convert the RGB color space (DebiceRGB) to DeviceGray.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>RGBCONV_NONE	</td><td>= 0 No Conversion</td></tr>
 *	<tr><td>RGBCONV_BLACK	</td><td>= 1 Black to DeviceGray</td></tr>
 *	<tr><td>RGBCONV_GRAY	</td><td>= 2 Gray to DeviceGray</td></tr>
 *	<tr><td>RGBCONV_ALL		</td><td>= 3 All RGB to DeviceGray</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of how to convert
 */
DFVINTERFACE_API DfvPDFRGBCONVERSION dfv_getPdfRGBConversion(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Specifies how to convert the RGB color space (DeviceRGB) to DeviceGray.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>RGBCONV_NONE	</td><td>= 0 No Conversion</td></tr>
 *	<tr><td>RGBCONV_BLACK	</td><td>= 1 Black to DeviceGray</td></tr>
 *	<tr><td>RGBCONV_GRAY	</td><td>= 2 Gray to DeviceGray</td></tr>
 *	<tr><td>RGBCONV_ALL		</td><td>= 3 All RGB to DeviceGray</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of how to convert
 */
DFVINTERFACE_API void dfv_setPdfRGBConversion(CDfvObjPtr pDfvObj, DfvPDFRGBCONVERSION newVal);

#if defined(_DOXYGEN) || (defined(_MSC_VER) && defined(_WIN32))

/**
 * Effective when outputting to PDF.
 * Gets the value of the rasterised-resolution of the transformed raster images.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	Rasterised-resolution
 */
DFVINTERFACE_API int dfv_getPdfRasterizeResolution(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Specifies the value of the rasterised-resolution of the transformed raster images in the range from 70 to 500(dpi). SVG, EMF and WMF are drawn in PDF as vectors without being transformed to raster images.
 * This setting is effective only with Windows version.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Rasterised-resolution (70 to 500)
 */
DFVINTERFACE_API void dfv_setPdfRasterizeResolution(CDfvObjPtr pDfvObj, int newVal);

#endif

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to output linearize PDF or not.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of whether to output linearize pdf or not.
 */
DFVINTERFACE_API long dfv_getPdfLinearize(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Specifies whether to output linearize PDF or not.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If the value is 'true' is specified, output linearlize PDF.
 */
DFVINTERFACE_API void dfv_setPdfLinearize(CDfvObjPtr pDfvObj, long newVal);

#if defined(_DOXYGEN) || (defined(_MSC_VER) && defined(_WIN32))

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to sign a signature to PDF or not.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of whether to sign a signature to PDF or not.
 */
DFVINTERFACE_API long dfv_getPdfSignature(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Specifies whether to sign a signature to PDF or not.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If the value is 'true' is specified, sign a signature to PDF.
 */
DFVINTERFACE_API void dfv_setPdfSignature(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of a signature information name.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	the value of a signature information name.
 */
DFVINTERFACE_API char* dfv_getPdfSignatureName(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Gets the value of a signature information name.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	the value of a signature information name.
 */
DFVINTERFACE_API wchar_t* dfv_getPdfSignatureNameW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Sets a signature information name.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of a signature information name.
 */
DFVINTERFACE_API void dfv_setPdfSignatureName(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Sets a signature information name.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of a signature information name.
 */
DFVINTERFACE_API void dfv_setPdfSignatureNameW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of a certificate information name.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	the value of a certificate information name.
 */
DFVINTERFACE_API char* dfv_getPdfCertificateName(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Gets the value of a certificate information name.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	the value of a certificate information name.
 */
DFVINTERFACE_API wchar_t* dfv_getPdfCertificateNameW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Sets a certificate information name.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of a certificate information name.
 */
DFVINTERFACE_API void dfv_setPdfCertificateName(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Sets a certificate information name.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of a certificate information name.
 */
DFVINTERFACE_API void dfv_setPdfCertificateNameW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

#endif

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to embed all embeddable fonts
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>EMBALLFONT_PART	</td><td>= 0 Specified fonts </td></tr>
 *	<tr><td>EMBALLFONT_ALL	</td><td>= 1 All fonts except Base14 fonts</td></tr>
 *	<tr><td>EMBALLFONT_BASE14	</td><td>= 2 All fonts</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of whether to embed all embeddable fonts
 */
DFVINTERFACE_API DfvEMBEDALLFONT dfv_getPdfEmbedAllFontsEx(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Specifies whether to embed the all outline data of fonts in PDF or not with one of the following values, which are True type fonts and Type1 Fonts and are embeddable in the formatted result.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>EMBALLFONT_PART	</td><td>= 0 Specified fonts </td></tr>
 *	<tr><td>EMBALLFONT_ALL	</td><td>= 1 All fonts except Base14 fonts</td></tr>
 *	<tr><td>EMBALLFONT_BASE14	</td><td>= 2 All fonts</td></tr>
 * </table>
 *
 *If the value is EMBALLFONT_PART, only fonts specified in dfv_setPdfEmbedFonts are embedded. If the value is EMBALLFONT_ALL, all fonts that can be embedded except Base 14 fonts will be embedded. If the value is EMBALLFONT_BASE14, all fonts including Base 14 fonts that can be embedded will be embedded.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of whether to embed all embeddable fonts
 */
DFVINTERFACE_API void dfv_setPdfEmbedAllFontsEx(CDfvObjPtr pDfvObj, DfvEMBEDALLFONT newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of method to downsample the color image
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of method to downsample the color image
 */
DFVINTERFACE_API DfvIMAGEDOWNSAMPLING dfv_getPdfImageDownSampling(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Specifies the following either of method to downsample the color image that is put into PDF.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGDOWNSAMPLING_NONE	</td><td>= 0 No downsampling </td></tr>
 *	<tr><td>IMGDOWNSAMPLING_AVERAGE	</td><td>= 1 Average downsamplin</td></tr>
 *	<tr><td>IMGDOWNSAMPLING_BICUBIC	</td><td>= 2 Bicubic downsampling</td></tr>
 *	<tr><td>IMGDOWNSAMPLING_SUBSAMPLING	</td><td>= 3 Subsampling</td></tr>
 * </table>
 *
 * When the value except IMGDOWNSAMPLING_NONE is specified, the image that has the resolution larger than the one specified by dfv_setPdfImageDownSamplingDPI will be downsampled into the resolution specified by dfv_setPdfImageDownSamplingTarget.
This is the setting for the color image. Spesify dfv_setPdfGrayscaleImageDownSampling for the grayscale image, and dfv_setPdfMonochromeImageDownSampling for the monochrome image.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of method to downsample the color image
 */
DFVINTERFACE_API void dfv_setPdfImageDownSampling(CDfvObjPtr pDfvObj, DfvIMAGEDOWNSAMPLING newVal);

/**
 * Effective when outputting to PDF.
 * Gets resolution when the color image is downsampled.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of resolution.
 */
DFVINTERFACE_API int dfv_getPdfImageDownSamplingTarget(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Set resolution when the color image is downsampled.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of resolution.
 */
DFVINTERFACE_API void dfv_setPdfImageDownSamplingTarget(CDfvObjPtr pDfvObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets resolution of the color image which performs a downsampling.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of resolution.
 */
DFVINTERFACE_API int dfv_getPdfImageDownSamplingDPI(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Set resolution of the color image which performs a downsampling.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of resolution.
 */
DFVINTERFACE_API void dfv_setPdfImageDownSamplingDPI(CDfvObjPtr pDfvObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets specification whether to embed to PDF the color profile of the color image that will be embedded to PDF.
 * 
 *
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	If nonezero is specified, it is embedded. If zero is specified, it is not embedded.
 */
DFVINTERFACE_API long dfv_getPdfPutImageColorProfile(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Specifies whether to embed to PDF the color profile of the color image that will be embedded to PDF.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If nonezero is specified, it is embedded. If zero is specified, it is not embedded.
 */
DFVINTERFACE_API void dfv_setPdfPutImageColorProfile(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of how to compress the grayscale images embedded in PDF.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGCMPR_AUTO	</td><td>= 0 Auto</td></tr>
 *	<tr><td>IMGCMPR_JPEG	</td><td>= 1 JPEG compression</td></tr>
 *	<tr><td>IMGCMPR_ZLIB	</td><td>= 2 ZLIB compression</td></tr>
 *	<tr><td>IMGCMPR_JPEG2K	</td><td>= 3 JPEG2000 compression</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of how raster graphics are compressed and stored
 */
DFVINTERFACE_API DfvPDFIMAGECOMPRESSION dfv_getPdfGrayscaleImageCompression(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * When the grayscale image format cannot be stored directly in PDF, the image is stored after being transformed into the bit map format which is compatible with PDF. The compression method of the data stored in a PDF file is then specified by one of the following values.<BR>
 * When IMGCMPR_AUTO is selected, the process is automatically done and creates the image data according to the setting of dfv_setPdfGrayscaleJPEGQuality and dfv_setPdfRasterizeResolution. Whichever has the smaller compressed size, JPEG or ZLIB, is selected. <BR>
This is the setting for the grayscale image. Spesify dfv_setPdfImageCompression for the color image, and dfv_setPdfMonochromeImageCompression for the monochrome image.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGCMPR_AUTO	</td><td>= 0 Auto</td></tr>
 *	<tr><td>IMGCMPR_JPEG	</td><td>= 1 JPEG compression</td></tr>
 *	<tr><td>IMGCMPR_ZLIB	</td><td>= 2 ZLIB compression</td></tr>
 *	<tr><td>IMGCMPR_JPEG2K	</td><td>= 3 JPEG2000 compression</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of how raster graphics are compressed and stored
 */
DFVINTERFACE_API void dfv_setPdfGrayscaleImageCompression(CDfvObjPtr pDfvObj, DfvPDFIMAGECOMPRESSION newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of the quality of JPEG format that is specified by dfv_setPdfGrayscaleImageCompression stored in PDF.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of the quality of JPEG format
 */
DFVINTERFACE_API int dfv_getPdfGrayscaleJPEGQuality(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * For the grayscale image format that can not be stored directly in PDF, specifies the image quality by the numerical value within the range of 1-100 when IMGCMPR_JPEG is specified by dfv_setPdfGrayscaleImageCompression. The quality becomes higher in proportion to the increase in the number; however the file size also becomes larger.<BR>
 * CAUTION: It is not for changing the quality of a JPEG format image.<BR>
 * This is the setting for the grayscale image. Spesify dfv_setPdfJPEGQuality for the color image.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of the quality of JPEG format
 */
DFVINTERFACE_API void dfv_setPdfGrayscaleJPEGQuality(CDfvObjPtr pDfvObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of method to downsample the grayscale image
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of method to downsample the grayscale image
 */
DFVINTERFACE_API DfvIMAGEDOWNSAMPLING dfv_getPdfGrayscaleImageDownSampling(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal
 */
DFVINTERFACE_API void dfv_setPdfGrayscaleImageDownSampling(CDfvObjPtr pDfvObj, DfvIMAGEDOWNSAMPLING newVal);

/**
 * Effective when outputting to PDF.
 * Gets resolution when the grayscale image is downsampled.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of resolution.
 */
DFVINTERFACE_API int dfv_getPdfGrayscaleImageDownSamplingTarget(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Specifies the following either of method to downsample the grayscale image that is put into PDF.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGDOWNSAMPLING_NONE	</td><td>= 0 No downsampling </td></tr>
 *	<tr><td>IMGDOWNSAMPLING_AVERAGE	</td><td>= 1 Average downsamplin</td></tr>
 *	<tr><td>IMGDOWNSAMPLING_BICUBIC	</td><td>= 2 Bicubic downsampling</td></tr>
 *	<tr><td>IMGDOWNSAMPLING_SUBSAMPLING	</td><td>= 3 Subsampling</td></tr>
 * </table>
 *
 * When the value except IMGDOWNSAMPLING_NONE is specified, the image that has the resolution larger than the one specified by dfv_setPdfGrayscaleImageDownSamplingDPI will be downsampled into the resolution specified by dfv_setPdfGrayscaleImageDownSamplingTarget.
This is the setting for the grayscale image. Spesify dfv_setPdfImageDownSampling for the color image, and dfv_setPdfMonochromeImageDownSampling for the monochrome image.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of method to downsample the grayscale image
 */
DFVINTERFACE_API void dfv_setPdfGrayscaleImageDownSamplingTarget(CDfvObjPtr pDfvObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets resolution of the grayscale image which performs a downsampling.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of resolution.
 */
DFVINTERFACE_API int dfv_getPdfGrayscaleImageDownSamplingDPI(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Set resolution of the grayscale image which performs a downsampling.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of resolution.
 */
DFVINTERFACE_API void dfv_setPdfGrayscaleImageDownSamplingDPI(CDfvObjPtr pDfvObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of how to compress the monochrome images embedded in PDF.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>MONOCMPR_CCITT4		</td><td>= 0 CCITTFaxDecode group 4 filter,default value</td></tr>
 *	<tr><td>MONOCMPR_CCITT3		</td><td>= 1 CCITTFaxDecode group 3 filter</td></tr>
 *	<tr><td>MONOCMPR_RUNLENGTH	</td><td>= 2 RunLengthDecode filter</td></tr>
 *	<tr><td>MONOCMPR_ZLIB		</td><td>= 3 FlateDecode filter</td></tr>
 *	<tr><td>MONOCMPR_OFF		</td><td>= 4 no filter</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of how raster graphics are compressed and stored
 */
DFVINTERFACE_API DfvMONOCHROMECOMPRESSION dfv_getPdfMonochromeImageCompression(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * When the monochrome image format cannot be stored directly in PDF, the image is stored after being transformed into the bit map format which is compatible with PDF. The compression method of the data stored in a PDF file is then specified by one of the following values.<BR>
This is the setting for the monochrome image. Spesify dfv_setPdfGrayscaleImageCompression for the grayscale image, and dfv_setPdfImageCompression for the color image.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>MONOCMPR_CCITT4		</td><td>= 0 CCITTFaxDecode group 4 filter,default value</td></tr>
 *	<tr><td>MONOCMPR_CCITT3		</td><td>= 1 CCITTFaxDecode group 3 filter</td></tr>
 *	<tr><td>MONOCMPR_RUNLENGTH	</td><td>= 2 RunLengthDecode filter</td></tr>
 *	<tr><td>MONOCMPR_ZLIB		</td><td>= 3 FlateDecode filter</td></tr>
 *	<tr><td>MONOCMPR_OFF		</td><td>= 4 no filter</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of how raster graphics are compressed and stored
 */
DFVINTERFACE_API void dfv_setPdfMonochromeImageCompression(CDfvObjPtr pDfvObj, DfvMONOCHROMECOMPRESSION newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of method to downsample the monochrome image
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of method to downsample the monochrome image
 */
DFVINTERFACE_API DfvIMAGEDOWNSAMPLING dfv_getPdfMonochromeImageDownSampling(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Specifies the following either of method to downsample the monochrome image that is put into PDF.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGDOWNSAMPLING_NONE	</td><td>= 0 No downsampling </td></tr>
 *	<tr><td>IMGDOWNSAMPLING_AVERAGE	</td><td>= 1 Average downsamplin</td></tr>
 *	<tr><td>IMGDOWNSAMPLING_BICUBIC	</td><td>= 2 Bicubic downsampling</td></tr>
 *	<tr><td>IMGDOWNSAMPLING_SUBSAMPLING	</td><td>= 3 Subsampling</td></tr>
 * </table>
 *
 * When the value except IMGDOWNSAMPLING_NONE is specified, the image that has the resolution larger than the one specified by dfv_setPdfMonochromeImageDownSamplingDPI will be downsampled into the resolution specified by dfv_setPdfMonochromeImageDownSamplingTarget.
This is the setting for the monochrome image. Spesify dfv_setPdfImageDownSampling for the color image, and dfv_setPdfGrayscaleImageDownSampling for the grayscale image.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of method to downsample the monochrome image
 */
DFVINTERFACE_API void dfv_setPdfMonochromeImageDownSampling(CDfvObjPtr pDfvObj, DfvIMAGEDOWNSAMPLING newVal);

/**
 * Effective when outputting to PDF.
 * Gets resolution when the monochrome image is downsampled.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of resolution.
 */
DFVINTERFACE_API int dfv_getPdfMonochromeImageDownSamplingTarget(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Set resolution when the monochrome image is downsampled.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of resolution.
 */
DFVINTERFACE_API void dfv_setPdfMonochromeImageDownSamplingTarget(CDfvObjPtr pDfvObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets resolution of the monochrome image which performs a downsampling.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of resolution.
 */
DFVINTERFACE_API int dfv_getPdfMonochromeImageDownSamplingDPI(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * Set resolution of the monochrome image which performs a downsampling.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of resolution.
 */
DFVINTERFACE_API void dfv_setPdfMonochromeImageDownSamplingDPI(CDfvObjPtr pDfvObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets the width of PDF to output.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the width of PDF. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getPdfOutputWidth(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Gets the width of PDF to output.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the width of PDF. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getPdfOutputWidthW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Scales the width of PDF to output. A value with a unit or % value can be specified as length.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the width of PDF to output.
 */
DFVINTERFACE_API void dfv_setPdfOutputWidth(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Scales the width of PDF to output. A value with a unit or % value can be specified as length.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the width of PDF to output.
 */
DFVINTERFACE_API void dfv_setPdfOutputWidthW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Effective when outputting to PDF.
 * Gets the height of PDF to output.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the height of PDF. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getPdfOutputHeight(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Gets the height of PDF to output.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the height of PDF. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getPdfOutputHeightW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Scales the height of PDF to output. A value with a unit or % value can be specified as length.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the width of PDF to output.
 */
DFVINTERFACE_API void dfv_setPdfOutputHeight(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Scales the height of PDF to output. A value with a unit or % value can be specified as length.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the width of PDF to output.
 */
DFVINTERFACE_API void dfv_setPdfOutputHeightW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to issue error or not when PDF/X is generating.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of whether to issue error.
 */
DFVINTERFACE_API long dfv_getPdfErrorOnPDFXFault(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to PDF.
 * An error is not issued when PDF/X is generating.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If the value is 'true' is specified, no error is issued.
 */
DFVINTERFACE_API void dfv_setPdfErrorOnPDFXFault(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to SVG.
 * Get the version of SVG.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the version of SVG.
 */
DFVINTERFACE_API DfvSVGVERSION	dfv_getSvgVersion(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to SVG.
 * Enables specifying whether the version of SVG is 1.1, Basic or Tiny.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Specifies the version of SVG.
 */
DFVINTERFACE_API void dfv_setSvgVersion(CDfvObjPtr pDfvObj, DfvSVGVERSION newVal);

/**
 * Effective when outputting to SVG.
 * Gets the setting indicating whether to compress the outputted SVG into gzip format or not.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	whether gzip compression or not.
 */
DFVINTERFACE_API long dfv_getSvgGzipCompression(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to SVG.
 * Specifies whether to compress the outputted SVG into gzip format or not.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If the value is 'true' is specified, enables to compress data into gzip format.
 */
DFVINTERFACE_API void dfv_setSvgGzipCompression(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to SVG.
 * Gets the setting indicating whether to embed fonts in the outputted SVG.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	whether embeds fonts or not.
 */
DFVINTERFACE_API long dfv_getSvgEmbedAllFonts(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to SVG.
 * Specifies whether to embed fonts in the outputted SVG.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If the value is 'true' is specified, embeds fonts.
 */
DFVINTERFACE_API void dfv_setSvgEmbedAllFonts(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to SVG.
 * Gets the format for naming files when the outputted SVG becomes multiple.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer, the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getSvgFormat(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * Effective when outputting to SVG.
 * Gets the format for naming files when the outputted SVG becomes multiple.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer, the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getSvgFormatW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to SVG.
 * Specifies the format for naming files when the outputted SVG becomes multiple.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the SVG file name format.
 */
DFVINTERFACE_API void dfv_setSvgFormat(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * Effective when outputting to SVG.
 * Specifies the format for naming files when the outputted SVG becomes multiple.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the SVG file name format.
 */
DFVINTERFACE_API void dfv_setSvgFormatW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Effective when outputting to SVG.
 * Gets the font specified to be embedded in SVG.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the fontnames. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getSvgEmbedFonts(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * Effective when outputting to SVG.
 * Gets the font specified to be embedded in SVG.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the fontnames. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getSvgEmbedFontsW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to SVG.
 * Embeds the specified font in SVG to create. If you want to specify plural fonts, put commas between fonts.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	fonts specified to embed
 */
DFVINTERFACE_API void dfv_setSvgEmbedFonts(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * Effective when outputting to SVG.
 * Embeds the specified font in SVG to create. If you want to specify plural fonts, put commas between fonts.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	fonts specified to embed
 */
DFVINTERFACE_API void dfv_setSvgEmbedFontsW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Effective when outputting to SVG.
 * Gets the value of whether to issues the error when failing to embed fonts.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of whether to issues the error
 */
DFVINTERFACE_API long dfv_getSvgErrorOnEmbedFault(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to SVG.
 * An error is issued in case of failing to embed fonts.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If the value is 'true' is specified, an error is issued.
 */
DFVINTERFACE_API void dfv_setSvgErrorOnEmbedFault(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to SVG.
 * Gets the value of how to compress the images embedded in SVG.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGCMPR_AUTO	</td><td>= 0 Auto conversion</td></tr>
 *	<tr><td>IMGCMPR_JPEG	</td><td>= 1 JPEG conversion</td></tr>
 *	<tr><td>IMGCMPR_PNG		</td><td>= 2 PNG conversion</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of how raster graphics are compressed and stored
 */
DFVINTERFACE_API DfvIMAGECONVERSION dfv_getSvgImageConversion(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to SVG.
 * Selects how to compress the images embedded in SVG to create from the following.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGCMPR_AUTO	</td><td>= 0 Auto conversion</td></tr>
 *	<tr><td>IMGCMPR_JPEG	</td><td>= 1 JPEG conversion</td></tr>
 *	<tr><td>IMGCMPR_PNG		</td><td>= 2 PNG conversion</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the value of how raster graphics are compressed and stored
 */
DFVINTERFACE_API void dfv_setSvgImageConversion(CDfvObjPtr pDfvObj, DfvIMAGECONVERSION newVal);

/**
 * Gets the value of the quality of JPEG format that is specified by dfv_setSvgImageConversion() stored in SVG.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value of the quality
 */
DFVINTERFACE_API int dfv_getSvgJPEGQuality(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to SVG.
 * Specifies the quality of the Raster graphics when stored in JPEG format using the range of 1-100.
 * The quality becomes higher in proportion to the increase in the number; however the file size also becomes larger.
 * The initial value is 80.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	JPEG quality (1 to 100)
 */
DFVINTERFACE_API void dfv_setSvgJPEGQuality(CDfvObjPtr pDfvObj, int newVal);

/**
 * Effective when outputting to SVG.
 * Gets specification how to treat the referred image.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGPT_EMBED_ALL	</td><td>= 0 Embeds all images to SVG.</td></tr>
 *	<tr><td>IMGPT_COPY_ALL	</td><td>= 1 Copies all image files to the destination that is specified by setSvgImageCopyPath, and then links.</td></tr>
 *	<tr><td>IMGPT_LINK		</td><td>= 2 Links images that have been linked, and embeds the embedded image. However, the raster images other than JPEG and PNG are always embedded.</td></tr>
 *	<tr><td>IMGPT_COPY		</td><td>= 3 Copies images that have been linked to the destination that is specified by setSvgImageCopyPath, and links. The embedded image are embedded.</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	specification how to treat the referred image.
 */
DFVINTERFACE_API DfvIMAGEPROCTYPE dfv_getSvgImageProcessingType(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to SVG.
 * Specifies how to treat the referred image.
 * 
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGPT_EMBED_ALL	</td><td>= 0 Embeds all images to SVG.</td></tr>
 *	<tr><td>IMGPT_COPY_ALL	</td><td>= 1 Copies all image files to the destination that is specified by setSvgImageCopyPath, and then links.</td></tr>
 *	<tr><td>IMGPT_LINK		</td><td>= 2 Links images that have been linked, and embeds the embedded image. However, the raster images other than JPEG and PNG are always embedded.</td></tr>
 *	<tr><td>IMGPT_COPY		</td><td>= 3 Copies images that have been linked to the destination that is specified by setSvgImageCopyPath, and links. The embedded image are embedded.</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	specification how to treat the referred image.
 */
DFVINTERFACE_API void dfv_setSvgImageProcessingType(CDfvObjPtr pDfvObj, DfvIMAGEPROCTYPE newVal);

/**
 * Effective when outputting to SVG.
 * Gets the copy destination of image as specifying IMGPT_COPY_ALL or IMGPT_COPY by dfv_setSvgImageProcessingType.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the image copy path. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getSvgImageCopyPath(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * Effective when outputting to SVG.
 * Specifies the copy destination of image as specifying IMGPT_COPY_ALL or IMGPT_COPY by dfv_setSvgImageProcessingType.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as image copy path
 */
DFVINTERFACE_API void dfv_setSvgImageCopyPath(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * Effective when outputting to SVG.
 * Gets the copy destination of image as specifying IMGPT_COPY_ALL or IMGPT_COPY by dfv_setSvgImageProcessingType.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the image copy path. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getSvgImageCopyPathW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to SVG.
 * Specifies the copy destination of image as specifying IMGPT_COPY_ALL or IMGPT_COPY by dfv_setSvgImageProcessingType.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as image copy path
 */
DFVINTERFACE_API void dfv_setSvgImageCopyPathW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Effective when outputting to SVG.
 * Gets specification whether to divide into multiple SVG or to output as one SVG when the formatted result extends to multiple pages. <BR>
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	specification whether to divide into multiple SVG or to output as one SVG when the formatted result extends to multiple pages.
 */
DFVINTERFACE_API long dfv_getSvgSingleFile(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to SVG.
 * Specifies whether to divide into multiple SVG or to output as one SVG when the formatted result extends to multiple pages. <BR>
 * If the value is true, outputs one SVG. If the value is false, outputs multiple SVG. When multiple SVG is output, the file name is modified by specifying format. <BR>
 * Effective only when outputting to the file. It is invalid in the output without the file name like the stream etc.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	specification whether to divide into multiple SVG or to output as one SVG when the formatted result extends to multiple pages.
 */
DFVINTERFACE_API void dfv_setSvgSingleFile(CDfvObjPtr pDfvObj, long newVal);

#if !defined(_DOXYGEN)

/**
 * Gets the value specified by setSvgSingleFileMaxPages.
 * Effective when outputting to SVG. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value specified by setSvgSingleFileMaxPages.
 */
DFVINTERFACE_API int dfv_getSvgSingleFileMaxPages(CDfvObjPtr pDfvObj);

/**
 * Specifies the maximum number of pages outputted when setSvgSingleFile = True is specified. .
 * When this parameter is omitted If this parameter is omitted, "5000" is considered as specified.
 * When either setSvgSingleFileMaxPages or setSvgSingleFileMaxHeight is specified, or both are specified, and the page exceeds either the maximum size (setSvgSingleFileMaxHeight) or the maximum number of pages (setSvgSingleFileMaxPages), Server Based Converter V1.2 will stop converting and abort the job as an error. Effective when outputting to SVG. 
 * 
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	maximum number of pages 
 */
DFVINTERFACE_API void dfv_setSvgSingleFileMaxPages(CDfvObjPtr pDfvObj, int newVal);

/**
 * Gets the value specified by setSvgImageDownsamplingDPI.
 * Effective when outputting to SVG. 
 * 
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value specified by setSvgImageDownsamplingDPI. 
 */
DFVINTERFACE_API int dfv_getSvgImageDownsamplingDPI(CDfvObjPtr pDfvObj);

/**
 * Specifies the resolution of the down sampling when embedding an image with 1 or more integers. .
 * When the resolution of the original image is lower than specification, it's embedded with the lower resolution. Effective when outputting to SVG. 
 * 
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	newVal	the resolution of the down sampling 
 */
DFVINTERFACE_API void dfv_setSvgImageDownsamplingDPI(CDfvObjPtr pDfvObj, int dpi);

/**
 * Gets the value specified by setSvgImageDownsamplingMethod.
 * Effective when outputting to SVG. 
 * 
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	the value specified by setSvgImageDownsamplingMethod
 */
DFVINTERFACE_API int dfv_getSvgImageDownsamplingMethod(CDfvObjPtr pDfvObj);

/**
 * Specifies the way of compression when down sampled.
 * 
 * S_SVG_IMGDOWNSAMPLING_AVERAGE : biliner 
 * S_SVG_IMGDOWNSAMPLING_BICUBIC : bicubic 
 * S_SVG_IMGDOWNSAMPLING_SUBSAMPLING : nearest neighbor
 * If this parameter is omitted, "IMGDOWNSAMPLING_AVERAGE" is considered as specified. Effective when outputting to SVG. 
 * 
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	type	the way of compression when down sampled 
 */
DFVINTERFACE_API void dfv_setSvgImageDownsamplingMethod(CDfvObjPtr pDfvObj, int type);

#endif

/**
 * Effective when outputting to SVG.
 * Gets specification whether to rename all file name to prefix specified by dfv_setSvgImagePrefix, or use original name.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	specification whether to rename all file name to prefix specified by dfv_setSvgImagePrefix, or use original name.
 */
DFVINTERFACE_API long dfv_getSvgImageRename(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to SVG.
 * When images are copied to the directory specified by dfv_setSvgImageCopyPath etc. and processed, specifies whether to rename all file name to prefix specified by dfv_setSvgImagePrefix, or use original name. When the file name overlaps, sequential number is added. When true is specified, all files are renamed.
 *
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	specification whether to rename all file name to prefix specified by dfv_setSvgImagePrefix, or use original name.
 */
DFVINTERFACE_API void dfv_setSvgImageRename(CDfvObjPtr pDfvObj, long newVal);

/**
 * Effective when outputting to SVG.
 * Gets the prefix of the file name when images are copied to the directory specified by dfv_setSvgImageCopyPath and processed.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the prefix. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getSvgImagePrefix(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * Effective when outputting to SVG.
 * When images are copied to the directory specified by dfv_setSvgImageCopyPath and processed, specifies the prefix of the file name. The file name will be prefix with sequence numbers. Default is empty character string with only sequential numbers.
 *
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the prefix of the file name.
 */
DFVINTERFACE_API void dfv_setSvgImagePrefix(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * Effective when outputting to SVG.
 * Gets the prefix of the file name when images are copied to the directory specified by dfv_setSvgImageCopyPath and processed.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the prefix. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getSvgImagePrefixW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to SVG.
 * When images are copied to the directory specified by dfv_setSvgImageCopyPath and processed, specifies the prefix of the file name. The file name will be prefix with sequence numbers. Default is empty character string with only sequential numbers.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the prefix of the file name.
 */
DFVINTERFACE_API void dfv_setSvgImagePrefixW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Effective when outputting to SVG.
 * Gets specification whether to add sequential number to the output SVG even if it has only one-page.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	specification whether to add sequential number to the output SVG even if it has only one-page.
 */
DFVINTERFACE_API long dfv_getSvgSinglePageNumber(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to SVG.
 * When dfv_setSvgSingleFile = 0 is specified, specifies whether to add sequential number to the output SVG even if it has only one-page. It is not added in case of false.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	specification whether to add sequential number to the output SVG even if it has only one-page.
 */
DFVINTERFACE_API void dfv_setSvgSinglePageNumber(CDfvObjPtr pDfvObj, long newVal);

#if defined(_DOXYGEN) || (defined(_MSC_VER) && defined(_WIN32))
/**
 * Effective when outputting to SVG.
 * Gets the value of the rasterised-resolution of the transformed raster images.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	Rasterised-resolution
 */
DFVINTERFACE_API int dfv_getSvgRasterizeResolution(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to SVG.
 * Specifies the value of the rasterised-resolution of the transformed raster images in the range from 70 to 500(dpi). SVG, EMF and WMF are drawn in SVG as vectors without being transformed to raster images.
 * This setting is effective only with Windows version.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Rasterised-resolution (70 to 500)
 */
DFVINTERFACE_API void dfv_setSvgRasterizeResolution(CDfvObjPtr pDfvObj, int newVal);
#endif

/**
 * Specifies multiple volume of PDF output.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Zpecifies zero or nonzero.
 */
DFVINTERFACE_API void dfv_setMultiVolume(CDfvObjPtr pDfvObj, long newVal);

/**
 * Get the error level to abort formatting process.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	Returns the error level.
 */
DFVINTERFACE_API DfvIfErrorLevel dfv_getExitLevel(CDfvObjPtr pDfvObj);

/**
 * Error level to abort formatting process. Server Based Converter will stop formatting when the detected
 * error level is equal to ExitLevel property or higher. The default value is 2 (Warning).
 * Thus if an error occurred and error level is 2 (Warning) or higher, formatting process will be
 * aborted. Please use the value from 1 to 4. When the value of 5 or more specified, it is considered
 * to be the value of 4. If a error-level:4 (fatal error) occurs, the formatting process will be
 * aborted unconditionally.
 * BTW : An error is not displayed no matter what value may be specified to be this property.
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>ELVL_INFORMATION	</td><td>= 1 Information</td></tr>
 *	<tr><td>ELVL_WARNING		</td><td>= 2 Warning</td></tr>
 *	<tr><td>ELVL_RECOVERABLE	</td><td>= 3 Recoveable Error</td></tr>
 *	<tr><td>ELVL_FATAL			</td><td>= 4 Fatal Error</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	error level to abort formatting process.
 */
DFVINTERFACE_API void dfv_setExitLevel(CDfvObjPtr pDfvObj, DfvIfErrorLevel newVal);

/**
 * Returns the error level of the error that occurred during the formatting process.
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>ELVL_INFORMATION	</td><td>= 1 Information</td></tr>
 *	<tr><td>ELVL_WARNING		</td><td>= 2 Warning</td></tr>
 *	<tr><td>ELVL_RECOVERABLE	</td><td>= 3 Recoveable Error</td></tr>
 *	<tr><td>ELVL_FATAL			</td><td>= 4 Fatal Error</td></tr>
 * </table>
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	Returns the error level.
 */
DFVINTERFACE_API DfvIfErrorLevel dfv_getErrorLevel(CDfvObjPtr pDfvObj);

/**
 * Returns the error code of the error that occurred during the formatting process.
 * Zero means no error. Non-zero indicates any error occurred.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	Returns the error code.
 */
DFVINTERFACE_API DfvIfErrorCode dfv_getErrorCode(CDfvObjPtr pDfvObj);

/**
 * Returns the error message of the error that occurred during the formatting process.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getErrorMessage(CDfvObjPtr pDfvObj, char* pVal, int size);
/**
 * Returns the error message of the error that occurred during the formatting process.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getErrorMessageW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Sets the substitution of font name. This substitution acts on the font names existing in FO.
 * The font name 'fontName' is replaced to 'aliasName'.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	src		Specifies the font name which is replaced.
 * @param	dst		Specifies the aliasName.
 */
DFVINTERFACE_API void dfv_setFontAlias(CDfvObjPtr pDfvObj, const char* src, const char* dst);
/**
 * Sets the substitution of font name. This substitution acts on the font names existing in FO.
 * The font name 'fontName' is replaced to 'aliasName'.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	src		Specifies the font name which is replaced.
 * @param	dst		Specifies the aliasName.
 */
DFVINTERFACE_API void dfv_setFontAliasW(CDfvObjPtr pDfvObj, const wchar_t* src, const wchar_t* dst);

/**
 * Clear all substitutions of font name.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 */
DFVINTERFACE_API void dfv_clearFontAlias(CDfvObjPtr pDfvObj);
/**
 * Clear all substitutions of font name.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 */

/**
 * Erase the substitution of font name 'fontName'.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	src	Specifies the font name which is replaced.
 */
DFVINTERFACE_API void dfv_eraseFontAlias(CDfvObjPtr pDfvObj, const char* src);
DFVINTERFACE_API void dfv_eraseFontAliasW(CDfvObjPtr pDfvObj, const wchar_t* src);

/**
 * Execute formatting and output to a PDF specified in OutputFilePath or printer specified in PrinterName.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	Returns the error code. Zero means no error. Non-zero indicates any error occurred.
 */
DFVINTERFACE_API DfvIfErrorCode dfv_execute(CDfvObjPtr pDfvObj);

/**
 * Initialize formatting engine.
 *
 * @param	pDfvObj Pointer to DfvObj instance.
 */
DFVINTERFACE_API void dfv_clear(CDfvObjPtr pDfvObj);

/**
 * Specifies the callback fucntion.
 * The error that occurred during the formatting process can be received.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	proc		Address of the callback function.
 *	<br>Callback function has the following form:<pre>
 * void DfvOnMessageProc(DfvIfErrorLevel errLevel, DfvIfErrorCode errCode, const char* errMessage);
 * void DfvOnMessageProcW(DfvIfErrorLevel errLevel, DfvIfErrorCode errCode, const wchar_t* errMessage);</pre>
 */
DFVINTERFACE_API void dfv_setOnMessageProc(CDfvObjPtr pDfvObj, DfvOnMessageProc* proc);

/**
 * Specifies the callback fucntion.
 * The error that occurred during the formatting process can be received.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	proc		Address of the callback function.
 *	<br>Callback function has the following form:<pre>
 * void DfvOnMessageProc(DfvIfErrorLevel errLevel, DfvIfErrorCode errCode, const char* errMessage);
 * void DfvOnMessageProcW(DfvIfErrorLevel errLevel, DfvIfErrorCode errCode, const wchar_t* errMessage);</pre>
 */
DFVINTERFACE_API void dfv_setOnMessageProcW(CDfvObjPtr pDfvObj, DfvOnMessageProcW* proc);

/**
 * Specifies the callback fucntion.
 * The page number in the formatting process can be received.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	proc	Address of the callback function.
 *	<br>Callback function has the following form:<pre>
 * void DfvOnFormatPageProc(long pageNo);</pre>
 */
DFVINTERFACE_API void dfv_setOnFormatPageProc(CDfvObjPtr pDfvObj, DfvOnFormatPageProc* proc);

/**
 * Specifies the callback fucntion.
 * The error that occurred during the formatting process can be received.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	proc		Address of the callback function.
 *	<br>Callback function has the following form:<pre>
 * void DfvOnMessageProc(DfvIfErrorLevel errLevel, DfvIfErrorCode errCode, const char* errMessage);
 * void DfvOnMessageProcW(DfvIfErrorLevel errLevel, DfvIfErrorCode errCode, const wchar_t* errMessage);</pre>
 * @param	pAnyObj		Address of an any object.
 */
DFVINTERFACE_API void dfv_setOnMessageProcEx(CDfvObjPtr pDfvObj, DfvOnMessageProcEx* proc, void* pAnyObj);

/**
 * Specifies the callback fucntion.
 * The error that occurred during the formatting process can be received.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	proc		Address of the callback function.
 *	<br>Callback function has the following form:<pre>
 * void DfvOnMessageProc(DfvIfErrorLevel errLevel, DfvIfErrorCode errCode, const char* errMessage);
 * void DfvOnMessageProcW(DfvIfErrorLevel errLevel, DfvIfErrorCode errCode, const wchar_t* errMessage);</pre>
 * @param	pAnyObj		Address of an any object.
 */
DFVINTERFACE_API void dfv_setOnMessageProcExW(CDfvObjPtr pDfvObj, DfvOnMessageProcExW* proc, void* pAnyObj);

/**
 * Specifies the callback fucntion.
 * The page number in the formatting process can be received.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	proc	Address of the callback function.
 *	<br>Callback function has the following form:<pre>
 * void DfvOnFormatPageProc(long pageNo);</pre>
 * @param	pAnyObj		Address of an any object.
 */
DFVINTERFACE_API void dfv_setOnFormatPageProcEx(CDfvObjPtr pDfvObj, DfvOnFormatPageProcEx* proc, void* pAnyObj);

/* Print Interface */
/**
 * Get the printer name where the formatted result is outputted.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getPrinterName(CDfvObjPtr pDfvObj, char* pVal, int size);
/**
 * Get the printer name where the formatted result is outputted.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getPrinterNameW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Specifies the output format or the printer name to output.
 * When a printer name is specified, the formatted result is outputted to that printer.
 * When "\@STDPRN" is specified, the formatted result is outputted to the currently used printer.
 * When "\@PDF" is specified, the formatted result is outputted to PDF.
 * When "\@SVG" is specified, the formatted result is outputted to SVG.
 * When "\@PS" is specified, the formatted result is outputted to PostScript.
 * When "\@INX" is specified, the formatted result is outputted to INX.
 * When "\@MIF" is specified, the formatted result is outputted to MIF.
 * When "\@TEXT" is specified, the formatted result is outputted to a text format file.
 * When "\@AreaTree" is specified, the AreaTree will be outputted.
 * When omitted, it is considered as "\@PDF" was specified.
 * It's impossible to output to the printer with any OS's other than Windows.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the printer name.
 */
DFVINTERFACE_API void dfv_setPrinterName(CDfvObjPtr pDfvObj, const char* newVal);
/**
 * Specifies the output format or the printer name to output.
 * When a printer name is specified, the formatted result is outputted to that printer.
 * When "\@STDPRN" is specified, the formatted result is outputted to the currently used printer.
 * When "\@PDF" is specified, the formatted result is outputted to PDF.
 * When "\@SVG" is specified, the formatted result is outputted to SVG.
 * When "\@PS" is specified, the formatted result is outputted to PostScript.
 * When "\@INX" is specified, the formatted result is outputted to INX.
 * When "\@MIF" is specified, the formatted result is outputted to MIF.
 * When "\@TEXT" is specified, the formatted result is outputted to a text format file.
 * When "\@AreaTree" is specified, the AreaTree will be outputted.
 * When omitted, it is considered as "\@PDF" was specified.
 * It's impossible to output to the printer with any OS's other than Windows.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the printer name.
 */
DFVINTERFACE_API void dfv_setPrinterNameW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

#if defined(_DOXYGEN) || (defined(_MSC_VER) && defined(_WIN32))

/**
 * Get the number of copies. Effective when outputting to printer.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	Returns the number of copies.
 */
DFVINTERFACE_API long dfv_getPrnCopies(CDfvObjPtr pDfvObj);

/**
 * Specifies the number of copies. Effective when outputting to printer.
 * If nothing is specified, the value is considered as 1.
 * This setting is effective only with Windows version.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	the number of copies.
 */
DFVINTERFACE_API void dfv_setPrnCopies(CDfvObjPtr pDfvObj, long newVal);

/**
 * Get collation of multiple copies.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	If zero is returned, the same page is multi-copied continuously.
 * 			  If nonezero is returned, the pages specified from start to end are printed repeatedly.
 */
DFVINTERFACE_API long dfv_getPrnCollate(CDfvObjPtr pDfvObj);

/**
 * Specifies collation of multiple copies. Effective when outputting to printer and the number of
 * copies is plural. If it is not specified or the value zero is specified, the same page is
 * multi-copied continuously.
 * If nonezero is specified, the pages specified from start to end are printed repeatedly.
 * This setting is effective only with Windows version.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Zpecifies zero or nonzero.
 */
DFVINTERFACE_API void dfv_setPrnCollate(CDfvObjPtr pDfvObj, long newVal);

/**
 * Get the setting of whether print dialog box is displayed or not when printing
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	If zero, the print dialog box is displayed. If nonezero, the print dialog box is not displayed.
 */
DFVINTERFACE_API long dfv_getBatchPrint(CDfvObjPtr pDfvObj);

/**
 * When the value 'false' is specified, the print dialog box is displayed when printing.
 * If the setting is omitted or the value 'true' is specified, the print dialog is not displayed.
 * This setting is effective only with Windows version.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If zero, the print dialog box is displayed. If nonezero, the print dialog box is not displayed.
 */
DFVINTERFACE_API void dfv_setBatchPrint(CDfvObjPtr pDfvObj, long newVal);

#endif	/* _WIN32 */

/**
 * Get the version string of Server Based Converter.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getVersion(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * Get the version string of Server Based Converter.
 * 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getVersionW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Get INX output mode.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	output mode of INX.
 */
DFVINTERFACE_API DfvINXOUTPUTMODE dfv_getInxOutputMode(CDfvObjPtr pDfvObj);

/**
 * Set INX output mode.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal mode of INX.
 */
DFVINTERFACE_API void dfv_setInxOutputMode(CDfvObjPtr pDfvObj, DfvINXOUTPUTMODE newVal);

/**
 * Get the specification that omit blank pages. return Specification that omit blank pages 
 */
DFVINTERFACE_API int dfv_getOmitBlankPages(CDfvObjPtr pDfvObj);
	
/**
 * Disregard any empty pages.
 * Effective only when the original file is MS Word or MS Excel. 
 * Specifies to disregard any empty pages at the beginning of document. 
 * By using this parameter with setEndPage = 1 parameter,
 * it is possible to acquire the output of the first page which has actual contents.
 * Other operation is not guaranteed. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		If the value is 'true' is specified, omit blank pages 
 */
DFVINTERFACE_API void dfv_setOmitBlankPages(CDfvObjPtr pDfvObj, int newVal);


/**
 * Get specifies of the FlashPartiallyOutput.
 * @since 2.1
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	specifies of FlashPartiallyOutput.
 */
DFVINTERFACE_API long dfv_getFlashPartiallyOutput(CDfvObjPtr pDfvObj);

/**
 * When an error occurs within the document, the flash file in process will be outputted.
 * Effective when outputting to Flash.
 * @since 2.1
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If the value is 'true' is specified, output the flash file.
 */
DFVINTERFACE_API void dfv_setFlashPartiallyOutput(CDfvObjPtr pDfvObj, long newVal);

/**
 * Get specifies of the FlashHidePageButton.
 * @since 3.0
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return	specifies of FlashHidePageButton.
 */
DFVINTERFACE_API long dfv_getFlashHidePageButton(CDfvObjPtr pDfvObj);

/**
 * Output a no page button. Effective when outputting to Flash.
 * @since 3.0
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	If the value is 'true' is specified, output a no page button.
 */
DFVINTERFACE_API void dfv_setFlashHidePageButton(CDfvObjPtr pDfvObj, long newVal);

#if defined(_DOXYGEN) || (defined(_MSC_VER) && defined(_WIN32))

/**
 * It print at size of paper.
 * Default is false.
 * Effective when outputting to printer, and only Windows version. 
 * 
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		If the value is 'true' is specified, print at size of paper. 
 */
DFVINTERFACE_API void dfv_setPrnFitPaper(CDfvObjPtr pDfvObj, int newVal);

/**
 * Specifies the scaling ratio of the PDF to output.
 * A value with a unit or % value can be specified as length.
 * Effective when outputting to PDF. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		the scaling ratio of the PDF 
 */
DFVINTERFACE_API void dfv_setPdfOutputScale(CDfvObjPtr pDfvObj, const char* newVal);
DFVINTERFACE_API void dfv_setPdfOutputScaleW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Get the image resolution when outputting JPEG and PNG.
 * This setting is effective only with Windows version.
 * Effective when outputting to image, and only Windows version. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return		Image resolution 
 */
DFVINTERFACE_API int dfv_getRasterDPI(CDfvObjPtr pDfvObj);

/**
 * Effective when outputting to image, and only Windows version. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		Image resolution (50 to 500) 
 */
DFVINTERFACE_API void dfv_setRasterDPI(CDfvObjPtr pDfvObj, int newVal);

/**
 *  Get the image scale when outputting JPEG and PNG.
 * Effective when outputting to image, and only Windows version. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the image copy path. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return		Image scale 
 */
DFVINTERFACE_API char* dfv_getRasterScale(CDfvObjPtr pDfvObj, char* pVal, int size);
DFVINTERFACE_API wchar_t* dfv_getRasterScaleW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Sets the image scale when outputting JPEG and PNG.
 * A numerical value, "%", or "px" (pixel) is available as the unit.
 * Specify the percentage for a numerical value and "%", and specify the width of image for pixel.
 * Effective when outputting to image, and only Windows version. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		Image scale 
 */
DFVINTERFACE_API void dfv_setRasterScale(CDfvObjPtr pDfvObj, const char* newVal);
DFVINTERFACE_API void dfv_setRasterScaleW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Get the maximum image height when outputting JPEG and PNG.<BR>
 * Effective when outputting to image, and only Windows version.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return			Maximum image height
 */
DFVINTERFACE_API int dfv_getRasterHeight(CDfvObjPtr pDfvObj);

/**
 * Sets the maximum image height decided by setRasterScale when outputting JPEG and PNG.<BR>
 * "px" (pixel) is available as the unit. 
 * Effective when outputting to image, and only Windows version.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Maximum image height
 */
DFVINTERFACE_API void dfv_setRasterHeight(CDfvObjPtr pDfvObj, int newVal);

/**
 * Get the file name naming format when outputting PNG and JPEG.<BR>
 * Effective when outputting to image, and only Windows version.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		Pointer to the buffer that will receive the image copy path. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return			format for naming files
 */
DFVINTERFACE_API char* dfv_getRasterFormat(CDfvObjPtr pDfvObj, char* pVal, int size);
DFVINTERFACE_API wchar_t* dfv_getRasterFormatW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * Specifies the file name naming format when outputting PNG and JPEG.<BR>
 * Effective when outputting to image, and only Windows version.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	format for naming files
 */
DFVINTERFACE_API void dfv_setRasterFormat(CDfvObjPtr pDfvObj, const char* newVal);
DFVINTERFACE_API void dfv_setRasterFormatW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Get the conversion accuracy when outputting JPEG.<BR>
 * Effective when outputting to image, and only Windows version.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return			JPEG quality
 */
DFVINTERFACE_API int dfv_getRasterJpegQuality(CDfvObjPtr pDfvObj);

/**
 * Specifies the conversion accuracy by the value with the range of 1-100(%) when outputting JPEG.<BR>
 * When this parameter is omitted, it is regarded as 80%.
 * Effective when outputting to image, and only Windows version.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	JPEG quality
 */
DFVINTERFACE_API void dfv_setRasterJpegQuality(CDfvObjPtr pDfvObj, int newVal);

/**
 * Gets specification whether to use GdiPlus .<BR>
 * Effective when outputting to image, and only Windows version.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * return			Specification whether to use GdiPlus.
 */
DFVINTERFACE_API long dfv_getRasterUseGdiPlus(CDfvObjPtr pDfvObj);

/**
 * GdiPlus is used when the file is converted to Jpeg or PNG.<BR>
 * This setting is effective only with Windows XP or later / Windows Server2003.
 * Effective when outputting to image, and only Windows version.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param newVal Specifies whether to use GdiPlus.
 */
DFVINTERFACE_API void dfv_setRasterUseGdiPlus(CDfvObjPtr pDfvObj, long newVal);

/**
 * Gets specification whether to convert to monochrome image, when outputting JPEG and PNG.<BR>
 * Effective when outputting to image, and only Windows version.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * return			Specification whether to convert to monochrome.
 */
DFVINTERFACE_API long dfv_getRasterMonochrome(CDfvObjPtr pDfvObj);

/**
 * Specifies whether to convert to monochrome image, when outputting JPEG and PNG.<BR>
 * Effective when outputting to image, and only Windows version.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param newVal Specifies whether to convert to monochrome.
 */
DFVINTERFACE_API void dfv_setRasterMonochrome(CDfvObjPtr pDfvObj, long newVal);

#endif	// #if defined(_DOXYGEN) || (defined(_MSC_VER) && defined(_WIN32))

/**
 * Specifies the height of the paper when inputting text.
 * Effective when inputting text. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		the height of paper 
 */
DFVINTERFACE_API void dfv_setTextPaperHeight(CDfvObjPtr pDfvObj, const char* newVal);
DFVINTERFACE_API void dfv_setTextPaperHeightW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Specifies the width of the paper when inputting text.
 * Effective when inputting text. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		the width of paper 
 */
DFVINTERFACE_API void dfv_setTextPaperWidth(CDfvObjPtr pDfvObj, const char* newVal);
DFVINTERFACE_API void dfv_setTextPaperWidthW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Specifies the left margin of the paper when inputting text.
 * Effective when inputting text. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		 the left margin of the paper 
 */
DFVINTERFACE_API void dfv_setTextMarginLeft(CDfvObjPtr pDfvObj, const char* newVal);
DFVINTERFACE_API void dfv_setTextMarginLeftW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Specifies the right margin of the paper when inputting text.
 * Effective when inputting text. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		the top margin of the paper 
 */
DFVINTERFACE_API void dfv_setTextMarginTop(CDfvObjPtr pDfvObj, const char* newVal);
DFVINTERFACE_API void dfv_setTextMarginTopW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Specifies the right margin of the paper when inputting text.
 * Effective when inputting text. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		the right margin of the paper 
 */
DFVINTERFACE_API void dfv_setTextMarginRight(CDfvObjPtr pDfvObj, const char* newVal);
DFVINTERFACE_API void dfv_setTextMarginRightW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Specifies the right margin of the paper when inputting text.
 * Effective when inputting text. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		the bottom margin of the paper 
 */
DFVINTERFACE_API void dfv_setTextMarginBottom(CDfvObjPtr pDfvObj, const char* newVal);
DFVINTERFACE_API void dfv_setTextMarginBottomW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Specifies the font family name when inputting text.
 * Effective when inputting text. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		font family name 
 */
DFVINTERFACE_API void dfv_setTextFontFamily(CDfvObjPtr pDfvObj, const char* newVal);
DFVINTERFACE_API void dfv_setTextFontFamilyW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Specifies the font size when inputting text.
 * Effective when inputting text. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		font size 
 */
DFVINTERFACE_API void dfv_setTextFontSize(CDfvObjPtr pDfvObj, const char* newVal);
DFVINTERFACE_API void dfv_setTextFontSizeW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Specifies the value of whether show page number or not when inputting text.
 * Effective when inputting text. 
 * 
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		the value of whether show page number or not 
 */
DFVINTERFACE_API void dfv_setTextShowPageNumber(CDfvObjPtr pDfvObj, int newVal);

/**
 * Specifies the value of whether show page number or not when inputting text.
 * Effective when inputting text. 
 * 
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		the value of whether show page number or not 	
 */
DFVINTERFACE_API void dfv_setTextShowLineNumber(CDfvObjPtr pDfvObj, int newVal);

/**
 * Specifies the offset value of range from body area when showing line number and inputting text.
 * Effective when inputting text. 
 * 
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		the offset value
 */
DFVINTERFACE_API void dfv_setTextLineNumberOffset(CDfvObjPtr pDfvObj, const char* newVal);
DFVINTERFACE_API void dfv_setTextLineNumberOffsetW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * Specifies the line number format when showing line number and inputting text.
 * Effective when inputting text. 
 * 
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal		line number format 	
 */
DFVINTERFACE_API void dfv_setTextLineNumberFormat(CDfvObjPtr pDfvObj, const char* newVal);
DFVINTERFACE_API void dfv_setTextLineNumberFormatW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

#if defined(_DOXYGEN) || (defined(_MSC_VER) && defined(_WIN32))
/**
 * Acquires the setting of the smoothing processing to text.<BR>
 * This setting is effective only with Windows XP or later / Windows Server2003 or later.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return			
 * Specify whether to perform the smoothing processing to text.
 */
DFVINTERFACE_API int dfv_getGdiTextAntialias(CDfvObjPtr pDfvObj);

/**
 * Performs the smoothing processing to text.<BR>
 * Effective only when printing and outputting images.<BR>
 * This setting is effective only with Windows XP or later / Windows Server2003 or later.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	
 * Performs the smoothing processing when true is specified.
 */
DFVINTERFACE_API void dfv_setGdiTextAntialias(CDfvObjPtr pDfvObj, int newVal);

/**
 * Acquires the setting of the smoothing processing to borders.<BR>
 * This setting is effective only with Windows XP or later / Windows Server2003 or later.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return			
 * Specify whether to perform the smoothing processing to borders.
 */
DFVINTERFACE_API int dfv_getGdiLineartSmoothing(CDfvObjPtr pDfvObj);

/**
 * Performs the smoothing processing to borders.<BR>
 * Effective only when printing and outputting images.<BR>
 * This setting is effective only with Windows XP or later / Windows Server2003 or later.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	
 * Performs the smoothing processing when true is specified.
 */
DFVINTERFACE_API void dfv_setGdiLineartSmoothing(CDfvObjPtr pDfvObj, int newVal);

/**
 * Acquires the setting of the smoothing processing to images.<BR>
 * This setting is effective only with Windows XP or later / Windows Server2003 or later.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @return			
 * Specify whether to perform the smoothing processing to images.
 */
DFVINTERFACE_API int dfv_getGdiImageSmoothing(CDfvObjPtr pDfvObj);

/**
 * Performs the smoothing processing to images.<BR>
 * Effective only when printing and outputting images.<BR>
 * This setting is effective only with Windows XP or later / Windows Server2003 or later.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	
 * Performs the smoothing processing when true is specified.
 */
DFVINTERFACE_API void dfv_setGdiImageSmoothing(CDfvObjPtr pDfvObj, int newVal);
#endif

/**
 * @deprecated
 * Get the watermark text on each page.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		
 *			Pointer to the buffer that will receive the text. 
 *			If the string is as long or longer than the buffer,
 *			the string is truncated and terminated with a NULL character.
 * @param	size
 *			Specifies the number of the 'pVal' buffer, including the NULL character.
 *			If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getWatermarkText(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * @deprecated
 * Get the watermark text on each page. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		
 *			Pointer to the buffer that will receive the text. 
 *			If the string is as long or longer than the buffer,
 *			the string is truncated and terminated with a NULL character.
 * @param	size
 *			Specifies the number of the 'pVal' buffer, including the NULL character.
 *			If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getWatermarkTextW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * @deprecated
 * Displays the specified watermark text on each page. 
 * Possible to make it multiple lines by delimiting with the line feed \n. 
 * This setting is invalid with the evaluation version.  
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string.
 */
DFVINTERFACE_API void dfv_setWatermarkText(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * @deprecated
 * Displays the specified watermark text on each page. 
 * Possible to make it multiple lines by delimiting with the line feed \n. 
 * This setting is invalid with the evaluation version.  
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string.
 */
DFVINTERFACE_API void dfv_setWatermarkTextW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * @deprecated
 * Get the font family of the watermark text.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		
 *			Pointer to the buffer that will receive the text. 
 *			If the string is as long or longer than the buffer,
 *			the string is truncated and terminated with a NULL character.
 * @param	size
 *			Specifies the number of the 'pVal' buffer, including the NULL character.
 *			If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getWatermarkFontFamily(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * @deprecated
 * Get the font family of the watermark text.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		
 *			Pointer to the buffer that will receive the text. 
 *			If the string is as long or longer than the buffer,
 *			the string is truncated and terminated with a NULL character.
 * @param	size
 *			Specifies the number of the 'pVal' buffer, including the NULL character.
 *			If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getWatermarkFontFamilyW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * @deprecated
 * Specifies the font family to the character string which you set to watermark-text.  
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string.
 */
DFVINTERFACE_API void dfv_setWatermarkFontFamily(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * @deprecated
 * Specifies the font family to the character string which you set to watermark-text.  
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string.
 */
DFVINTERFACE_API void dfv_setWatermarkFontFamilyW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * @deprecated
 * Get the font weight of the watermark text.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		
 *			Pointer to the buffer that will receive the text. 
 *			If the string is as long or longer than the buffer,
 *			the string is truncated and terminated with a NULL character.
 * @param	size
 *			Specifies the number of the 'pVal' buffer, including the NULL character.
 *			If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getWatermarkFontWeight(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * @deprecated
 * Get the font weight of the watermark text. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		
 *			Pointer to the buffer that will receive the text. 
 *			If the string is as long or longer than the buffer,
 *			the string is truncated and terminated with a NULL character.
 * @param	size
 *			Specifies the number of the 'pVal' buffer, including the NULL character.
 *			If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getWatermarkFontWeightW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * @deprecated
 * Specifies the font weight to the character string which you set to watermark-text. 
 * Possible to specify normal, bold or the numerical value from 100 to 900.  
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string.
 */
DFVINTERFACE_API void dfv_setWatermarkFontWeight(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * @deprecated
 * Specifies the font weight to the character string which you set to watermark-text. 
 * Possible to specify normal, bold or the numerical value from 100 to 900.  
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string.
 */
DFVINTERFACE_API void dfv_setWatermarkFontWeightW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * @deprecated
 * Get the font style of the watermark text.
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		
 *			Pointer to the buffer that will receive the text. 
 *			If the string is as long or longer than the buffer,
 *			the string is truncated and terminated with a NULL character.
 * @param	size
 *			Specifies the number of the 'pVal' buffer, including the NULL character.
 *			If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getWatermarkFontStyle(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * @deprecated
 * Get the font style of the watermark text. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		
 *			Pointer to the buffer that will receive the text. 
 *			If the string is as long or longer than the buffer,
 *			the string is truncated and terminated with a NULL character.
 * @param	size
 *			Specifies the number of the 'pVal' buffer, including the NULL character.
 *			If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getWatermarkFontStyleW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * @deprecated
 * Specifies the font style to the character string which you set to watermark-text.  
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string.
 */
DFVINTERFACE_API void dfv_setWatermarkFontStyle(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * @deprecated
 * Specifies the font style to the character string which you set to watermark-text.  
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string.
 */
DFVINTERFACE_API void dfv_setWatermarkFontStyleW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

/**
 * @deprecated
 * Get the opacity of the watermark text. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		
 *			Pointer to the buffer that will receive the text. 
 *			If the string is as long or longer than the buffer,
 *			the string is truncated and terminated with a NULL character.
 * @param	size
 *			Specifies the number of the 'pVal' buffer, including the NULL character.
 *			If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API char* dfv_getWatermarkOpacity(CDfvObjPtr pDfvObj, char* pVal, int size);

/**
 * @deprecated
 * Get the opacity of the watermark text. 
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	pVal		
 *			Pointer to the buffer that will receive the text. 
 *			If the string is as long or longer than the buffer,
 *			the string is truncated and terminated with a NULL character.
 * @param	size
 *			Specifies the number of the 'pVal' buffer, including the NULL character.
 *			If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
DFVINTERFACE_API wchar_t* dfv_getWatermarkOpacityW(CDfvObjPtr pDfvObj, wchar_t* pVal, int size);

/**
 * @deprecated
 * Specifies the opacity to the character string which you set to watermark-text.  
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string.
 */
DFVINTERFACE_API void dfv_setWatermarkOpacity(CDfvObjPtr pDfvObj, const char* newVal);

/**
 * @deprecated
 * Specifies the opacity to the character string which you set to watermark-text.  
 *
 * @param	pDfvObj	Pointer to DfvObj instance.
 * @param	newVal	Pointer to a null-terminated string.
 */
DFVINTERFACE_API void dfv_setWatermarkOpacityW(CDfvObjPtr pDfvObj, const wchar_t* newVal);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif	/* DFVIFC_C_H__ */
