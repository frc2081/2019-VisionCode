CC = g++

OBJECT_DIR = obj
BIN_DIR = bin
SOURCE_DIR = src
FRC_DIR = /usr/local/frc

EXECUTABLE := vision-target

SOURCES := CameraDisplay.cpp CameraSource.cpp ConfigurationReader.cpp \
					ContourWriter.cpp GripPipeline.cpp ImageData.cpp \
					IoEntity.cpp OpencvTest.cpp RawCameraSource.cpp \
					stdafx.cpp VisionConfiguration.cpp VisionManager.cpp \
					VisionManagerFactory.cpp VisionSink.cpp VisionSource.cpp

OBJECTS := $(SOURCES:.cpp=.o)

SOURCES := $(addprefix $(SOURCE_DIR)/, $(SOURCES))
OBJECTS := $(addprefix $(OBJECT_DIR)/, $(OBJECTS))
EXECUTABLE := $(addprefix $(BIN_DIR)/, $(EXECUTABLE))

CFLAGS := -Wall -ggdb -I$(FRC_DIR)/include -I$(SOURCE_DIR)
LDFLAGS := -L$(FRC_DIR)/lib -lopencv_calib3dd -lopencv_calib3d -lopencv_cored -lopencv_core -lopencv_features2dd -lopencv_features2d -lopencv_flannd -lopencv_flann -lopencv_highguid -lopencv_highgui -lopencv_imgcodecsd -lopencv_imgcodecs -lopencv_imgprocd -lopencv_imgproc -lopencv_java344 -lopencv_mld -lopencv_ml -lopencv_objdetectd -lopencv_objdetect -lopencv_photod -lopencv_photo -lopencv_shaped -lopencv_shape -lopencv_stitchingd -lopencv_stitching -lopencv_superresd -lopencv_superres -lopencv_videod -lopencv_videoiod -lopencv_videoio -lopencv_video -lopencv_videostabd -lopencv_videostab

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

mkdirs:
	mkdir -p $(SOURCE_DIR) $(OBJECT_DIR) $(BIN_DIR)

clean:
	rm -r $(OBJECT_DIR) $(BIN_DIR)
