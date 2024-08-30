BUILD_DIR := build

CMAKE_CMD := cmake
CMAKE_OPTIONS := -S . -B $(BUILD_DIR)

BUILD_CMD := $(CMAKE_CMD) --build $(BUILD_DIR)

EXECUTABLE := BlockchainSimulation

all: $(BUILD_DIR)/$(EXECUTABLE)

$(BUILD_DIR)/$(EXECUTABLE): $(BUILD_DIR)/CMakeCache.txt
	$(BUILD_CMD)

$(BUILD_DIR)/CMakeCache.txt: | $(BUILD_DIR)
	$(CMAKE_CMD) $(CMAKE_OPTIONS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

run: $(BUILD_DIR)/$(EXECUTABLE)
	./$(BUILD_DIR)/$(EXECUTABLE)

.PHONY: all clean
