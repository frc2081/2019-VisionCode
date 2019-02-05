CC = g++

OBJECT_DIR = obj
BIN_DIR = bin
SOURCE_DIR = src

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

CFLAGS := -Wall -ggdb $(shell pkg-config --cflags opencv) -I$(SOURCE_DIR)
LDFLAGS := $(shell pkg-config --libs opencv)

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
