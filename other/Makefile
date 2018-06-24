CC := arm-none-eabi-gcc
CFLAGS := -mfloat-abi=soft -march=armv4t -g -c 
INCLUDE_PATH := -I/opt/EmbedSky/4.3.3/armv4t/include -I../vtos/port/ -I../vtos/src/ -Idriver/inc/ -I../OsPro/UCGUI/Start/GUI/WM/ -I../OsPro/UCGUI/Start/GUI/Widget/ -I../OsPro/UCGUI/Start/GUI/Core/ -I../OsPro/UCGUIStart/JPEG/ -I../OsPro/UCGUI/Start/Config/
OBJS_PATH := objs/
SRCS_S := driver/src/start_s.S \
driver/src/mmu_s.S
OBJS_S := $(patsubst %.S, %.o, $(SRCS_S))
SRCS_C := driver/src/led.c \
driver/src/nand.c \
driver/src/start_c.c \
driver/src/timer.c \
driver/src/2440lib.c \
driver/src/LCD_TFT.c \
driver/src/Touchpanel.c \
driver/src/SD_MMC.c \
driver/src/mmu.c
OBJS_C := $(patsubst %.c, %.o, $(SRCS_C))
all : $(OBJS_PATH) $(OBJS_S) $(OBJS_C)

$(OBJS_PATH) :
	@echo "build obj path"
	@mkdir $(OBJS_PATH)

%.o : %.c
	@echo "CC $<"
	@$(CC) $(CFLAGS) $< -o $@ $(INCLUDE_PATH)
	@cp $@ $(OBJS_PATH)$(notdir $@)
%.o : %.S
	@echo "CC $<"
	@$(CC) $(CFLAGS) $< -o $@ $(INCLUDE_PATH)
	@cp $@ $(OBJS_PATH)$(notdir $@)
.PHONY : clean
clean :
	@rm -rf $(OBJS_PATH) $(OBJS_S) $(OBJS_C)