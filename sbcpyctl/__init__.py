import os
from ctypes import *

dfvifc_c = None
if os.name == "nt":
	dfvifc_c = cdll.LoadLibrary("DfvInterface")
else:
	dfvifc_c = cdll.LoadLibrary("libDfvInterface.so")

if dfvifc_c == None:
	raise StandardError("DfvInterface library was not loaded.")

class DfvObj:
	def __init__(self):
		self.pDfvObj = dfvifc_c.dfv_createDfvObject(None)

	def releaseDfvObject(self):
		dfvifc_c.dfv_releaseDfvObject(self.pDfvObj)

	def getDocumentURI(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getDocumentURI.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getDocumentURI.restype = c_char_p
		return dfvifc_c.dfv_getDocumentURI(self.pDfvObj, cstr, 1024)

	def setDocumentURI(self, newVal):
		dfvifc_c.dfv_setDocumentURI(self.pDfvObj, newVal)

	def getOutputFilePath(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getOutputFilePath.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getOutputFilePath.restype = c_char_p
		return dfvifc_c.dfv_getOutputFilePath(self.pDfvObj, cstr, 1024)

	def setOutputFilePath(self, newVal):
		dfvifc_c.dfv_setOutputFilePath(self.pDfvObj, newVal)

	def getOptionFileURI(self, n):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getOptionFileURI.argtypes = [c_void_p, c_char_p, c_int, c_int]
		dfvifc_c.dfv_getOptionFileURI.restype = c_char_p
		return dfvifc_c.dfv_getOptionFileURI(self.pDfvObj, cstr, 1024, n)

	def setOptionFileURI(self, newVal):
		dfvifc_c.dfv_setOptionFileURI(self.pDfvObj, newVal)

	def addOptionFileURI(self, newVal):
		dfvifc_c.dfv_addOptionFileURI(self.pDfvObj, newVal)

	def getOptionFileCount(self):
		return dfvifc_c.dfv_getOptionFileCount(self.pDfvObj)

	def getStartPage(self):
		return dfvifc_c.dfv_getStartPage(self.pDfvObj)

	def setStartPage(self, newVal):
		dfvifc_c.dfv_setStartPage(self.pDfvObj, newVal)

	def getEndPage(self):
		return dfvifc_c.dfv_getEndPage(self.pDfvObj)

	def setEndPage(self, newVal):
		dfvifc_c.dfv_setEndPage(self.pDfvObj, newVal)

	def setPdfOwnerPassword(self, newVal):
		dfvifc_c.dfv_setPdfOwnerPassword(self.pDfvObj, newVal)

	def setPdfUserPassword(self, newVal):
		dfvifc_c.dfv_setPdfUserPassword(self.pDfvObj, newVal)

	def setPdfNoPrinting(self, newVal):
		dfvifc_c.dfv_setPdfNoPrinting(self.pDfvObj, newVal)

	def getPdfNoPrinting(self):
		return dfvifc_c.dfv_getPdfNoPrinting(self.pDfvObj)

	def setPdfNoChanging(self, newVal):
		dfvifc_c.dfv_setPdfNoChanging(self.pDfvObj, newVal)

	def getPdfNoChanging(self):
		return dfvifc_c.dfv_getPdfNoChanging(self.pDfvObj)

	def setPdfNoContentCopying(self, newVal):
		dfvifc_c.dfv_setPdfNoContentCopying(self.pDfvObj, newVal)

	def getPdfNoContentCopying(self):
		return dfvifc_c.dfv_getPdfNoContentCopying(self.pDfvObj)

	def setPdfNoAddingOrChangingCommnets(self, newVal):
		dfvifc_c.dfv_setPdfNoAddingOrChangingCommnets(self.pDfvObj, newVal)

	def getPdfNoAddingOrChangingCommnets(self):
		return dfvifc_c.dfv_getPdfNoAddingOrChangingCommnets(self.pDfvObj)

	def setPdfNoAddingOrChangingComments(self, newVal):
		dfvifc_c.dfv_setPdfNoAddingOrChangingComments(self.pDfvObj, newVal)

	def getPdfNoAddingOrChangingComments(self):
		return dfvifc_c.dfv_getPdfNoAddingOrChangingComments(self.pDfvObj)

	def setPdfVersion(self, newVal):
		dfvifc_c.dfv_setPdfVersion(self.pDfvObj, newVal)

	def getPdfVersion(self):
		return dfvifc_c.dfv_getPdfVersion(self.pDfvObj)

	def setPdfNoFillForm(self, newVal):
		dfvifc_c.dfv_setPdfNoFillForm(self.pDfvObj, newVal)

	def getPdfNoFillForm(self):
		return dfvifc_c.dfv_getPdfNoFillForm(self.pDfvObj)

	def setPdfNoAccessibility(self, newVal):
		dfvifc_c.dfv_setPdfNoAccessibility(self.pDfvObj, newVal)

	def getPdfNoAccessibility(self):
		return dfvifc_c.dfv_getPdfNoAccessibility(self.pDfvObj)

	def setPdfNoAssembleDoc(self, newVal):
		dfvifc_c.dfv_setPdfNoAssembleDoc(self.pDfvObj, newVal)

	def getPdfNoAssembleDoc(self):
		return dfvifc_c.dfv_getPdfNoAssembleDoc(self.pDfvObj)

	def setPdfEncryptLevel(self, newVal):
		dfvifc_c.dfv_setPdfEncryptLevel(self.pDfvObj, newVal)

	def getPdfEncryptLevel(self):
		return dfvifc_c.dfv_getPdfEncryptLevel(self.pDfvObj)

	def getPdfEmbedAllFonts(self):
		return dfvifc_c.dfv_getPdfEmbedAllFonts(self.pDfvObj)

	def setPdfEmbedAllFonts(self, newVal):
		dfvifc_c.dfv_setPdfEmbedAllFonts(self.pDfvObj, newVal)

	def getPdfEmbedFonts(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getPdfEmbedFonts.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getPdfEmbedFonts.restype = c_char_p
		return dfvifc_c.dfv_getPdfEmbedFonts(self.pDfvObj, cstr, 1024)

	def setPdfEmbedFonts(self, newVal):
		dfvifc_c.dfv_setPdfEmbedFonts(self.pDfvObj, newVal)

	def getPdfErrorOnEmbedFault(self):
		return dfvifc_c.dfv_getPdfErrorOnEmbedFault(self.pDfvObj)

	def setPdfErrorOnEmbedFault(self, newVal):
		dfvifc_c.dfv_setPdfErrorOnEmbedFault(self.pDfvObj, newVal)

	def getPdfErrorOnMissingGlyph(self):
		return dfvifc_c.dfv_getPdfErrorOnMissingGlyph(self.pDfvObj)

	def setPdfErrorOnMissingGlyph(self, newVal):
		dfvifc_c.dfv_setPdfErrorOnMissingGlyph(self.pDfvObj, newVal)

	def getPdfPrintingAllowed(self):
		return dfvifc_c.dfv_getPdfPrintingAllowed(self.pDfvObj)

	def setPdfPrintingAllowed(self, newVal):
		dfvifc_c.dfv_setPdfPrintingAllowed(self.pDfvObj, newVal)

	def getPdfImageCompression(self):
		return dfvifc_c.dfv_getPdfImageCompression(self.pDfvObj)

	def setPdfImageCompression(self, newVal):
		dfvifc_c.dfv_setPdfImageCompression(self.pDfvObj, newVal)

	def getPdfJPEGQuality(self):
		return dfvifc_c.dfv_getPdfJPEGQuality(self.pDfvObj)

	def setPdfJPEGQuality(self, newVal):
		dfvifc_c.dfv_setPdfJPEGQuality(self.pDfvObj, newVal)

	def getPdfCompressContentStream(self):
		return dfvifc_c.dfv_getPdfCompressContentStream(self.pDfvObj)

	def setPdfCompressContentStream(self, newVal):
		dfvifc_c.dfv_setPdfCompressContentStream(self.pDfvObj, newVal)

	def getPdfUseLaunchForRelativeURI(self):
		return dfvifc_c.dfv_getPdfUseLaunchForRelativeURI(self.pDfvObj)

	def setPdfUseLaunchForRelativeURI(self, newVal):
		dfvifc_c.dfv_setPdfUseLaunchForRelativeURI(self.pDfvObj, newVal)

	def getPdfRGBConversion(self):
		return dfvifc_c.dfv_getPdfRGBConversion(self.pDfvObj)

	def setPdfRGBConversion(self, newVal):
		dfvifc_c.dfv_setPdfRGBConversion(self.pDfvObj, newVal)

	def getPdfRasterizeResolution(self):
		return dfvifc_c.dfv_getPdfRasterizeResolution(self.pDfvObj)

	def setPdfRasterizeResolution(self, newVal):
		dfvifc_c.dfv_setPdfRasterizeResolution(self.pDfvObj, newVal)

	def getPdfLinearize(self):
		return dfvifc_c.dfv_getPdfLinearize(self.pDfvObj)

	def setPdfLinearize(self, newVal):
		dfvifc_c.dfv_setPdfLinearize(self.pDfvObj, newVal)

	def getPdfEmbedAllFontsEx(self):
		return dfvifc_c.dfv_getPdfEmbedAllFontsEx(self.pDfvObj)

	def setPdfEmbedAllFontsEx(self, newVal):
		dfvifc_c.dfv_setPdfEmbedAllFontsEx(self.pDfvObj, newVal)

	def getPdfImageDownSampling(self):
		return dfvifc_c.dfv_getPdfImageDownSampling(self.pDfvObj)

	def setPdfImageDownSampling(self, newVal):
		dfvifc_c.dfv_setPdfImageDownSampling(self.pDfvObj, newVal)

	def getPdfImageDownSamplingTarget(self):
		return dfvifc_c.dfv_getPdfImageDownSamplingTarget(self.pDfvObj)

	def setPdfImageDownSamplingTarget(self, newVal):
		dfvifc_c.dfv_setPdfImageDownSamplingTarget(self.pDfvObj, newVal)

	def getPdfImageDownSamplingDPI(self):
		return dfvifc_c.dfv_getPdfImageDownSamplingDPI(self.pDfvObj)

	def setPdfImageDownSamplingDPI(self, newVal):
		dfvifc_c.dfv_setPdfImageDownSamplingDPI(self.pDfvObj, newVal)

	def getPdfPutImageColorProfile(self):
		return dfvifc_c.dfv_getPdfPutImageColorProfile(self.pDfvObj)

	def setPdfPutImageColorProfile(self, newVal):
		dfvifc_c.dfv_setPdfPutImageColorProfile(self.pDfvObj, newVal)

	def getPdfGrayscaleImageCompression(self):
		return dfvifc_c.dfv_getPdfGrayscaleImageCompression(self.pDfvObj)

	def setPdfGrayscaleImageCompression(self, newVal):
		dfvifc_c.dfv_setPdfGrayscaleImageCompression(self.pDfvObj, newVal)

	def getPdfGrayscaleJPEGQuality(self):
		return dfvifc_c.dfv_getPdfGrayscaleJPEGQuality(self.pDfvObj)

	def setPdfGrayscaleJPEGQuality(self, newVal):
		dfvifc_c.dfv_setPdfGrayscaleJPEGQuality(self.pDfvObj, newVal)

	def getPdfGrayscaleImageDownSampling(self):
		return dfvifc_c.dfv_getPdfGrayscaleImageDownSampling(self.pDfvObj)

	def setPdfGrayscaleImageDownSampling(self, newVal):
		dfvifc_c.dfv_setPdfGrayscaleImageDownSampling(self.pDfvObj, newVal)

	def getPdfGrayscaleImageDownSamplingTarget(self):
		return dfvifc_c.dfv_getPdfGrayscaleImageDownSamplingTarget(self.pDfvObj)

	def setPdfGrayscaleImageDownSamplingTarget(self, newVal):
		dfvifc_c.dfv_setPdfGrayscaleImageDownSamplingTarget(self.pDfvObj, newVal)

	def getPdfGrayscaleImageDownSamplingDPI(self):
		return dfvifc_c.dfv_getPdfGrayscaleImageDownSamplingDPI(self.pDfvObj)

	def setPdfGrayscaleImageDownSamplingDPI(self, newVal):
		dfvifc_c.dfv_setPdfGrayscaleImageDownSamplingDPI(self.pDfvObj, newVal)

	def getPdfMonochromeImageCompression(self):
		return dfvifc_c.dfv_getPdfMonochromeImageCompression(self.pDfvObj)

	def setPdfMonochromeImageCompression(self, newVal):
		dfvifc_c.dfv_setPdfMonochromeImageCompression(self.pDfvObj, newVal)

	def getPdfMonochromeImageDownSampling(self):
		return dfvifc_c.dfv_getPdfMonochromeImageDownSampling(self.pDfvObj)

	def setPdfMonochromeImageDownSampling(self, newVal):
		dfvifc_c.dfv_setPdfMonochromeImageDownSampling(self.pDfvObj, newVal)

	def getPdfMonochromeImageDownSamplingTarget(self):
		return dfvifc_c.dfv_getPdfMonochromeImageDownSamplingTarget(self.pDfvObj)

	def setPdfMonochromeImageDownSamplingTarget(self, newVal):
		dfvifc_c.dfv_setPdfMonochromeImageDownSamplingTarget(self.pDfvObj, newVal)

	def getPdfMonochromeImageDownSamplingDPI(self):
		return dfvifc_c.dfv_getPdfMonochromeImageDownSamplingDPI(self.pDfvObj)

	def setPdfMonochromeImageDownSamplingDPI(self, newVal):
		dfvifc_c.dfv_setPdfMonochromeImageDownSamplingDPI(self.pDfvObj, newVal)

	def getPdfOutputWidth(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getPdfOutputWidth.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getPdfOutputWidth.restype = c_char_p
		return dfvifc_c.dfv_getPdfOutputWidth(self.pDfvObj, cstr, 1024)

	def setPdfOutputWidth(self, newVal):
		dfvifc_c.dfv_setPdfOutputWidth(self.pDfvObj, newVal)

	def getPdfOutputHeight(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getPdfOutputHeight.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getPdfOutputHeight.restype = c_char_p
		return dfvifc_c.dfv_getPdfOutputHeight(self.pDfvObj, cstr, 1024)

	def setPdfOutputHeight(self, newVal):
		dfvifc_c.dfv_setPdfOutputHeight(self.pDfvObj, newVal)

	def getPdfErrorOnPDFXFault(self):
		return dfvifc_c.dfv_getPdfErrorOnPDFXFault(self.pDfvObj)

	def setPdfErrorOnPDFXFault(self, newVal):
		dfvifc_c.dfv_setPdfErrorOnPDFXFault(self.pDfvObj, newVal)

	def getSvgVersion(self):
		return dfvifc_c.dfv_getSvgVersion(self.pDfvObj)

	def setSvgVersion(self, newVal):
		dfvifc_c.dfv_setSvgVersion(self.pDfvObj, newVal)

	def getSvgGzipCompression(self):
		return dfvifc_c.dfv_getSvgGzipCompression(self.pDfvObj)

	def setSvgGzipCompression(self, newVal):
		dfvifc_c.dfv_setSvgGzipCompression(self.pDfvObj, newVal)

	def getSvgEmbedAllFonts(self):
		return dfvifc_c.dfv_getSvgEmbedAllFonts(self.pDfvObj)

	def setSvgEmbedAllFonts(self, newVal):
		dfvifc_c.dfv_setSvgEmbedAllFonts(self.pDfvObj, newVal)

	def getSvgFormat(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getSvgFormat.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getSvgFormat.restype = c_char_p
		return dfvifc_c.dfv_getSvgFormat(self.pDfvObj, cstr, 1024)

	def setSvgFormat(self, newVal):
		dfvifc_c.dfv_setSvgFormat(self.pDfvObj, newVal)

	def getSvgEmbedFonts(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getSvgEmbedFonts.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getSvgEmbedFonts.restype = c_char_p
		return dfvifc_c.dfv_getSvgEmbedFonts(self.pDfvObj, cstr, 1024)

	def setSvgEmbedFonts(self, newVal):
		dfvifc_c.dfv_setSvgEmbedFonts(self.pDfvObj, newVal)

	def getSvgErrorOnEmbedFault(self):
		return dfvifc_c.dfv_getSvgErrorOnEmbedFault(self.pDfvObj)

	def setSvgErrorOnEmbedFault(self, newVal):
		dfvifc_c.dfv_setSvgErrorOnEmbedFault(self.pDfvObj, newVal)

	def getSvgImageConversion(self):
		return dfvifc_c.dfv_getSvgImageConversion(self.pDfvObj)

	def setSvgImageConversion(self, newVal):
		dfvifc_c.dfv_setSvgImageConversion(self.pDfvObj, newVal)

	def getSvgJPEGQuality(self):
		return dfvifc_c.dfv_getSvgJPEGQuality(self.pDfvObj)

	def setSvgJPEGQuality(self, newVal):
		dfvifc_c.dfv_setSvgJPEGQuality(self.pDfvObj, newVal)

	def getSvgImageProcessingType(self):
		return dfvifc_c.dfv_getSvgImageProcessingType(self.pDfvObj)

	def setSvgImageProcessingType(self, newVal):
		dfvifc_c.dfv_setSvgImageProcessingType(self.pDfvObj, newVal)

	def getSvgImageCopyPath(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getSvgImageCopyPath.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getSvgImageCopyPath.restype = c_char_p
		return dfvifc_c.dfv_getSvgImageCopyPath(self.pDfvObj, cstr, 1024)

	def setSvgImageCopyPath(self, newVal):
		dfvifc_c.dfv_setSvgImageCopyPath(self.pDfvObj, newVal)

	def getSvgSingleFile(self):
		return dfvifc_c.dfv_getSvgSingleFile(self.pDfvObj)

	def setSvgSingleFile(self, newVal):
		dfvifc_c.dfv_setSvgSingleFile(self.pDfvObj, newVal)

	def getSvgSingleFileMaxPages(self):
		return dfvifc_c.dfv_getSvgSingleFileMaxPages(self.pDfvObj)

	def setSvgSingleFileMaxPages(self, newVal):
		dfvifc_c.dfv_setSvgSingleFileMaxPages(self.pDfvObj, newVal)

	def getSvgImageDownsamplingDPI(self):
		return dfvifc_c.dfv_getSvgImageDownsamplingDPI(self.pDfvObj)

	def setSvgImageDownsamplingDPI(self, dpi):
		dfvifc_c.dfv_setSvgImageDownsamplingDPI(self.pDfvObj, dpi)

	def getSvgImageDownsamplingMethod(self):
		return dfvifc_c.dfv_getSvgImageDownsamplingMethod(self.pDfvObj)

	def setSvgImageDownsamplingMethod(self, type):
		dfvifc_c.dfv_setSvgImageDownsamplingMethod(self.pDfvObj, type)

	def getSvgImageRename(self):
		return dfvifc_c.dfv_getSvgImageRename(self.pDfvObj)

	def setSvgImageRename(self, newVal):
		dfvifc_c.dfv_setSvgImageRename(self.pDfvObj, newVal)

	def getSvgImagePrefix(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getSvgImagePrefix.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getSvgImagePrefix.restype = c_char_p
		return dfvifc_c.dfv_getSvgImagePrefix(self.pDfvObj, cstr, 1024)

	def setSvgImagePrefix(self, newVal):
		dfvifc_c.dfv_setSvgImagePrefix(self.pDfvObj, newVal)

	def getSvgSinglePageNumber(self):
		return dfvifc_c.dfv_getSvgSinglePageNumber(self.pDfvObj)

	def setSvgSinglePageNumber(self, newVal):
		dfvifc_c.dfv_setSvgSinglePageNumber(self.pDfvObj, newVal)

	def getSvgRasterizeResolution(self):
		return dfvifc_c.dfv_getSvgRasterizeResolution(self.pDfvObj)

	def setSvgRasterizeResolution(self, newVal):
		dfvifc_c.dfv_setSvgRasterizeResolution(self.pDfvObj, newVal)

	def setMultiVolume(self, newVal):
		dfvifc_c.dfv_setMultiVolume(self.pDfvObj, newVal)

	def getExitLevel(self):
		return dfvifc_c.dfv_getExitLevel(self.pDfvObj)

	def setExitLevel(self, newVal):
		dfvifc_c.dfv_setExitLevel(self.pDfvObj, newVal)

	def getErrorLevel(self):
		return dfvifc_c.dfv_getErrorLevel(self.pDfvObj)

	def getErrorCode(self):
		return dfvifc_c.dfv_getErrorCode(self.pDfvObj)

	def getErrorMessage(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getErrorMessage.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getErrorMessage.restype = c_char_p
		return dfvifc_c.dfv_getErrorMessage(self.pDfvObj, cstr, 1024)

	def setFontAlias(self, src, dest):
		dfvifc_c.dfv_setFontAlias(self.pDfvObj, src, dest)

	def clearFontAlias(self):
		dfvifc_c.dfv_clearFontAlias(self.pDfvObj)

	def eraseFontAlias(self):
		dfvifc_c.dfv_eraseFontAlias(self.pDfvObj, src)

	def execute(self):
		return dfvifc_c.dfv_execute(self.pDfvObj)

	def clear(self):
		dfvifc_c.dfv_clear(self.pDfvObj)

	def setOnMessageProc(self, proc):
		self.onMessageProc_CALLBACK = CFUNCTYPE(None, c_int, c_long, c_char_p)
		self.onMessageProc_callback = self.onMessageProc_CALLBACK(proc)
		dfvifc_c.dfv_setOnMessageProc(self.pDfvObj, self.onMessageProc_callback)

	def setOnFormatPageProc(self, proc):
		self.onFormatPageProc_CALLBACK = CFUNCTYPE(None, c_long)
		self.onFormatPageProc_callback = self.onFormatPageProc_CALLBACK(proc)
		dfvifc_c.dfv_setOnFormatPageProc(self.pDfvObj, self.onFormatPageProc_callback)

	def getPrinterName(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getPrinterName.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getPrinterName.restype = c_char_p
		return dfvifc_c.dfv_getPrinterName(self.pDfvObj, cstr, 1024)

	def setPrinterName(self, newVal):
		dfvifc_c.dfv_setPrinterName(self.pDfvObj, newVal)

	def getPrnCopies(self):
		return dfvifc_c.dfv_getPrnCopies(self.pDfvObj)

	def setPrnCopies(self, newVal):
		dfvifc_c.dfv_setPrnCopies(self.pDfvObj, newVal)

	def getPrnCollate(self):
		return dfvifc_c.dfv_getPrnCollate(self.pDfvObj)

	def setPrnCollate(self, newVal):
		dfvifc_c.dfv_setPrnCollate(self.pDfvObj, newVal)

	def getBatchPrint(self):
		return dfvifc_c.dfv_getBatchPrint(self.pDfvObj)

	def setBatchPrint(self, newVal):
		dfvifc_c.dfv_setBatchPrint(self.pDfvObj, newVal)

	def getVersion(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getVersion.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getVersion.restype = c_char_p
		return dfvifc_c.dfv_getVersion(self.pDfvObj, cstr, 1024)

	def getInxOutputMode(self):
		return dfvifc_c.dfv_getInxOutputMode(self.pDfvObj)

	def setInxOutputMode(self, newVal):
		dfvifc_c.dfv_setInxOutputMode(self.pDfvObj, newVal)

	def getOmitBlankPages(self):
		return dfvifc_c.dfv_getOmitBlankPages(self.pDfvObj)

	def setOmitBlankPages(self, newVal):
		dfvifc_c.dfv_setOmitBlankPages(self.pDfvObj, newVal)

	def getFlashPartiallyOutput(self):
		return dfvifc_c.dfv_getFlashPartiallyOutput(self.pDfvObj)

	def setFlashPartiallyOutput(self, newVal):
		dfvifc_c.dfv_setFlashPartiallyOutput(self.pDfvObj, newVal)

	def getFlashHidePageButton(self):
		return dfvifc_c.dfv_getFlashHidePageButton(self.pDfvObj)

	def setFlashHidePageButton(self, newVal):
		dfvifc_c.dfv_setFlashHidePageButton(self.pDfvObj, newVal)

	def getFlashSplitPage(self):
		return dfvifc_c.dfv_getFlashSplitPage(self.pDfvObj)

	def setFlashSplitPage(self, newVal):
		dfvifc_c.dfv_setFlashSplitPage(self.pDfvObj, newVal)

	def getFlashOutputAction(self):
		return dfvifc_c.dfv_getFlashOutputAction(self.pDfvObj)

	def setFlashOutputAction(self, newVal):
		dfvifc_c.dfv_setFlashOutputAction(self.pDfvObj, newVal)

	def getFlashImageLimitSize(self):
		return dfvifc_c.dfv_getFlashImageLimitSize(self.pDfvObj)

	def setFlashImageLimitSize(self, newVal):
		dfvifc_c.dfv_setFlashImageLimitSize(self.pDfvObj, newVal)

	def setPrnFitPaper(self, newVal):
		dfvifc_c.dfv_setPrnFitPaper(self.pDfvObj, newVal)

	def setPdfOutputScale(self, newVal):
		dfvifc_c.dfv_setPdfOutputScale(self.pDfvObj, newVal)

	def getRasterDPI(self):
		return dfvifc_c.dfv_getRasterDPI(self.pDfvObj)

	def setRasterDPI(self, newVal):
		dfvifc_c.dfv_setRasterDPI(self.pDfvObj, newVal)

	def getRasterScale(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getRasterScale.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getRasterScale.restype = c_char_p
		return dfvifc_c.dfv_getRasterScale(self.pDfvObj, cstr, 1024)

	def setRasterScale(self, newVal):
		dfvifc_c.dfv_setRasterScale(self.pDfvObj, newVal)

	def getRasterHeight(self):
		return dfvifc_c.dfv_getRasterHeight(self.pDfvObj)

	def setRasterHeight(self, newVal):
		dfvifc_c.dfv_setRasterHeight(self.pDfvObj, newVal)

	def getRasterFormat(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getRasterFormat.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getRasterFormat.restype = c_char_p
		return dfvifc_c.dfv_getRasterFormat(self.pDfvObj, cstr, 1024)

	def setRasterFormat(self, newVal):
		dfvifc_c.dfv_setRasterFormat(self.pDfvObj, newVal)

	def getRasterJpegQuality(self):
		return dfvifc_c.dfv_getRasterJpegQuality(self.pDfvObj)

	def setRasterJpegQuality(self, newVal):
		dfvifc_c.dfv_setRasterJpegQuality(self.pDfvObj, newVal)

	def getRasterUseGdiPlus(self):
		return dfvifc_c.dfv_getRasterUseGdiPlus(self.pDfvObj)

	def setRasterUseGdiPlus(self, newVal):
		dfvifc_c.dfv_setRasterUseGdiPlus(self.pDfvObj, newVal)

	def getRasterMonochrome(self):
		return dfvifc_c.dfv_getRasterMonochrome(self.pDfvObj)

	def setRasterMonochrome(self, newVal):
		dfvifc_c.dfv_setRasterMonochrome(self.pDfvObj, newVal)

	def getRasterRGBProfile(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getRasterRGBProfile.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getRasterRGBProfile.restype = c_char_p
		return dfvifc_c.dfv_getRasterRGBProfile(self.pDfvObj, cstr, 1024)

	def setRasterRGBProfile(self, newVal):
		dfvifc_c.dfv_setRasterRGBProfile(self.pDfvObj, newVal)

	def getRasterCMYKProfile(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getRasterCMYKProfile.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getRasterCMYKProfile.restype = c_char_p
		return dfvifc_c.dfv_getRasterCMYKProfile(self.pDfvObj, cstr, 1024)

	def setRasterCMYKProfile(self, newVal):
		dfvifc_c.dfv_setRasterCMYKProfile(self.pDfvObj, newVal)

	def getRasterGrayscale(self):
		return dfvifc_c.dfv_getRasterGrayscale(self.pDfvObj)

	def setRasterGrayscale(self, newVal):
		dfvifc_c.dfv_setRasterGrayscale(self.pDfvObj, newVal)

	def getRaster256Color(self):
		return dfvifc_c.dfv_getRaster256Color(self.pDfvObj)

	def setRaster256Color(self, newVal):
		dfvifc_c.dfv_setRaster256Color(self.pDfvObj, newVal)

	def getRasterCompression(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getRasterCompression.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getRasterCompression.restype = c_char_p
		return dfvifc_c.dfv_getRasterCompression(self.pDfvObj, cstr, 1024)

	def setRasterCompression(self, newVal):
		dfvifc_c.dfv_setRasterCompression(self.pDfvObj, newVal)

	def setTextPaperHeight(self, newVal):
		dfvifc_c.dfv_setTextPaperHeight(self.pDfvObj, newVal)

	def setTextPaperWidth(self, newVal):
		dfvifc_c.dfv_setTextPaperWidth(self.pDfvObj, newVal)

	def setTextMarginLeft(self, newVal):
		dfvifc_c.dfv_setTextMarginLeft(self.pDfvObj, newVal)

	def setTextMarginTop(self, newVal):
		dfvifc_c.dfv_setTextMarginTop(self.pDfvObj, newVal)

	def setTextMarginRight(self, newVal):
		dfvifc_c.dfv_setTextMarginRight(self.pDfvObj, newVal)

	def setTextMarginBottom(self, newVal):
		dfvifc_c.dfv_setTextMarginBottom(self.pDfvObj, newVal)

	def setTextFontFamily(self, newVal):
		dfvifc_c.dfv_setTextFontFamily(self.pDfvObj, newVal)

	def setTextFontSize(self, newVal):
		dfvifc_c.dfv_setTextFontSize(self.pDfvObj, newVal)

	def setTextShowPageNumber(self, newVal):
		dfvifc_c.dfv_setTextShowPageNumber(self.pDfvObj, newVal)

	def setTextShowLineNumber(self, newVal):
		dfvifc_c.dfv_setTextShowLineNumber(self.pDfvObj, newVal)

	def setTextLineNumberOffset(self, newVal):
		dfvifc_c.dfv_setTextLineNumberOffset(self.pDfvObj, newVal)

	def setTextLineNumberFormat(self, newVal):
		dfvifc_c.dfv_setTextLineNumberFormat(self.pDfvObj, newVal)

	def getGdiTextAntialias(self):
		return dfvifc_c.dfv_getGdiTextAntialias(self.pDfvObj)

	def setGdiTextAntialias(self, newVal):
		dfvifc_c.dfv_setGdiTextAntialias(self.pDfvObj, newVal)

	def getGdiLineartSmoothing(self):
		return dfvifc_c.dfv_getGdiLineartSmoothing(self.pDfvObj)

	def setGdiLineartSmoothing(self, newVal):
		dfvifc_c.dfv_setGdiLineartSmoothing(self.pDfvObj, newVal)

	def getGdiImageSmoothing(self):
		return dfvifc_c.dfv_getGdiImageSmoothing(self.pDfvObj)

	def setGdiImageSmoothing(self, newVal):
		dfvifc_c.dfv_setGdiImageSmoothing(self.pDfvObj, newVal)

	def getWatermarkText(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getWatermarkText.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getWatermarkText.restype = c_char_p
		return dfvifc_c.dfv_getWatermarkText(self.pDfvObj, cstr, 1024)

	def setWatermarkText(self, newVal):
		dfvifc_c.dfv_setWatermarkText(self.pDfvObj, newVal)

	def getWatermarkFontFamily(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getWatermarkFontFamily.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getWatermarkFontFamily.restype = c_char_p
		return dfvifc_c.dfv_getWatermarkFontFamily(self.pDfvObj, cstr, 1024)

	def setWatermarkFontFamily(self, newVal):
		dfvifc_c.dfv_setWatermarkFontFamily(self.pDfvObj, newVal)

	def getWatermarkFontWeight(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getWatermarkFontWeight.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getWatermarkFontWeight.restype = c_char_p
		return dfvifc_c.dfv_getWatermarkFontWeight(self.pDfvObj, cstr, 1024)

	def setWatermarkFontWeight(self, newVal):
		dfvifc_c.dfv_setWatermarkFontWeight(self.pDfvObj, newVal)

	def getWatermarkFontStyle(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getWatermarkFontStyle.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getWatermarkFontStyle.restype = c_char_p
		return dfvifc_c.dfv_getWatermarkFontStyle(self.pDfvObj, cstr, 1024)

	def setWatermarkFontStyle(self, newVal):
		dfvifc_c.dfv_setWatermarkFontStyle(self.pDfvObj, newVal)

	def getWatermarkOpacity(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getWatermarkOpacity.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getWatermarkOpacity.restype = c_char_p
		return dfvifc_c.dfv_getWatermarkOpacity(self.pDfvObj, cstr, 1024)

	def setWatermarkOpacity(self, newVal):
		dfvifc_c.dfv_setWatermarkOpacity(self.pDfvObj, newVal)

	def getContinuePageNumber(self):
		return dfvifc_c.dfv_getContinuePageNumber(self.pDfvObj)

	def setContinuePageNumber(self, newVal):
		dfvifc_c.dfv_setContinuePageNumber(self.pDfvObj, newVal)

	def getPdfColorProfile(self):
		cstr = create_string_buffer(1024)
		dfvifc_c.dfv_getPdfColorProfile.argtypes = [c_void_p, c_char_p, c_int]
		dfvifc_c.dfv_getPdfColorProfile.restype = c_char_p
		return dfvifc_c.dfv_getPdfColorProfile(self.pDfvObj, cstr, 1024)

	def setPdfColorProfile(self, newVal):
		dfvifc_c.dfv_setPdfColorProfile(self.pDfvObj, newVal)

def onMessage(level, code, message):
	print "Level:", level
	print "Code:", code
	print "Message:", message
	print
	return None

if __name__=="__main__":
	import sys
	dfvObj = DfvObj()
	dfvObj.setExitLevel(4)
	dfvObj.setDocumentURI(sys.argv[1])
	dfvObj.setOutputFilePath(sys.argv[2])
	dfvObj.setOnMessageProc(onMessage)
	dfvObj.execute()

