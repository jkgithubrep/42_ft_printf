# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkettani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 14:15:50 by jkettani          #+#    #+#              #
#    Updated: 2019/03/20 16:37:33 by jkettani         ###   ########.fr        #
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
OBJ_PATH =         .obj
TEST_PATH =        tests
TEST_SRC =         $(TEST_PATH)/main_ft_printf_test.c
TEST_PRINTF_SRC =  $(TEST_PATH)/printf_output_tests.c
LFT_PATH =         libft
LIB_PATH =         .
RM =               rm -f
RMDIR =            rmdir -p
AR =               ar
ARFLAGS =          -rcs
CC =               gcc
ifeq ($(LEAK_TYPE), full)
LEAK_TYPE =        full
else
LEAK_TYPE =        summary
endif
VALFLAGS =         --leak-check=$(LEAK_TYPE)
CERRFLAGS =        -Wall -Wextra
CFLAGS =           -g3 -Werror -Wall -Wextra
CPPFLAGS =         -I$(INC_PATH)
DEPFLAGS =         -MT $@ -MMD -MP -MF $(OBJ_PATH)/$*.Td
LIBFLAGS =         -L$(LIB_PATH) -lftprintf
COMPILE.c =        $(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c
POSTCOMPILE =      @mv -f $(OBJ_PATH)/$*.Td $(OBJ_PATH)/$*.d && touch $@
SRC_NAME_LFT =     str/ft_strdel str/ft_strlen str/ft_strchr str/ft_instr \
				   convert/ft_atoi char/ft_isdigit char/ft_isspace \
				   convert/ft_digits_base convert/ft_udigits_base \
				   convert/ft_imaxtoa_base convert/ft_uimaxtoa_base \
				   str/ft_strnew mem/ft_bzero mem/ft_memset \
				   convert/ft_is_valid_base char/ft_isprint \
				   char/ft_issign math/ft_max str/ft_strpad_left \
				   str/ft_strpad_right str/ft_strprepend str/ft_strappend \
				   str/ft_strcnew str/ft_strjoin str/ft_strcat str/ft_strcpy \
				   str/ft_strskip str/ft_strcut str/ft_strncpy \
				   str/ft_strdup mem/ft_memalloc mem/ft_memcpy \
				   mem/ft_memjoin mem/ft_memcat char/ft_tolower \
				   char/ft_isupper str/ft_strndup str/ft_strcmp str/ft_strclcat\
				   str/ft_strlcat str/ft_strdel_ret math/ft_exponent \
				   bigint/ft_bigint_comp bigint/ft_bigint_add \
				   bigint/ft_bigint_subst bigint/ft_bigint_order \
				   bigint/ft_bigint_size bigint/ft_uimax_to_bigint \
				   bigint/ft_bigint_shiftleft bigint/ft_bigint_multiply_uint \
				   bigint/ft_bigint_cpy bigint/ft_bigint_multiply \
				   bigint/ft_bigint_divide bigint/ft_bigint_pow10 math/ft_abs \
				   str/ft_strupper char/ft_islower char/ft_toupper \
				   str/ft_strdel_ret_null
SRC_NAME =     	   ft_printf get_formatted_str \
				   dbl_to_str_conv format_parser conv_spec_parser \
				   int_type_handler dbl_type_handler dbl_utils \
				   int_to_str_conv formatting_utils int_formatting_utils \
				   options_handler conv_spec_parser_utils \
				   dbl_digits_buf_rfmt dbl_prec_utils \
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
	$(QUIET) $(CC) $(CERRFLAGS) $(CPPFLAGS) $(TEST_SRC) $(LIBFLAGS) -o $@
	$(ECHO) "Launching tests..."
	$(QUIET) ./$@

.PHONY: valgrind
valgrind: test
	$(ECHO) "Launching valgrind on $(WARN_COLOR)$(TEST)$(NC)"
	$(QUIET) valgrind $(VALFLAGS) ./$(TEST)

.PHONY: printf_test
printf_test: $(TEST_PRINTF)

.PHONY: $(TEST_PRINTF)
$(TEST_PRINTF):
	$(QUIET) $(CC) $(CERRFLAGS) $(TEST_PRINTF_SRC) -o $@
	$(QUIET) ./$@ $(select)

.PHONY: norminette
norminette: 
	norminette $(SRC_PATH)/*.c
	norminette $(INC_PATH)/*.h

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
	$(ECHO) "Cleaning ${WARN_COLOR}$(TEST)${NC}..."
	$(QUIET) $(RM) $(TEST)
	$(ECHO) "Cleaning ${WARN_COLOR}$(TEST_PRINTF)${NC}..."
	$(QUIET) $(RM) $(TEST_PRINTF)

.PHONY: re
re: fclean all

# ----- INCLUDES -----

-include $(DEP)
