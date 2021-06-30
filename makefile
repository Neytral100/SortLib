APP_NAME = sortapp
LIB_NAME = libsort

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MP -MMD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).so

SRC_EXT = c

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TST_OBJECTS:.o=.d)

.PHONY: all
all: $(BIN_DIR) $(OBJ_DIR) $(SRC_DIR) $(RES_DIR) $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -L$(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME) -lsort -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	$(CC) -shared -o $(LIB_PATH) $^

$(OBJ_DIR)/%.o: %.c
	$(CC) -fPIC -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(APP_NAME)
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)

.PHONY: clean
clean:
	-rm -f $(APP_PATH) $(LIB_PATH) $(APP_OBJECTS) $(LIB_OBJECTS) $(DEPS) 