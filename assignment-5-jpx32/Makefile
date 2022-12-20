TARGET_EXEC := project

BUILD_DIR := ./build
SRC_DIR := ./src

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

RELEASE := $(BUILD_DIR)/$(TARGET_EXEC)

$(RELEASE): $(OBJS)
	$(CC) $(OBJS) -o $@ -lm

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ -lm

all: $(RELEASE)

debug: CPPFLAGS += -g -Wall -lm
debug: all

clean:
	rm -rf $(BUILD_DIR)

	