# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkettani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 14:15:50 by jkettani          #+#    #+#              #
#    Updated: 2019/01/18 17:56:15 by jkettani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- VARIABLES -----

NC =               \x1b[0m
OK_COLOR =         \x1b[32;01m
ERR_COLOR =        \x1b[31;01m
WARN_COLOR =       \x1b[34;01m
QUIET :=           @
ECHO :=            @echo
ifneq ($(QUIET),   @)
ECHO :=            @true
endif
SHELL =            /bin/sh
MAKEFLAGS +=       --warn-undefined-variables
NAME =             libftprintf.a
TEST =			   test.out
TEST_PRINTF =      printf_test.out
SRC_PATH =         srcs
INC_PATH =         includes
INC_PATH_LFT =     $(SRC_PATH)/libft/includes
OBJ_PATH =         .obj
TEST_PATH =        tests
TEST_SRC =         $(TEST_PATH)/main_test.c
TEST_PRINTF_SRC =  $(TEST_PATH)/printf_output_tests.c
LFT_PATH =         libft/srcs
LIB_PATH =         .
RM =               rm -f
RMDIR =            rmdir -p
AR =               ar
ARFLAGS =          -rcs
CC =               gcc
CFLAGS =           -Werror -Wall -Wextra
CPPFLAGS =         -I$(INC_PATH) -I$(INC_PATH_LFT)
DEPFLAGS =         -MT $@ -MMD -MP -MF $(OBJ_PATH)/$*.Td
LIBFLAGS =         -L$(LIB_PATH) -lftprintf
COMPILE.c =        $(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c
POSTCOMPILE =      @mv -f $(OBJ_PATH)/$*.Td $(OBJ_PATH)/$*.d && touch $@
SRC_NAME_LFT =     str/ft_strdup_c str/ft_strdel print/ft_putstr \
				   print/ft_putstr_fd str/ft_strlen print/ft_putnbr \
				   print/ft_putnbr_fd print/ft_putchar_fd
SRC_NAME =     	   ft_printf \
				   $(addprefix $(LFT_PATH)/, $(SRC_NAME_LFT))
SRC =              $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(SRC_NAME)))
OBJ =              $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))
DEP =              $(addprefix $(OBJ_PATH)/, $(SRC:.c=.d))
OBJ_TREE =         $(shell find $(OBJ_PATH) -type d -print 2> /dev/null)

.SUFFIXES:
.SUFFIXES: .c .o .h

# ----- RULES -----

.PHONY: all
all: $(NAME)

.PRECIOUS: $(OBJ_PATH)%/. $(OBJ_PATH)/. 
$(OBJ_PATH)/. $(OBJ_PATH)%/.: 
	$(ECHO) "Making directory $(WARN_COLOR)$@$(NC)..."
	$(QUIET) mkdir -p $@

$(OBJ_PATH)/%.d: ;

.SECONDEXPANSION:

$(OBJ): $(OBJ_PATH)/%.o: %.c $(OBJ_PATH)/%.d | $$(@D)/.
	$(ECHO) "Compiling $(WARN_COLOR)$<$(NC)..."
	$(QUIET) $(COMPILE.c) $< -o $@
	$(QUIET) $(POSTCOMPILE)

$(NAME): $(OBJ)
	$(ECHO) "Building archive file $(WARN_COLOR)$(NAME)$(NC)..."
	$(QUIET) $(AR) $(ARFLAGS) $@ $?

.PHONY: test
test: $(TEST)

.PHONY: $(TEST)
$(TEST): all
	$(ECHO) "Compiling $(WARN_COLOR)$@$(NC)..."
	$(QUIET) $(CC) $(CFLAGS) $(CPPFLAGS) $(TEST_SRC) $(LIBFLAGS) -o $@
	$(ECHO) "Launching tests..."
	$(QUIET) ./$@

.PHONY: printf_test
printf_test: $(TEST_PRINTF)

.PHONY: $(TEST_PRINTF)
$(TEST_PRINTF):
	$(QUIET) $(CC) $(TEST_PRINTF_SRC) -o $@
	$(QUIET) ./$@

.PHONY: clean
clean:
	$(ECHO) "Cleaning object files..."
	$(QUIET) $(RM) $(OBJ)
	$(ECHO) "Cleaning dependency files..."
	$(QUIET) $(RM) $(DEP)
	$(ECHO) "Cleaning obj tree..."
	$(QUIET) echo $(OBJ_TREE) | xargs $(RMDIR) 2> /dev/null || true
	@if [ -d $(OBJ_PATH) ]; \
		then echo "$(ERR_COLOR)-> Could not clean obj directory.$(NC)"; \
		else echo "$(OK_COLOR)-> Obj directory succesfully cleaned.$(NC)"; fi

.PHONY: fclean
fclean: clean
	$(ECHO) "Cleaning $(NAME)..."
	$(QUIET) $(RM) $(NAME)
	@if [ -f $(NAME) ]; \
		then echo "$(ERR_COLOR)-> Could not clean $(NAME).$(NC)"; \
		else echo "$(OK_COLOR)-> $(NAME) succesfully cleaned.$(NC)"; fi
	$(QUIET) $(RM) $(TEST)

.PHONY: re
re: fclean all

# ----- INCLUDES -----

-include $(DEP)
