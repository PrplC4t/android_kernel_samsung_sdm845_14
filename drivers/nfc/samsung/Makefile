#
# Makefile for nfc devices
#

obj-$(CONFIG_SEC_NFC)		+= sec_nfc.o
obj-$(CONFIG_NFC_PN547)		+= pn547.o
obj-$(CONFIG_NFC_PN547_ESE_SUPPORT)		+= p61.o
obj-$(CONFIG_ESE_P3_LSI)		+= ese_p3.o
obj-y				+= nfc_logger/

ccflags-$(CONFIG_NFC_DEBUG) := -DDEBUG

ifneq ($(SEC_BUILD_CONF_USE_ESE_TZ), false)
	ccflags-y += -DENABLE_ESE_SPI_SECURED
endif
