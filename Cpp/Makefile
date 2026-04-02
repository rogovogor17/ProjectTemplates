# Makefile for managing CMake assemblies

# Colors for output
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[1;33m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[1;37m
BOLD := \033[1m
NC := \033[0m

# Project configurations
PROJECT_NAME := MyProject
BUILD_DIR := build
SOURCE_DIR := src
TESTS_DIR := tests
DEBUG_BUILD_DIR := $(BUILD_DIR)/Debug
RELEASE_BUILD_DIR := $(BUILD_DIR)/Release
PROJECT_ROOT := $(shell pwd)

# Cmake flags
CMAKE := cmake
CMAKE_FLAGS := -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# Default targets
.DEFAULT_GOAL := default

# Default target
.PHONY: default
default: help

# Show help
.PHONY: help
help:
	@echo "$(CYAN)=== Available targets ===$(NC)"
	@echo "  $(GREEN)debug$(NC)     		- Build debug version"
	@echo "  $(GREEN)release$(NC)   		- Build release version"
	@echo "  $(GREEN)all$(NC)       		- Build both versions"
	@echo "  $(MAGENTA)run-debug$(NC)    		- Run debug version"
	@echo "  $(MAGENTA)run-release$(NC)  		- Run release version"
	@echo "  $(BLUE)build-src$(NC)     	- Build single file (make build-src FILE=filename)"
	@echo "  $(BLUE)run-src$(NC)     		- Build and run single file (make run-src FILE=filename [ARGS=\"arguments\"])"
	@echo "  $(RED)clean$(NC)     		- Clear all assemblies"
	@echo "  $(WHITE)help$(NC)         		- Show help"

# Debug assemble
.PHONY: debug
debug: configure-debug
	@echo "$(YELLOW)Build debug version...$(NC)"
	@$(CMAKE) --build $(DEBUG_BUILD_DIR) --config Debug -- --no-print-director
	@echo "$(GREEN)✓ Debug build completed successfully$(NC)"

# Release assemble
.PHONY: release
release: configure-release
	@echo "$(YELLOW)Build release version...$(NC)"
	@$(CMAKE) --build $(RELEASE_BUILD_DIR) --config Release -- --no-print-director
	@echo "$(GREEN)✓ Release build completed successfully$(NC)"

# Both assemblies
.PHONY: all
all: debug release
	@echo "$(GREEN)✓ All builds completed successfully$(NC)"

# Config debug version
.PHONY: configure-debug
configure-debug:
	@echo "$(BLUE)Config debug version...$(NC)"
	@mkdir -p $(DEBUG_BUILD_DIR)
	@cd $(DEBUG_BUILD_DIR) && $(CMAKE) $(PROJECT_ROOT) -DCMAKE_BUILD_TYPE=Debug $(CMAKE_FLAGS)
	@echo "$(GREEN)✓ Debug configuration completed$(NC)"

# Config release version
.PHONY: configure-release
configure-release:
	@echo "$(BLUE)Config release version...$(NC)"
	@mkdir -p $(RELEASE_BUILD_DIR)
	@cd $(RELEASE_BUILD_DIR) && $(CMAKE) $(PROJECT_ROOT) -DCMAKE_BUILD_TYPE=Release $(CMAKE_FLAGS)
	@echo "$(GREEN)✓ Release configuration completed$(NC)"

# Run debug version
.PHONY: run-debug
run-debug: debug
	@echo "$(MAGENTA)Run debug version...$(NC)"
	@./$(DEBUG_BUILD_DIR)/$(PROJECT_NAME) $(ARGS)

# Run release version
.PHONY: run-release
run-release: release
	@echo "$(MAGENTA)Run release version...$(NC)"
	@./$(RELEASE_BUILD_DIR)/$(PROJECT_NAME) $(ARGS)

# Build single file using CMake
.PHONY: build-src
build-src: configure-debug
	@if [ -z "$(FILE)" ]; then \
		echo "$(RED)Error: Please specify FILE parameter (filename without extension)$(NC)"; \
		echo "$(YELLOW)Usage: make build-src FILE=filename$(NC)"; \
		echo ""; \
		echo "$(CYAN)Available source files:$(NC)"; \
		$(MAKE) list-src; \
		exit 1; \
	fi
	@echo "$(YELLOW)Building $(FILE) with CMake...$(NC)"
	@if cd $(DEBUG_BUILD_DIR) && $(CMAKE) --build . --target $(FILE) -- --no-print-director; then \
		echo "$(GREEN)✓ Successfully built $(FILE)$(NC)"; \
	else \
		echo "$(RED)✗ Failed to build $(FILE) with CMake$(NC)"; \
		exit 1; \
	fi

# Run single file using CMake (debug mode by default)
.PHONY: run-src
run-src: build-src
	@echo "$(MAGENTA)Running $(FILE) with arguments: $(ARGS)$(NC)"
	@./$(DEBUG_BUILD_DIR)/$(FILE) $(ARGS)

# Clear debug assemble
.PHONY: clean-debug
clean-debug:
	@echo "$(RED)Clear debug assemble...$(NC)"
	@rm -rf $(DEBUG_BUILD_DIR)
	@echo "$(GREEN)✓ Debug assemble cleared$(NC)"

# Clear release assemble
.PHONY: clean-release
clean-release:
	@echo "$(RED)Clear release assemble...$(NC)"
	@rm -rf $(RELEASE_BUILD_DIR)
	@echo "$(GREEN)✓ Release assemble cleared$(NC)"

# Complete clean
.PHONY: clean
clean: clean-debug clean-release
	@echo "$(RED)Complete clean...$(NC)"
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN)✓ All assemblies cleared$(NC)"
