#############################################
#                 MakeFile                  #
#############################################

.PHONY: all
all: gpio i2c spi main

gpio:
	cd GPIO && $(MAKE)

i2c:
    cd I2C && $(MAKE)

spi:
    cd SPI && $(MAKE)

main:
	cd MAIN && $(MAKE)


uninstall:
	rm output/*.o