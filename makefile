CC = g++

OBJECT_DIR = obj
BIN_DIR = bin
INIT_SRC_DIR = init
INIT_SCRIPT = visiontargetd
INIT_INSTALL_DIR = /etc/init.d
INIT_RC_DIR = /etc/rc5.d
SOURCE_DIR = src
FRC_DIR = /usr/local/frc
INSTALL_DIR = /usr/local/bin
HEADER_DIR = include
WPI_INCLUDE = /usr/include/frc
WPI_LIB = /usr/lib/frc

EXECUTABLE_NAME := vision-target

SOURCES := CameraDisplay.cpp CameraSource.cpp ConfigurationReader.cpp \
					ContourWriter.cpp GripPipeline.cpp ImageData.cpp \
					IoEntity.cpp OpencvTest.cpp RawCameraSource.cpp \
					stdafx.cpp VisionConfiguration.cpp VisionManager.cpp \
					VisionManagerFactory.cpp VisionSink.cpp VisionSource.cpp \
					VisionFilter.cpp TargetFilter.cpp TextDisplay.cpp \
					TargetPairFilter.cpp SingleVisionFilter.cpp TestSource.cpp \
					ContourDrawingFilter.cpp ImageDisplay.cpp DataOverlayFilter.cpp

OBJECTS := $(SOURCES:.cpp=.o)

SOURCES := $(addprefix $(SOURCE_DIR)/, $(SOURCES))
OBJECTS := $(addprefix $(OBJECT_DIR)/, $(OBJECTS))
EXECUTABLE := $(addprefix $(BIN_DIR)/, $(EXECUTABLE_NAME))
INIT_RC_SCRIPT := S02$(INIT_SCRIPT)

CFLAGS := -Wall -ggdb $(shell pkg-config --cflags opencv) -I$(HEADER_DIR) -I$(WPI_INCLUDE)
LDFLAGS := -L$(WPI_LIB) $(shell pkg-config --libs opencv) -lntcore -lwpiutil

all: mkdirs $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(EXECUTABLE) $(OBJECTS)

$(OBJECT_DIR)/CameraDisplay.o: $(SOURCE_DIR)/CameraDisplay.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/CameraSource.o: $(SOURCE_DIR)/CameraSource.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/ConfigurationReader.o: $(SOURCE_DIR)/ConfigurationReader.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/ContourWriter.o: $(SOURCE_DIR)/ContourWriter.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/GripPipeline.o: $(SOURCE_DIR)/GripPipeline.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/ImageData.o: $(SOURCE_DIR)/ImageData.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/IoEntity.o: $(SOURCE_DIR)/IoEntity.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/OpencvTest.o: $(SOURCE_DIR)/OpencvTest.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/RawCameraSource.o: $(SOURCE_DIR)/RawCameraSource.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/stdafx.o: $(SOURCE_DIR)/stdafx.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/VisionConfiguration.o: $(SOURCE_DIR)/VisionConfiguration.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/VisionManager.o: $(SOURCE_DIR)/VisionManager.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/VisionManagerFactory.o: $(SOURCE_DIR)/VisionManagerFactory.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/VisionSink.o: $(SOURCE_DIR)/VisionSink.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/VisionSource.o: $(SOURCE_DIR)/VisionSource.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/VisionFilter.o: $(SOURCE_DIR)/VisionFilter.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/TargetFilter.o: $(SOURCE_DIR)/TargetFilter.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/TargetPairFilter.o: $(SOURCE_DIR)/TargetPairFilter.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/SingleVisionFilter.o: $(SOURCE_DIR)/SingleVisionFilter.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/TextDisplay.o: $(SOURCE_DIR)/TextDisplay.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/TestSource.o: $(SOURCE_DIR)/TestSource.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/ContourDrawingFilter.o: $(SOURCE_DIR)/ContourDrawingFilter.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/ImageDisplay.o: $(SOURCE_DIR)/ImageDisplay.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/DataOverlayFilter.o: $(SOURCE_DIR)/DataOverlayFilter.cpp
	$(CC) $(CFLAGS) -c $< -o $@

mkdirs:
	mkdir -p $(SOURCE_DIR) $(OBJECT_DIR) $(BIN_DIR)

clean:
	rm -fr $(OBJECT_DIR) $(BIN_DIR)

install:
	cp -v $(EXECUTABLE) $(INSTALL_DIR)
	cp -v "$(INIT_SRC_DIR)/$(INIT_SCRIPT)" "$(INIT_INSTALL_DIR)"
	# Forcefull removes windows-based line endings, in the event that git puts them there.
	sed -i 's/\r//g' "$(INIT_INSTALL_DIR)/$(INIT_SCRIPT)" 
	ln -s "$(INIT_INSTALL_DIR)/$(INIT_SCRIPT)" "$(INIT_RC_DIR)/$(INIT_RC_SCRIPT)"
	

uninstall:
	rm -fv $(INSTALL_DIR)/$(EXECUTABLE_NAME)
	rm -fv "$(INIT_INSTALL_DIR)/$(INIT_SCRIPT)"
	rm -fv "$(INIT_RC_DIR)/$(INIT_RC_SCRIPT)"

cleaninstall: uninstall clean all install
